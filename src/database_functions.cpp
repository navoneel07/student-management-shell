#include <iostream>
#include <unordered_map>
#include "../include/file_functions.hpp"
#include "../include/database_functions.hpp"
#include "../include/student.hpp"
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/*============== A Simple Query Parser ============================*/

vector<string> tokenizer(string command){
    vector<string> statement;
    string token;
    istringstream inpstr(command);
    while(inpstr>>token){
        statement.push_back(token);
    }
    return statement;
}

int precedence(string op){
    if(op == "|"){return 1;}
    else if(op == "&"){return 2;}
    return -1;
}

bool expressionEvaluate(string expression, Student student){
    string field, value;
    value = expression.substr(expression.find('=')+1, expression.length()-expression.find('='));

    if((expression.find("!=")+1) > 0){
        field = expression.substr(0, (expression.find('=') - 1));
        return !(student.getData(field) == value);
    }
    else{
        field = expression.substr(0, (expression.find('=')));
        return student.getData(field) == value;
    }
    return false;
}

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

/*==============  End here : A Simple Query Parser ================*/

void addNewStudentToDatabase(){
    Student student;
    student.newStudent();
    writeStudentToFile(student);
}

void searchStudent(unordered_map<string, string> studentMap) {
    string uid;
    cout<<"Enter UID: ";
    cin>>uid;
    if(studentMap.find(uid) == studentMap.end()){
        cout<<"No such student record exists! Exiting...\n";
        exit(1);
    }
    else{
        string fileName = studentMap[uid];
        Student student = readStudentFromFile(fileName);
        student.viewStudent();
    }
}

void filterStudent(unordered_map<string, string> studentMap){
    int flag = 0, count = 0;
    Student student;
    string cmd;
    cout<<"Enter command for filtering: \n>>> ";
    getline(cin, cmd);
    cmd+=' ';

    vector<string> commands = tokenizer(cmd);

    for(auto i:studentMap){
        student = readStudentFromFile(i.second);
        if(commandEvaluate(commands, student)){
            student.viewStudent();
            flag = 1;
            count++;
        }
        else{continue;}
    }

    if(flag == 0){
        cout<<"No such student exists!\n\n";
    }
    else{
        cout<<"====================================\nTotal records matched = "<<count<<"\n====================================\n\n";
    }

}
