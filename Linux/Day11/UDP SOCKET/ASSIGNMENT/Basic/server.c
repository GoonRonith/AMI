#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", PORT);

    while (1) {
        // Receive message from client
        ssize_t recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, 
                                    (struct sockaddr *)&client_addr, &addr_len);
        if (recv_len < 0) {
            perror("Receive failed");
            continue;
        }
        buffer[recv_len] = '\0'; // Null terminate the received message

        // Get client details
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        int client_port = ntohs(client_addr.sin_port);

        printf("Received from [%s:%d]: %s\n", client_ip, client_port, buffer);

        // Respond to client
        const char *response = "Hello, Client!";
        sendto(sockfd, response, strlen(response), 0, 
               (struct sockaddr *)&client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}
