#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd;
    char *filename = "example.txt";

  
    fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    
    char buffer[] = "Advanced File Control System Calls in C.\n";
    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

   
    int fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("Duplicated file descriptor: %d\n", fd_dup);

   
    close(fd);
    close(fd_dup);

    return 0;
}
