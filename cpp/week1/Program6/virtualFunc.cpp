#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;

    Employee() {}

    Employee(string name) {
        this->name = name;
    }

    virtual void display() { 
        cout << "Base Employee class and employee name -> " << this->name << endl;
    }
};

class SalariedEmployee : public Employee {
public:
    double salary;

    
    SalariedEmployee(string name, double salary) : Employee(name) {
        this->salary = salary;
    }

    void display() { 
        cout << "Hello, my name is "<<this->name<<" and i am a salaried employee and my salary is " << this->salary << " LPA" << endl;
    }
};

class ContractLabour : public Employee {
public:
    double wages;

   
    ContractLabour(string name, double wages) : Employee(name) {
        this->wages = wages;
    }

    void display()  { 
        cout << "Hello, my name is " <<this->name<<" and i am a contract labour and my per day wage is " << this->wages << " rupees" << endl;
        
    }
};

int main() {
    SalariedEmployee emp2("Harry", 4);
    ContractLabour emp3("John", 200); 
    Employee* emp1;

    emp1 = &emp2;
    emp1->display(); 

    emp1 = &emp3;
    emp1->display(); 

    return 0;
}
