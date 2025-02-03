#include <stdio.h>

int main() {
    int *ptr = NULL;  
    printf("Pointer address before dereferencing: %p\n",ptr);
    printf("Value at pointer: %d\n", *ptr);

    return 0;
}
