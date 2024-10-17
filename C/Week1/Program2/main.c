
#include "main.h"

// Conditional compilation for defining variables
#if STAGE == 1
    int side = 5;  // Global variable for square side
#elif STAGE == 2
    float radius = 3.5;  // Global variable for circle radius
#endif

int main() {
    // Function to display the area
    extern void display_area();
    display_area();
    
    return 0;
}
