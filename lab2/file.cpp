#include <iostream>
#include <cmath>
using namespace std;

struct Calculator {
  double firstNum;
  double secondNum;
  int userMode;
  enum Operation { Add = 1, Subtract = 2, Multiply = 3, Divide = 4, Sqrt = 5,Exponent = 6 };

  Calculator(double firstInput,double secondInput,int modeInput){
      firstNum = firstInput;
      secondNum = secondInput;
      userMode = modeInput;
  }

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

    cout << "Calculator options:\n Addtion: 1  \n Subtractions: 2 \n Multiply: 3 \n Divide: 4 \n Square Root: 5 \n Exponent: 6 ";
    cin >> mode; 
    cout << "Input your first number \n";
    cin >> firstInput;
    if(mode != 5) {
    cout << "Input your Second num \n";
    cin >> secondInput;
    }
    Calculator answer = Calculator(firstInput,secondInput,mode);
    cout << answer.calculate(mode);
    return 0;
}
