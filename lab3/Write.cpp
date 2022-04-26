#include "Analysis.cpp"
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <fstream>

void printWithdrawRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateInstructor.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateCourse.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateTerm.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateSpring(map<string,vector<double>>* m){
    ofstream file;
    file.open("withdrawRateSpring.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}

void printWithdrawRateFall(map<string,vector<double>>* m){
    ofstream file;
    file.open("WithdrawRateFall.txt");
    for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }
    file.close();

}
void printPassRateInstructor(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateInstructor.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateCourse(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateCourse.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateTerm(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateTerm.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateSpring(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateSpring.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}
void printPassRateFall(map<string,vector<double>>* m){
    ofstream file;
    file.open("passRateFall.txt");
     for(const auto& t:*m){
        file << t.first << ": "<< t.second[0] << "," << t.second[1] << "," <<  t.second[2] << endl;
    }

    file.close();

}



void write(){
    cout << "3";
    college brooklynCollege = read();
    
    map<string, vector<double>> passRateInstructor = ratingForInstructor(&brooklynCollege, &passed);
    map<string, vector<double>> passRateCourse = ratingForCourse(&brooklynCollege, &passed);
    map<string, vector<double>> passRateTerm = ratingForTerm(&brooklynCollege, &passed);
    map<string, vector<double>> passRateSpring = ratingForCourse(&brooklynCollege, &passed);
    map<string, vector<double>> passRateFall = ratingForTerm(&brooklynCollege, &passed);

    cout << "4";
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



}