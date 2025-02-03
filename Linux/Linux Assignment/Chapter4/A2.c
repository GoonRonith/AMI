#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        pid_t pid2 = fork();
        if (pid2 == -1) {
            perror("fork failed");
            exit(1);
        } else if (pid2 > 0) {
            exit(0); 
        }

        sleep(1);
        printf("Orphaned child (PID: %d) (PPID:%d) exiting...\n", getpid(),getppid());
        exit(0);
    } else {
        
        printf("Parent process (PID: %d) running...\n", getpid());
        sleep(3);
        exit(0);
    }

    return 0;
}
