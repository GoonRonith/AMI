#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int server_fd;

void* receiveMsg(void* arg) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(server_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("\n%s\n", buffer);
        fflush(stdout);
    }

    printf("\nServer disconnected.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    pthread_t recv_thread;

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

    printf("Connected to server. Type 'bye' to exit.\n");

    if (pthread_create(&recv_thread, NULL, receiveMsg, NULL) != 0) {
        perror("Receive thread creation failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("\nYou: ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0';

        if (strcmp(message, "bye") == 0) {
            printf("Disconnecting from server...\n");
            close(server_fd);
            exit(EXIT_SUCCESS);
        }

        send(server_fd, message, strlen(message), 0);
    }

    return 0;
}
