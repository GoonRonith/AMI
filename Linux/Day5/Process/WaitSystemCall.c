#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
    pid_t q;
    printf("\nbefore fork");
    fflush(stdout); 
    
    q = fork();
    
    if (q < 0) {
        printf("\nError creating child process");
    } 
    else if (q == 0) {
        //sleep(3) //It means child process waits for 3 seconds
        printf("\nI am child process and my PID: %d", getpid());
        printf("\nI am child process and my parent's PID: %d", getppid());
    } 
    else {
        wait(NULL); //It means Parent process waits until child process is not terminated
        printf("\nI am parent process and my PID: %d", getpid());
        printf("\nI am parent process and my child's PID: %d", q);
    }
    
    return 0;
}