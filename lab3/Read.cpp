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
    ifstream in_stream;

    vector <string> files = {"1115.csv", "3115.csv", "3130.csv"};
    college brooklynCollege;

    for (string file : files) {
        in_stream.open("../datas/" + file);
        if (in_stream.good()) {    
            string header;
            in_stream >> header;
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

            while (in_stream >> lines) {
                stringstream line (lines);
                getline(line, emplId, ',');
                getline(line, courseNumber, ',');
                getline(line, instructorId, ',');
                getline(line, termId, ',');
                getline(line, sectionCode, ',');
                getline(line, grade);

                string classId = termId + '.' + courseNumber + '.' + sectionCode;
                section* sect = brooklynCollege.getSection(classId);
                term* t = brooklynCollege.getTerm(termId);
                if(!sect) {
                    sect = new section (classId, courseNumber, sectionCode, instructorId, termId);
                    brooklynCollege.scheduleCourse(classId, sect);
                }

                if(!t) {
                    t = new term(termId, classId);
                    brooklynCollege.scheduleTerm(termId, t);
                }
                
            
                sect->addStudent(emplId);
                t->addCourse(classId);
            
                brooklynCollege.enrollStudent(emplId, classId, grade);
                brooklynCollege.assignInstructor(instructorId, classId);
            }
        }
        in_stream.close();
    }

    return brooklynCollege;
}
