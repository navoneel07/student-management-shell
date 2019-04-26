#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../include/file_functions.hpp"

#include <string>

using namespace std;

//just a tester function
void clearKeys(){
    ofstream ofile;
    ofile.open("db/key.txt", ios::trunc);
    ofile.close();
}

//initialize any map
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

//write a student object to a file
void writeStudentToFile(Student student, StudentAcademic s_a, StudentFinance s_f){
    ofstream ofile, kfile, afile, ffile;
    string new_student_file = "db/"+student.getUID()+".txt";
    string new_student_afile = "db/"+student.getUID()+"_a.txt";
    string new_student_ffile = "db/"+student.getUID()+"_f.txt";

    ofile.open(new_student_file.c_str(), ios::app | ios::binary);
    afile.open(new_student_afile.c_str(), ios::app | ios::binary);
    ffile.open(new_student_ffile.c_str(), ios::app|ios::binary);
    kfile.open("db/key.txt", ios::app);

    ofile.write((char*)&student, sizeof(student));
    afile.write((char*) &s_a, sizeof(s_a));
    ffile.write((char*) &s_f, sizeof(s_f));
    kfile<<student.getUID()<<' '<<new_student_file<<'\n';
    cout<<"New Student Added!";

    ffile.close();
    afile.close();
    ofile.close();
    kfile.close();
}

//modify a student file
void modifyFile(Student student, unordered_map<string, string> studentMap){
    ofstream ofile;
    ofile.open("db/temp.txt", ios::binary);
    ofile.write((char*) &student, sizeof(student));
    string filename = studentMap[student.getUID()];
    ofile.close();
    remove(filename.c_str());
    rename("db/temp.txt", filename.c_str());
}

//read data from a file into a student object
Student readStudentFromFile(string fileName){
    ifstream ifile;
    Student student;
    ifile.open(fileName.c_str());
    ifile.read((char*)&student, sizeof(student));
    return student;
}

//read data from a file into a student academic object
StudentAcademic readAcademicFromFile(string filename){
    ifstream ifile;
    StudentAcademic student_a;
    ifile.open(filename.c_str());
    ifile.read((char*)&student_a, sizeof(student_a));
    return student_a;
}

//read data from a file into a student finance object
StudentFinance readFinanceFromFile(string filename){
  ifstream ifile;
  StudentFinance student_f;
  ifile.open(filename.c_str());
  ifile.read((char*)&student_f, sizeof(student_f));
  return student_f;
}

//read data from a file into an alumni object
Alumni readAlumFile(string filename){
  ifstream ifile;
  Alumni a;
  ifile.open(filename.c_str());
  ifile.read((char*)&a, sizeof(a));
  return a;
}

//remove a line from a file, used to delete a key record from the key file
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

//convert a student file to an alumni file when transferred to the alumni database
void convert_to_alumni_file(string uid, Alumni a){
  ofstream temp;
  ifstream ifile;
  string fil = "db/"+uid+".txt";
  temp.open("db/temp.txt", ios::app | ios::binary);
  ifile.open(fil.c_str());
  temp.write((char*) &a, sizeof(a));
  remove(fil.c_str());
  rename("db/temp.txt", fil.c_str());
}

//transfer key reference from student key file to alumni key file
void transfer_key(string uid){
  ofstream akfile;
  ifstream skfile;
  skfile.open("db/key.txt");
  akfile.open("db/key_al.txt", ios::app);
  string line;
  while(getline(skfile, line)){
    istringstream inpstr(line);
    string word;
    inpstr>>word;
    if(word == uid){
      akfile<<line<<endl;
      removeLine(uid);
    }
  }
}
