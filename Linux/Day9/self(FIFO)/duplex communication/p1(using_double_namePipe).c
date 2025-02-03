#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd;
    char *pipe1 = "myFifo4p1";
    char *pipe2 = "myFifo4p2";
    char msg1[100];
    char msg2[100];
    mkfifo(pipe1, 0777);
    mkfifo(pipe2, 0777);
    printf("\nUser1");
    while (1)
    {
        fd=open(pipe1,O_WRONLY);
        printf("\nEnter msg to send user2:");
        fgets(msg1,100,stdin);
        write(fd,msg1,100);
        close(fd);
        fd=open(pipe2,O_RDONLY);
        read(fd,msg2,100);
        printf("\nUser2:%s",msg2);
        close(fd);
    }
    

}