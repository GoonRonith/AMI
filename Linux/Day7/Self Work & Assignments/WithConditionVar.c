#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int foodReady = 0;  // Shared variable

pthread_mutex_t lock;
pthread_cond_t cond;

void* chef(void* arg) {
    sleep(2);  // Simulate cooking time
    pthread_mutex_lock(&lock);
    foodReady = 1;
    printf("Chef: Food is ready! Notifying the waiter...\n");
    pthread_cond_signal(&cond);  // Notify waiter
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* waiter(void* arg) {
    pthread_mutex_lock(&lock);
    while (foodReady == 0) {  // Wait for food to be ready
        printf("Waiter: Waiting for the chef to prepare food...\n");
        pthread_cond_wait(&cond, &lock);  // Releases lock and waits
    }
    printf("Waiter: Food is ready! Serving it now.\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t chefThread, waiterThread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&chefThread, NULL, chef, NULL);
    pthread_create(&waiterThread, NULL, waiter, NULL);

    pthread_join(chefThread, NULL);
    pthread_join(waiterThread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    printf("Restaurant closing.\n");
    return 0;
}
