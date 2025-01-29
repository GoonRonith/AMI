#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function for even numbers factorial calculation
void *even_factorial(void *arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("\nEven Numbers Factorial:\n");
    for (int i = 2; i <= 30; i += 2) {
        printf("Factorial of %d = %llu\n", i, factorial(i));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken by Even Thread: %.6f seconds\n", time_taken);
    return NULL;
}

// Function for odd numbers factorial calculation
void *odd_factorial(void *arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("\nOdd Numbers Factorial:\n");
    for (int i = 1; i <= 30; i += 2) {
        printf("Factorial of %d = %llu\n", i, factorial(i));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken by Odd Thread: %.6f seconds\n", time_taken);
    return NULL;
}

int main() {
    pthread_t evenThread, oddThread;
    struct timespec start, end;

    // Start measuring execution time for main thread (excluding other threads)
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Creating even and odd number threads
    pthread_create(&evenThread, NULL, even_factorial, NULL);
    pthread_create(&oddThread, NULL, odd_factorial, NULL);

    // Ensuring both threads finish before running main thread calculations
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    // Now executing the main thread calculations
    printf("\nMain Thread - All Numbers Factorial:\n");
    for (int i = 1; i <= 30; i++) {
        printf("Factorial of %d = %llu\n", i, factorial(i));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time taken by Main Thread: %.6f seconds\n", time_taken);

    return 0;
}
