#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int main() {
    char *pipeName = "myFifo1";
    int fd = open(pipeName, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }
    // char msg[100];
    char *msg = (char *)malloc(100 * sizeof(char));
    int bytesRead = read(fd, msg, sizeof(msg) - 1);
    if (bytesRead > 0) {
        msg[bytesRead] = '\0';  
        printf("\nReceiver:\n");
        printf("\nReceived msg is -> %s\n", msg);
    } else {
        printf("\nNo message received.\n");
    }
    close(fd);
    return 0;
}
