#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdint.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int clients_fd[MAX_CLIENTS];
int client_no = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void broadCastingMsg(int sender_fd, char* msg) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_no; i++) {
        if (clients_fd[i] != sender_fd) {
            send(clients_fd[i], msg, strlen(msg), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

void removeClient(int client_fd) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_no; i++) {
        if (clients_fd[i] == client_fd) {
            for (int j = i; j < client_no - 1; j++) {
                clients_fd[j] = clients_fd[j + 1];
            }
            client_no--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
}

void* handleClient(void *arg) {
    int client_fd = *(int *)arg;
    free(arg);
    char buffer[BUFFER_SIZE];

    printf("Client[%d] connected.\n", client_fd);

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

        printf("Client[%d]: %s\n", client_fd, buffer);

        char response[BUFFER_SIZE];
        snprintf(response, sizeof(response), "Client[%d]: %.900s", client_fd, buffer);

        broadCastingMsg(client_fd, response);
    }

    close(client_fd);
    removeClient(client_fd);
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

    if (listen(server_fd, MAX_CLIENTS) == -1) {
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

        pthread_mutex_lock(&lock);
        if (client_no < MAX_CLIENTS) {
            clients_fd[client_no++] = *client_fd;
        } else {
            printf("Server full. Rejecting client %d\n", *client_fd);
            close(*client_fd);
            free(client_fd);
            pthread_mutex_unlock(&lock);
            continue;
        }
        pthread_mutex_unlock(&lock);

        if (pthread_create(&thread_id, NULL, handleClient, (void *)client_fd) != 0) {
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
