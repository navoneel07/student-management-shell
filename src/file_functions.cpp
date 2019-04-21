#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../include/file_functions.hpp"

#include <string>

using namespace std;

//just a tester func
void clearKeys(){
    ofstream ofile;
    ofile.open("db/key.txt", ios::trunc);
    ofile.close();
}

void mapInit(unordered_map<string, string> &genericMap, string filename){
    genericMap.clear();
    ifstream kfile;
    kfile.open(filename.c_str());
    pair<string, string> p;
    string line;
    while (getline(kfile, line)) {
        istringstream inpstr(line);
        string word1, word2;
        inpstr>>word1>>word2;
        p.first = word1;
        p.second = word2;
        genericMap.insert(p);
    }
    kfile.close();
}

void writeStudentToFile(Student student, StudentAcademic s_a){
    ofstream ofile, kfile, afile;
    string new_student_file = "db/"+student.getUID()+".txt";
    string new_student_afile = "db/"+student.getUID()+"_a.txt";
    ofile.open(new_student_file.c_str(), ios::app | ios::binary);
    afile.open(new_student_afile.c_str(), ios::app | ios::binary);
    kfile.open("db/key.txt", ios::app);

    ofile.write((char*)&student, sizeof(student));
    afile.write((char*) &s_a, sizeof(s_a));

    kfile<<student.getUID()<<' '<<new_student_file<<'\n';
    cout<<"New Student Added!";

    afile.close();
    ofile.close();
    kfile.close();
}

void modifyFile(Student student, unordered_map<string, string> studentMap){
    ofstream ofile;
    ofile.open("db/temp.txt", ios::binary);
    ofile.write((char*) &student, sizeof(student));
    string filename = studentMap[student.getUID()];
    ofile.close();
    remove(filename.c_str());
    rename("db/temp.txt", filename.c_str());
}

Student readStudentFromFile(string fileName){
    ifstream ifile;
    Student student;
    ifile.open(fileName.c_str());
    ifile.read((char*)&student, sizeof(student));
    return student;
}

StudentAcademic readAcademicFromFile(string filename){
    ifstream ifile;
    StudentAcademic student_a;
    ifile.open(filename.c_str());
    ifile.read((char*)&student_a, sizeof(student_a));
    return student_a;
}

void removeLine(string uid){
    int flag = 0;
    ifstream ifile;
    ofstream ofile;
    ifile.open("db/key.txt");
    ofile.open("db/temp.txt");
    string line;
    while (getline(ifile, line)) {
        istringstream inpstr(line);
        string word;
        inpstr>>word;
        if(word == uid){
            flag = 1;
            continue;
        }
        ofile<<line<<endl;
    }
    if(flag == 0){
        cout<<"No matches found...";
        exit(0);
    }else{cout<<"Student has been removed!\n";}
    remove("db/key.txt");
    rename("db/temp.txt", "db/key.txt");

}
