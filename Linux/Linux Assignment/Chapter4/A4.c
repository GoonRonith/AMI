#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for child 1");
        exit(1);
    } else if (pid1 == 0) {
        // Child 1
        printf("Child 1 (PID: %d) created by Parent (PID: %d)\n", getpid(), getppid());
        exit(0);
    }

  
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for child 2");
        exit(1);
    } else if (pid2 == 0) {
        // Child 2
        printf("Child 2 (PID: %d) created by Parent (PID: %d)\n", getpid(), getppid());
        exit(0);
    }

 
    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed for child 3");
        exit(1);
    } else if (pid3 == 0) {
        
        printf("Child 3 (PID: %d) created by Parent (PID: %d)\n", getpid(), getppid());
        exit(0);
    }
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("Parent (PID: %d) exiting after all children\n", getpid());
    return 0;
}
