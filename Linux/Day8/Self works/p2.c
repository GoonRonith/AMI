#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
int local=10;
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
    printf("\n local in child=%d",local);
    local++;
    sleep(2);
    write(fd[1],"Ronith Goon",12);
}
else if(p1>0){
    //parent process
    printf("\n local in parent=%d",local);
    local++;
    wait(NULL);
    read(fd[0],buf,12);
    printf("\n data sent by child process is %s\n",buf);

}
else{
    printf("\nError creating child process");
    exit(1);
}
    printf("\n local=%d\n",local);
}
/*
key points:
1) Variable local is Duplicated (Not Shared)
The variable local is initialized to 10 in the parent before fork().
When fork() is called, the child process gets a separate copy of local, not a shared memory.
Any changes made to local in one process do not affect the other.
Parent prints local in parent = 10 and then increments local to 11.
Child prints local in child = 10 and then increments local to 11.

2)
Parent and Child Print Their Own local Values
The final printf("\n local=%d\n",local); runs in both parent and child, showing their respective local values.
Expected output for local at the end:
Parent: local=11
Child: local=11
*/

