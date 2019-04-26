#include "../include/student.hpp"

void writeStudentToFile(Student, StudentAcademic, StudentFinance);
void mapInit(std::unordered_map<std::string, std::string>&, std::string);
void clearKeys();
void modifyFile(Student student, std::unordered_map<std::string, std::string>);
Student readStudentFromFile(std::string);
StudentAcademic readAcademicFromFile(std::string);
StudentFinance readFinanceFromFile(std::string);
Alumni readAlumFile(std::string);
void removeLine(std::string);
void convert_to_alumni_file(std::string, Alumni);
void transfer_key(std::string);
