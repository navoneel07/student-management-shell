# StudentManage
## A Project for CSII

A student management system for the student body of HKU written in C++11, made for the course ENGG1340.

**Abstract**
HKU has a large body of students, both current and previous. It is quite imperative to have a system to effectively and efficiently manage all students so as have relevant and accurate student data at hand. This project aims to create such an information and management system using C++11. A basic student member would have data associated such as:
    UID [Primary key]
    Name
    Year
    Faculty
    Curriculum
    Status [Fulltime/ Exchange] --> if exchange, then Home Institution

Upon running a query on a particular student, Further data is shown divided into:
    **Academic**
        Show all courses past and current
        Show courses pending for approval
        Give GPA for previous semester, Current expected GPA bases on linear regression and current CGPA
        Show total credits accumulated

    **Financial**
        Show due payments - the amount, due date and overdue, **if any**
        Show past payments

Basic **features** of the system include:
1. Add a new student (upon admission)
2. Show all students
3. sort by criteria and filter out specific students according to a criteria
4. Search for a specific student.
5. modify student record, including approval of courses, posting of grades, calculating new GPA etc.
6. Delete/transfer a student depending upon the situation: delete when drop-out and transfer when pass out from the current to alumni database.

For alumni, it’s more or less the same, except GPA is unmodifiable, and new fields like year of graduation etc will be available.
