#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int server_fd,client_fd;
    struct sockaddr_in server_add,client_add;
    socklen_t addr_len;
    char buffer[BUFFER_SIZE];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
     if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    server_add.sin_family=AF_INET;
    server_add.sin_addr.s_addr=INADDR_ANY;
    server_add.sin_port = htons(PORT);
     if (bind(server_fd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

     if (listen(server_fd, 2) < 0) {  // Only 2 client allowed
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    addr_len=sizeof(client_add);
    client_fd = accept(server_fd, (struct sockaddr *)&client_add, &addr_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected!\n");
    int bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            printf("Client disconnected\n");
            return 0;
        }
        buffer[bytes_read] = '\0';
        printf("Client: %s\n", buffer);
        send(client_fd, "Thanks(From Server)", 20, 0);
           close(client_fd);
    close(server_fd);
    return 0;


}