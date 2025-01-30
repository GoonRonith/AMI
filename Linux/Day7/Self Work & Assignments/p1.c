//This function works proper as no threads are sleeping.Shared variable's value updates to  1 always
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

static  int shared=1;

static  void* threadIncrement(void* arg){
    printf("\nIn increment thread:");
     int loc=shared;
    loc++;
    shared=loc;
}

static  void* threadDecrement(void* arg){
    printf("\nIn decrement thread:");
    int loc=shared;
    loc--;
    shared=loc;
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