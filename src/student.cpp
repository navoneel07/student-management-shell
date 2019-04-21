#include "../include/student.hpp"
#include <iostream>
#include <iomanip>
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
    cout<<left<<setw(14)<<uid
    <<left<<setw(20)<<name
    <<left<<setw(12)<<year
    <<left<<setw(12)<<faculty
    <<left<<setw(14)<<curriculum
    <<left<<setw(12)<<status
    <<left<<setw(14)<<nationality
    <<left<<setw(12)<<res_status<<'\n';
}

void Student::setData(string field, string value){
    if(field == "uid"){
        uid = value;
    }
    else if(field == "name"){
        name = value;
    }
    else if(field == "year"){
        year = value;
    }
    else if(field == "faculty"){
        faculty = value;
    }
    else if(field == "curriculum"){
        curriculum = value;
    }
    else if(field == "status"){
        status = value;
    }
    else if(field == "nationality"){
        nationality = value;
    }
    else if(field == "res_status"){
        res_status = value;
    }
    else{
        cout<<"Field doesn't exist!"<<endl;
        return;
    }
}

string Student::getData(string field){
    if(field == "uid"){
        return uid;
    }
    else if(field == "name"){
        return name;
    }
    else if(field == "year"){
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

void StudentAcademic::newStudentAcademic(){
    int a, b;
    cout<<"\nAcademic\nEnter number of current courses: ";
    cin>>a;
    for (int i = 0; i < a; i++) {
        cout<<"Enter course code for course "<<i+1<<" : ";
        cin>>cur_courses[i];
    }
    for (int i = a; i < 6; i++) {
        cur_courses[i] = "0";
    }
    cout<<"\nEnter number of past courses: ";
    cin>>b;
    string course_code;
    for (int i = 0; i < b; i++) {
        cout<<"Enter course code for course "<<i+1<<" : ";
        cin>>past_courses[i];
    }
    for (int i = b; i < 42; i++) {
        past_courses[i] = "0";
    }
    total_credits = 6*b;
}

void StudentAcademic::viewStudentAcademic(unordered_map<string, string> courseMap){
    cout<<"\n=======================\nAcademic information\n=======================\nCurrent Courses\n";
    for(int i=0;i<cur_courses.size();i++){
        if (cur_courses[i] == "0") {
            continue;
        }
        cout<<cur_courses[i]<<" "<<courseMap[cur_courses[i]]<<"\n";
    }
    cout<<"\nPast Courses\n";
    for(int i=0;i<past_courses.size();i++){
        if (past_courses[i] == "0") {
            continue;
        }
        cout<<past_courses[i]<<" "<<courseMap[past_courses[i]]<<"\n";
    }
    cout<<"\nTotal credits accumulated = "<<total_credits<<"\n\n";
}
