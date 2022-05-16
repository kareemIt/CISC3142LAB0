#include "Analysis.cpp"
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <fstream>

void printWithdrawRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateInstructor.txt");
    file << "Instructor, Students taking instructor, Total Students, Percentage of students withdrawal \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateCourse.txt");
    file << "Course, Students taking course, Total Students, Percentage of students withdrawal \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateTerm.txt");
    file << "Term, Students taking course, Total Students, Percentage of students withdrawal \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printPassRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateInstructor.txt");
    file << "Instructor, Students taking instructor, Total Students, Percentage of students pass \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateCourse.txt");
    file << "Course, Students taking course, Total Students, Percentage of students pass \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateTerm.txt");
    file << "Term, Students taking course, Total Students, Percentage of students pass \n";
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}


void write(){
    college brooklynCollege = read();

    //this writes all the information about passing 
    map<string, vector<double>> passRateInstructor = ratingForInstructor(&brooklynCollege, &passed);
    map<string, vector<double>> passRateCourse = ratingForCourse(&brooklynCollege, &passed);
    map<string, vector<double>> passRateTerm = ratingForTerm(&brooklynCollege, &passed);

    printPassRateInstructor(&passRateInstructor);
    printPassRateCourse(&passRateCourse);
    printPassRateTerm(&passRateTerm);

    //this writes all the information about withdraw
    map<string, vector<double>> withdrawRateInstructor = ratingForInstructor(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateCourse = ratingForCourse(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateTerm = ratingForTerm(&brooklynCollege, &withdrew);

    printWithdrawRateInstructor(&withdrawRateInstructor);
    printWithdrawRateCourse(&withdrawRateCourse);
    printWithdrawRateTerm(&withdrawRateTerm);




}