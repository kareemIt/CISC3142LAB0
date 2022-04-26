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

    //opens the CSV files of 1115,3115,3130

    vector <string> files = {"1115.csv", "3115.csv", "3130.csv"};
    college brooklynCollege;

    //parses each of the files one at at time
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

            string lines;
            string emplId;
            string courseNumber;
            string instructorId;
            string termId;
            string sectionCode;
            string grade;

            while (inStream >> lines) {
                //keeps track of emplId,courseNumber,instructorId,termId,sectionCode,and grade 
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
