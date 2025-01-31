#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include<errno.h>
int main() 
{ 
    int fd[2];  
    char buff[50]; 
    char data[50] = {};
 
    //Open a pipe
    if (pipe(fd) == -1)  
    { 
        perror("pipe"); // error in pipe 
        exit(1); // exit from the program 
    } 
    // fd[0] contains descriptor to read end of pipe, fd[1] contains descriptor to write end of pipe 
    sprintf(buff,"PIPE data flow demo:");
    // writing to pipe 
    int ret=write(fd[0], buff, strlen(buff));  
    if(ret <0){
        printf("\n write error (error no->%d) : %s\n",errno,strerror(errno));
    }
    printf("\n"); 
    // reading pipe , and storing data in data buffer
    read(fd[1], data, 5); 
    printf("%s\n", data);  
 
    read(fd[1], data, 5); 
    printf("%s\n", data);  
 
    read(fd[1], data, 10); 
    printf("%s\n", data);  
 
} 