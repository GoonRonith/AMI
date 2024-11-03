#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void displayVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}


void rotateRight(vector<int>& vec, int k) {
    k %= vec.size();  
    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
}


void rotateLeft(vector<int>& vec, int k) {
    k %= vec.size();  
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
    reverse(vec.begin(), vec.end());
}


void reverseInGroups(vector<int>& vec, int groupSize) {
    for (size_t i = 0; i < vec.size(); i += groupSize) {
        if (i + groupSize <= vec.size()) {
            reverse(vec.begin() + i, vec.begin() + i + groupSize);
        } else {
            reverse(vec.begin() + i, vec.end());
        }
    }
}

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original Vector: ";
    displayVector(myVector);

    int k;
    cout << "\nEnter number of positions to rotate to the right: ";
    cin >> k;
    rotateRight(myVector, k);
    cout << "Vector after right rotation by " << k << " positions: ";
    displayVector(myVector);


    myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "\nEnter number of positions to rotate to the left: ";
    cin >> k;
    rotateLeft(myVector, k);
    cout << "Vector after left rotation by " << k << " positions: ";
    displayVector(myVector);

   
    int groupSize;
    cout << "\nEnter group size for unique reversal: ";
    cin >> groupSize;
    reverseInGroups(myVector, groupSize);
    cout << "Vector after reversing in groups of size " << groupSize << ": ";
    displayVector(myVector);

    return 0;
}
