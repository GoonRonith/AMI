#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> set;
    int n, element;


    cout << "Enter the number of elements:";
    cin >> n;


    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        set.insert(input);
    }

 
    cout << "Current elements in the set: ";
    for (int val : set) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Enter an element to delete: ";
    cin >> element;
    if (set.erase(element)) {
        cout << "Element deleted successfully.\n";
    } else {
        cout << "Element not found in the set.\n";
    }

    cout << "Set after deletion: ";
    for (int val : set) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Enter an element to search: ";
    cin >> element;
    if (set.find(element) != set.end()) {
        cout << "Yes, element found in the set.\n";
    } else {
        cout << "No, element not found in the set.\n";
    }

    return 0;
}
