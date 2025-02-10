package server

import "gotcp/peer"

type Server interface {
	ListenAndStart() error
	AcceptLoop()
	ReadLoop()
	OnPeer(peer.Peer) error
}
