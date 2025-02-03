#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_NAME "/test_queue"

int main() {
    mqd_t mq;
    char buffer[256];

    // Open existing message queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Receive message
    if (mq_receive(mq, buffer, sizeof(buffer), NULL) == -1) {
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s\n", buffer);
    
    // Cleanup: Remove message queue
    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}
