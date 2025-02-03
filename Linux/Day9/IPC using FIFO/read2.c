// Process B: Reads first, then writes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    char write_msg[80], read_msg[80];

    // Create FIFO if it doesn't exist
    mkfifo(FIFO_PATH, 0660);

    while (1) {
        // Open FIFO for reading
        fd = open(FIFO_PATH, O_RDONLY);
        read(fd, read_msg, 80);
        printf("\nProcess A: %s\n", read_msg);
        close(fd);

        // Open FIFO for writing
        fd = open(FIFO_PATH, O_WRONLY);
        printf("\nProcess B: Enter message: ");
        fgets(write_msg, 80, stdin);
        write(fd, write_msg, strlen(write_msg) + 1);
        close(fd);
    }
    return 0;
}