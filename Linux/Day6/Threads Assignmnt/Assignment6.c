#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

void factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    printf("\nfactorial of %d is %d",n,fact);
}

int main(){
    struct timespec start,end;
    int i;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=1;i<=30;i++){
        factorial(i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\nTime taken by Main(Serial Process): %.6f seconds\n", time_taken);
}