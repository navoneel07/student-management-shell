#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../include/file_functions.hpp"

#include <string>

using namespace std;

void clearKeys(){
    ofstream ofile;
    ofile.open("db/key.txt", ios::trunc);
    ofile.close();
}

void mapInit(unordered_map<string, string> &studentMap){
    ifstream kfile;
    kfile.open("db/key.txt");
    pair<string, string> p;
    string line;
    while (getline(kfile, line)) {
        istringstream inpstr(line);
        string word1, word2;
        inpstr>>word1>>word2;
        p.first = word1;
        p.second = word2;
        studentMap.insert(p);
    }
    kfile.close();
}

void writeStudentToFile(Student student){
    ofstream ofile, kfile;
    string new_student_file = "db/"+student.getUID()+".txt";

    ofile.open(new_student_file.c_str(), ios::app | ios::binary);
    kfile.open("db/key.txt", ios::app);

    ofile.write((char*)&student, sizeof(student));

    kfile<<student.getUID()<<' '<<new_student_file<<'\n';
    cout<<"New Student Added!";

    ofile.close();
    kfile.close();
}

Student readStudentFromFile(string fileName){
    ifstream ifile;
    Student student;
    ifile.open(fileName.c_str());
    ifile.read((char*)&student, sizeof(student));
    return student;
}
