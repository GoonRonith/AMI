#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    while (1) {
        char message[BUFFER_SIZE];
        printf("\nEnter message to server: ");
        fgets(message, BUFFER_SIZE, stdin);

        message[strcspn(message, "\n")] = '\0'; // Remove newline

        send(server_fd, message, strlen(message), 0);

        if (strcmp(message, "bye") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }
        int bytes_received = recv(server_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Server: %s\n", buffer);
        }
        if (strcmp(buffer, "busy") == 0) {
            printf("Rejecting from server...\n");
            break;
        }

       
    }

    close(server_fd);
    return 0;
}
