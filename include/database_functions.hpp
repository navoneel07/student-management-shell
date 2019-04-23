#include <unordered_map>

void tableHeader();
void addNewStudentToDatabase();
void searchStudent(std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::string>, std::string);
void filterStudent(std::unordered_map<std::string, std::string>, std::string);
void modify(std::unordered_map<std::string, std::string>, std::string);
void deleteStudent(std::unordered_map<std::string, std::string> &, std::string);
void sort(std::unordered_map<std::string, std::string>, std::string);
void viewTable(std::unordered_map<std::string, std::string>);
void commandLineMode(std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::string>);
