#include <iostream>
using namespace std;

template <class T>
T sumOfArrayElemnts(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {3.6,5.2,9.6,9.6,4.8};

    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "Sum of integer array: " << sumOfArrayElemnts(intArray, intSize) << endl;
    cout << "Sum of float array: " << sumOfArrayElemnts(floatArray, floatSize) << endl;

    return 0;
}
