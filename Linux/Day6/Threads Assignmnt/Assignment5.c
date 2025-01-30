#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *threadFunc(void *arg) {
    while (1) {
        printf("Thread is running...\n");
        sleep(1); 
    }
    return NULL;
}

int main() {
    pthread_t thread;

   
    pthread_create(&thread, NULL, threadFunc, NULL);
    
    sleep(3); 
    
   
    printf("Requesting thread cancellation...\n");
    pthread_cancel(thread);
    
    
    pthread_join(thread, NULL);
    
    printf("Thread successfully canceled.\n");
    return 0;
}
