#include <iostream>
#include <unordered_map>
#include "../include/database_functions.hpp"
#include "../include/file_functions.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_map<string, string> studentMap;
    unordered_map<string, string> courseMap;

    cout<<"Welcome to the qLang shell";

    while(true){
        mapInit(studentMap, "db/key.txt");
        mapInit(courseMap, "data/course_codes.txt");
        commandLineMode(studentMap, courseMap);
    }
    return 0;
}
