#include <iostream>
#include <unordered_map>
#include "../include/display.hpp"
#include "../include/database_functions.hpp"
#include "../include/file_functions.hpp"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define EXIT 13

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_map<string, string> studentMap;
    unordered_map<string, string> courseMap;
    unordered_map<string, string> alumMap;
    cout<<"Welcome! To the student manage system\n\nChoose the following actions: \n\n";
    displayMenu();
    int choice;
    cin>>choice;

    while(true){
        mapInit(studentMap, "db/key.txt");
        mapInit(courseMap, "data/course_codes.txt");
        mapInit(alumMap, "db/key_al.txt");
        if (choice == 1) {
            addNewStudentToDatabase();
        }
        else if (choice == 2) {
            string uid;
            cout<<"Enter UID of student to delete: ";
            cin>>uid;
            deleteStudent(studentMap, uid);
        }
        else if(choice == 3){
            viewTable(studentMap);
        }
        else if(choice  == 4){
            string uid, field, value, cmd;
            cout<<"Enter uid of student to modify: ";
            cin>>uid;
            cout<<"Enter field to modify: ";
            cin>>field;
            cout<<"Enter value of field: ";
            cin>>value;
            cmd = uid+" "+field+"="+value;
            modify(studentMap, cmd);
        }
        else if(choice == 5){
            string field, value, cmd;
            cout<<"Enter field by which to search: ";
            cin>>field;
            cout<<"Enter value of field to search: ";
            cin>>value;
            cmd = field+"="+value;
            searchStudent(studentMap, courseMap, cmd);
        }
        else if(choice == 6){
            string field;
            cout<<"Enter field by which to sort: ";
            cin>>field;
            sort(studentMap, field);
        }
        else if(choice == 7){
            string cmd;
            cout<<"Enter command for filtering: \n";
            cin.ignore(256, '\n');
            getline(cin, cmd);
            filterStudent(studentMap, cmd);
        }
        else if(choice == 8){
          string uid;
          cout<<"Enter UID of student to transfer to alumni database: ";
          cin>>uid;
          transfer(uid, studentMap);
        }
        else if(choice == 9){
          viewAlumTable(alumMap);
        }
        else if(choice == 10){
            system(CLEAR);
            cin.ignore(256, '\n');
            cout<<"Welcome to the qLang shell!";
            while(true){
                commandLineMode(studentMap, courseMap, alumMap);
            }
        }
        else if(choice == 11){
          grant_scholarship(studentMap);
        }
        else if(choice == 12){
          cout<<"Help is under construction! Please check back later...\n";
        }
        else if(choice == EXIT){
            break;
        }
        cout<<"---------------------------------------------------------------------------------------------------------------\n";
        displayMenu();
        cin>>choice;
    }
    cout<<"Thank you for using our software!\n";
    return 0;
}
