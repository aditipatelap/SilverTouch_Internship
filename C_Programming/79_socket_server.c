#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Binding failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listening failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    socklen_t clientAddrLen = sizeof(clientAddr);
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen)) == -1) {
        perror("Acceptance failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    // Receive data from the client and send it back
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
            perror("Receiving failed");
            break;
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected.\n");
            break;
        }

        printf("Received from client: %s\n", buffer);

        // Send the received data back to the client
        if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
            perror("Sending failed");
            break;
        }
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}