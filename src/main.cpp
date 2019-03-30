#include <iostream>
#include "../include/student.hpp"
#include "../include/file_functions.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Student student;
    student.newStudent();
    writeStudentToFile(student);
    return 0;
}
