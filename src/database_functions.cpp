#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <sstream>
#include "../include/file_functions.hpp"
#include "../include/database_functions.hpp"
#include "../include/student.hpp"
#include "../include/qlang.hpp"


using namespace std;

//print student table header
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

//print alumni table header
void alumniTableHeader(){
  cout<<left<<setw(14)<<"UID"
  <<left<<setw(20)<<"NAME"
  <<left<<setw(12)<<"FACULTY"
  <<left<<setw(14)<<"CURRICULUM"
  <<left<<setw(18)<<"YEAR OF GRAD"
  <<left<<setw(18)<<"CLASSIFICATION"
  <<left<<setw(12)<<"FINAL CGPA"<<endl;
  cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
}

//print entire table
void viewTable(unordered_map<string, string> studentMap){
    tableHeader();
    for(auto &s : studentMap){
        Student student = readStudentFromFile(s.second);
        student.viewStudent();
    }
}

//print entire alumni table
void viewAlumTable(unordered_map<string, string> alumMap){
  alumniTableHeader();
  for(auto &a : alumMap){
      Alumni alum = readAlumFile(a.second);
      alum.viewAlumni();
  }
}

//to add new studet to database
void addNewStudentToDatabase(){
    Student student;
    StudentAcademic student_a;
    StudentFinance student_f;
    student.newStudent();
    student_a.newStudentAcademic();
    student_f.newStudentFinance();
    writeStudentToFile(student, student_a, student_f);
    cout<<"\nNew student added!\n";
}

//search for a student in the database
void searchStudent(unordered_map<string, string> studentMap, unordered_map<string, string> courseMap, string search_cmd) {
    for(auto &s : studentMap){
        Student student = readStudentFromFile(s.second);
        if(expressionEvaluate(search_cmd, student)){
            tableHeader();
            student.viewStudent();
            StudentAcademic s_a = readAcademicFromFile("db/"+student.getUID()+"_a.txt");
            StudentFinance s_f = readFinanceFromFile("db/"+student.getUID()+"_f.txt");
            cout<<"\nExpand the student? (Y/N): ";
            char ch;
            cin>>ch;
            switch(ch){
                case 'Y': s_a.viewStudentAcademic(courseMap);
                          s_f.viewStudentFinance();
                          break;
                case 'N':
                          break;
                default: cout<<"Invalid Choice!";
                          break;
            }
            return;
        }
    }
    cout<<"\nNo such student found!";
}

//filter students in the database
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

//delete student from database
void deleteStudent(unordered_map<string, string> &studentMap, string uid){
    removeLine(uid);
    mapInit(studentMap, "db/key.txt");
}

//sort students according to a key field
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

//modifies a student record
void modify(unordered_map<string, string> studentMap, string command){
    vector<string> commandTokens = tokenizer(command);
    string field, value;
    Student student = readStudentFromFile(studentMap[commandTokens[0]]);
    field = commandTokens[1].substr(0, commandTokens[1].find('='));
    value = commandTokens[1].substr(commandTokens[1].find('=') + 1, commandTokens[1].length()-1-commandTokens[1].find('='));
    student.setData(field, value);
    modifyFile(student, studentMap);
    cout<<"Student data modified!\n";
}

//launch command line mode
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

//convert a student to alumni
Alumni convert_to_alumni(Student s){
  string temp;
  Alumni a;
  a.setUID(s.getData("uid"));
  a.setName(s.getData("name"));
  cout<<"\nEnter year of graduation: ";
  cin>>temp;
  a.setGrad(temp);
  a.setFac(s.getData("faculty"));
  a.setCur(s.getData("curriculum"));
  cin.ignore(256, '\n');
  cout<<"\nEnter Graduation Classification: ";
  getline(cin, temp);
  a.setGradClass(temp);
  cout<<"\nEnter Final CGPA: ";
  cin>>temp;
  a.setFinCGPA(temp);
  return a;
}

//transfer a student to the alumni database
void transfer(string uid, unordered_map<string, string> studentMap){
  string fil = "db/"+uid+".txt";
  Student s = readStudentFromFile(fil.c_str());
  Alumni a = convert_to_alumni(s);
  convert_to_alumni_file(uid, a);
  transfer_key(uid);
  mapInit(studentMap, "db/key.txt");
  cout<<"Student transferred!";
}
