package peer

import "net"

type TCPPeer struct {
	Id uint16
	net.Conn
}

func NewTCPPeer(id uint16, conn net.Conn) *TCPPeer {
	return &TCPPeer{
		Id:   id,
		Conn: conn,
	}
}

func (p *TCPPeer) Send(msg []byte) error {
	_, err := p.Conn.Write(msg)
	return err
}

func (p *TCPPeer) GetId() uint16 {
	return p.Id
}
