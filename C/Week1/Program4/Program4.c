#include <stdio.h>

int main() {
    // Declare variables
    int marks[5];    // Array to store marks of five subjects
    int total = 0;   // Variable to store total marks
    float percentage; // Variable to store percentage
    char grade;      // Variable to store grade
    
    // Input marks of five subjects
    printf("Enter marks for 5 subjects (out of 100):\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        
        // Sum the total marks
        total += marks[i];
    }
    
    // Calculate percentage
    percentage = (total / 500.0) * 100;

    // Determine grade based on percentage
    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }
    
    // Display percentage and grade
    printf("\nTotal Marks: %d / 500\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);
    
    return 0;
}
