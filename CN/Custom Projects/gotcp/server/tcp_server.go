package server

import (
	"fmt"
	"gotcp/ds"
	"gotcp/peer"
	"net"
	"sync"
)

type Message struct {
	Id         uint16
	RemoteAddr string
	Payload    []byte
}

type TCPServer struct {
	listenAddr string
	ln         net.Listener

	quitch chan struct{}
	msgch  chan Message

	peerLock sync.Mutex
	peers    map[string]peer.Peer

	pq ds.PriorityQueue
}

func NewTCPServer(listenAddr string) *TCPServer {
	pq := ds.InitPq(101)
	return &TCPServer{
		listenAddr: listenAddr,
		quitch:     make(chan struct{}),
		msgch:      make(chan Message, 10),
		peers:      make(map[string]peer.Peer),
		pq:         pq,
	}
}

func (s *TCPServer) OnPeer(p peer.Peer) error {
	s.peerLock.Lock()
	defer s.peerLock.Unlock()
	s.peers[p.RemoteAddr().String()] = p
	return nil
}

func (s *TCPServer) ListenAndStart() error {
	ln, err := net.Listen("tcp", s.listenAddr)
	if err != nil {
		return err
	}
	defer ln.Close()
	s.ln = ln

	// Listen func
	go func() {
		for msg := range s.msgch {
			text := string(msg.Payload)
			tp := text[0]
			if _, ok := s.peers[msg.RemoteAddr]; !ok {
				fmt.Printf("peer not connected, unknown: (%d - %s - %s)\n", msg.Id, msg.RemoteAddr, text)
				continue
			}
			fmt.Printf("received message from connection: (%d - %s - %s)\n", msg.Id, msg.RemoteAddr, text)
			switch tp {
			case '1':
				{
					// Message all
					for _, peer := range s.peers {
						if msg.Id != peer.GetId() {
							bid := []byte(" - by " + fmt.Sprint(peer.GetId()) + "\n")
							msg.Payload = append(msg.Payload, bid...)
							peer.Send(msg.Payload)
						}
					}
				}
			case '2':
				{
					// Message server -> ping pong
					s.peers[msg.RemoteAddr].Send([]byte("Received message\n"))
				}
			default:
				{
					fmt.Printf("unknown msg type: %v\n", tp)
				}
			}
		}
	}()

	go s.AcceptLoop()
	<-s.quitch
	close(s.msgch)

	return nil
}
func (s *TCPServer) getId() uint16 {
	s.peerLock.Lock()
	defer s.peerLock.Unlock()
	return s.pq.Pop().(*ds.Item).Value
}

func (s *TCPServer) pushId(id uint16) {
	s.peerLock.Lock()
	defer s.peerLock.Unlock()
	item := ds.Item{
		Value: id,
	}
	s.pq.Push(&item)
}

func (s *TCPServer) AcceptLoop() {
	for {
		conn, err := s.ln.Accept()
		if err != nil {
			fmt.Println("accept error:", err)
			continue
		}
		p := peer.NewTCPPeer(s.getId(), conn)
		s.OnPeer(p)
		fmt.Printf("new connection: (%d -> %v)\n", p.Id, p.Conn.RemoteAddr())
		go s.ReadLoop(p)
	}
}

func (s *TCPServer) ReadLoop(p peer.Peer) {
	defer p.Close()
	defer s.pushId(p.GetId())
	buf := make([]byte, 1024)
	for {
		n, err := p.Read(buf)
		if err != nil {
			fmt.Println("read error:", err)
			return
		}
		s.msgch <- Message{
			Id:         p.GetId(),
			RemoteAddr: p.RemoteAddr().String(),
			Payload:    buf[:n],
		}
	}
}
