#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int copy_fd = dup(fd); 
    printf("Original FD: %d, Duplicate FD: %d\n", fd, copy_fd);

    int newFD=dup2(fd, 11); 
    printf("\nNew Fd->%d",newFD);
    // printf("\nThis will be written to output.txt\n");

    close(fd);
    close(copy_fd);
    return 0;
}
