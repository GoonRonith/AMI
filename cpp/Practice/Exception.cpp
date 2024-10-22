#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main() {
    try {
        int a;
        int b;
        
        cout << "Enter two integers: ";
        cin >> a >> b;

        if (cin.fail()) {
            throw runtime_error("Invalid input");
        }
        
       if(b==0){
        throw runtime_error("error");
       }

        cout << "Result: " << a / b << endl;
    }
    catch (const runtime_error& e) { 
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
