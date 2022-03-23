# CISC3142LAB0
## lab2

## Build instructions
First we clone the repository 
git clone https://github.com/kareemIt/CISC3142LAB0
Then we can move into the repository
cd CISC3142LAB0
After we can move into lab2
cd lab2
Call the makefile
make lab2
Finally run the complied file
./fileout

### Test Cases
1. 1+1=2

![image](https://user-images.githubusercontent.com/49353198/159611582-6b5b9fdb-be97-4c71-a825-0da15e5ccf3e.png)

2. 2-2=0

![image](https://user-images.githubusercontent.com/49353198/159611782-b67b59d4-e452-4364-ab47-9f4c01ffc8e1.png)

3. 3*1=3

![image](https://user-images.githubusercontent.com/49353198/159611816-e65a8496-8b85-4f03-a029-c8c7cf993868.png)

4. 4/2=2

![image](https://user-images.githubusercontent.com/49353198/159611847-bae3c409-dce3-4113-9e06-ac08285c5fd9.png)

5. 5^2=25

![image](https://user-images.githubusercontent.com/49353198/159611910-5114ff93-e9dd-473a-87c3-54cd6bff074d.png)

6. sqrt(4)=2

![image](https://user-images.githubusercontent.com/49353198/159614814-8ac6681c-54a0-4102-8d51-9b1c3c66318b.png)



### Evidence of articulating the problem
In this problem I have to make a calculator that has the functions addition,subtraction,division,multiplication,square root,and exponent.

### Evidence of problem-solving technique
In main there is three variables firstInput, secondInput,mode, then the user is prompted with the choice of operation they want to do so then mode is updated but if the input they put in isnt a number then it stops the program, a same process then happens to firstInput and secondInput. After this values get updated the Calculator Struc is called which takes in firstInput,secondInput,mode. Inside of the Calculator struc there are three local values called firstNum,secondNum,userMode which get updated by firstInput,secondInput,mode.Then a switch case gets called taking in userMode then depending on the number userMode is, is what operation ends up happening.After that it returns a value that has gone through the case then gets printed out for the user to see


## Evidence of articulating the solution
In this problem I used enums to represent the operations in the calculator, such as     
    Add = 1,
    Subtract = 2,
    Multiply = 3,
    Divide = 4,
    Sqrt = 5,
    Exponent = 6 
the point of this is when the user inputs what mode they want to use, the userinput is compared to the enum values and then excutes the command depending on the input.
This is apart of the struc Calculator, in this struc we have first number,second number, user mode along with I have a constructor that takes in userinput and updates first number, second number, user mode. Then in the struc there is a switch case that checks the usermode with the enums operations and does the respective operation.


