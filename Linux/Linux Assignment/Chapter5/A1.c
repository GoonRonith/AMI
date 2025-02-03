#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t p1,p2;
    int fd[2];
    char buf[50];
if(pipe(fd)==-1){
        perror("pipe"); 
        exit(1); 
}
p1=fork();
if(p1==0){
    //child process 1
    sleep(2);
    write(fd[1],"Ronith Goon",12);
}

p2=fork();
if(p2==0){
    //child process 2
    sleep(2);
    write(fd[1],"Ronith Goon",12);
}






}