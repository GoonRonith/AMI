#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

static void * ThreadFunction(void *arg){
    char *str=(char *)arg;
    printf("\n Inside Thread1 and passed argument is-:%s",str);
    for(int i=1;i<=5;i++){
        sleep(1);
        printf("\n%d",i);
    }
}

int main(){
    pthread_t t1;
    char *msg="Ronith Goon";
    int s=pthread_create(&t1,NULL,ThreadFunction,msg);
    if (s != 0)
        perror("Thread create error");

    printf("\n Inside Main Thread ");
    for(int i=6;i<=10;i++){
        sleep(1);
        printf("\n%d",i);
    }
}