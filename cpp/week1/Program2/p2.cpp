#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    string brand;
    int makeYear;
    double price;

public:
    
    Car() {
        this->model = "default";
        this->brand = "default";
        this->makeYear = 0;
        this->price = 0.0;
    }

   
    Car(string model, string brand, int makeYear, float price) {
        this->model = model;
        this->brand = brand;
        this->makeYear = makeYear;
        this->price = price;
    }

    
    Car(const Car &car) {
        model = car.model;
        brand = car.brand;
        makeYear = car.makeYear;
        price = car.price;
    }

    
    void displayDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Make Year: " << makeYear << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    string model;
    string brand;
    int year;
    float price;

    cout << "Enter the brand name of the car: ";
    cin >> brand;
    cout << "Enter the model name of the car: ";
    cin >> model;
    cout << "Enter the make year of the car: ";
    cin >> year;
    cout << "Enter the price of the car: ";
    cin >> price;

    Car car1(model, brand, year, price); 
    Car car2 = car1; 

    cout << "\nDetails of Car 1:" << endl;
    car1.displayDetails(); 

    cout << "\nDetails of Car 2 (Copy of Car 1):" << endl;
    car2.displayDetails(); 

    return 0;
}
