# Application Level Programming

> [!IMPORTANT]
> Here we will use **Go** to *summarize* the knowledge of handling routers, servers, hadnlers and data transferring using REST or TCP

HTTP Server
-

### Using Default Server

```go
func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello from Go server!")
}

func main() {
	http.HandleFunc("/", handler)
	err := http.ListenAndServe(":8080", nil) // nil means use default ServeMux
	if err != nil {
		fmt.Println("Server error:", err)
	}
}
```

### Using a Custom http.ServeMux (Basic Router)

```go
func main() {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, "Custom router in action!")
	})

	http.ListenAndServe(":8080", mux)
}
```

### Using a Third-Party Router (e.g., chi)

```go
func main() {
	r := chi.NewRouter()

	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		w.Write([]byte("Welcome with Chi!"))
	})

	http.ListenAndServe(":8080", r)
}
```

### TCP Server using net Package (Lower-Level Network Programming)

```go
func handleConnection(conn net.Conn) {
	defer conn.Close()
	message, _ := bufio.NewReader(conn).ReadString('\n')
	fmt.Print("Message Received:", string(message))
	conn.Write([]byte("Message received\n"))
}

func main() {
	listener, _ := net.Listen("tcp", ":9000")
	defer listener.Close()
	fmt.Println("TCP server running on port 9000")

	for {
		conn, _ := listener.Accept()
		go handleConnection(conn)
	}
}
```
