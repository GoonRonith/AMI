#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void handle_sigchld(int sig) {
    int status;
    waitpid(-1, &status, WNOHANG); 
}

int main() {
    pid_t pid;
    signal(SIGCHLD, handle_sigchld);

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(2);  
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0); 
    } else {
        
        printf("Parent process (PID: %d) is waiting for child to finish...\n", getpid());
        while (1) {
            sleep(1);
        }
    }

    return 0;
}
