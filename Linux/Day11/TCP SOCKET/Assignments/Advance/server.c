#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdint.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENT 10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int current_clients=0;

struct Client{
    int client_fd;
    char client_name[BUFFER_SIZE];
};
struct Client clients[MAX_CLIENT];

int getClientFdByClientName(char *targetClientName){
    for(int i=0;i<MAX_CLIENT;i++){
        if(strcmp(clients[i].client_name,targetClientName)==0){
            return clients[i].client_fd;
        }
    }
    return -1;
}



void* handleClient(void *arg) {
    
    struct Client *client = (struct Client*)arg;
    printf("\nhandling client[%d]",client->client_fd);
    char buffer[BUFFER_SIZE];
    char other_client_name[BUFFER_SIZE];

    int bytes_received=recv(client->client_fd, client->client_name, BUFFER_SIZE, 0);
    client->client_name[bytes_received] = '\0';
 

 
   
    while (1) {
        bytes_received=recv(client->client_fd, other_client_name, BUFFER_SIZE, 0);
        other_client_name[bytes_received] = '\0';
        int other_client_fd=getClientFdByClientName(other_client_name);
        if(other_client_fd<0){
            printf("\n Client not found");
            continue;
        }
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client->client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client[%d] disconnected.\n", other_client_fd);
            break;
        }
        
        buffer[bytes_received] = '\0'; // Ensure null-terminated string

        if (strcmp(buffer, "bye") == 0) {
            printf("Client[%d] requested to close the connection.\n", other_client_fd);
            break;
        }

    char formatted_message[BUFFER_SIZE];

    // Calculate max message length allowed in buffer
    int max_msg_len = BUFFER_SIZE - strlen(client->client_name) - 3; // 3 for ": " and '\0'

    if (max_msg_len > 0) {
        buffer[max_msg_len] = '\0'; // Truncate buffer to fit within limits
    }

            // Use snprintf safely
        snprintf(formatted_message, BUFFER_SIZE, "%s: %.*s", client->client_name, max_msg_len, buffer);     
        send(other_client_fd, formatted_message, strlen(formatted_message), 0);
    }

    close(client->client_fd);
    return NULL;
}

int main() {
   int server_fd;
   struct sockaddr_in server_addr,client_addr;
   socklen_t addr_size;
    pthread_t thread_id;
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1){
          perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENT) == -1) {
        perror("Listening failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

     printf("Server listening on port %d...\n", PORT);

     while (1)
     {
        addr_size = sizeof(client_addr);
        clients[current_clients].client_fd=accept(server_fd,(struct sockaddr*)&client_addr,&addr_size);
        if (clients[current_clients].client_fd < 0) {
            perror("Accept failed");
            continue; 
        }
        
        pthread_mutex_lock(&lock);
        if (current_clients < MAX_CLIENT) {
            current_clients++;
        } else {
            printf("Server full. Rejecting client %d\n", clients[current_clients].client_fd);
            close(clients[current_clients].client_fd);
            pthread_mutex_unlock(&lock);
            continue;
        }
        pthread_mutex_unlock(&lock);
        printf("\nnew client:%d",clients[current_clients-1].client_fd);
        printf("\nno  of client:%d",current_clients);
        printf("\nClient[%d] connected.\n", clients[current_clients-1].client_fd);
        if(pthread_create(&thread_id,NULL,handleClient,(void *)&clients[current_clients-1])!=0){
            perror("Thread creation failed");
            close(clients[current_clients].client_fd);
        }
        else{
            pthread_detach(thread_id);
        }
     }
     close(server_fd);
    return 0;
}
