/*
Header file for each of the student data items. Contains class defintion along with
member functions such as Add etc.
*/

#include <string>

using namespace std;

class Student{
    unsigned int uid;           //10-digit UID
    string name;                //Name of student
    int year;                   //Year of study
    string faculty;             //Faculty of study
    string curriculum;          //Curriculum of study
    string status;              //Exchange or full-time
    string nationality;         //Nationality of student
    string res_status;          //Residential status

public:
    void newStudent();          //function for adding a new student
};
