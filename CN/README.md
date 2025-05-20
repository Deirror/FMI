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

# (6) Converting IPv4 addresses to physical ones

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

Network Address Translation (NAT)
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

Address Resolution Protocol (ARP)
-

- **ARP (Address Resolution Protocol)** is a network protocol used to map an IP address (Layer 3) to a MAC address (Layer 2) within a local network
- Operates between the Network Layer and Data Link Layer
- Enables devices on the same LAN to discover each other's hardware (MAC) addresses
- When a device wants to send data to an IP address, it broadcasts an **ARP Request** asking:  
  *"Who has this IP? Tell me your MAC address."*
- The device with the matching IP responds with an **ARP Reply** containing its MAC address
- The requester caches the MAC address for future use to improve efficiency
- Essential for IPv4 communication on Ethernet networks
- IPv6 uses a similar mechanism called **Neighbor Discovery Protocol (NDP)** instead of ARP

Reverse Address Resolution Protocol (RARP)
-

- **RARP (Reverse Address Resolution Protocol)** is a network protocol used to map a MAC address (Layer 2) to an IP address (Layer 3) within a local network
- Works opposite to ARP by resolving hardware (MAC) addresses to IP addresses
- Mainly used by diskless or bootstrapping devices that know their MAC address but need to discover their IP address
- The device broadcasts a **RARP Request** asking:  
  *"Who has this MAC? Tell me the IP address."*
- A RARP server on the network replies with the corresponding IP address
- Largely obsolete today, replaced by more advanced protocols such as BOOTP and DHCP

Dynamic Host Configuration Protocol (DHCP)
-

- DHCP automatically assigns IP addresses and network settings (gateway, DNS, domain, etc.) to devices on a network, simplifying configuration
- Client-server protocol standardized
- Clients broadcast a request at startup; the DHCP server replies with IP and config info (DORA and DDD)
- IP allocation methods:
  - **Dynamic:** IPs leased temporarily from a pool
  - **Automatic:** Permanent IPs assigned from a pool
  - **Static:** Manual MAC-to-IP mapping (also called DHCP reservation)
- DHCP enables easy network management and device mobility

Internet Control Message Protocol (ICMP)
-

- ICMP is a core protocol of the IP suite used mainly for network error detection and diagnostic messaging
- ICMP messages are carried inside standard IP packets
- When a router decrements the IP packet's TTL to zero, it sends an ICMP "Time Exceeded" message back to the sender
- Common diagnostic tools use ICMP:
  - `ping` uses ICMP Echo Request and Echo Reply messages
  - `traceroute` sends UDP packets with varying TTLs, relying on ICMP Time Exceeded and Destination Unreachable replies
- IPv4 uses ICMPv4; IPv6 uses ICMPv6 (a related protocol)
- ICMP helps troubleshoot and manage IP networks effectively

Ping
-

- Ping is a network tool used to test the reachability of a host over an IP network
- Sends ICMP **Echo Request** packets to the target host
- Waits for ICMP **Echo Reply** responses
- Measures round-trip time (RTT) and packet loss
- Provides statistics including minimum, average, maximum, and sometimes standard deviation of RTT

Traceroute
-

- Traceroute is a network diagnostic tool used to discover the path packets take to reach a destination host
- Sends packets in sets of three, incrementing the TTL (Time To Live) starting from 1
- Each router decrements TTL by 1; when TTL reaches 0, the router discards the packet and sends back an ICMP "Time Exceeded" message
- Traceroute uses these ICMP replies to map each hop along the route
- Reports round-trip delay (latency) for each packet in milliseconds
- If no response is received before timeout, prints `*` (asterisk)
- May not show all intermediate hosts due to network routing or filtering

# (7) Network Protocol - IPv6

- Enable access to the global network for billions of hosts, even with inefficient use of the address space
- Reduce the size of routing tables
- Simplify the protocol to speed up packet processing during routing
- Enhance the security level of the protocol
- Ensure compatibility and coexistence between IPv6 and IPv4 protocols

Key IPv6 Features
-

- **Traffic Class:** Replaces IPv4’s Type of Service (ToS) for packet prioritization
- **Flow Label:** New field for Quality of Service (QoS) management
- **Payload Length:** Supports up to 64 KB payload per packet
- **Next Header:** Identifies the type of header following the IPv6 header
- **Hop Limit:** Replaces IPv4’s TTL (Time To Live)

Quality of Service (QoS)
-

- IPv4 treats packets equally using a "best effort" delivery model
- TCP guarantees delivery but does not control delay or bandwidth
- IPv6 supports QoS through Differentiated Services and Integrated Services
- Enables traffic prioritization policies and better network management

IPv6 Address Format
-

- IPv6 addresses consist of three parts:
  - **Network Prefix:** Identifies the network, assigned by ISPs or registries
  - **Subnet ID:** Identifies sub-networks within a larger network, assigned by administrators
  - **Host ID:** Identifies a specific interface on a host

Prefix Notation
-

- IPv6 uses prefix length notation, similar to IPv4 subnet masks
- Address Compression Rules:
  - Consecutive 16-bit groups of zeros can be compressed as `::` (only once per address)
  - Leading zeros in each group can be omitted
 
IPv6 vs IPv4
-

| Feature                     | IPv4                                              | IPv6                                                  |
|----------------------------|---------------------------------------------------|-------------------------------------------------------|
| **Address Length**         | 32-bit (e.g., `192.168.0.1`)                      | 128-bit (e.g., `2001:db8::1`)                         |
| **NAT**                    | Widely used due to address exhaustion             | Not required – large address space eliminates need   |
| **Auto Configuration**     | Manual or DHCP                                    | Stateless (SLAAC) and/or stateful (DHCPv6)           |
| **Neighbor Discovery**     | Uses ARP                                          | Uses **Neighbor Solicitation** (part of ND protocol) |
| **ICMP**                   | ICMPv4 (RFC 792), limited functionality           | ICMPv6 (RFC 4443), handles errors, discovery, etc.    |
| **Multicast Support**      | Limited multicast; heavy reliance on broadcast    | Extensive multicast; **broadcast removed**           |
| **Broadcast**              | Supported (`255.255.255.255`)                     | **Not supported** – replaced by multicast             |
| **Mobility and Extensibility** | Limited; requires NAT traversal and workarounds | Built-in features for mobile IP and extensibility     |
| **Header Complexity**      | Variable size, many fields                        | Simplified, fixed header size                         |

ICMPv4 vs ICMPv6
-

- **ICMPv4**: Primarily used for error reporting and tools like `ping` and `traceroute`.
- **ICMPv6**: Much more comprehensive; supports:
  - Router Solicitation & Advertisement
  - Neighbor Solicitation & Advertisement (replaces ARP)
  - Redirects
  - Multicast Listener Discovery (MLD)
  - Packet too big, Time exceeded, etc

Multicast vs Broadcast
-

| Type         | IPv4                     | IPv6                              |
|--------------|--------------------------|------------------------------------|
| **Broadcast**| Used for ARP, DHCP, etc. | **Not available**                 |
| **Multicast**| Limited use              | Core mechanism for discovery and services |
| **Unicast**  | Supported                | Supported                          |
| **Anycast**  | Rare                     | **Native support** in IPv6         |


- IPv6 improves performance, scalability, and security, especially by removing broadcast traffic and eliminating the need for NAT

# (8) Introduction to Routing

| **Category**                | **Description**                                                                                                                                 |
|----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| **Main Function**          | The network layer routes packets from source to destination over multiple hops. Each router uses a **routing table** to forward packets.       |
| **Routing Decision Basis** | - **Datagram networks**: Route selected per-packet. <br> - **Virtual circuit networks**: Route chosen during circuit setup.                    |


| **Requirement**                              | **Purpose**                                                                                     |
|---------------------------------------------|-------------------------------------------------------------------------------------------------|
| Simplicity & reliability                    | Easy configuration and stable network operation                                                 |
| Fault detection                              | Reacts quickly to router or link failures                                                       |
| Alternate path discovery                     | Finds other routes when failures occur                                                          |
| Delay vs. Throughput trade-off              | Low delay vs. high throughput—often competing optimization goals                                |
| Fair resource usage                         | Ensures all users have fair access to network resources                                         |

| **Type**            | **Description**                                                                                     | **Use Case**                            |
|---------------------|-----------------------------------------------------------------------------------------------------|-----------------------------------------|
| Static (Non-adaptive) | Precomputed routes, manually updated if topology changes.                                          | Small, stable networks                  |
| Dynamic (Adaptive)  | Routing tables update automatically based on current network state.                                 | Medium to large, changing networks      |


| **Concept**      | **Explanation**                                                                                                  |
|------------------|------------------------------------------------------------------------------------------------------------------|
| **Convergence**  | Time taken for all routers to synchronize their routing tables after a change.                                  |
| **Metric**       | Criteria used to compute best path: hops, delay, cost, reliability, etc.                                         |
| **Optimization Principle** | Every sub-path of an optimal path is also optimal (used in shortest path algorithms).                 |


| **Algorithm**        | **Type**        | **Key Features**                                                                            |
|----------------------|----------------|---------------------------------------------------------------------------------------------|
| Dijkstra's Algorithm | Link-state     | Finds shortest path from one node to all others; works with positive edge weights only.     |
| Bellman-Ford         | Distance-vector| Handles negative weights; slower convergence.                                               |

| **Metric**    | **Definition**                                                     |
|---------------|--------------------------------------------------------------------|
| Hop Count     | Number of routers between source and destination                  |
| Delay         | Time to forward a packet                                           |
| Reliability   | Probability of link being available                               |
| Cost          | Administratively assigned value                                   |

| **Concept**     | **Description**                                                                                         |
|------------------|--------------------------------------------------------------------------------------------------------|
| **Sink Tree**    | Optimal paths from all nodes to a destination form a tree.                                             |
| **SPF Tree**     | Shortest Path First Tree – result of Dijkstra’s algorithm.                                             |

# (9) Static routing

- Static routing involves manually defining fixed paths in a router's configuration. It’s commonly used in small, stable networks where routes rarely change

Key Characteristics
-
- Routes are manually added and do not change automatically
- Simple and fast, but lacks fault tolerance
- Best suited for networks with one path to external networks (stub networks)

Stub Networks
-

- Stub networks have only one exit point. In these setups:
  - Static routes direct all outbound traffic to the main router
  - Branch routers only need to know how to reach the core (e.g., HQ)
  - Reduces the need for dynamic routing protocols on WAN links

Interface Static Routes
-
- A static route can reference only the outbound interface, treating the destination as directly connected

Network Functions Virtualization (NFV)
-

- **Network Functions Virtualization (NFV)** is a transformative approach to building and operating networks by virtualizing traditional network functions
- NFV replaces dedicated network hardware (like routers and firewalls) with software-based functions
- These functions run on **standard high-performance servers, switches, and storage**, removing the need for specialized equipment

Key Benefits
-

- **Dynamic deployment**: Functions can be moved or replicated across the network without new hardware
- **Efficiency**: Consolidates various network devices onto shared infrastructure
- **Scalability**: Rapid scaling and provisioning of services via software

NFV and SDN
-
- NFV and SDN (Software-Defined Networking) are **complementary technologies**:
- **SDN** separates the control plane from the data plane, providing a centralized view of the network
- **NFV** focuses on virtualizing and optimizing network services themselves

# (10) Distance Vector Routing

- **Distance Vector (DV) Routing** is a distributed routing method where routers share information about the direction and distance to network destinations

## Core Concepts

- Each router advertises its routing table as a vector:
  - **Direction**: The next hop address and outgoing interface
  - **Distance (Metric)**: Typically the number of hops to the destination

- Routers using DV do **not** know the full path to the destination — only the next hop and cost

Bellman-Ford Algorithm
-

- DV routing is based on the **Bellman-Ford algorithm**
- Each node periodically sends its distance vector to immediate neighbors
- Each router builds a **routing table** that stores:
  - Destination address
  - Next hop
  - Metric (cost of best-known path)

Metrics
-

- The metric can be:
  - **Hop count**: Each hop has a cost of 1
  - **Load**: Based on the number of packets in the outgoing queue
  - **Delay**: Measured via echo packets and response time from neighbors

Advantages
-

- Lightweight on CPU and memory
- Simple to implement and maintain

Disadvantages
-

- **Slow convergence**, especially for "bad news" (e.g., link failures)
- Periodic updates consume bandwidth
- Susceptible to routing loops and outdated information

# (11) Routing with connection status monitoring

- Link-State (LS) routing protocols provide each router with a complete map of the network
- Unlike Distance Vector (DV), which relies on periodic rumor-based updates, LS routing is more precise and faster to converge

Key Characteristics
-

- **LS packets**: Routers share info about directly connected neighbors and link states
- **Flooding**: Each router broadcasts link-state packets across the network
- **Database**: All routers construct an identical link-state database
- **Computation**: Each router independently computes shortest paths using Dijkstra's algorithm

Main LS Protocols
-

- **OSPF** (Open Shortest Path First)
- **IS-IS** (Intermediate System to Intermediate System)
- **OLSR** (Optimized Link State Routing Protocol, RFC 3626)

Steps in LS Routing
-

1. **Neighbor Discovery**: Send echo packets and identify adjacent routers
2. **Link Measurement**: Determine link cost (e.g., delay, load)
3. **LS Packet Generation**: Package local link info with a unique ID and TTL
4. **Flooding**: Distribute LS packets across the network
5. **Shortest Path Calculation**: Use Dijkstra’s algorithm to build routing tables

Comparison: Link-State vs Distance Vector
-

| Feature            | Distance Vector (DV)         | Link-State (LS)                |
|--------------------|-------------------------------|--------------------------------|
| Info Scope         | Next hop + metric only        | Full network topology          |
| Update Trigger     | Periodic                      | On topology change or interval |
| Convergence        | Slow                          | Fast                           |
| Computation        | Bellman-Ford                  | Dijkstra                       |

- LS routing adapts efficiently to changes in network topology, offering faster convergence and more informed path selection

Flooding of Link-State Packets
-

- To reliably distribute link-state information across the network, routers use **flooding**:
  - Each link-state packet is sent on **all interfaces except the one it was received on**
  - If a router receives a packet with a **newer sequence number** than previously seen from that origin, it updates its link-state database and forwards the packet
  - If the sequence number is **equal or lower**, the packet is discarded

Time-to-Live (TTL) for Link-State Data
-

- Link-state packets include a **TTL field**, indicating how long the information is valid:
  - TTL is decremented by **1 each second** and each time the packet is forwarded
  - When TTL reaches **0**, the data is discarded
  - This prevents stale routing data from lingering and being used incorrectly

Hierarchical Routing
-

- As networks grow, full topological awareness becomes inefficient. **Hierarchical routing** addresses this:
  - The network is split into **areas** (regions)
  - Routers know full topology **within their own area**
  - Between areas, routers only maintain **summary routes**, reducing table size and complexity

- Benefits:
  - **Scalability**: Smaller routing tables and reduced update overhead
  - **Efficiency**: Faster convergence within local areas
  - **Modularity**: Changes in one area don’t impact others

# (12) Routing Protocol RIP

- RIP (Routing Information Protocol) and the widely used distance vector routing protocol (DV)
- It is mainly suitable for small networks in which topology changes occur relatively rarely
- The max count of hops in a RIP Network is 15 - fixes "Count to infinity" problem
- Also has a TTL field
- There are a lot of configurations

# (13) Routing Protocol OSPF

- Open Shortest Path First (OSPF) is dynamic protocol for routing, which uses link-state routing (LS)

- Topology:
  - Network represented as a graph:
    - Nodes: Routers
    - Edges: Direct communication links
  - Cost values are inversely proportional to link speed
  - Each router maintains a complete Link-State Database (LSDB)
 
- Operation Phases:
  1. Hello Protocol:
     - Used to discover and maintain neighbor relationships.
     - Periodic Hello packets sent via active interfaces.
 
  2. Adjacency Formation (on LAN):
     - Routers elect a Designated Router (DR) and Backup DR (BDR).
     - Reduces OSPF update traffic by centralizing link-state exchanges.
 
  3. OSPF Neighbor States:
     - DOWN: No Hello received yet.
     - INIT: One-way Hello received.
     - 2-WAY: Bidirectional communication established; DR/BDR election.
     - EXSTART: Master/Slave roles set; start Database Descriptor (DBD) exchange.
     - EXCHANGE: Routers exchange DBD packets to describe their LSDB.
     - LOADING: Routers request missing LSAs (Link-State Advertisements).
     - FULL: LSDBs are synchronized; routers are fully adjacent.

- Multicast Support:
  - OSPF uses both unicast and multicast (e.g., 224.0.0.5 for all OSPF routers).
