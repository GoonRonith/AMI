
#include "main.h"

void display_area() {
    // Display the area based on the STAGE macro
#if STAGE == 1
    printf("The area of the square is: %d\n", AREA(side));
#elif STAGE == 2
    printf("The area of the circle is: %.2f\n", AREA(radius));
#endif
}
