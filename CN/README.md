# Concepts of Computer Networking

# (1) Computer Networking


- Represents a graph with physical devices and connections between them
- The physical devices are the **nodes**
- The connections are the **edges**
 
Networking Hardware
-

<img src="https://github.com/user-attachments/assets/bd2a3455-35fe-46a9-b442-816f204c2c8d" height=300 width=450/>

### Adapters

- PCI cards
- USB/CardBus adapter

### Modem

- A device, which allows the computer to transfer data via **dial-up** or **DSL**

Protocols
-

- A rule about how should the data be transfer via Internet

Topologies
-

- It is about how the physical devices should be organized
  - **Physical** - defines the layout of the physical devices
  - **Signal** - defines how the signals travel(electrical or wirelessly)
  - **Logical** - defines how data flows(Ethernet, switch LAN/WAN and etc.)

- **Logical Topology** is defined by the *networking architecture*

<img src="https://github.com/user-attachments/assets/4cd6bc4d-c4e1-4cd0-a03a-c9fc37e7499d" height=300 width=520/>

Standarts
-

- ISO/IEEE 802

Metropolitan Area Networks(MAN)
-

- Backbone and client interface

Commutation
-

- The responsibility to maintain a connection
- **Commutation of packets** - transfering segments of the data with numbering each transfer

# (2) OSI Model And TCP/IP


Decomposing
-

- Breaking down a complex task into several simpler tasks – modules

Multilayer network architecture
-

- Each layer offers an interface for the next layer
- If we change the implementation of one layer, this shouldn't break the oder ones - **transparency** and **flexibility**
- **Service** - defines the functionalities of the layer
- **Interface** - defines the way which the layer can be accessed
- **Protocol** - defines the realization of the service

Layers
-


| Name | Description | Devices | Protocols | Realization |
| --- | --- | --- | --- | --- |
| **Physical** | Decoding and encoding the signals | **Networking cards**, **Modems** | **Ethernet**, **Wi-Fi** | Hardware |
| **Data Link** | Controlling the **P2P** model. The data is exchanged with portions(**PDU**) | **Switch** | **MAC** | Hardware |
| **Network** | Responsible for the functioning of the communication subnet. Assigns IP adresses and manages packages | **Routers**, **Firewalls** | **IP** | Hardware/Program |
| **Transport** | Ensures the transportation of the data from sender to reciever (using ports, *end-to-end*), by accepting segments(**PDU**) from or passing them to the **Network Layer** | **Load Balancers**, **Firewalls** | **TCP**, **UDP** | Program |
| **Session** | Responsible for establishing, maintaining, and terminating communication sessions between applications | **Gateways** | **RPC** | Program |
| **Presentation** | Formats, (d)encrypts/ and compresses data | **VPN**, **Proxy** | **SSL/TSL** | Program |
| **Application** | Handles user interactions and application services | **Web servers** | **HTTP**, **FTP**, **DNS** | Program |

TCP/IP
-

- Communication protocol that defines how data is transmitted, received over networks

| Protocol | Description | Type |
| --- | --- | -- |
| **IP** | Packets are sent without prior setup of a session between sender and receiver and can take different paths to reach the destination | **Connectionless** |
| **UDP** | Runs on top of **IP**. Used for real-time applications like VoIP, video streaming, and online gaming | **Connectionless** |
| **TCP** | Establishes a connection before sending data (via handshake). It ensures reliable delivery, correct order, and error correction | **Connection-based** |

Random Linear Network Coding
-

- Encodes each package in a linear equation, meaning decoding needs N packages to decode whole data

# (3) Channel(Data Link) Level And Protocols

| Protocol Types |
| --- |
| Synchornous/Asynchornous sending of bits |
| Symbol/Bit oriented |
| Pre-established connection/datagram |
| Detection/Ignoring of corrupted data |
| Making/Ignoring lost data |
| Recovery/Ignoring of lost and damaged data |
| (Without)Support for dynamic data compression |

| Channel Types | Description |
| --- | --- |
| **Simplex** | Allows only one-directional transmissions |
| **Half-Duplex** | Allows one and bidirectional transmissions |
| **Duplex** | Allows only bidirectional transmissions |

Main Services
-

- Data transfer. It can be (un)acknowledged connection(less|-oriented) service

Flow Control
 -

- Sometimes the source to send frames faster than they can be received by the recipient. This is resolved in the **Transport Layer**

Formation of frames
 -

- **Network Layer** sends data as packages and then the **Data Link Layer** is responsible for converting it into a **frame**, which consists of *header*, *payload* and *trailer*(stores checksum)

| Formation Method | Description |
| --- | --- |
| **Character count** | Stores the bytes of the *payload* in the *header* |
| **Character stuffing** | Adds **STX**(start of text), **ЕТX**(end of text) or **ESC**(escape) before the two special ones, which marks the borders of the *payload* |
| **Bit stuffing** | The beginning and end of each payload are marked with the flag *01111110* |

Procedure of work
-

- Timeout, resending, numbering frames, duplicates removing
- Cyclic Redundancy Check - calculating checksums

Sliding Window
-

- **Stop-And-Wait**, **Go Back N**, **Selective Repeat** - Sending data methods
- Protocols - **SDLC**, **HDLC**, **PPP**, **LCP**, **PAP/CHAP**, **NCP**, **IP**, **MPLS** and etc. - A way to structure data in a frame

# (4) Channel(Data Link) Level In LAN

- **LAN** - Public Broadcasting Networks
- **MAC** - Medium Access Control
- **Determined** and **racing**

- Slotted/Pure **ALOHA**

- **(Nonpersistent) CSMA** - Carrier Sense Multiple Access - sending data based on a time interval

- **Ethernet** - from **LAN**
- **MTU** - Maximum Transmission Unit - max size of *payload*
- **Jumbo Frames** - max size 9000 bytes

- Straight/Crossed Ethernet cabel

- **Hub** and **repeater** - If one device sends data, these devices send the data to the other devices
- **Bridge** and **switch** - same as **hub**, but analyzes recieved data and sends data **ONLY** to one other device

Spanning Tree
-

- **STP** - Spanning Tree Protocol - topology without cycles
- **STP** Algorithm - finds a path witout a cycle
  - Selecting Root Bridge - finds the lowest bridge ID (MAC address)
  - Selecting Root Ports - From the alternative paths, those with the lowest cost to Root Bridge are selected
  - Selecting Designated Ports - Port that sends and receives traffic from the Root Bridge – with the lowest value to the Root Bridge

# (5) Network Protocol - IPv4

Characteristics of IPv4
-

- IPv4 implements information exchange through packets, which are called IP datagrams
- IPv4 is a protocol for interaction without establishing a logical connection
- IPv4 provides fragmentation of the IP datagram if necessary (the maximum size of the IP fragment is 65535 bytes, but we use max around 1500 bytes)
- IPv4 datagrams have a specified lifetime in the network
- IPv4 does not guarantee the reliability of IP datagram delivery from the recipient
- IPv4 does not have any means of controlling the intensity of IP datagram transmission from the sender (flow control)
- IPv4 does not guarantee the correct sequence of IP datagrams from the recipient

Format of an IPv4's packet
-

| Field Name             | Size (Bits) | Description                                     |
|------------------------|-------------|-------------------------------------------------|
| Version                | 4           | IPv version (always 4 for IPv4)                 |
| IHL (Header Length)    | 4           | Header length in 32-bit words                   |
| Type of Service (ToS)  | 8           | Service priority and delay/throughput hints     |
| Total Length           | 16          | Total length of packet (header + data)          |
| Identification         | 16          | Used to identify fragments of the same packet   |
| Flags                  | 3           | Fragmentation control flags                     |
| Fragment Offset        | 13          | Position of this fragment in the original packet|
| Time to Live (TTL)     | 8           | Max hops before the packet is discarded         |
| Protocol               | 8           | Indicates payload type (e.g., TCP, UDP, ICMP)   |
| Header Checksum        | 16          | Error-checking for the header only              |
| Source IP Address      | 32          | Sender's IP address                             |
| Destination IP Address | 32          | Receiver's IP address                           |
| Options (optional)     | Variable    | Extra options (rarely used)                     |
| Data (Payload)         | Variable    | Actual encapsulated data (e.g., TCP/UDP)        |

IPv4 Classes
-

| Class | Address Range          | First Octet Range | Default Subnet Mask   | Leading Bits | Usage                      |
|-------|------------------------|-------------------|------------------------|--------------|----------------------------|
| A     | 0.0.0.0 – 127.255.255.255 | 0 – 127          | 255.0.0.0              | 0xxxxxxx     | Large networks             |
| B     | 128.0.0.0 – 191.255.255.255 | 128 – 191      | 255.255.0.0            | 10xxxxxx     | Medium networks            |
| C     | 192.0.0.0 – 223.255.255.255 | 192 – 223      | 255.255.255.0          | 110xxxxx     | Small networks             |
| D     | 224.0.0.0 – 239.255.255.255 | 224 – 239      | Not applicable         | 1110xxxx     | Multicast groups           |
| E     | 240.0.0.0 – 255.255.255.255 | 240 – 255      | Not applicable         | 1111xxxx     | Experimental (reserved)    |

Classless Inter-Domain Routing
-

- A method for allocating IP addresses and routing IP packets more efficiently than the old class-based system (Class A/B/C)
- Example: 192.168.1.0/24 -> /24 means the first 24 bits are the network portion 

Unicast, Multicast, Anycast, Broadcast
-

| Type      | Description                                                                 | Destination Count | Example Use Case                          |
|-----------|-----------------------------------------------------------------------------|-------------------|-------------------------------------------|
| **Unicast**   | One-to-one communication between a single sender and a single receiver.     | 1                 | Accessing a website from a user's PC      |
| **Multicast** | One-to-many communication for a group of interested receivers.              | 1 to many         | Streaming video to multiple subscribers   |
| **Anycast**   | One-to-one-of-many; data is sent to the nearest (or best) receiver in a group. | 1 (closest)       | CDN servers selecting the nearest node    |
| **Broadcast** | One-to-all communication on a local network (IPv4 only).                    | All on subnet     | ARP requests on a LAN                     |

# (6) Converting IP addresses to physical ones

Special and Partial IP addresses
-

| Address Range       | Name / Purpose              | Description                                                                 | Routable on Internet? |
|---------------------|-----------------------------|-----------------------------------------------------------------------------|------------------------|
| `127.0.0.0/8`       | Loopback                    | Used to send packets to self (e.g., `127.0.0.1` = `localhost`)              | ❌ No                 |
| `169.254.0.0/16`    | Link-Local                  | Auto-assigned if no DHCP; for local communication only                      | ❌ No                 |
| `10.0.0.0/8`        | Private Network             | Large private network space                                                 | ❌ No                 |
| `172.16.0.0/12`     | Private Network             | Medium private network space                                                | ❌ No                 |
| `192.168.0.0/16`    | Private Network             | Small private network space (common in home routers)                        | ❌ No                 |
| `0.0.0.0/8`         | "This host"                 | Represents the current device (used in routing or DHCP requests)            | ❌ No                 |
| `255.255.255.255`   | Broadcast                   | Broadcast address to all hosts on a local network                           | ❌ No                 |
| `224.0.0.0/4`       | Multicast                   | Reserved for multicast traffic                                              | ❌ No                 |
| `240.0.0.0/4`       | Reserved for future use     | Experimental or future definition                                           | ❌ No                 |

NAT
-

- **NAT (Network Address Translation)** is a function built into routers that allows multiple devices on a private network to share a single public IP address when accessing the internet
- Devices inside your network have **private IP addresses** (e.g., `192.168.x.x`)
- Your router has a **public IP address** from your internet provider
- NAT translates internal IPs to the public IP using different **port numbers**
- Responses from the internet are routed back to the correct internal device

| Device       | Private IP     | NAT Translation       | Public IP Appearance      |
|--------------|----------------|------------------------|----------------------------|
| Laptop       | 192.168.1.2    | → 203.0.113.42:45001   | Seen as 203.0.113.42:45001 |
| Phone        | 192.168.1.3    | → 203.0.113.42:45002   | Seen as 203.0.113.42:45002 |


- NAT runs on your **Wi-Fi router**, which:
 - Acts as a **gateway** between your private network and the public internet
 - Keeps track of connections using **port numbers**
 - Ensures traffic goes to the right device

- Saves IPv4 addresses
- Adds a layer of privacy
- Enables many devices to share one internet connection
