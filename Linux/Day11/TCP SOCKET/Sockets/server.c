#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client [%d]: %s\n", sock, buffer);
        send(sock, buffer, bytes_read, 0); // Echo message back
    }

    printf("Client [%d] disconnected\n", sock);
    close(sock);
    free(client_socket);
    return NULL;
}

int main() {
    int server_fd, *client_sock, addr_len;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        client_sock = malloc(sizeof(int));
        *client_sock = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);
        
        if (*client_sock < 0) {
            perror("Accept failed");
            free(client_sock);
            continue;
        }

        printf("New client connected [%d]\n", *client_sock);
        
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client_sock) != 0) {
            perror("Thread creation failed");
            free(client_sock);
        }

        pthread_detach(thread_id); // Detach the thread to free resources after execution
    }

    close(server_fd);
    return 0;
}
