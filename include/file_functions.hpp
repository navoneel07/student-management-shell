#include "../include/student.hpp"

void writeStudentToFile(Student, StudentAcademic);
void mapInit(std::unordered_map<std::string, std::string>&, std::string);
void clearKeys();
void modifyFile(Student student, std::unordered_map<std::string, std::string>);
Student readStudentFromFile(std::string);
StudentAcademic readAcademicFromFile(std::string);
void removeLine(std::string);
