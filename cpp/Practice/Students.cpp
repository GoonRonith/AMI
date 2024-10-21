#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int main(){
    ifstream st("students.txt");
    string line;
    string number;
    int total_marks=0;
    int total_students=0;
    while (getline(st,line))
    {
        for(int i=0;i<line.length();i++){
            if(line[i]==','){
                number=line.substr(i+1,line.length());
                total_students++;
                break;
            }
        }
        int marks=stoi(number);

        total_marks+=marks;
    }
    st.close();
    ifstream st1("students.txt");
    int avg_marks=total_marks/total_students;
    cout<<"average marks:"<<avg_marks<<endl;
     while (getline(st1,line))
    {
        for(int i=0;i<line.length();i++){
            if(line[i]==','){
                number=line.substr(i+1,line.length());
                int marks=stoi(number);
                // cout<<marks;
                if(marks>avg_marks){

                    cout<<line.substr(0,i)<<endl;
                }
                
            }
        }
        

        
    }

    
}