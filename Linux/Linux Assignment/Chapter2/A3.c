#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 3 

int A[SIZE][SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int B[SIZE][SIZE] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

int C[SIZE][SIZE]; 
typedef struct {
    int row;
} ThreadData;

void* multiplyRow(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int row = data->row;
    free(data); 

    for (int col = 0; col < SIZE; col++) {
        C[row][col] = 0;
        for (int k = 0; k < SIZE; k++) {
            C[row][col] += A[row][k] * B[k][col];
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData));
        data->row = i;
        pthread_create(&threads[i], NULL, multiplyRow, data);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

  
    printf("Resultant Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
