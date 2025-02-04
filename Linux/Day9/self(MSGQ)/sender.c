#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_NAME "/test_queue"

int main() {
    mqd_t mq;
    struct mq_attr attr;
    
//     // Set message queue attributes
//     attr.mq_flags = 0;
//     attr.mq_maxmsg = 10;
//     attr.mq_msgsize = 256;
//     attr.mq_curmsgs = 0;
// // 
    // Create or open message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Send message
    char message[] = "Hello from POSIX sender!";
    if (mq_send(mq, message, sizeof(message), 0) == -1) {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message);
    mq_close(mq);
    return 0;
}
