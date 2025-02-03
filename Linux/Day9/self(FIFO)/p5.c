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
        mkfifo(pipeName,0777);
        fd=open(pipeName,O_WRONLY);
        if(fd==-1){
            printf("\n opening error");
        }
        // char msg[100];
        char *msg = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\nSender:");
            printf("\nEnter Message to the receiver:");
            fgets(msg,100,stdin);
            write(fd,msg,100);
        }
        
}