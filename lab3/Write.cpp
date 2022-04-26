#include "Analysis.cpp"
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <fstream>

void printWithdrawRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateInstructor.txt");

    file.close();

}

void printWithdrawRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateCourse.txt");

    file.close();

}

void printWithdrawRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateTerm.txt");

    file.close();

}

void printWithdrawRateSpring(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateSpring.txt");

    file.close();

}

void printWithdrawRateFall(map<string,vector<double>>* m){
    ofstream file;
    file.open("WithdrawRateFall.txt");
    for(const auto& terms:*m){
        file << terms.first << endl;
    }

    file.close();

}
void printPassRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateInstructor.txt");

    file.close();

}
void printPassRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateCourse.txt");

    file.close();

}
void printPassRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateTerm.txt");

    file.close();

}
void printPassRateSpring(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateSpring.txt");

    file.close();

}
void printPassRateFall(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateFall.txt");

    file.close();

}



int write(){
    college brooklynCollege = read();
    
    map<string, vector<double>> passRateInstructor = ratingForInstructor(&brooklynCollege, &passed);
    map<string, vector<double>> passRateCourse = ratingForCourse(&brooklynCollege, &passed);
    map<string, vector<double>> passRateTerm = ratingForTerm(&brooklynCollege, &passed);
    map<string, vector<double>> passRateSpring = ratingForCourse(&brooklynCollege, &passed);
    map<string, vector<double>> passRateFall = ratingForTerm(&brooklynCollege, &passed);

    printPassRateInstructor(&passRateInstructor);
    printPassRateCourse(&passRateCourse);
    printPassRateTerm(&passRateTerm);
    printPassRateSpring(&passRateSpring);
    printPassRateFall(&passRateFall);

    map<string, vector<double>> withdrawRateInstructor = ratingForInstructor(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateCourse = ratingForCourse(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateTerm = ratingForTerm(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateSpring = ratingForCourse(&brooklynCollege, &withdrew);
    map<string, vector<double>> withdrawRateFall = ratingForTerm(&brooklynCollege, &withdrew);

    printWithdrawRateInstructor(&withdrawRateInstructor);
    printWithdrawRateCourse(&withdrawRateCourse);
    printWithdrawRateTerm(&withdrawRateTerm);
    printWithdrawRateSpring(&withdrawRateSpring);
    printWithdrawRateFall(&withdrawRateFall);
    return 0;
}