#include <iostream>
#include <fstream>
#include "../include/student.hpp"
#include "../include/file_functions.hpp"

void writeStudentToFile(Student student){
    ofstream ofile;
    ofile.open("db/student.txt", ios::app | ios::binary);
    if(ofile.fail()){
        cout<<"Failed to open file...";
        exit(1);
    }
    ofile.write((char*)&student, sizeof(student));
    cout<<"New Student Added!";
    ofile.close();
}

void readStudentFromFile(Student student){
    ifstream ifile;
    ifile.open("db/student.txt", ios::binary);
    ifile.read((char*)&student, sizeof(student));
}
