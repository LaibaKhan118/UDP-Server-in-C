# Windows-Native UDP Server in C

This project is a simple UDP server written in C that runs natively on Microsoft Windows using the Winsock2 library. It listens for incoming datagram messages on localhost port 5501 and prints received text to the console.

## Overview

The server is built as a connectionless UDP service, which means it does not establish a long-lived TCP connection. Instead, it receives individual packets and processes them immediately.

This implementation was adapted from common UDP client/server examples and modified to work on Windows instead of Linux.

## Features

- Windows-compatible socket programming using Winsock2
- Continuous listening loop for incoming UDP packets
- Simple text message reception from clients
- Explicit socket initialization and error handling

## Requirements

Before building the project, make sure you have:

1. A Windows C compiler such as MinGW-w64
2. The compiler added to your system PATH
3. Ncat for testing the server from another terminal

## Build the Server

Open Command Prompt or PowerShell, navigate to your folder, and run:

```bash
gcc main.c -o server.exe -lws2_32
```

### Run the Server

Start the server with:

```bash
./server.exe
```

The server binds to 127.0.0.1 on port 5501.

## Test with Ncat

Open a second terminal and send UDP data with:

```bash
ncat -u 127.0.0.1 5501
```

Type a message and press Enter. The server terminal will display the received payload.

## Notes

- Use Ctrl + C to stop the server.
- The program uses the UDP protocol, so messages are sent as datagrams rather than streams.

## Credits and Acknowledgments

* **Original Source Code**: [nikhilroxtomar/UDP-Client-Server-Program-in-C](https://github.com/nikhilroxtomar/UDP-Client-Server-Program-in-C/blob/master/udpServer.c)
* **Inspiration**: Built as a hands-on learning exercise while following along with the course "[Fundamentals of Network Engineering](https://www.udemy.com/course/fundamentals-of-networking-for-effective-backend-design)" by Hussein Nasser.
