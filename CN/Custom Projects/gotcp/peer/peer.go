package peer

import "net"

type Peer interface {
	net.Conn
	Send([]byte) error
	GetId() uint16
}
