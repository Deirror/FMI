# Application Level Programming

> [!IMPORTANT]
> Here we will use **Go** to *summarize* the knowledge of handling routers, servers, hadnlers and data transferring using REST or TCP

HTTP Server
-

```go
package main

import (
	"fmt"
	"net/http"
)

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
