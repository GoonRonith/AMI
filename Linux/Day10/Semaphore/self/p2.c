#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <semaphore.h> 
#include <unistd.h>

int main(){
    sem_t *sem;
    int ret,sval;
    sem=sem_open("/sem1",O_RDONLY);
     if (sem == SEM_FAILED){
        perror("sem_open fail;");
        return -1;
    }else{
        printf("\n sem_open success\n");
    }
    
    sem_getvalue(sem,&sval);
    printf("\n before sem_wait semaphore val = (%d)\n",sval);
    
    ret=sem_wait(sem);
    printf("\nProcess 2 executing critical section\n");
    sleep(10);
    printf("\n ret is (%d)\n",ret);
    printf("\nprocess 2:\n");
    sem_post(sem);
 
    printf("\nProcess 2 executed critical section\n");

    sem_getvalue(sem,&sval);
    printf("\n after exiting process 2 semaphore val = (%d)\n",sval);

    sem_unlink("/sem1");
}