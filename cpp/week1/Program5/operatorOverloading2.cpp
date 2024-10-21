#include<iostream>
using namespace std;
#include<string>
class StringCompare{
    public:
    string s1;
    StringCompare(string s){
        s1=s;
    }
    public:
    bool operator==(const StringCompare &s2){
        return (s1.compare(s2.s1)==0);
    }
};
int main(){
    StringCompare s1("ronith");
    StringCompare s2("ronit");
    if(s1==s2){
        cout<<"matching";
    }
    else{
        cout<<"not matching";
    }

}