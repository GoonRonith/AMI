#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>  
#include <errno.h>

#define SNOOZE_TIME 5 

time_t alarm_time;

void handle_alarm(int sig) {
    
    time_t now;
    time(&now);
    printf("\nAlarm! Current time: %s", ctime(&now));
    
   
    char response;
    printf("Press 's' to snooze for %d seconds, or any other key to stop.\n", SNOOZE_TIME);
    response = getchar();
    
    if (response == 's' || response == 'S') {
        printf("Snooze activated! The alarm will ring again in %d seconds...\n", SNOOZE_TIME);
        
       
        alarm_time = time(NULL) + SNOOZE_TIME;
        
      
        struct itimerval timer;
        timer.it_value.tv_sec = SNOOZE_TIME;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL, &timer, NULL);
    } else {
        printf("Alarm stopped.\n");
    }
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handle_alarm);
    
   
    time(&alarm_time);
    alarm_time += 10;  
    

    timer.it_value.tv_sec = alarm_time - time(NULL);
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    
  
    while(1) {
        pause();  
    }

    return 0;
}
