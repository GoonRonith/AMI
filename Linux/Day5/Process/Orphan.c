#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is terminating...\n", getpid());
        exit(0);
    } else {
        // Child process
        sleep(5); // Sleep to ensure the parent exits before the child
        printf("Child process (PID: %d) is now orphaned and adopted by init (PPID: %d)\n", getpid(), getppid());
    }

    return 0;
}
