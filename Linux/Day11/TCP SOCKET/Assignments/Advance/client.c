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
    char buffer[BUFFER_SIZE];
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

    printf("Connected to server.\n");
    char name[BUFFER_SIZE];
    char other_client_name[BUFFER_SIZE];

    if (pthread_create(&recv_thread, NULL, receiveMsg, NULL) != 0) {
        perror("Receive thread creation failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("\nEnter Your name ");
    fgets(name, BUFFER_SIZE, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline
    send(server_fd, name, strlen(name), 0);



    while (1) {
        printf("\nEnter the name of the client to whom you want to send the message:");
        fgets(other_client_name, BUFFER_SIZE, stdin);
        other_client_name[strcspn(other_client_name, "\n")] = '\0'; // Remove newline
        send(server_fd, other_client_name, strlen(other_client_name), 0);
        char message[BUFFER_SIZE];
        fgets(message, BUFFER_SIZE, stdin);

        message[strcspn(message, "\n")] = '\0'; // Remove newline

        send(server_fd, message, strlen(message), 0);

        if (strcmp(message, "bye") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }

        // int bytes_received = recv(server_fd, buffer, BUFFER_SIZE, 0);
        // if (bytes_received > 0) {
        //     buffer[bytes_received] = '\0';
        //     printf("Server: %s\n", buffer);
        // }
    }

    close(server_fd);
    return 0;
}
