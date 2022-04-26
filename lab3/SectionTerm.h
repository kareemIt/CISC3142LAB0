#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct term {
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
    string classId; 
    string courseNumber; 
    string sectionNumber; 
    string instructorId; 
    string term; 
    vector<string> students; 

    section(string classId, string courseNumber, string sectionNumber, string instructorId, string term) {
        this->classId = classId;
        this->courseNumber = courseNumber;
        this->sectionNumber = sectionNumber;
        this->instructorId = instructorId;
        this->term = term;
    }

    void addStudent(string emplid) {
        students.push_back(emplid);
    }
};
