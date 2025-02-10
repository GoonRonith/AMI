#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include<pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void sendFile(int client_fd, const char *fileName) {
    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        char *errorMsg = "Error: File not found\n";
        send(client_fd, errorMsg, strlen(errorMsg), 0);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Send the file contents in chunks
    // while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
    //     ssize_t bytes_sent = send(client_fd, buffer, bytes_read, 0);
    //     if (bytes_sent == -1) {
    //         perror("Error sending file");
    //         break;
    //     }
    //     memset(buffer, 0, BUFFER_SIZE); 
    // }

    // // Send EOF message to indicate end of file
    // char eof_msg[] = "EOF";
    // send(client_fd, eof_msg, strlen(eof_msg), 0);

    bytes_read=read(fd, buffer, sizeof(buffer));
    send(client_fd, buffer, bytes_read, 0);
    close(fd);
    printf("File [%s] sent successfully!\n", fileName);
}

void* handleClient(void *arg) {
    int client_fd = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);

        if (bytes_received <= 0) {
            printf("Client[%d] disconnected.\n", client_fd);
            break;
        }

        buffer[bytes_received] = '\0';

        if (strcmp(buffer, "bye") == 0) {
            printf("Client[%d] requested to close the connection.\n", client_fd);
            break;
        }

        printf("Client[%d] requested file: %s\n", client_fd, buffer);
        sendFile(client_fd, buffer);
    }

    close(client_fd);
    return NULL;
}

int main() {
    int server_fd, *client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("Listening failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_fd = malloc(sizeof(int));
        *client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);

        if (*client_fd < 0) {
            perror("Accept failed");
            free(client_fd);
            continue;
        }

        printf("Client[%d] connected.\n", *client_fd);

        if (pthread_create(&thread_id, NULL, handleClient, client_fd) != 0) {
            perror("Thread creation failed");
            close(*client_fd);
            free(client_fd);
        } else {
            pthread_detach(thread_id);
        }
    }

    close(server_fd);
    return 0;
}
