#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <ctime>
#include "College.cpp"

using namespace std;

college read() {
    ifstream inStream;

    vector <string> files = {"1115.csv", "3115.csv", "3130.csv"};
    college brooklynCollege;

    for (string file : files) {
        inStream.open("../datas/" + file);
        if (inStream.good()) {    
            string header;
            inStream >> header;
            stringstream head (header);
            string column;

            int header_length = 0;
            while (getline(head, column, ',')) {
                header_length++;
            }

            if (header_length != 6) {
                throw runtime_error ("One or more of the .csv files is incorrectly formatted (missing columns).");
            }

            string lines;
            string emplId;
            string courseNumber;
            string instructorId;
            string termId;
            string sectionCode;
            string grade;

            while (inStream >> lines) {
                stringstream line (lines);
                getline(line, emplId, ',');
                getline(line, courseNumber, ',');
                getline(line, instructorId, ',');
                getline(line, termId, ',');
                getline(line, sectionCode, ',');
                getline(line, grade);

                string classId = termId + '.' + courseNumber + '.' + sectionCode;
                section* currentSection = brooklynCollege.getSection(classId);
                term* currentTerm = brooklynCollege.getTerm(termId);
                if(!currentSection) {
                    currentSection = new section (classId, courseNumber, sectionCode, instructorId, termId);
                    brooklynCollege.scheduleCourse(classId, currentSection);
                }

                if(!currentTerm) {
                    currentTerm = new term(termId, classId);
                    brooklynCollege.scheduleTerm(termId, currentTerm);
                }
                
            
                currentSection->addStudent(emplId);
                currentTerm->addCourse(classId);
            
                brooklynCollege.enrollStudent(emplId, classId, grade);
                brooklynCollege.assignInstructor(instructorId, classId);
            }
        }
        inStream.close();
    }

    return brooklynCollege;
}
