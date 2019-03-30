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
