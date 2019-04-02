#include <iostream>
#include <string>
#include "../include/hash_student.hpp"

using namespace std;

void student_map::addNewStudent(string uid){
    pair<string, string> p (uid, "/db/"+uid+".txt");
    studentMap.insert(p);
}

string student_map::retrieveStudentFile(string uid){
    return studentMap[uid];
}
