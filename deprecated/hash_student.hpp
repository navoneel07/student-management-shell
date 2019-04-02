#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class student_map{
    unordered_map<string, string> studentMap;
public:
    void addNewStudent(string);
    string retrieveStudentFile(string);
};
