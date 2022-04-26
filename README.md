# CISC3142LAB0
## lab3

### Build instructions
1.Clone the repository 

git clone https://github.com/kareemIt/CISC3142LAB0

2.Then we can move into the repository

cd CISC3142LAB0

3.After we can move into lab3

cd lab3

4.Call the makefile

make lab3

5.Finally run the complied file

./fileout

### Evidence of articulating the problem
In this problem, I have to parse 3 CSV files and make files that give out information about students, instructors, courses, and pass rates. To do this first I need to parse through the CSV files and take note of the courses, students, instructors, and terms. Then I have to make four structs to keep track of the information. Then assign the right values to a map then later run an algorithm to get the pass rate for the students/instructors, then withdrawal rates, then both for the spring and fall semester. Finally, after the information is formatted properly I can print them out in separate files to show the user the rates of each situation. I will have to keep in mind that I need to parse the CSV files carefully if I miss up gathering the information I can mess up the whole problem.

### Evidence of problem-solving technique
First I need to get the CSV files so I need to use .gitmodules and use the link provided so I can call on the CSV files. Second I need to make structs for courses, students, instructors, and terms. Third, I can start going through the CSV files and start adding them to an unordered map to help me easily call and use the information I got for later. Fourth I use ratingForInstructor, rating for the course,ratingForInstructor,ratingForTerm what this does is parse through the unordered map I used to help me get the desired information I need such as how many students took a class, and what percentage of them passed the class. Finally, I call on my write.CPP makes files corresponding to what information is needed such as pass rate per instructor, withdraw rate per instructor, and more. When this is done the user can see the statistics within each of the files.


## Evidence of articulating the solution
In this problem, I use a combination of structs, classes, unordered maps, maps, vectors, file reading, and writing. The use of the structs and classes is so I can use the getters so I can get certain information from a struct to make it easier to use what information I need to answer the problem. The use of unordered maps, maps, and vectors is so I can keep my information stored in a data structure so I can have easy access to it when I use it later to find the data I need to answer the question. I use file reading and writing is so that I can read the CSV files so I can get the information and then I can populate the unordered maps, maps, vectors, and writing so then I can when I get the data needed to answer the question  I can print them out in a file where the users can easily access the files and read the information. When these elements are used together I can read the CSV files then put them in a map, later using structs to access the information, after receiving the correct information I can write the information to a file and display it to the user.

## lab2

## Build instructions
1.Clone the repository 

git clone https://github.com/kareemIt/CISC3142LAB0

2.Then we can move into the repository

cd CISC3142LAB0

3.After we can move into lab2

cd lab2

4.Call the makefile

make lab2

5.Finally run the complied file

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
In this problem I have to make a calculator that has the functions addition,subtraction,division,multiplication,square root,and exponent.So what I am planning on doing is be able to take in user input first then setup a switch case statement that will be dependented on the type of operation a person would like to do.I will use enums to keep track of the operations that are avabile to the person.Also keep in mind edge cases where people may put any but a number.Finally make sure that the instructions for a person are understandable to follow.This could also be done by making the calcultor simplier in desgin so the user can use it without confusion.

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

