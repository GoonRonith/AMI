#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>

static int glob = 0; 
static void *threadFunc1(void *arg)
{
    int sval;
    sem_t * sem;   
    sem=sem_open("/sem1",O_RDWR|O_CREAT,0777,1);
     if (sem == SEM_FAILED){
        perror("sem_open fail;");
        return NULL;
    }else{
        printf("\n sem_open success\n");
    }
    sem_wait(sem);
    printf("\nthread1 is executing critical section\n");
    sem_getvalue(sem , &sval );
    printf("\n(Into the cs of thread1)current semaphore value=%d",sval);
    int loc, j;
    int loop = 10000;
    for (j = 0; j < loop; j++) {
        loc = glob;
        loc++;
        glob = loc;
        }
    sem_post(sem);
    sem_getvalue(sem , &sval );
    printf("\ncurrent semaphore value after executing thread1=%d",sval);
    return NULL;
}
 
static void *threadFunc2(void *arg)
{
    int sval;
    sem_t * sem;   
    sem=sem_open("/sem1",O_RDWR|O_CREAT,0777,1);
     if (sem == SEM_FAILED){
        perror("sem_open fail;");
        return NULL;
    }else{
        printf("\n sem_open success\n");
    }
    sem_wait(sem);
    printf("\nthread2 is executing critical section\n");
    sem_getvalue(sem , &sval );
    printf("\n(Into the cs of thread2) current semaphore value=%d",sval);
    int loc, j;
    int loop = 10000;
    for (j = 0; j < loop; j++) {
        loc = glob;
        loc++;
        glob = loc;
        }
    sem_post(sem);
    sem_getvalue(sem , &sval );
    printf("\ncurrent semaphore value after executing thread2=%d",sval);
    return NULL;
}
 
 
int main(int argc, char *argv[])
{

    pthread_t t1, t2;
    int loops, s;
    s = pthread_create(&t1, NULL, threadFunc1, NULL);
    if (s != 0)
        perror("pthread_create");
    s = pthread_create(&t2, NULL, threadFunc2, NULL);
    if (s != 0)
        perror("pthread_create");
    s = pthread_join(t1, NULL);
    if (s != 0)
        perror("pthread_join");
    s = pthread_join(t2, NULL);
    if (s != 0)
        perror("pthread_join");
    printf("\nglob = %d\n", glob);
    exit(0);
}