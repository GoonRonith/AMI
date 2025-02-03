#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments...]\n", argv[0]);
        exit(1);
    }
    // printf("\nargc=%d\n",argc);
    // for (int i = 0; argv[i] != NULL; i++) {
    //     printf("\nargv[%d]: %s\n", i, argv[i]);
    // }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        execvp(argv[1], &argv[1]);
        perror("exec failed"); 
        exit(1);
    } else {
        wait(NULL);

    }

    return 0;
}
