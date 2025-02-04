#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;
    int fd[2];
    char buf[50];

    if (pipe(fd) == -1) {
        perror("pipe"); 
        exit(1); 
    }

    p1 = fork();
    if (p1 == -1) {
        perror("fork1");
        exit(1);
    }

    if (p1 == 0) {
        // Child process 1
        close(fd[0]);  // Close unused read end
        sleep(2);
        write(fd[1], "Ronith Goon\n", 12);
        close(fd[1]);  // Close write end after writing
        exit(0);
    }

    p2 = fork();
    if (p2 == -1) {
        perror("fork2");
        exit(1);
    }

    if (p2 == 0) {
        // Child process 2
        close(fd[0]);  // Close unused read end
        sleep(2);
        write(fd[1], "Hello World\n", 12);
        close(fd[1]);  // Close write end after writing
        exit(0);
    }

    // Parent process
    close(fd[1]);  // Close write end, only reading now

    // Read from pipe
    printf("Parent reading from pipe:\n");
    while (read(fd[0], buf, sizeof(buf) - 1) > 0) {
        buf[sizeof(buf) - 1] = '\0';  // Null-terminate the string
        printf("%s", buf);
    }

    close(fd[0]);  // Close read end

    // Wait for both child processes to finish
    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    return 0;
}
