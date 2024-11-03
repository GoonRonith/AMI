#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers;
    int n, choice, element, position;
    cout << "Enter the number of elements you want to store: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Sort the vector\n";
        cout << "2. Add a new element\n";
        cout << "3. Erase a specific element\n";
        cout << "4. Display vector\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sort(numbers.begin(), numbers.end());
                break;

            case 2:
                cout << "Enter the element to add: ";
                cin >> element;
                numbers.push_back(element);
                break;

            case 3:
                
                cout << "Enter the position of the element to delete ";
                cin >> position;
                if (position >= 0 && position < numbers.size()) {
                    numbers.erase(numbers.begin() + position);
                    cout << "Element erased.\n";
                } else {
                    cout << "Invalid position.\n";
                }
                break;

            case 4:
                
                cout << "Current vector: ";
                displayVector(numbers);
                break;

            case 5:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
