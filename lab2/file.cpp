//

#include <iostream>
#include <cmath>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Calculator
{
  double firstNum;
  double secondNum;
  int userMode;
  // keeps tracks of the operations as enums with set values
  enum Operation
  {
    Add = 1,
    Subtract = 2,
    Multiply = 3,
    Divide = 4,
    Sqrt = 5,
    Exponent = 6
  };

  // takes in the user inputs and sets them to local variables for doing operartions
  Calculator(double firstInput, double secondInput, int modeInput)
  {
    firstNum = firstInput;
    secondNum = secondInput;
    userMode = modeInput;
  }
  // Takes in the user inputed mode then chooses the right action depending on what they put in or default to -1
  int calculate(int userMode)
  {
    switch (userMode)
    {
    case Operation::Add:
      return firstNum + secondNum;
    case Operation::Subtract:
      return firstNum - secondNum;
    case Operation::Multiply:
      return firstNum * secondNum;
    case Operation::Divide:
      return firstNum / secondNum;
    case Operation::Sqrt:
      return sqrt(firstNum);
    case Operation::Exponent:
      return pow(firstNum, secondNum);
    default:
      return -1;
    }
  }
};

int main()
{
  double firstInput;
  double secondInput;
  int mode;

  // displays options for the users and takes in user input
  cout << "Input a number into the following\n";
  cout << "Calculator options:\n Addtion: 1  \n Subtraction: 2 \n Multiply: 3 \n Divide: 4 \n Square Root: 5 \n Exponent: 6 \n";
  cin >> mode;
  if (cin.fail())
  {
    cout << "Your inputted value is not a number";
    return -1;
  }
  cout << "Input your first number \n";
  cin >> firstInput;

  if (cin.fail())
  {
    cout << "Your first input is not a number";
    return -1;
  }

  if (mode != 5)
  {
    cout << "Input your Second number \n";
    cin >> secondInput;
  }

  if (cin.fail())
  {
    cout << "Your second input is not a number";
    return -1;
  }

  Calculator answer = Calculator(firstInput, secondInput, mode);

  // displays the answer for the user
  cout << "Your final answer: " << answer.calculate(mode);
  return 0;
}
