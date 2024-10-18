#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int age;
    string name;
    string gender;

public:
    Person() {}

    Person(int age, string name, string gender) {
        this->age = age;
        this->name = name;
        this->gender = gender;
    }
};

class EmployeeDetails1 : public Person {
protected:
    string employee_department;
    string employee_id;

public:
    EmployeeDetails1() {}

    EmployeeDetails1(string dep, string eid, int age, string name, string gender) : Person(age, name, gender) {
        employee_department = dep;
        employee_id = eid;
    }
};

class EmployeeDetails2 : public EmployeeDetails1 {
protected:
    double emp_salary;
    int year_of_joining;

public:
    EmployeeDetails2(double emp_salary, int year_of_joining, string dep, string eid, int age, string name, string gender)
        : EmployeeDetails1(dep, eid, age, name, gender) {
        this->emp_salary = emp_salary;
        this->year_of_joining = year_of_joining;
    }

    void displayDetailsOfEmployee() {
        cout << "Details -> "
             << "Name: " << name 
             << ", Age: " << age 
             << ", Gender: " << gender 
             << ", Department: " << employee_department 
             << ", Employee ID: " << employee_id 
             << ", Salary: " << emp_salary 
             << ", Year of Joining: " << year_of_joining << endl;
    }
};

int main() {
    EmployeeDetails2 emp2(40000, 2025, "HR", "E02", 22, "Bijay", "male");
    emp2.displayDetailsOfEmployee();
    return 0;
}
