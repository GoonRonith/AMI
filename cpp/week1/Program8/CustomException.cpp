#include<iostream>
#include<exception>
using namespace std;
class Bank{
    private:
    double balance;
    public:
    Bank(){
        this->balance=0;
    }
    Bank(double balance){
        this->balance=balance;
    }
    void deposit(double amount){
        if(amount<=0){
            throw runtime_error("Invalid amount...");
        }
        balance+=amount;
        cout<<amount<<" is credited"<<endl;
    }
    void withDraw(double amount){
        if(amount <=balance){
            cout<<"Please collect your cash"<<endl;
            balance-=amount;
        }
        else{
            throw runtime_error("Insufficient balance...");
        }
    }
    void displayBalance(){
        cout<<"your balance is=>"<<this->balance<<endl;
    }
};
int main(){
     Bank b1;
    try{
    b1.displayBalance();
    b1.deposit(500);
    b1.withDraw(200);
    b1.withDraw(300);
    b1.withDraw(200);
    }
    catch(const runtime_error& e){
        try
        {
        std::cerr << e.what() << '\n';
          b1.deposit(-5);
        }
        catch(exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
    }
    }
