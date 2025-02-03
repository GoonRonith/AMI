#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork(); 

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {  
        printf("Child (PID: %d)(PPID: %d) is exiting quickly to become a zombie...\n", getpid(),getppid());
        exit(0); 
    } 
    else { 
        
        printf("Parent (PID: %d) created child (PID: %d) and is going to sleep...\n", getpid(), child_pid);
        sleep(3);  
        char cmd[50];
        
        snprintf(cmd, sizeof(cmd), "ps -o pid,ppid,state -p %d", child_pid);
        printf("Checking child process status (should be ZOMBIE):\n");
        system(cmd);

        printf("Parent is now exiting, making the zombie an orphan...\n");
        exit(0);

    }
}
