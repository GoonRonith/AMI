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
}
else if(p1>0){
    //parent process
    wait(NULL);
    read(fd[0],buf,12);
    printf("\n data sent by child process is %s\n",buf);

}
else{
    printf("\nError creating child process");
    exit(1);
}
}

/*
Key points:
1)
in child process if we wait for 2secs and in that time parent trying to execute(assume we are not using wait(null) 
inside the parent)then The read system call in the parent process will block until data is available in the pipe. 
Similarly, the child process will wait for a chance to write to the pipe.

2)if we are using wait(null) system call in parent process the it works fine as  
Parent process waits until child process is not terminated

*/