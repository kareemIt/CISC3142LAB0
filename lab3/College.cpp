#include "College.h"

//getters for Students
student* college::getStudent(string emplId) {
        return students[emplId]; 
}
unordered_map<string, student*>* college::getStudents() {
    return &students;
}

//getters for Instructor
instructor* college::getInstructor(string instructorId) {
    return instructors[instructorId]; 
}
unordered_map<string, instructor*>* college::getInstructors() {
    return &instructors;
}

//getters for Section
section* college::getSection(string classId) {
    return courses[classId];
}
unordered_map<string, section*>* college::getCourses() {
    return &courses;
}

//getters for Term
term* college::getTerm(string termId) {
    return terms[termId];
}
unordered_map<string, term*>* college::getTerms() {
    return &terms;
}


void college::enrollStudent(string emplId, string course, string grade) {
    if (!students.count(emplId)) {
        student* currentStudent = new student(emplId, course, grade);
        students[emplId] = currentStudent;
    } else {
        students[emplId]->addCourse(course, grade);
    }
}

void college::assignInstructor(string instructorId, string course) {
    if (!instructors.count(instructorId)) {
        instructor* currentInstructor = new instructor(instructorId, course);
        instructors[instructorId] = currentInstructor;
    } else {
        instructors[instructorId]->addCourse(course);
    }
}

void college::scheduleCourse(string course, section* currentSection) {
    courses[course] = currentSection;   
}

void college::scheduleTerm(string termId, term* currentTerm) {
    terms[termId] = currentTerm;
}
