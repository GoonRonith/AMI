#include <stdio.h>

// Macros for bit manipulation
#define READBIT(value, bit) ((value >> bit) & 1)  // Reads a bit from a specific position
#define SETBIT(value, bit) (value | (1 << bit))   // Sets a bit at a specific position
#define RESETBIT(value, bit) (value & ~(1 << bit))// Resets a bit at a specific position

int main() {
    unsigned char InputValue, OutputValue = 0;  // 8-bit variables for Input and Output
    
    // Getting the InputValue from the user
    printf("Enter an 8-bit InputValue (0-255): ");
    scanf("%hhu", &InputValue);
    
    // Read the last 4 bits of InputValue and modify the MSB 4 bits of OutputValue
    for (int i = 0; i < 4; i++) {
        int bit = READBIT(InputValue, i);  // Read the i-th bit of InputValue
        
        if (bit) {
            // If the bit is 1, set the corresponding MSB of OutputValue
            OutputValue = SETBIT(OutputValue, i + 4);  // MSB 4-bits start from position 4 to 7
        } else {
            // If the bit is 0, reset the corresponding MSB of OutputValue
            OutputValue = RESETBIT(OutputValue, i + 4);
        }
    }
    
    // Print the resulting OutputValue
    printf("Modified OutputValue with MSB set/reset from InputValue: %u\n", OutputValue);
    
    return 0;
}
