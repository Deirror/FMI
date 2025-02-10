# Socketz

Description
-

The main goal of `Socketz` is to demonstrate how networking in general works.

-  I chose C/C++ in order to show each step of the process
-  `Asio`(Asynchronous I/O model) used here as it is cross-platform and easy to understand

Steps
-
1. Asio 1.18 must be installed on your device
2. Clone the repo and make sure that you run on C++17 or higher(Modern C++ is used in the project)
3. Make *NetServer* and *NetClient* depend on the static library *NetCommon*
4. Compile them so that you get *NetServer.exe* and *NetClient.exe*
5. First, run the server and then run as many clients as you want
6. Press the keys(specified down below in the table) and see how networking works in C++

Keys
-

| Key | Task |
|---|---|
| `1` | Shows the ping of the connection(how much time it took to connect to the server) |
| `2` | Messages all the connected and accepted clients by a concrete client|
| `3` | Disconnects form the server |
