#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

static void * ThreadFunc(void *arg){
    int *marks=(int *)arg;
    printf("\n Inside Thread1 and passed argument is-:%d",*marks);
    for(int j=1;j<=5;j++){
        sleep(1);
        printf("\n%d",j);
    }
    
}

int main(){
    pthread_t t1;
    int marks=100;
    void *res;
    int s=pthread_create(&t1,NULL,ThreadFunc,&marks);
    pthread_detach(t1);
     if (s != 0)
        perror("Thread create error");
    printf("\n Inside Main Thread ");
    for(int i=6;i<=10;i++){
        sleep(1);
        printf("\n%d",i);
    }
    // printf("\nReturn value from thread 1->%s",(char *)res);
}