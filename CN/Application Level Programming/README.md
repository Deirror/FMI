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
