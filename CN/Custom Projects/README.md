# Concepts of Computer Networking

(1) Computer Networking
-

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

(2) OSI Model
-

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


| Name | Description | Devices | Realization |
| --- | --- | --- | --- |
| **Physical** | Decoding and encoding the signals | **Networking cards**, **Switch** or modems | Hardware |
| **Data Link** | Controlling the **P2P** model. The data is exchanged with portions(**PDU**) | **MAC** | Hardware |
| **Network** | Responsible for the functioning of the communication subnet. Assigns IP adresses and manages packages | **Routers**, **Firewalls** | Program |
| **Transport** | Ensures the transportation of the data from sender to reciever (using ports, *end-to-end*), by accepting from or passing the segments(**PDU**) to the **Network Layer** | **Computers** | Program |
| **Session** | | |
|**Presentation** | | | 
| **Application** | | |
