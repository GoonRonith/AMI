#include<iostream>

using namespace std;
class Shape{
    public:
    double getArea(int side){
        return side*side;
    }
    double getArea(double length,double breadth){
        return length*breadth;
    }
    double getArea(double radius){
        return 3.14*radius*radius;
    }

};
int main(){
    Shape obj1;
    cout<<"Area of Side->"<<obj1.getArea(5)<<endl;
    cout<<"Area of Rectangle->"<<obj1.getArea(10,20)<<endl;
    cout<<"Area of Square->"<<obj1.getArea(5.6)<<endl;
}