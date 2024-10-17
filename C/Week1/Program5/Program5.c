#include <stdio.h>

// Function prototypes
int countEvenNumbers(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
int removeDuplicates(int arr[], int size);

int main() {
    int arr[10], size;
    
    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    // Input the array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Count the even numbers in the array
    int evenCount = countEvenNumbers(arr, size);
    printf("\nNumber of even numbers in the array: %d\n", evenCount);
    
    // Sort the array in ascending order
    sortAscending(arr, size);
    printf("Array in ascending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array in descending order
    sortDescending(arr, size);
    printf("Array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Remove duplicates and print the unique array
    size = removeDuplicates(arr, size);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to count even numbers in the array
int countEvenNumbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Function to sort the array in ascending order
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort the array in descending order
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to remove duplicates from the sorted array
int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) return size;  // No duplicates in empty or single-element array
    
    int temp[size];
    int j = 0;
    
    // Remove duplicates from sorted array
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[size - 1];  // Add the last element
    
    // Copy the modified array back to the original
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    
    return j;  // Return the new size of the array
}
