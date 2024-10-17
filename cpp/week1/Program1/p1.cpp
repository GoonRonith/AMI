#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    string name;
    int marks;
    int age;
    public:
    static int totalStudents;
    Student(){
     totalStudents++;
        this->marks=0;
        this->name="default name";
        this->age=0;
    }
    // void increaseRoll(){
    //     totalStudents++;
    // }
    void setName(string name){
        this->name=name;
    }
    void setMarks(int marks){
        this->marks=marks;
    }
    void setAge(int age){
        this->age=age;
    }
    string getName(){
        return this->name;
    }
    int getMarks(){
        return this->marks;
    }
    int getAge(){
        return this->age;
    }

};
int Student::totalStudents=0;
int main(){
    Student object1;
    Student object2;
    object1.setName("Ronith");
    object2.setName("Ram");
    object1.setMarks(98);
    object2.setMarks(58);
    object1.setAge(22);
    object2.setAge(22);
    cout<<"Total No of students are=>"<<Student::totalStudents<<endl;
    cout << "Student 1: Name -> " << object1.getName() << ", Marks -> " << object1.getMarks() << ", Age -> " << object1.getAge() << endl;
    cout << "Student 2: Name -> " << object2.getName() << ", Marks -> " << object2.getMarks() << ", Age -> " << object2.getAge() << endl;
}