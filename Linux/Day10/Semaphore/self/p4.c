#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <semaphore.h> 
 
#define MAX_THREAD 3
 
static int glob[2] = {0};
sem_t* sem;
 
void *fn(void *arg)
{
    printf("[START] Thread %s\n", (char *)arg);
 
   sem_wait(sem);
    int instance;
    sem_getvalue(sem, &instance);
    printf("\nThread %s\n and semaphore val=%d", (char *)arg,instance);
    for (int i = 0; i < 10000; i++)
    {
        // extracting the instance number of resourse
        glob[instance]++;
    }
    sem_post(sem);
 
    printf("[EXIT] %s\n", (char *)arg);
}
 
int main()
{
    int rval;
    sem = sem_open("/sem1", O_CREAT | O_RDWR, 0660, 2);
    // sem_init(&sem, 0, 2);
 
    pthread_t th[MAX_THREAD];
 
    rval = pthread_create(&th[0], NULL, fn, "1");
 
    rval = pthread_create(&th[1], NULL, fn, "2");
 
    rval = pthread_create(&th[2], NULL, fn, "3");
 
    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(th[i], NULL);
    }
 
    printf("Value of resourse 1 : %d\n", glob[0]);
    printf("Value of resourse 2 : %d\n", glob[1]);
    printf("Value added : %d\n", glob[0] + glob[1]);
    sem_unlink("/sem1");
    return 0;
}