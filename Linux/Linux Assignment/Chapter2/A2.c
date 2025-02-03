#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>  
#define SIZE 5

int arr[] = {10, 2, 5, 6, 9};
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void* maxElmThread(void *arg) {
    int *max = malloc(sizeof(int)); 
    if (!max) pthread_exit(NULL);   

    *max = arr[0];
    
    pthread_mutex_lock(&mtx);
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
    pthread_mutex_unlock(&mtx);

    pthread_exit(max);
}

static void* sumOfArrayThread(void *arg) {
    int *sum = malloc(sizeof(int)); 
    if (!sum) pthread_exit(NULL);   

    *sum = 0;
    
    pthread_mutex_lock(&mtx);
    for (int i = 0; i < SIZE; i++) {
        *sum += arr[i];
    }
    pthread_mutex_unlock(&mtx);

    pthread_exit(sum);
}

int main() {
    pthread_t t1, t2;
    int s1 = pthread_create(&t1, NULL, maxElmThread, NULL);
    int s2 = pthread_create(&t2, NULL, sumOfArrayThread, NULL);

    if (s1 != 0 || s2 != 0) {
        printf("Failed to create threads.\n");
        return 1;
    }

    void* max;
    void* sum;

    pthread_join(t1, &max);
    pthread_join(t2, &sum);

    if (max && sum) {
        printf("\n%d is the maximum element.", *(int *)max);
        printf("\n%d is the sum.\n", *(int *)sum);
    }

    free(max); 
    free(sum);

    return 0;
}
