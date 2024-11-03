#include <iostream>
using namespace std;

template <class T>
class Calc {
private:
    T a, b;

public:

    Calc(T x, T y) : a(x), b(y) {}


    T add() { return a + b; }


    T sub() { return a - b; }

   
    T mul() { return a * b; }

  
    T div() {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero" << endl;
            return 0;
        }
    }
};

int main() {

    Calc<int> calcInt(10, 5);
    cout << "Integer Addition: " << calcInt.add() << endl;
    cout << "Integer Subtraction: " << calcInt.sub() << endl;
    cout << "Integer Multiplication: " << calcInt.mul() << endl;
    cout << "Integer Division: " << calcInt.div() << endl;

    Calc<float> calcFloat(10.5, 2.5);
    cout << "Float Addition: " << calcFloat.add() << endl;
    cout << "Float Subtraction: " << calcFloat.sub() << endl;
    cout << "Float Multiplication: " << calcFloat.mul() << endl;
    cout << "Float Division: " << calcFloat.div() << endl;

    return 0;
}
