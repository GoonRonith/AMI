#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

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
        char fileName[BUFFER_SIZE];
        printf("\nEnter file name to request (or 'bye' to exit): ");
        fgets(fileName, BUFFER_SIZE, stdin);
        fileName[strcspn(fileName, "\n")] = '\0'; // Remove newline
        send(server_fd, fileName, strlen(fileName), 0);

        if (strcmp(fileName, "bye") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }

        int fd = open("received_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd == -1) {
            perror("Error opening file to save");
            break;
        }

        ssize_t bytes_received;
        // while ((bytes_received = recv(server_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        //     // If EOF is received, break the loop
        //     printf("\n%s",buffer);
        //     if (strcmp(buffer, "EOF") == 0) {
        //         printf("File transfer complete.\n");
        //         break;
        //     }
        //     write(fd, buffer, bytes_received);
        //     memset(buffer, 0, BUFFER_SIZE); 
        // }
        bytes_received=recv(server_fd, response, BUFFER_SIZE, 0);
        printf("File transfer complete.\n");
        write(fd, response, bytes_received);
        close(fd);
        printf("File received and saved as 'received_file.txt'.\n");
    }

    close(server_fd);
    return 0;
}



