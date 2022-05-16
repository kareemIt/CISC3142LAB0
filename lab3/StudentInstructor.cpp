#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct instructor {
    //struct to keep track of the instructor's instructorId,classes. adds courses to instructor
    string instructorId;
    unordered_set<string> classes;  

    instructor (string instructorId, string course) {
        this->instructorId = instructorId;
        classes.insert(course);
    }
    
    void addCourse(string course) {
        classes.insert(course);
    }
};


struct student { 
    //struct to keep track of student's emplId,courses,and grades. Also adds courses to student
    string emplId;
    unordered_map<string, string> classes; 

    student(string emplId, string course, string grade) {
        this->emplId = emplId;
        classes[course] = grade;
    }

    void addCourse(string course, string grade) {
        classes[course] = grade;
    }
};
