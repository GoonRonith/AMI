#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void displayDeque(const deque<int>& d) {
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    deque<int> myDeque;

   
    cout << "Inserting data into deque...\n";
    for (int i = 1; i <= 5; ++i) {
        myDeque.insert(myDeque.end(), i * 10); 
    }
    cout << "Deque after inserting elements: ";
    displayDeque(myDeque);

    myDeque.push_front(5);
    myDeque.push_back(60);
    cout << "\nDeque after push_front(5) and push_back(60): ";
    displayDeque(myDeque);

    myDeque.pop_front();
    myDeque.pop_back();
    cout << "\nDeque after pop_front() and pop_back(): ";
    displayDeque(myDeque);
    for (auto it = myDeque.begin(); it != myDeque.end(); ) {
        
        it = myDeque.erase(it); 
        if (it != myDeque.end()) {
            ++it; 
        }
    }

    cout << "\nDeque after unique erase (every second element): ";
    displayDeque(myDeque);

    return 0;
}
