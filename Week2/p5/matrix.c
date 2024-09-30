#include <stdio.h>

#define MAX 10

// Function to add two matrices
void addMatrices(int (*a)[MAX], int (*b)[MAX], int (*result)[MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int (*a)[MAX], int (*b)[MAX], int (*result)[MAX], int rowA, int colA, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0; // Initialize result matrix cell
            for (int k = 0; k < colA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int (*matrix)[MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX], product[MAX][MAX];
    int rowA, colA, rowB, colB;

    // Input for first matrix
    printf("Enter rows and columns for first matrix (A): ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input for second matrix
    printf("Enter rows and columns for second matrix (B): ");
    scanf("%d %d", &rowB, &colB);
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Addition
    if (rowA == rowB && colA == colB) {
        addMatrices(a, b, sum, rowA, colA);
        printf("Sum of matrices A and B:\n");
        printMatrix(sum, rowA, colA);
    } else {
        printf("Matrices A and B cannot be added due to dimension mismatch.\n");
    }

    // Multiplication
    if (colA == rowB) {
        multiplyMatrices(a, b, product, rowA, colA, colB);
        printf("Product of matrices A and B:\n");
        printMatrix(product, rowA, colB);
    } else {
        printf("Matrices A and B cannot be multiplied due to dimension mismatch.\n");
    }

    return 0;
}
