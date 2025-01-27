#include <stdio.h>
#include <unistd.h>

int main() {
    void *prev_brk, *new_brk;

    prev_brk = sbrk(0); 
    printf("Initial break: %p\n", prev_brk);

    sbrk(1024); 

    new_brk = sbrk(0); 
    printf("New break after sbrk(1024): %p\n", new_brk);

    return 0;
}
