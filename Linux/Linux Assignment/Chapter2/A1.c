#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


void *even_factorial(void *arg) {
    printf("\nEven Numbers Factorial:\n");
    for (int i = 2; i <= 30; i += 2) {
        printf("Even Factorial of %d = %llu\n", i, factorial(i));
    }
}

void *odd_factorial(void *arg) {
    printf("\nOdd Numbers Factorial:\n");
    for (int i = 1; i <= 30; i += 2) {
        printf("Odd  Factorial of %d = %llu\n", i, factorial(i));
    }

}

int main(){
    pthread_t evenThread, oddThread;
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    pthread_create(&evenThread, NULL, even_factorial, NULL);
    pthread_create(&oddThread, NULL, odd_factorial, NULL);
    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nTime taken by Threads(Even and Odd): %.6f seconds\n", time_taken);
}