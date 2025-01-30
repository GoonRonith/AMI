//This code still works  proper although threads are sleeping as we implenet thread synchronisation using of mutex.Shared variable's value is always 1
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

static  int shared=1;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;

static  void* threadIncrement(void* arg){
    printf("\nIn increment thread:");
    printf("\n increment thread trying to acquire the lock...\n");
    pthread_mutex_lock(&mtx);
    printf("\nincrement thread acuired the lock");
    int loc=shared;
    loc++;
    printf("\ncontrol goes to decrement thread as increment thread sleeps for 5 sec");
    sleep(5);
    shared=loc;
    pthread_mutex_unlock(&mtx);
    printf("\nincrement thread released the lock");
}

static  void* threadDecrement(void* arg){
    printf("\nIn decrement thread:");
    printf("\n decrement thread trying to acquire the lock\n");
    pthread_mutex_lock(&mtx);
    printf("\n decrement thread acuired the lock");
    int loc=shared;
    loc--;
    
    sleep(1);
    shared=loc;
    pthread_mutex_unlock(&mtx);
    printf("\n decrement thread released the lock");
}


int main(){
    pthread_t t1;
    pthread_t t2;
    int s1=pthread_create(&t1,NULL,threadIncrement,NULL);
    int s2=pthread_create(&t2,NULL,threadDecrement,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
   
    printf("\nvalue of shared variable->%d\n",shared);
    printf("\nMain thread exiting\n");
}