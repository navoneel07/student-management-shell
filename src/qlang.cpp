#include <vector>
#include <string>
#include<unordered_map>
#include "../include/student.hpp"
#include<iostream>
#include<sstream>
using namespace std;

//temolate class to create stack using linked list(using pointers)
template <typename T>
class Stack{
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
public:
    Stack(){
        head = nullptr;
    }
    bool empty(){return head == nullptr;}
    void push(T val){
        Node* temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        if(head!=nullptr){
            temp->next = head;
        }
        head = temp;
    };
    void pop(){
        Node* temp;
        temp = head;
        head = head->next;
        delete temp;
    };
    T top(){return head-> data;}
};

//tokenizes an input string
vector<string> tokenizer(string command){
    vector<string> statement;
    string token;
    istringstream inpstr(command);
    while(inpstr>>token){
        statement.push_back(token);
    }
    return statement;
}

//define precedence of the operators
int precedence(string op){
    if(op == "|"){return 1;}
    else if(op == "&"){return 2;}
    return -1;
}

//evaluate an equality expression to be true or false
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

//evaluate boolean statements which have & and | (and and or)
bool booleanEvaluate(bool val1, bool val2, string op){
    if(op == "&"){return val1 && val2;}
    else if(op == "|"){return val1 || val2;}
    return false;
}

//evaluate a tokenized and booleanized command using stacks to evaluate the infix expression
bool commandEvaluate(vector<string> expressions, Student student){
    Stack<bool> values;
    Stack<string> ops;
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
