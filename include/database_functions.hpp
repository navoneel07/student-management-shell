#include <unordered_map>
#include "../include/student.hpp"

void tableHeader();
void alumniTableHeader();
void addNewStudentToDatabase();
void searchStudent(std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::string>, std::string);
void filterStudent(std::unordered_map<std::string, std::string>, std::string);
void modify(std::unordered_map<std::string, std::string>, std::string);
void deleteStudent(std::unordered_map<std::string, std::string> &, std::string);
void sort(std::unordered_map<std::string, std::string>, std::string);
void viewTable(std::unordered_map<std::string, std::string>);
void viewAlumTable(std::unordered_map<std::string, std::string>);
void commandLineMode(std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::string>);
Alumni convert_to_alumni(Student);
void transfer(std::string, std::unordered_map<std::string, std::string>);
