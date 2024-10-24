#include<iostream>
using namespace std;
#include<string>
class StudentBasicInfo{
    private:
    int id;
    string name;
    int marks[5];
    public:
    StudentBasicInfo(){
    }
  
    void setBasicInformationOfStudent(int id,string name,int marks[5]){
        this->id=id;
        this->name=name;
        for(int i=0;i<5;i++){
            this->marks[i]=marks[i];
        }
    }
    void printAllBasicInfo(){
        cout<<"Name->"<<this->name<<endl;
        cout<<"Id->"<<this->id<<endl;
        cout<<"Marks"<<endl;
        for(int i=0;i<5;i++){
            cout<<this->marks[i]<<endl;
        }
    }
    int getId(){
        return this->id;
    }
};
class studentUnderGraduateInfo:public StudentBasicInfo{
    private:
    string departmentName;
    public:
    studentUnderGraduateInfo(){
    }
    void setDepartmentName(string depName){
        this->departmentName=depName;
    }
    void printAllDetails(){
            this->printAllBasicInfo();
            cout<<"department->"<<this->departmentName<<endl;
        
    }
    bool serachUnderGraduateStudentById(int id){
        if(this->getId()==id) {
            cout<<"Under Graduate Student Information"<<endl;
            this->printAllBasicInfo();
            cout<<"department->"<<this->departmentName<<endl;
            return true;
        }
        return false;
    }
};
class studentPostGraduateInfo: public StudentBasicInfo{
    private:
    string departmentName;
    public:
    studentPostGraduateInfo(){
    }
    void setDepartmentName(string depName){
        this->departmentName=depName;
    }
     void printAllDetails(){
            this->printAllBasicInfo();
            cout<<"department->"<<this->departmentName<<endl;
        
    }
     bool serachPostGraduateStudentById(int id){
        if(this->getId()==id) {
            cout<<"Post Graduate Student Information"<<endl;
            this->printAllBasicInfo();
            cout<<"department->"<<this->departmentName<<endl;
        }
    }
};

int main(){
    int totalUnderGraduateStudent=3;
    int totalPostGraduateStudent=3;
    cout<<"Enter the number of students of the under Graduate college->"<<endl;
    cin>>totalUnderGraduateStudent;
    studentUnderGraduateInfo obj[10];
    int id;
    int marks[5];
    string name;
    string depName;
    for(int i=0;i<totalUnderGraduateStudent;i++){
        cout<<"Enter the id of the student"<<i+1<<endl;
        cin>>id;
        cout<<"Enter the name of the student"<<endl;
        cin>>name;
        for(int j=0;j<5;j++){
            cout<<"Enter subject"<<j+1<<" marks"<<endl;
            cin>>marks[j];
        }
        obj[i].setBasicInformationOfStudent(id,name,marks);
        cout<<"Enter the department for undergraduate student=>"<<endl;
        cin>>depName;
        obj[i].setDepartmentName(depName);
    }
    cout<<"ALL DETAILS FOR UNDERGRADUATE STUDENTS"<<endl;
   for(int i=0;i<totalUnderGraduateStudent;i++){
    cout<<"-----Student"<<i+1<<endl;
    obj[i].printAllDetails();
   }



 cout<<"Enter the number of students of the post Graduate college->"<<endl;
    cin>>totalPostGraduateStudent;
    studentPostGraduateInfo obj2[10];
    for(int i=0;i<totalPostGraduateStudent;i++){
        cout<<"Enter the id of the student"<<i+1<<endl;
        cin>>id;
        cout<<"Enter the name of the student"<<endl;
        cin>>name;
        for(int j=0;j<5;j++){
            cout<<"Enter subject"<<j+1<<" marks"<<endl;
            cin>>marks[j];
        }
        obj2[i].setBasicInformationOfStudent(id,name,marks);
        cout<<"Enter the department for postgraduate student=>"<<endl;
        cin>>depName;
        obj2[i].setDepartmentName(depName);
    }
    cout<<"ALL DETAILS FOR POSTGRADUATE STUDENTS"<<endl;
   for(int i=0;i<totalPostGraduateStudent;i++){
    cout<<"-----Student"<<i+1<<endl;
    obj2[i].printAllDetails();
   }


    //Searching
    int searchId;
    cout<<"Enter the id of undergraduate student that u want to searh"<<endl;
    cin>>searchId;
    bool find=false;
    for(int i=0;i<totalUnderGraduateStudent;i++){
        if(obj[i].serachUnderGraduateStudentById(searchId)){
            find=true;
            break;
        }

    }
    if(!find) cout<<"Under graduate Student not found...";

    cout<<"Enter the id of postgraduate student that u want to searh"<<endl;
    cin>>searchId;
    bool find=false;
    for(int i=0;i<totalPostGraduateStudent;i++){
        if(obj2[i].serachPostGraduateStudentById(searchId)){
            find=true;
            break;
        }

    }
    if(!find) cout<<"Post graduate Student not found...";


}
