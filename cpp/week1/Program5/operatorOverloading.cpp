#include<iostream>
using namespace std;
class Complex{
    public:
    double realPart;
    double imaginarypart;
    Complex(){
        realPart=0;
        imaginarypart=0;
    }
    Complex(double realPart,double imaginaryPart){
        this->realPart=realPart;
        this->imaginarypart=imaginaryPart;
    }
    Complex operator+(const Complex &obj){
        Complex res;
        res.realPart=this->realPart+obj.realPart;
        res.imaginarypart=this->imaginarypart+obj.imaginarypart;
        return res;
    }
      Complex operator-(const Complex &obj){
        Complex res;
        res.realPart=this->realPart-obj.realPart;
        res.imaginarypart=this->imaginarypart-obj.imaginarypart;
        return res;
    }
    Complex operator*(const Complex &obj){
        Complex res;
        res.realPart=(this->realPart*obj.realPart)-(this->imaginarypart-obj.imaginarypart);
        res.imaginarypart=(this->realPart*obj.realPart)-(this->imaginarypart-obj.imaginarypart);
        return res;
    }
    Complex operator/(const Complex &obj){
        Complex res;
         double denominator = obj.realPart * obj.realPart + obj.imaginarypart * obj.imaginarypart;
            res.realPart=(this->realPart * obj.realPart+this->imaginarypart * obj.imaginarypart)/denominator;
            res.imaginarypart=(this->imaginarypart * obj.realPart-this->realPart * obj.imaginarypart)/denominator;
            return res;
    }

};
int main(){
    Complex c1(4, 5);
    Complex c2(2, 3);
    cout<<"c1+c2->"<<(c1+c2).realPart<<"+"<<(c1+c2).imaginarypart<<"i"<<endl;
    cout<<"c1-c2->"<<(c1-c2).realPart<<"+"<<(c1-c2).imaginarypart<<"i"<<endl;
    cout<<"c1*c2->"<<(c1*c2).realPart<<"+"<<(c1*c2).imaginarypart<<"i"<<endl;
    cout<<"c1/c2->"<<(c1/c2).realPart<<"+"<<(c1/c2).imaginarypart<<"i"<<endl;
}