
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

// Define the STAGE macro
#define STAGE 1  // Change to 2 for Circle

// Conditional compilation for AREA macro based on STAGE
#if STAGE == 1
    #define AREA(side) (side * side)  // Area of square
#elif STAGE == 2
    #define AREA(radius) (3.14159 * radius * radius)  // Area of circle
#else
    #error "Invalid STAGE value. It should be either 1 or 2."
#endif

// Declare extern variables for radius and side
extern int side;
extern float radius;

#endif
