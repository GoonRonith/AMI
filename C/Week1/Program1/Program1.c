#include <stdio.h>

int main() {
    int intVar;
    float floatVar;
    
    // Input from the user
    printf("Enter an integer: ");
    scanf("%d", &intVar);
    
    printf("Enter a float: ");
    scanf("%f", &floatVar);
    
    // Displaying the values
    printf("Integer: %d\n", intVar);
    printf("Float: %.2f\n", floatVar);
    
    // Printing the sizes of both variables
    printf("Size of integer: %lu bytes\n", sizeof(intVar));
    printf("Size of float: %lu bytes\n", sizeof(floatVar));
    
    return 0;
}
