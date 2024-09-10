# Tutorial 2 - Variables and Program Input/Output 

In this practical, we will build on last week’s work by enabling our programs to receive and respond to user input. By the end of this practical you should be familiar with: 

1.	Variables and data types in C++.  
2.	The std::cin function for reading data from the QWERTY keyboard into variables within our programs.  
3.	How to display variable values with std::cout.
4.	A basic loop for repeating blocks of code.  

## Getting stated
Ensure that your IAP::run function is empty, and that any work from last week is appropriately saved.

## Recap

We can use the std::out command to print text to the user:

```cpp
std::cout << "Hello Person";
```

## Variables

Write the following code into your main run function:

```cpp
int year = 2085; 
std::cout << "The Value of Year: " << year << "\n";
```


Check that it compiles and runs, and that the number is printed.

The first line of this program is called a variable declaration, and there is usually 4 parts. The first part is the type of variable we want to have, in this instance we have a variable of type int (see the bellow table for different types). The second part of this is the variables name, in this case we call it year. Part 3 is the assignment operator, used to give variables a value. And finally part 4 is the value we wish to assign, in this case 2085.

```cpp
(1) int	(2) year (3) = (4) 2085; 
```

We then use the std::cout command to print the value of the variable year. Note we can chain up as many messages and variables for printing as we like as long as we separate them by the << symbol.

We will use 3 main data types in IAP for storing data and these are, int, float and std::string. There are 2 other data types that you also might come across and these are included in the table for reference. Will not be using (bool, char) data types during this practical
    

Data Type | Description | Range of values
--- | --- | ---
int |	Store whole numbers, i.e. 1670, 5, 123985718275 |	-2147483648 to 2147483647 
float |	Store numbers with a decimal part. i.e. 0.76, 440.56 | 10^38 to −10^38 
std::string |	Store strings of characters, i.e. “IAP” , “I Love programming” | ASCII characters
bool | Stores true or false values only | True or false
char | Store single characters, i.e. ‘a’, ‘b’, ‘5’ | A single ASCII character

An example of using each of these is shown bellow.

```cpp
int age = 25;
std::string name = "Phill";
float height = 1.83;
bool btnState = true;
char decision = 'y';
```

There are many other data types, but we will explore these in detail in later practicals. 

## Data Input

By definition variables are designed to hold data that might change, but the examples so far have used data that is the same each time the program runs. One way to change the values of such variables by user input is to use the std::cin command.

```cpp
int age = 0;
std::cin >> age;
```

In the above code snippet we declare a variable called age of type int and give it an initial value of 0. To get the users input we use the std::cin command, followed by the >> symbol (note the direction of flow, we want to put data from the input into age). We then specify the variable that we want to write into.



## Exercise 1a: Basic input
Copy the following code into your run function.

```cpp
void IAP::run ()
{
    int age = 0;
    std::cout << "please enter your age\n";
    std::cin >> age;
    std::cout << "Your age is: " << age << "\n";
}
```

Note that as we are supply the value of the variable age via the std::cin command, therefore the value we supply on the first line (0) is not needed. However, it is ALWAYS good practice to give a variable a default value, in this case 0.


## Exercise 1b: Debugging
Debugging is a term that used to mean literally removing bugs from large computers to stop them gnawing at the cables! However, nowadays, it means to search for and remove erronous bits of code from our code to make it work or to be more efficient! Given what we have learned so far, can you give two reasons why the following code will the not work?:

```cpp
std::cout >> "I am broken, please fix me…"
```



## Exercise 2: Frequency Input Into Aserve

The code below is deliberately in the wrong order, an exercise for you to rearrange. 

Firstly, be sure your IAP::run function is empty, then add each line of the code below in the correct order.

```cpp
1.	std::cin >> frequency;
2.	float frequency = 23000;
3.	aserveOscillator(0, frequency, 1.0, 0);
4.	aserveSleep(1000);
5.	std::cout << "Please enter a frequency value in hz \n";
```



## Exercise 3: Adding Amplitude Control

Extend the above exercise so that it prompts the user for *both* a frequency and amplitude before using those values. Remember that each variable can only hold a single piece of data, so you will need to add a second variable. Follow these steps:

1.	Add an additional floating-point variable with an appropriate name.
2.	Add an additional prompt for the user.
3.	Read their additional value into the appropriate variable.
4.	Display both values on screen to the user.
5.	Set the oscillator amplitude and oscillator frequency to the values entered previously. 


## Exercise 4: Loops

The exercise above will exit once the user has heard the oscillator play. Practically speaking, if the user will wishes to enter another set of frequency and amplitude values they must start the program from scratch. To avoid this, and have the program repeatedly ask for input until the user quits the program, we can use a loop.

```cpp
void IAP::run ()
{
    while (true) 
    {
        //Code from previous exercise
    }   
}
```

This is a **loop** and it enables any code that is between the { and {} to be repeated. The **true** part of the while loop makes this section of code repeat forever. Adjust your solution to the previous exercise by adding in a while loop.

## Operators

A crucial feature of any programming language is the ability to describe operations on data. For example we can use the + operator to add two numbers together.

```cpp
int sum = 10 + 5;
```

A list of common arithmetic operators is provided in the table below:

Operator | Meaning
--- | ---
" = " | Assign
" + " | Add
" - " | Subtract
" * " | Multiply
" / " | Divide
" % " | Modulus or remainder

*It's worth noting >> and << are also operators that we've used with std::cin and std:cout, however these are not arithmetic operators like those listed above.*


## Rules of precedence
It is important to consider the rules of precedence when creating arithmetic expressions. The operators * / % have higher precedence than the + - operators. This means that in a single expression, all * / % operators are computed prior to the + - operators. Therefore, you may have to use brackets to ensure that a calculation is performed as intended. An example is provided below: 

1 + 2 * 3 is computed as 1 + 6 = 7 whereas

( 1 + 2 ) * 3 is computed as 3 * 3 = 9


## Console Challenge Exercise: A Simple Average
Write a program that reads two numbers from the user and computes their average.
To compute an average of two values, you can simply do the following (assuming that num1, num2 and result are our variables)

```cpp
result = num1 + num2 / 2.0;
```

The steps for getting started are as follows:

1.	Create two float variables called num1 and num2
2.	Use std::cout to instruct the user to enter the first number
3.	Use std::cin to read a number from the user
4.	Repeats steps 2-3 for the second number
5.	Compute the result using the above sum
6.	Use std::cout to print the result to the user


## Aserve Challenge Exercise: Waves, Freq and Oscs!
Firstly, ensure that you have completed exercise 4.

Extend exercise 4 to use std::cin to read in the users choice of wave type but before switching on oscillators. Secondly switch on a second oscillator that has a frequency value that is twice the value of the original. Finally add a third oscillator that is half the value of the original. You should end up with a program that switches on three oscillators at the same time with a specified base frequency, amplitude and wavetype.


## Important Material

Knowledge of the following will be assumed in next week’s practical:

1.	The properties of the data types int, float, and std::string.
2.	The use and meaning of the while(true) loop. 
3.	The use of std::cin and std::cout to store and display variable values.
4.	The conventions for declaring and identifying/naming variables. 
5.	The basics of applying arithmetic operators to variables.






## Videos

The following videos may help you during this session:

### Variables
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/UNdOMshCIlk/0.jpg)](http://www.youtube.com/watch?v=UNdOMshCIlk)

### Text Input 
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/c0Wo8mMCpDQ/0.jpg)](http://www.youtube.com/watch?v=c0Wo8mMCpDQ)
