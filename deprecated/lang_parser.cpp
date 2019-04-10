#include "../include/lang_parser.hpp"
#include "../include/file_functions.hpp"
#include "../include/student.hpp"
#include <stack>
#include <sstream>

vector<string> tokenizer(string command){
    vector<string> statement;
    string token;
    istringstream inpstr(command);
    while(inpstr>>token){
        statement.push_back(token);
    }
    return statement;
}
//works
int precedence(string op){
    if(op == "|"){return 1;}
    else if(op == "&"){return 2;}
    return -1;
}
//works
bool expressionEvaluate(string expression, Student student){
    string field, value;
    field = expression.substr(0, (expression.find('=')));
    value = expression.substr(expression.find('=')+1, expression.length()-expression.find('='));

    if(student.getData(field) == value){
        return true;
    }
    return false;
}
//works
bool booleanEvaluate(bool val1, bool val2, string op){
    if(op == "&"){return val1 && val2;}
    else if(op == "|"){return val1 || val2;}
    return false;
}

bool commandEvaluate(vector<string> expressions, Student student){
    stack <bool> values;
    stack <string> ops;
    for (auto expression : expressions) {
        if(isalpha(expression[0])){
            values.push(expressionEvaluate(expression, student));
        }

        else if(expression == "("){
            ops.push(expression);
        }

        else if(expression == ")"){
            while(!ops.empty() && (ops.top() != "(")){
                bool val1 = values.top();
                values.pop();
                bool val2 = values.top();
                values.pop();
                string op = ops.top();
                ops.pop();

                values.push(booleanEvaluate(val1, val2, op));
            }
            ops.pop();
        }

        else{
            while(!ops.empty() && precedence(ops.top())>=precedence(expression)){
                bool val1 = values.top();
                values.pop();
                bool val2 = values.top();
                values.pop();

                string op = ops.top();
                ops.pop();

                values.push(booleanEvaluate(val1, val2, op));
            }
            ops.push(expression);
        }
    }

    while(!ops.empty()){
        bool val1 = values.top();
        values.pop();
        bool val2 = values.top();
        values.pop();

        string op = ops.top();
        ops.pop();

        values.push(booleanEvaluate(val1, val2, op));
    }

    return values.top();
}
