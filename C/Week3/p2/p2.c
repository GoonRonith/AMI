#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKCAPACITY 10
#define QUEUECAPACITY 10

int sizeOfStack = 0;
int sizeOfQueue = 0;

struct stack {
    int data;
    struct stack *next;
};

struct queue {
    int data;
    struct queue *next;
};

struct queue *rear = NULL;
struct queue *front = NULL;

// Stack functions
bool isEmpty(struct stack* top) {
    return top == NULL;
}

bool isFull() {
    return sizeOfStack == STACKCAPACITY;
}

struct stack* push(struct stack* top, int item) {
    if (isFull()) {
        printf("\nStack overflow");
        return top;
    }
    sizeOfStack++;
    struct stack* newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = item;
    newNode->next = top;
    return newNode;
}

struct stack* pop(struct stack* top) {
    if (isEmpty(top)) {
        printf("\nStack is empty!");
        return NULL;
    }
    printf("\nPopped element is -> %d", top->data);
    struct stack* temp = top;
    top = top->next;
    free(temp);
    sizeOfStack--;
    return top;
}

void displayStack(struct stack* top) {
    if (isEmpty(top)) {
        printf("\nStack is empty!");
        return;
    }
    printf("\nStack is ->");
    struct stack* temp = top;
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}


void pushInQueue(int data) {
    if (sizeOfQueue == QUEUECAPACITY) {
        printf("\nQueue is full");
        return;
    }
    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
        sizeOfQueue++;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    sizeOfQueue++;
}

void popInQueue() {
    if (front == NULL) {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nPopped item from queue is -> %d", front->data);
    struct queue* temp = front;
    front = front->next;
    free(temp);
    sizeOfQueue--;
    if (front == NULL) {
        rear = NULL; 
    }
}

void displayQueue() {
    if (front == NULL) {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nQueue is ->");
    struct queue* temp = front;
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}


int main() {
    struct stack *top = NULL;
    int choice, item;

    while (true) {
        printf("\nMenu:");
        printf("\n1. Push to Stack");
        printf("\n2. Pop from Stack");
        printf("\n3. Display Stack");
        printf("\n4. Push to Queue");
        printf("\n5. Pop from Queue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push to stack: ");
                scanf("%d", &item);
                top = push(top, item);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                printf("Enter item to push to queue: ");
                scanf("%d", &item);
                pushInQueue(item);
                break;
            case 5:
                popInQueue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}
