#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define maxLimit 10

pthread_mutex_t mtxOddEven=PTHREAD_MUTEX_INITIALIZER;

int global=1;


static void* OddThread(void* arg){
sleep(1);
pthread_mutex_lock(&mtxOddEven);

while (global <= maxLimit)
{
    if(global%2!=0) {
    printf("\n odd->%d",global);
    global++;
    pthread_mutex_unlock(&mtxOddEven);
    sleep(1);
}
else{
     pthread_mutex_unlock(&mtxOddEven);
}
}


} 

 static void* EvenThread(void* arg){

pthread_mutex_lock(&mtxOddEven);
while (global <= maxLimit){
    if(global%2==0) {
    printf("\n Even->%d",global);
    global++;
    pthread_mutex_unlock(&mtxOddEven);
    sleep(1);
}
else{
     pthread_mutex_unlock(&mtxOddEven);
}
}


}

int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,OddThread,NULL);
    pthread_create(&t2,NULL,EvenThread,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
   

    return 0;
}