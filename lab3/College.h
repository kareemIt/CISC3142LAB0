#include <iostream>
#include <unordered_map>
#include <vector>
#include "SectionTerm.h"
#include "StudentInstructor.cpp"


class college {
    //I use an unordered map to keep track of students,courses,instrucotors,and terms.
    unordered_map<string, student*> students;
    unordered_map<string, section*> courses;
    unordered_map<string, instructor*> instructors;
    unordered_map<string, term*> terms;

    public: 
    college() {};

    student* getStudent(string emplId);
    section* getSection(string classId);
    instructor* getInstructor(string instructorId);
    term* getTerm(string termId);

    void enrollStudent(string emplId, string course, string grade);
    void scheduleCourse(string course, section* currentSection);
    void assignInstructor(string instructorId, string course);
    void scheduleTerm(string termId, term* currentTerm);

    unordered_map<string, student*>* getStudents();
    unordered_map<string, section*>* getCourses();
    unordered_map<string, instructor*>* getInstructors();
    unordered_map<string, term*>* getTerms();

};