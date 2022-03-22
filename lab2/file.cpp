#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Calculator {
  double firstNum;
  double secondNum;
  int userMode;
  //keeps tracks of the operations as enums with set values
  enum Operation { Add = 1, Subtract = 2, Multiply = 3, Divide = 4, Sqrt = 5,Exponent = 6 };

//takes in the user inputs and sets them to local variables for doing operartions
  Calculator(double firstInput,double secondInput,int modeInput){
      firstNum = firstInput;
      secondNum = secondInput;
      userMode = modeInput;
  }
//Takes in the user inputed mode then chooses the right action depending on what they put in or default to -1
  int calculate(int userMode) {
      switch (userMode){
      case Operation::Add:
          return firstNum + secondNum;
          break;
       case Operation:: Subtract:
          return firstNum - secondNum;
          break;
       case Operation::  Multiply:
          return firstNum * secondNum;
          break;
        case Operation::  Divide:
          return firstNum / secondNum;
          break;
        case Operation:: Sqrt:
          return sqrt(firstNum);
          break;
        case Operation:: Exponent:
          return pow(firstNum,secondNum);
          break;              
      default:
          return -1;
          break;
      }
  }
};

int main() {
    double firstInput;
    double secondInput;
    int mode;

    //displays options for the users and takes in user input
    cout << "Input a number into the following";
    cout << "Calculator options:\n Addtion: 1  \n Subtractions: 2 \n Multiply: 3 \n Divide: 4 \n Square Root: 5 \n Exponent: 6 \n";
    cin >> mode; 
    cout << "Input your first number \n";
    cin >> firstInput;

    // if(isNumber(firstInput)){
    //   cout << "Your first input is not a number";
    //   return -1;
    // }

    if(mode != 5) {
    cout << "Input your Second number \n";
    cin >> secondInput;
    }

    // if(isNumber(secondInput)){
    //   cout << "Your second input is not a number";
    //   return -1;
    // }
    
    Calculator answer = Calculator(firstInput,secondInput,mode);

    //displays the answer for the user
    cout <<"Your final answer: " <<answer.calculate(mode);
    return 0;
}
