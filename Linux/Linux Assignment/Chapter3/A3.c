#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigterm(int sig) {
    printf("\nReceived SIGTERM (signal to terminate the process)\n");
    exit(0);
}

int main() {
    sigset_t set, oldset;

   
    sigemptyset(&set);
    sigaddset(&set, SIGINT); 
    sigaddset(&set, SIGQUIT); 

    
    if (sigprocmask(SIG_BLOCK, &set, &oldset) == -1) {
        perror("sigprocmask");
        exit(1);
    }

  
    signal(SIGTERM, handle_sigterm);

    printf("SIGINT and SIGQUIT are blocked. Try sending SIGTERM...\n");

    
    while (1) {
        printf("Program running... Press Ctrl+C or Ctrl+\\ won't interrupt it.\n");
        sleep(3);
    }

    return 0;
}
