#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdint.h>

#define PORT 8080
#define BUFFER_SIZE 1024
int client_no=0;
void* handleClient(void *arg) {
    int client_fd = (int)(uintptr_t)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        
        if (bytes_received <= 0) {
            printf("Client[%d] disconnected.\n", client_fd);
            break;
        }

        buffer[bytes_received] = '\0'; // Ensure null-terminated string

        if (strcmp(buffer, "bye") == 0) {
            printf("Client[%d] requested to close the connection.\n", client_fd);
            break;
        }

        printf("Client[%d]: %s\n", client_fd, buffer);

        char response[BUFFER_SIZE];
        snprintf(response, sizeof(response), "Hello, Client[%d]!", client_fd);

        send(client_fd, response, strlen(response), 0);
    }
    client_no--;
    close(client_fd);
    return NULL;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t thread_id;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) == -1) {
        perror("Listening failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
        
        if (client_fd < 0) {
            perror("Accept failed");
            continue; // Keep listening for new clients
        }
        client_no++;
        if(client_no>1){
            char serverBusy[]="busy";
            send(client_fd,serverBusy,sizeof(serverBusy),0);
            printf("\nRejecting new client request...");
            close(client_fd);
        }
        if(client_no==1) printf("Client[%d] connected.\n", client_fd);

        if (pthread_create(&thread_id, NULL, handleClient, (void *)(uintptr_t)client_fd) != 0) {
            perror("Thread creation failed");
            close(client_fd);
        } else {
            pthread_detach(thread_id); // Free resources automatically after thread exits
        }
    }

    close(server_fd);
    return 0;
}
