#include <iostream>
#include <unordered_map>
#include "../include/database_functions.hpp"
#include "../include/file_functions.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_map<string, string> studentMap;
    mapInit(studentMap);
    filterStudent(studentMap);
    return 0;
}
