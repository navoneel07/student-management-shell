# StudentManage
## A Project for CSII

A student management system for the student body of HKU written in C++11, made for the course ENGG1340.

**Abstract**

HKU has a large body of students, both current and previous. It is quite imperative to have a system to effectively and efficiently manage all undergraduate students so as have relevant and accurate student data at hand. This project aims to create such an information and management system using C++11. A basic student member would have data associated such as:

- UID [Primary key]
- Name
- Year
- Faculty
- Curriculum
- Status [Fulltime/ Exchange] --> if exchange, then Home Institution
- Residence status: University housing / Non-University housing

The queries will be divided into two in accordance to alumni body or current student body.

Upon running a query on a particular student, Further data is shown divided into:
- Academic
  - Show all courses past and current
  - Show courses pending for approval
  - Give GPA for previous semester and current CGPA
  - Show total credits accumulated

- Financial
  - Show due payments - the amount, due date and overdue, **if any**
  - Show past payments

Basic **features** of the system include:
- Add a new student (upon admission)
- Show all students
- Sort by criteria and filter out specific students according to a criteria
- Search for a specific student.
- Modify student record, including approval of courses, posting of grades, calculating new GPA etc.
- Delete/transfer a student depending upon the situation: delete when drop-out and transfer when pass out from the current to alumni database.
- Handling of housing requests: Assigning university housing based on preference list.

**Alumni system**

The skeletal fields for the alumni system remains the same. However we introduce some new fields, which include:
- Final CGPA
- Year of Graduation
- Graduation Classification [1st division, 2nd division]
- Status will be removed
- Residence status will be removed
