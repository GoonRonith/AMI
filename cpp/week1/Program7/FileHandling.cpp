#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ofstream f1("sample.txt");
    f1<<"This is some text that is being written for the first time"<<endl;
    f1.close();
    ofstream f2("sample.txt",ios::out | ios::app);
    if(f2.is_open()){
         f2<<"This is some text that is being written for the second time"<<endl;
    }
    f2.close();
    cout<<"After writing 2 times into the file now the content is->";
    ifstream f3("sample.txt");
    string line;
    while (getline(f3,line))
    {
        cout<<line<<endl;
    }
    f3.close();

    fstream f4("sample.txt");
    f4.seekg(20);
    cout<<"======>"<<endl;
    f4<<"After 20th character this string is appended";
    f4.seekg(20);
    while (getline(f4,line))
    {
        cout<<line<<endl;
    }
    
    
}