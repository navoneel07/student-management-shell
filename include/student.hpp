/*
Header file for each of the student data items. Contains class defintion along with
member functions such as Add etc.
*/

class Student{
    unsigned int uid;           //10-digit UID
    string name;                //Name of student
    int year;                   //Year of study
    string faculty;             //Faculty of study
    string curriculum;          //Curriculum of study
    string status;              //Exchange or full-time
    string nationality;         //Nationality of student
    string res_status;          //Residential status

public:
    Student(){                  //a class constructor
        uid = 0;
        name = NULL;
        year = 0;
        faculty = NULL;
        curriculum = NULL;
        status = NULL;
        nationality = NULL;
        res_status = NULL;
    }

    void addStudent();          //function for adding a new student
    void modifyStudent();       //to modify an already existing student

    ~Student(){                 //class destructor
        uid = 0;
        name = NULL;
        year = 0;
        faculty = NULL;
        curriculum = NULL;
        status = NULL;
        nationality = NULL;
        res_status = NULL;
    }
};
