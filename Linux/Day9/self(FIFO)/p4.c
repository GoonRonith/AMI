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

    fd = open(pipeName, O_RDONLY);
    if (fd == -1) {
        perror("Error opening pipe for reading");
        exit(EXIT_FAILURE);
    }

    char msg[100];

    while (1) {
        printf("\nReceiver waiting...\n");

        ssize_t bytesRead = read(fd, msg, sizeof(msg));
        if (bytesRead <= 0) {
            perror("Error reading from pipe or sender closed connection");
            break;
        }

        printf("Received message: %s", msg);
        if (strncmp(msg, "exit", 4) == 0) {
            printf("Receiver exiting...\n");
            break;
        }
    }

    close(fd);
    return 0;
}
