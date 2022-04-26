#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>
#include "Read.cpp"

using namespace std;


bool passed(string grade) {
    unordered_set<string> passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR", "C-", "D+", "D", "D-", "P"};
    return passing.count(grade);
}
bool withdrew(string grade) {
    unordered_set<string> withdrawals = {"W", "WN", "WD", "WU"};
    return withdrawals.count(grade);
}
bool spring(string grade) {
    unordered_set<string> spring = {"T04","T05","T07","T08","T09","T11"};
    return spring.count(grade);
}
bool fall(string grade) {
    unordered_set<string> fall = {" T12","T13","T15","T16","T17","T19"};
    return fall.count(grade);
}




map<string, vector<double>> ratingForCourse(college* brookylnCollege, bool (*criterion)(string)) {
    double hit;
    double total;
    double studentTotal = 0;
    string courseNumber;
    vector<double> hitRate;
    map<string, vector<double>> ratePerCourse;

    unordered_map<string, section*>* courses = brookylnCollege->getCourses();
    unordered_map<string, student*>* students = brookylnCollege->getStudents();
    cout << "1";


    for(const auto& c : *courses) {
        hit = 0;
        total = 0;
        hitRate = {};
        courseNumber = c.second->courseNumber;
        for (const auto& s : c.second->students) {
            hit += criterion(students->at(s)->classes.at(c.first));
            total++;
        }

        if(ratePerCourse.count(courseNumber)) {
            ratePerCourse[courseNumber][0] += hit;
            ratePerCourse[courseNumber][1] += total;
        } else {
            hitRate.push_back(hit);
            hitRate.push_back(total);
            ratePerCourse[courseNumber] = hitRate;
        }
        studentTotal += total;
    }

    vector<string> courseNumbers = {"1115", "3115", "3130"};
    for (string s : courseNumbers) {
        ratePerCourse[s].push_back(ratePerCourse[s][0] / ratePerCourse[s][1]);
    }
    cout << "7";

    return ratePerCourse;
}

map<string, vector<double>> ratingForInstructor(college* brookylnCollege, bool (*criterion)(string)) {
    double hit;
    double total;
    double studentTotal = 0;
    vector<double> passRate;
    map<string, vector<double>> ratePerInstructor;
    
    unordered_map<string, section*>* courses = brookylnCollege->getCourses();
    unordered_map<string, student*>* students = brookylnCollege->getStudents();
    unordered_map<string, instructor*>* instructors = brookylnCollege->getInstructors();
    
    for(const auto& i : *instructors) {
        hit = 0;
        total = 0;
        passRate = {};
        for (const auto& c : i.second->classes) {
            for(string s : courses->at(c)->students) {
                hit += criterion(students->at(s)->classes[c]);
                total++;
            }
        }
        passRate.push_back(hit);
        passRate.push_back(total);
        passRate.push_back(double (hit)/total);
        ratePerInstructor[i.first] = passRate;
        studentTotal += total;
    }
    cout << "5";
    return ratePerInstructor;
}
map<string, vector<double>> ratingForTerm (college* brookylnCollege, bool (*criterion)(string)) {
    double studentAttentendingSpring = 0;
    double studentSpringTotal = 0;
    double studentAttendingFall = 0;
    double studentFallTotal = 0;
    double studentTotal = 0;
    vector<double> passRate;
    map<string, vector<double>> passRatePerTerm = {
        {"Spring", {0, 0, 0}}, {"Fall", {0, 0, 0}}
    };
    
    unordered_map<string, section*>* courses = brookylnCollege->getCourses();
    unordered_map<string, student*>* students = brookylnCollege->getStudents();
    unordered_map<string, term*>* terms = brookylnCollege->getTerms();
    
    for(const auto& i : *terms) {
        passRate = {};
        for (string c : i.second->courses) {
            for(string s : courses->at(c)->students) {
               if (fall(i.second->termId)) {
                    studentAttendingFall += criterion(students->at(s)->classes[c]);
                    studentFallTotal++;
                } else if(spring(i.second->termId)) {
                    studentAttentendingSpring += criterion(students->at(s)->classes[c]);
                    studentSpringTotal++;
                }
                studentTotal++;
            }
        }
    }
    passRatePerTerm["Spring"][0] = studentAttentendingSpring;
    passRatePerTerm["Spring"][1] = studentSpringTotal;
    passRatePerTerm["Spring"][2] = studentAttentendingSpring/studentSpringTotal;

    passRatePerTerm["Fall"][0] = studentAttendingFall;
    passRatePerTerm["Fall"][1] = studentFallTotal;
    passRatePerTerm["Fall"][2] = studentAttendingFall/studentFallTotal;

    cout << "6";
    return passRatePerTerm;
}

