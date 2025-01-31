#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

pthread_mutex_t mtxFile=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myconVar=PTHREAD_COND_INITIALIZER;
int fileCreation=0;


static void* createFileThread(void *arg){
    pthread_mutex_lock(&mtxFile);
    if(fileCreation==0){
         printf("\ncreation of file by create Thread");
        int fd= open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        fileCreation=1;
        pthread_cond_signal(&myconVar);
        
    }
        pthread_mutex_unlock(&mtxFile);
    
}

static void* writeFileThread(void *arg){
        pthread_mutex_lock(&mtxFile);
        if(fileCreation!=0){
            printf("\nwriting into file by write Thread\n");
            int fd=open("example.txt",O_WRONLY);
            write(fd,"text written by WRITEFILETHREAD",31);
            pthread_mutex_unlock(&mtxFile);
        }
        else{
            pthread_cond_wait(&myconVar,&mtxFile);
        }
}

int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,createFileThread,NULL);
    pthread_create(&t2,NULL,writeFileThread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}