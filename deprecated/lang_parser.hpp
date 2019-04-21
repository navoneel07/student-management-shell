#include <vector>
#include <string>
#include<unordered_map>
#include "../include/student.hpp"

std::vector<std::string> tokenizer(std::string);
//works
int precedence(std::string);
//works
bool expressionEvaluate(std::string, Student);
//works
bool booleanEvaluate(bool, bool, std::string);

bool commandEvaluate(std::vector<std::string>, Student);

void commandParser(std::vector);
