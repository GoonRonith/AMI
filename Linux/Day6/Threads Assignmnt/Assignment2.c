#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

static void * ThreadFunc(void *arg){
    int *marks=(int *)arg;
    printf("\n Inside Thread1 and passed argument is-:%d",*marks);
    for(int i=1;i<=5;i++){
        sleep(1);
        printf("\n%d",i);
    }
}

int main(){
    pthread_t t1;
    int marks=100;
    int s=pthread_create(&t1,NULL,ThreadFunc,&marks);
     if (s != 0)
        perror("Thread create error");

     s = pthread_join(t1,NULL);
    if (s != 0)
        perror("pthread_join error");
    printf("\n Inside Main Thread ");
    for(int i=6;i<=10;i++){
        sleep(1);
        printf("\n%d",i);
    }
}