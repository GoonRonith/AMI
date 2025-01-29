#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    pid_t q;
    printf("\nbefore fork");
    fflush(stdout); 
    q = fork();
    
    if (q < 0) {
        printf("\nError creating child process");
    } 
    else if (q == 0) {
        printf("\nI am child process and my PID: %d", getpid());
        printf("\nI am child process and my parent's PID: %d", getppid());
    } 
    else {
        sleep(3);
        printf("\nI am parent process and my PID: %d", getpid());
        printf("\nI am parent process and my child's PID: %d", q);
    }
    
    return 0;
}
