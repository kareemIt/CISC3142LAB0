#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct term {
    //struct to keep track of the termId,courses. Also adds course
    string termId;
    unordered_set<string> courses;

    term() {}

    term (string termId, string course) {
        this->termId = termId;
        courses.insert(course);
    }

    void addCourse(string course) {
        courses.insert(course);
    }

};

struct section {
    string term;
    string classId; 
    string courseNumber; 
    string sectionNumber; 
    string instructorId; 

    vector<string> students; 

    section(string classId, string courseNumber, string sectionNumber, string instructorId, string term) {
        this->term = term;
        this->classId = classId;
        this->instructorId = instructorId;
        this->courseNumber = courseNumber;
        this->sectionNumber = sectionNumber;
    }

    void addStudent(string emplid) {
        students.push_back(emplid);
    }
};
