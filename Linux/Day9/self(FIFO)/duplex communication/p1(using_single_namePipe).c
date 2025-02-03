#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd;
    char *pipeName = "myFifo3";
    char msg1[100];
    char msg2[100];
    mkfifo(pipeName, 0777);
    printf("\nUser1");
    while (1)
    {
        fd=open(pipeName,O_WRONLY);
        printf("\nEnter msg to send user2:");
        fgets(msg1,100,stdin);
        write(fd,msg1,100);
        close(fd);
        fd=open(pipeName,O_RDONLY);
        read(fd,msg2,100);
        printf("\nUser2:%s",msg2);
        close(fd);
    }
    

}