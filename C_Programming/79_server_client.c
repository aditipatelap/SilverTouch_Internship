#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Connection failed");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server at %s:%d\n", SERVER_IP, PORT);

    // Send and receive data from the server
    while (1) {
        printf("Enter a message (type 'exit' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Send the message to the server
        if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
            perror("Sending failed");
            break;
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Disconnected from the server.\n");
            break;
        }

        // Receive the echo from the server
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
            perror("Receiving failed");
            break;
        }

        printf("Received from server: %s\n", buffer);
    }

    // Close the socket
    close(clientSocket);

    return 0;
}