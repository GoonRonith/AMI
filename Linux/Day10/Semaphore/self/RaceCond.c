#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int glob=1;

void* func1(void *arg){
    printf("\nCurrent thread%s",(char *)arg);
    int loc=glob;
    printf("\n thread2 reads the current val of glob as %d",loc);
    loc++;
    sleep(1);
    glob=loc;
    printf("\n (t1)glob=%d ",glob);
}

void* func2(void *arg){
    printf("\nCurrent thread%s",(char *)arg);
    int loc=glob;
    printf("\n thread2 reads the current val of glob as %d",loc);
    loc--;
    sleep(1);
    glob=loc;
    printf("\n (t2)glob=%d ",glob);
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func1,"T1");
    pthread_create(&t2,NULL,func1,"T2");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("final value of glob=%d\n",glob);
}