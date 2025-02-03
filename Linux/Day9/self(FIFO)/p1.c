#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char *pipeName = "myFifo1";

    mkfifo(pipeName, 0777);
    int fd = open(pipeName, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }
    printf("\nSender:\n");
    // char msg[] = "ronith";
    char *msg="ronith";
    write(fd, msg, strlen(msg) + 1);
    close(fd);

    return 0;
}
