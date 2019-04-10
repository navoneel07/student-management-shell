#include "../include/student.hpp"
#include <iostream>

using namespace std;

void Student::newStudent(){
    cout<<"Enter the following information: "<<endl;
    cout<<"UID: ";
    cin>>uid;
    cin.ignore(256, '\n');
    cout<<"Name: ";
    getline(cin, name);
    cout<<"Year: ";
    cin>>year;
    cin.ignore(256, '\n');
    cout<<"Faculty: ";
    getline(cin, faculty);
    cout<<"Curriculum: ";
    getline(cin, curriculum);
    cout<<"Status of Study: ";
    getline(cin, status);
    cout<<"Nationality: ";
    getline(cin, nationality);
    cout<<"Residential status: ";
    getline(cin, res_status);
}

void Student::viewStudent(){
    cout<<endl;
    cout<<"UID: "<<uid<<"\nName: "<<name<<"\nYear: "<<year<<"\nFaculty: "<<faculty<<"\nCurriculum: "<<curriculum<<"\nStatus of Study: "<<status<<"\nNationality: "<<nationality<<"\nResidential Status: "<<res_status<<"\n";
}

string Student::getData(string field){
    if(field == "year"){
        return year;
    }
    else if(field == "faculty"){
        return faculty;
    }
    else if(field == "curriculum"){
        return curriculum;
    }
    else if(field == "status"){
        return status;
    }
    else if(field == "nationality"){
        return nationality;
    }
    else if(field == "res_status"){
        return res_status;
    }
    else{
        cout<<"Field doesn't exist!"<<endl;
        return NULL;
    }
}
