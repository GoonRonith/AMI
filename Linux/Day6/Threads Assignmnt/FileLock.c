#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;  // Start at the beginning
    lock.l_len = 3;  // Lock first 3 bytes

    printf("\nChecking if file is already locked...\n");

    // First, check if the file is locked
    struct flock test_lock = lock;
    if (fcntl(fd, F_GETLK, &test_lock) == -1) {
        perror("Error checking lock");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (test_lock.l_type != F_UNLCK) {
        
        printf("File is already locked by process %d\n", test_lock.l_pid);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("\nFile is not locked.. press any key to lock");
    getchar();

    // Apply the lock
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error locking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File locked by process %d. Press Enter to unlock.\n", getpid());
    getchar();  // Wait for user input

    // Unlock file
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error unlocking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File unlocked.\n");
    close(fd);
    return 0;
}
