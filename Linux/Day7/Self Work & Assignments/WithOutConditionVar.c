#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int foodReady = 0;  // Shared variable
pthread_mutex_t lock;

void* chef(void* arg) {
    sleep(2);  // Simulate cooking time
    pthread_mutex_lock(&lock);
    foodReady = 1;
    printf("Chef: Food is ready!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* waiter(void* arg) {
    while (1) {  // Busy waiting
        pthread_mutex_lock(&lock);
        printf("Waiter: Waiting for the chef to prepare food...\n");
        if (foodReady == 1) {
            printf("Waiter: Serving the food.\n");
            pthread_mutex_unlock(&lock);
            break;
        }
        
        pthread_mutex_unlock(&lock);
        sleep(1);  // Avoid excessive CPU usage
    }
    return NULL;
}

int main() {
    pthread_t chefThread, waiterThread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&chefThread, NULL, chef, NULL);
    pthread_create(&waiterThread, NULL, waiter, NULL);

    pthread_join(chefThread, NULL);
    pthread_join(waiterThread, NULL);

    pthread_mutex_destroy(&lock);
    printf("Restaurant closing.\n");
    return 0;
}
