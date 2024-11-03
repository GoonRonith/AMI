#include <iostream>
#include <queue>
using namespace std;
void displayQueue(queue<int> q) {
    if (q.empty()) {
        cout << "The queue is empty." << endl;
        return;
    }
    cout << "Current Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> myQueue;
    int choice, value;
    while (true) {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Check Queue Status\n";
        cout << "2. Access Next Element\n";
        cout << "3. Access Last Element\n";
        cout << "4. Add New Element to the Queue\n";
        cout << "5. Create and Insert Element to the Queue\n";
        cout << "6. Remove Element from the Queue\n";
        cout << "7. Swap the Content of Two Queues\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (myQueue.empty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty. Size: " << myQueue.size() << endl;
                }
                break;

            case 2:
                if (!myQueue.empty()) {
                    cout << "The next element in the queue is: " << myQueue.front() << endl;
                } else {
                    cout << "The queue is empty, no next element." << endl;
                }
                break;

            case 3:
                if (!myQueue.empty()) {
                    cout << "The last element in the queue is: " << myQueue.back() << endl;
                } else {
                    cout << "The queue is empty, no last element." << endl;
                }
                break;

            case 4:
                cout << "Enter a value to add to the queue: ";
                cin >> value;
                myQueue.push(value);
                cout << "Element " << value << " added to the queue." << endl;
                displayQueue(myQueue);
                break;

            case 5:
                cout << "Enter a value to create and insert into the queue: ";
                cin >> value;
                myQueue.emplace(value);
                cout << "Element " << value << " created and added to the queue using emplace." << endl;
                displayQueue(myQueue);
                break;

            case 6:
                if (!myQueue.empty()) {
                    cout << "Element " << myQueue.front() << " removed from the queue." << endl;
                    myQueue.pop();
                } else {
                    cout << "The queue is empty, nothing to remove." << endl;
                }
                displayQueue(myQueue);
                break;

            case 7: {
                queue<int> newQueue;
                cout << "Enter 3 values to fill a new queue: ";
                for (int i = 0; i < 3; ++i) {
                    cin >> value;
                    newQueue.push(value);
                }
                cout << "Swapping the content of the current queue with the new queue..." << endl;
                myQueue.swap(newQueue);
                cout << "After swapping:" << endl;
                cout << "My Queue: ";
                displayQueue(myQueue);
                cout << "New Queue: ";
                displayQueue(newQueue);
                break;
            }

            case 8:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }
}
