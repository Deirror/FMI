package main

import (
	"gotcp/server"
	"log"
)

func main() {
	s := server.NewTCPServer(":3000")
	log.Fatal(s.ListenAndStart())
}
