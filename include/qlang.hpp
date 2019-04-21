#include <vector>
#include <string>
#include<unordered_map>
#include "../include/student.hpp"

using namespace std;

vector<string> tokenizer(string);

int precedence(string);

bool expressionEvaluate(string, Student);

bool booleanEvaluate(bool, bool, string);

bool commandEvaluate(vector<string>, Student);
