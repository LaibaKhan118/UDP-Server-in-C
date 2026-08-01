#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    int port = 5501;
    SOCKET socket_fd;
    struct sockaddr_in myaddr, remoteAddr;
    char buffer[1024];
    int addr_size;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (socket_fd == INVALID_SOCKET) {
        printf("Socket creation failed. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    memset(&myaddr, '\0', sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(port);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socket_fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == SOCKET_ERROR){
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(socket_fd);
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    addr_size = sizeof(remoteAddr);

    memset(buffer, '\0', sizeof(buffer));
    int bytes_received = recvfrom(socket_fd, buffer, 1023, 0, (struct sockaddr *)&remoteAddr, &addr_size);
    if(bytes_received == SOCKET_ERROR) {
        buffer[bytes_received] = '\0';
        printf("Got data from %s:", buffer);
    } else {
        printf("REcvfrom failed. Error Code: %d\n", WSAGetLastError());
    }

    closesocket(socket_fd);
    WSACleanup();
    return 0;
}