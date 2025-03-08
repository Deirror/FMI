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
| **Bit stuffing** | The beginning and end of each payload are marke with the flag *01111110* |

Procedure of work
-

- Timeout, resending, numbering frames, duplicates removing
- Cyclic Redundancy Check - calculating checksums

Sliding Window
-

- **Stop-And-Wait**, **Go Back N**, **Selective Repeat** - Sending data methods
- Protocols - **SDLC**, **HDLC**, **PPP**, **LCP**, **PAP/CHAP**, **NCP**, **IP**, **MPLS** and etc. - A way to structure data in a frame

# (4) Channel(Data Link) Level In LAN

- Medium Access Control - MAC
