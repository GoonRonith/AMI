#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pattern>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipe_fd1[2], pipe_fd2[2];

    
    if (pipe(pipe_fd1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

   
    if (pipe(pipe_fd2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {  
        /
        close(pipe_fd1[0]);
        close(pipe_fd2[0]);
        close(pipe_fd2[1]);

        
        dup2(pipe_fd1[1], STDOUT_FILENO);
        close(pipe_fd1[1]);

        // Execute "ls -l"
        char *args1[] = {"ls", "-l", NULL};
        if (execvp(args1[0], args1) == -1) {
            perror("execvp (ls)");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork2");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {  
       
        close(pipe_fd1[1]);
        close(pipe_fd2[0]);

       
        dup2(pipe_fd1[0], STDIN_FILENO);
        dup2(pipe_fd2[1], STDOUT_FILENO);
        close(pipe_fd1[0]);
        close(pipe_fd2[1]);

        
        char *args2[] = {"grep", argv[1], NULL};
        if (execvp(args2[0], args2) == -1) {
            perror("execvp (grep)");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid3 = fork();
    if (pid3 < 0) {
        perror("fork3");
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0) {  
        
        close(pipe_fd1[0]);
        close(pipe_fd1[1]);
        close(pipe_fd2[1]);

      
        dup2(pipe_fd2[0], STDIN_FILENO);
        close(pipe_fd2[0]);

        
        char *args3[] = {"wc", "-l", NULL};
        if (execvp(args3[0], args3) == -1) {
            perror("execvp (wc)");
            exit(EXIT_FAILURE);
        }
    }

    
    close(pipe_fd1[0]);
    close(pipe_fd1[1]);
    close(pipe_fd2[0]);
    close(pipe_fd2[1]);

    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
