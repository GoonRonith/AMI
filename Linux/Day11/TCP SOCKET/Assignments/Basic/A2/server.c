#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>


#define PORT 8080
#define BUFFERSIZE 1024

int main(){
    int server_fd,client_fd;
    struct sockaddr_in server_addr,client_addr;
    socklen_t addr_size;
    char buffer[BUFFERSIZE];

    //creating socket
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    if(server_fd==-1){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    // Configure server address
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(PORT);
    
    //bind socket
    if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    //listen for connection
    if(listen(server_fd,5)<0){
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);
    
        addr_size=sizeof(client_addr);
        client_fd=accept(server_fd,(struct sockaddr*)&client_addr,&addr_size);
        if (client_fd < 0) {
            perror("Accept failed");
        }
        printf("Client[%d] connected.\n",client_fd);
        while (1)
    {
        memset(buffer, 0, BUFFERSIZE);  // Clear buffer
        recv(client_fd,buffer,BUFFERSIZE,0);

        if (strcmp(buffer, "bye") == 0) {
            printf("Client requested to close the connection.\n");
            break;
        }
        printf("Client: %s\n", buffer);

        char response[] = "Hello, Client!";
        send(client_fd, response, strlen(response), 0);
 
    }
    close(client_fd);
    printf("Client disconnected.\n");
    close(server_fd);
    return 0;
}