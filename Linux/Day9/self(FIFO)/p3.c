#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    char *pipeName = "myfifo2";

    if (mkfifo(pipeName, 0777) == -1) {
        perror("mkfifo error");
    }

    fd = open(pipeName, O_WRONLY);
    if (fd == -1) {
        perror("Error opening pipe for writing");
        exit(EXIT_FAILURE);
    }

    char msg[100];

    while (1) {
        printf("\nSender: Enter message to the receiver: ");
        fgets(msg, 100, stdin);

        if (strncmp(msg, "exit", 4) == 0) {
            printf("Sender exiting...\n");
            break;
        }

        if (write(fd, msg, strlen(msg) + 1) == -1) {
            perror("Error writing to pipe");
            break;
        }
    }

    close(fd);
    return 0;
}
