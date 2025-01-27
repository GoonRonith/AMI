#include<stdlib.h>
#include<unistd.h>

int main(){
    char buf[128];
    int fd;
    fd=read(0,buf,128);
    if(fd==-1){
        write(2,"A read error has occurred\n",26);
    }

    if(write(1,buf,fd) != fd){
        write(2,"A write error has occurred\n",27);
    }
    exit(0);
    
}
