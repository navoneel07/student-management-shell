#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sstream>
#include "../include/file_functions.hpp"
#include "../include/database_functions.hpp"
#include "../include/student.hpp"
#include "../include/qlang.hpp"


using namespace std;


void tableHeader(){
    cout<<left<<setw(14)<<"UID"
    <<left<<setw(20)<<"NAME"
    <<left<<setw(12)<<"YEAR"
    <<left<<setw(12)<<"FACULTY"
    <<left<<setw(14)<<"CURRICULUM"
    <<left<<setw(12)<<"STATUS"
    <<left<<setw(14)<<"NATIONALITY"
    <<left<<setw(12)<<"RES STATUS"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
}

void viewTable(unordered_map<string, string> studentMap){
    tableHeader();
    for(auto &s : studentMap){
        Student student = readStudentFromFile(s.second);
        student.viewStudent();
    }
}

void addNewStudentToDatabase(){
    Student student;
    StudentAcademic student_a;
    student.newStudent();
    student_a.newStudentAcademic();
    writeStudentToFile(student, student_a);
    cout<<"\nNew student added!\n";
}

void searchStudent(unordered_map<string, string> studentMap, unordered_map<string, string> courseMap, string search_cmd) {
    for(auto &s : studentMap){
        Student student = readStudentFromFile(s.second);
        if(expressionEvaluate(search_cmd, student)){
            tableHeader();
            student.viewStudent();
            StudentAcademic s_a = readAcademicFromFile("db/"+student.getUID()+"_a.txt");
            cout<<"\nView academic record of student? (Y/N): ";
            char ch;
            cin>>ch;
            switch(ch){
                case 'Y': s_a.viewStudentAcademic(courseMap);
                          break;
                case 'N': cout<<"Fuck you man!";
                          break;
                default: cout<<"Type karna aata h?";
                          break;
            }
            return;
        }
    }
    cout<<"\nNo such student found!";
}

void filterStudent(unordered_map<string, string> studentMap, string cmd){
    int flag = 0, count = 0;
    Student student;
    cmd+=' ';
    vector<string> commands = tokenizer(cmd);
    tableHeader();
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

void deleteStudent(unordered_map<string, string> &studentMap, string uid){
    removeLine(uid);
    mapInit(studentMap, "db/key.txt");
}

void sort(unordered_map<string, string> studentMap, string criteria){
    vector<pair<string, string> > criteria_vector;
    Student student;
    pair<string, string> temp;
    for(auto &s:studentMap){
        student = readStudentFromFile(s.second);
        temp.first = s.first;
        temp.second = student.getData(criteria);
        criteria_vector.push_back(temp);
    }

    int n = criteria_vector.size();

    //Bubble sort for right now :>

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i -1 ; j++) {
            if(criteria_vector[j].second > criteria_vector[j+1].second){
                pair<string, string> temp;
                temp = criteria_vector[j];
                criteria_vector[j] = criteria_vector[j+1];
                criteria_vector[j+1] = temp;
            }
        }
    }
    tableHeader();
    for(auto &s : criteria_vector){
        student = readStudentFromFile(studentMap[s.first]);
        student.viewStudent();
    }
}

void modify(unordered_map<string, string> studentMap, string command){
    vector<string> commandTokens = tokenizer(command);
    string field, value;
    Student student = readStudentFromFile(studentMap[commandTokens[0]]);
    field = commandTokens[1].substr(0, commandTokens[1].find('='));
    value = commandTokens[1].substr(commandTokens[1].find('=') + 1, commandTokens[1].length()-1-commandTokens[1].find('='));
    student.setData(field, value);
    modifyFile(student, studentMap);
    cout<<"Student data modified!";
}

void commandLineMode(unordered_map<string, string> studentMap, unordered_map<string, string> courseMap){
    cout<<"\n>>> ";
    string cmdline;
    getline(cin, cmdline);
    if(cmdline[0] == '$'){
        searchStudent(studentMap, courseMap, cmdline.substr(2, cmdline.length()-2));
    }
    else if(cmdline[0] == '%'){
        filterStudent(studentMap, cmdline.substr(2, cmdline.length()-2));
    }
    else if(cmdline[0] == '^'){
        sort(studentMap, cmdline.substr(2, cmdline.length()-2));
    }
    else if(cmdline[0] == '*'){
        modify(studentMap, cmdline.substr(2, cmdline.length()-2));
    }
    else if(cmdline[0] == '~'){
        deleteStudent(studentMap, cmdline.substr(2, cmdline.length()-2));
    }
    else if(cmdline[0] == '+'){
        addNewStudentToDatabase();
    }
    else if(cmdline[0] == '@'){
        viewTable(studentMap);
    }
    else if(cmdline == "exit"){
        exit(0);
    }
    else{
        cout<<"Command not found!\n";
    }
}
