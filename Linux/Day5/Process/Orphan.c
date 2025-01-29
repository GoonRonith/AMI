#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        sleep(15); 
        printf("Child process (PID: %d) is now orphaned and adopted by init (PPID: %d)\n", getpid(), getppid());
    } else {
         // Parent process
        sleep(6);
        printf("Parent process (PID: %d) is terminating...\n", getpid());
        exit(0);
    }

    return 0;
}
