#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"  // Server IP (localhost)
#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Connected to server. Type messages below:\n");
    printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline

        // if (strlen(buffer) == 0) 

        // Send message to server
        send(sock, buffer, strlen(buffer), 0);

        // Receive and print response from server
        int bytes_received = read(sock, buffer, BUFFER_SIZE - 1);
        if (bytes_received <= 0) {
            printf("Server closed connection\n");
            return 0;
        }
        buffer[bytes_received] = '\0';
        printf("Server: %s\n", buffer);
        close(sock);
    return 0;
}