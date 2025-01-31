#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){

pid_t p1;
int fd[2];
char buf[50];
if(pipe(fd)==-1){
        perror("pipe"); 
        exit(1); 
}
p1=fork();
if(p1==0){
    //child process
    sleep(2);
    write(fd[1],"Ronith Goon",12);
    close(fd[0]);
}
else if(p1>0){
    //parent process
    wait(NULL);
    int ret=read(fd[0],buf,12);
    printf("\n read() returns %d",ret);
    printf("\n data sent by child process is %s\n",buf);

}
else{
    printf("\nError creating child process");
    exit(1);
}
}

