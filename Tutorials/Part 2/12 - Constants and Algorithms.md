# Constants and Algorithms

This tutorial is broken into two different parts. The first looks at constants, defines and enums. The second explores a few more algorithims that can be applied specifically to arrays and other data containers.

# Part 1: Constants, defines and enums: 

So far we have either used variables or literals to represent data. However, there are many occasions where we might to define a constant value, in essence a variable whose value cannot be updated or changed. We will explore 3 topics in this exercise:

1.	Consants
2.	Defines
3.	enums

# Constants

In previous exercises we have written code that looks like the following:

```cpp
  float freq = 440.0 * pow(2.0, (note - 69.0)/ 12.0);
  aserveOscillator(0, freq, 1.0, 0);
```

In this situation the variable freq is set once and following on from this its value never gets updated. This is a perfect occasion for making the freq variable a constant.
  
```cpp
  const float freq = 440.0 * pow(2.0, (note - 69.0)/ 12.0);
```

The const keyword can be placed in front of any variable and means that after the variables value has been set it can no longer be updated, and is read only.

```cpp
  const float concertPitch = 440.0;
  concertPitch = 443.0; //will produce a compiler error!
```

Using consts can also make your program more readable. For example, when checking for CC’s we often simply state the number of the CC as a literal.

```cpp
  if (cc == 115) {
```      

Instead using constants, we get the following:

```cpp
  const int playBtn = 115;
  
  if (cc == playBtn) { //easier to read
```

Constants are often placed either at the top of our program between the includes and run function. **This is one of the few times variables should be declared here**. They are often also placed inside class's as member variables.


## Defines

Defines can also be used to define constant values. The general form of a define is:

```cpp
#define SYMBOL value
```

For example, in this instance, the symbol COLUMNS holds the value 16.

```cpp
#define COLUMNS 16
```

And can be used for doing the following (shown below) In essence a define is a find and replace, whereby the compiler will actually swap each occurrence of COLUMNS for the value 16. Like const, define is a method for making code more readable

```cpp
for (int i = 0; i < 16; i++) {

for (int i = 0; i < COLUMNS; i++) {
```

A define is generally not recommended for defining constant values, and you are encouraged to use const instead. Define can however do things that const cannot, for example:

```cpp
#define SLEEP_500 aserveSleep(500);
```

Therefore, anytime you want to sleep for 500ms you can write SLEEP_500.

```cpp
SLEEP_500
```

It is worth knowing about define for the purposes of learning the C++ language however it has limited use for this course. Define can solve some very tricky programming problems, but is also frequently abused!

## Enum

The last type of programming construct you an use for defining constants, is an enum. An enum is shorting for enumeration and allows a series of constant symbols to be defined in a series, whereby each enums value is +1 of the previous value. We could use an enum structure for defining each wave types numerical value.


```cpp
    enum eWaveTypes {
        eSine = 0,
        eSquare, //will have the value 1
        eSaw,
        eReverseSaw,
        eTri,
        eNoise //will have the value 5
    };
```

Be default the enums first entry will be given the value 0, however you should always specify a value even if it is still 0. The value of eSquare will be 1, eSaw will be 2 and so on.

Now when we wish to turn on an oscillator we can write the following:

```cpp
aserveOscillator(0, 440.0, 1.0, eSine);
```

Which is more readable than:

```cpp
aserveOscillator(0, 440.0, 1.0, 0);
```

The general form of an enum is as follows:

    enum name {
      entry0 = 0,
      entry1
    };
    
Each entry should be separated by a comma, and the statement should end with a brace and semicolon. enums should be placed in inside a class. By convention enums should start with a lowercase **e**.
 
You can also group constants in an enum that are not necessarily sequential, but you must define the value of each.
 
```cpp
    enum eControls {
        eKnob1 = 21,
        eSlider1 = 41,
        ePlayBtn = 115,
    };
```

## Enums as types

An enum can also be used as a variable data type.

```cpp
eWaveTypes waveType;
```

However, be aware than you can only assign values to waveType that were specified in the eWaveType enum.

```cpp
    waveType = eSaw; //is fine
    waveType = 2; //compiler warning
```

*Note that it is possible to assign integer values directly to an enum type (see below) but is mostly discouraged*

```cpp
  eWaveTypes waveType;
  int waveInt = 3;
    
   waveType = static_cast<eWaveTypes>(waveInt);
```

## Exercise 1: Code refactoring

Download the supplied [starting point CPP and H files](../../Code%20Exercises/Extra%20Tutorial/enums) and copy them into your project. The supplied code is **deliberately messy** and would strongly benefit from refactoring, cleaning, and tidying using the techniques we have discussed. Practice these techniques by cleaning up, tidying, and refactoring the code.

1.	You should make any variables const that are not going to be modified after being initiliased
2.	Replace any arbitrary literals with constants
a.	Note that values within calculations are fine as they are.
3.	Make use of at least one enum
4.	Ensure you save your solution to codebook
5.	Remember to check your solution with one of the lecturers during next week’s tutorial

# Part 2 Array/Vector Algorithms:

There are a number of functions built into the standard C++ Library (std) that are powerful tools for performing operations on arrays and vectors. In this exercise we will look at and explore a number of these including:

1.	Passing arrays/vectors as function arguments
2.	Sorting array/vector
3.	Reversing array/vector
4.	Randomising array/vector

## Passing arrays & vectors to functions

Arrays can be passed to functions just like normal variables, however it is difficult to do this effectively as you need to specify the size of the array as the argument.

```cpp
  void exampleFunction (std::array<int, 4> array);
```

Meaning that if we wanted to pass an array with 6 elements we would have to create another function just for this (and for each subsequent array size)

```cpp
  void exampleFunction (std::array<int, 6> array);
```

As you might imagine this is cumbersome and inefficient. Instead if we replace the argument with a vector instead of an array, we can pass in a vector of any size:

```cpp
  void exampleFunction (std::vector<int> vector);
```
Note this function will only work with integer vectors.

## Printing every element

It is extremely useful (especially for the practical exercises here!) to display all elements of an array or vector. We may use a loop to iterate over each element and print the value stored at that index to the console. Note the use of `.size()` in the code below which ensures the loop automatically adjusts to match the size of the vector or array. **To see this in action, try changing the array to a vector, and use `.push()` to test the behaviour**

```cpp
  std::array<int, 6> array = { 30, 70, 54, 72, 68, 59 };
  for(int i=0; i < array.size(); i++)
  {
     std::cout << array[i] << "\n";
  }
```

## Sorting

There are a number of algorithms for sorting the elements of an array into ascending or descending order. At this stage of the course we will use the inbuilt sorting methods found in the **std library**, however we will implement our own rudimentary sorting algorithm towards the end of this course.

To sort an array we can simply use the std::sort function.

```cpp
  std::array<int, 6> array = { 30, 70, 54, 72, 68, 59 };
    
  std::sort(array.begin(), array.end());
```

The std::sort function takes two arguments called **iterators** one for specifying where we would like to start sorting from and another to specify where we would like to stop sorting. As we want to sort the entire array we can use the **begin** and **end** member functions. We will cover **iterators** in detail towards the end of this module, for now we can simply use them without worrying too much about them.

Use the code above which prints every element of an array **before** and then **after** sorting. Compare the display carefully.

## Reversing 

There are a few occasions where we might want to reverse the contents of an array. For example, playing a sequence of notes backwards or reversing the sorted order of a list. For this we can use the std::reverse function.

```cpp
  std::reverse(array.begin(), array.end());
```

The syntax for this should look very similar to std::sort

## Randomize

Another useful function that you may wish to use from time to time is std::random_shuffle

```cpp
  std::random_shuffle(array.begin(), array.end());
```

You can use this to shuffle or randomize the order of the elements within an array.

**Note that all of the above functions can be applied to both arrays and vectors.**

## Exercise 2: Sort, Reverse, Randomize

To conclude this tutorial, you should try out each of the 3 functions discussed previously. A placeholder for this exercise can be found here [Tutorial 13 sorting getting started](../../Code%20Exercises/Extra%20Tutorial/sorting/getting%20started.txt).

