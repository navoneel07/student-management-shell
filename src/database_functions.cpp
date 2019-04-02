#include <iostream>
#include <unordered_map>
#include "../include/file_functions.hpp"
#include "../include/database_functions.hpp"

using namespace std;

void addNewStudentToDatabase(){
    Student student;
    student.newStudent();
    writeStudentToFile(student);
}

void searchStudent(unordered_map<string, string> studentMap) {
    string uid;
    cout<<"\nEnter UID: ";
    cin>>uid;
    string fileName = studentMap[uid];
    Student student = readStudentFromFile(fileName);
    student.viewStudent();    
}
