#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};  // Command to execute `ls -l`
    
    printf("Before execv\n");

    if (execv(args[0], args) == -1) {
        perror("execv failed");
    }

    printf("This will not be printed if execv is successful\n");

    return 0;
}
