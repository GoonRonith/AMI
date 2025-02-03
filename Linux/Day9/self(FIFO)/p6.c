#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main(){
    int fd;
    char *pipeName="myfifo2";
    fd=open(pipeName,O_RDONLY);
    // char msg[100];
    char *msg = (char *)malloc(100 * sizeof(char));
    if(fd==-1){
            printf("\n opening error");
    }
    while (1)
    {
        printf("\nReceiver Waiting:");
        read(fd,msg,100);
        printf("\nReceived msg:%s\n",msg);
    }
    
}