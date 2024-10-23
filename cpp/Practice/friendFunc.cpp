#include<iostream>
using namespace std;
class A;
class B;
class A{
    private:
    int x;
    public:
    A(int x){
        this->x=x;
    }
    friend void accessAandB(A,B);
    friend class B;

};
class B{
    private:
    int y;
    public:
    B(int y){
        this->y=y;
    }
    friend void accessAandB(A,B);
     void accessAFromB(A obj){
        cout<<"Acces data member of A from B that is->"<<obj.x;
    }
};

void accessAandB(A obj1,B obj2){
    cout<<"private memeber of A->"<<obj1.x<<endl;
    cout<<"private memeber of B->"<<obj2.y<<endl;
}

int main(){
    A obj1(10);
    B obj2(20);
    accessAandB(obj1,obj2);
    obj2.accessAFromB(obj1);

}