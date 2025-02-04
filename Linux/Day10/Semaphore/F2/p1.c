#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

static int glob = 0;
sem_t sem;

static void* threadFunc(void *arg) {
    int loc, j, ret;
    int loops = 10;
    
    // Wait on the semaphore (block until it's available)
    ret = sem_wait(&sem);
    if (ret != 0) {
        perror("semaphore wait error");
    }

    // Critical section: increment global variable
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }

    // Release the semaphore (allow other threads to proceed)
    ret = sem_post(&sem);
    if (ret != 0) {
        perror("semaphore post error");
    }

    printf("\nThread func exiting");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int ret;

    // Initialize the semaphore, initially set to 1 (binary semaphore)
    ret = sem_init(&sem, 0, 1);
    if (ret != 0) {
        perror("semaphore initialization error");
        exit(EXIT_FAILURE);
    }

    // Create two threads
    ret = pthread_create(&t1, NULL, threadFunc, NULL);
    if (ret != 0) {
        perror("thread creation error");
        exit(EXIT_FAILURE);
    }

    ret = pthread_create(&t2, NULL, threadFunc, NULL);
    if (ret != 0) {
        perror("thread creation error");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Cleanup semaphore
    sem_destroy(&sem);

    // Print final value of glob
    printf("\nFinal value of glob: %d\n", glob);

    return 0;
}
