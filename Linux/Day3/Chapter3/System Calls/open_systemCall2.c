#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char block[1024]; 
    int in, out; 
    int nread;

    in = open("file.in", O_RDONLY);
    if (in == -1) {
        perror("Error opening file.in");
        exit(1);
    }

    out = open("file.out", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (out == -1) {
        perror("Error opening file.out");
        close(in);
        exit(1);
    }

    while ((nread = read(in, block, sizeof(block))) > 0) {
        if (write(out, block, nread) == -1) {
            perror("Error writing to file.out");
            close(in);
            close(out);
            exit(1);
        }
    }

    if (nread == -1) {
        perror("Error reading from file.in");
    }

    close(in);
    close(out);
    return 0;
}
