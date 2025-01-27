#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    char buffer[20];

  
    fd = open("file.in", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    
    write(fd, "Hello, World!", 13);


    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek error");
        close(fd);
        return 1;
    }


    read(fd, buffer, 13);
    buffer[13] = '\0'; 
    printf("Read from file: %s\n", buffer);

    if (lseek(fd, 7, SEEK_SET) == -1) {
        perror("lseek error");
        close(fd);
        return 1;
    }

   
    read(fd, buffer, 6);
    buffer[6] = '\0';  
    printf("Read after seeking:%s\n", buffer);

    close(fd);
    return 0;
}
