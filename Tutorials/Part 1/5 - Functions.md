# Tutorial 5 – Functions

In this practical we will learn how common functionality in larger programs can be written as smaller sub-components called 'functions'. On successful completion of this practical you will have an understanding of: 

1.	How programs can be organized into functions.
2.	How to declare, define and call your own functions.
3.	How to pass values into functions.
4.	How to return values from functions. 

Practicals from here on will assume knowledge of functions so please ensure you complete this week’s practical. This is a very IMPORTANT practical.

## Motivation

C++ 'functions' enable multiple statements to be executed by a single statement referred to as a function call. We have already written programs which use functions, e.g. aserveOscillator(), pow() are both function calls. However, an important part of any programming language is to define your own functions - to group multiple statements together which can be called.  If you know how to do this, any large complex program can be divided into smaller blocks of code. This makes programs easier to design, read and maintain. 

It is possible to write your program **without** using custom functions, however your programs will end up being:
-	Overwhelmingly large
-	Challenging to understand
-	Difficult to maintain
-	Repetitive
-	Potentially error prone (e.g. typos in repetitions)

## Declaring Functions

When declaring your own function, there are two steps that should be taken before it can be used (or called). 

1.	Write a function **declaration** (in the IAP.h file, underneath the FUNCTIONS label).
2.	Write the function **definition** (at the bottom of the IAP.cpp file, after the run loop). 

The function **declaration** tells the compiler how the function can be used (to enable error checking at compile time), while the function **definition** specifies what the function does when it is called. 	


The general form of the function declaration is as follows: 

```cpp
return-type functionName ( argument-type(s) ); 
```

The return-type indicates the data type of the value which is returned from the function. The argument-types indicate the data types of any values that are passed into the function. The function-name should indicate what the function does. 

C++ functions can take many arguments but only return one. If a function does not return anything, the return type must be written as **void**.

Examples of a few function declarations are shown bellow.

```cpp
//A function that does not return anything, nor have any arguments

void makeErrorTone ();

//A function that does not return anything, but takes a single argument.

void printTime (int time);

//A function that returns a int value, and takes a single argument.    

int covertCtoF (int centigrade);

// A function that does not return anything, but takes 3 arguments.

void setNote (int note, int velocity, int wave);
```

## Function Definitions

Function definitions should appear in IAP.cpp separated from the IAP::run() function. The first line of the definition should match the declaration, but have the IAP:: statement placed between the return type and function name. This must be followed by opening and closing braces that enclose the statements that are to be executed when the function is called. Note that the semi-colon included in the declaration is not used in the definition.

## A deliberately messy example

To illustrate when we might to make a function, let's use some deliberately messy code.
The code below is a perfect example of duplicated repetitive code that can be made more compact with the use of functions.
**If you find yourself writing code like this, you should re-write it as a function.** We'll show you how to re-write it below.

Study the code below.

```cpp
void IAP::run()
{
  // read four numbers
  int numberA = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberA;

  int numberB = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberB;

  int numberC = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberC;

  int numberD = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberD;

  // perform a calculation and display the result
  std::cout << "Your numbers multiplied together: ";
  std::cout << numberA * numberB * numberC * numberD << "\n";
}
```
Study the code above. 

There are four groups of statements, each marginally different. If we look closely, the only difference is the variable we are storing our data in. 
We read four numbers (`numberA`, `numberB`, `numberC`, and `numberD`) in sequence then perform a simple multiplication to display the result..

**If you find yourself writing code like this, you should re-write it as a function.** We'll show you how to re-write it below.

## Exercise 1: Avoiding repetition with functions

1. Select the `IAP.h` file for editing
2. Place the following line of code under the FUNCTIONS label, after the run function that is already there.

```cpp
int readNumber ();
```

1. Select the `IAP.cpp` file for editing
2. Add the following code under our main run() function.

```cpp
int IAP::readNumber ()
{
    int number = 0;
    std::cout << "Please enter a number : \n";
    std::cin >> number;
    return number;
}
```

Our new `readNumber()` function code allows us to write compact, simple, and readable code in our main `IAP::run()` function. 
**All of the duplication that we had befrore can now be simplified into just four lines.**

```cpp
void IAP::run()
{
    // read four numbers
    int numberA = readNumber();
    int numberB = readNumber();
    int numberC = readNumber();
    int numberD = readNumber();

    // perform a calculation and display the result
    int result = numberA * numberB * numberC * numberD;
    std::cout << "Your numbers multiplied together are ";
    std::cout << result << "\n";
}
```

You should now be able to see how much more clear the code is to read. We will now look at functions in more detail.

## Exercise 2: mtof function

Back in practical 3 we used a formula for converting note numbers into frequencies. This formula is commonly known as the "MIDI to Frequency" equation. This is often shortened to "mtof". We'll use this equation throughout this module, so it would make sense to put this code inside a function. 

Below is some code for your IAP.cpp file that makes Aserve play midi notes:
```cpp

//
//  IAP.cpp
//

#include "IAP.h"
#include <iostream>

/* This is our main function code. Nearly Everything goes in here. */
void IAP::run ()
{
    while (true) {
        aserveSleep(1000);
    }
}

/* This callback function handles events from the keybed and drumpads */
void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
    float freq = 440.0 * pow(2.0, (note-69)/12.0);
    aserveOscillator(0, freq, 1.0, 0);
}
```

and here is the IAP.h file:

```cpp
//
//  IAP.h
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

//---------------------------------------------------------------------
// USER CREATED CLASS
// You might add your own classes, like 'IAPSynth' or 'Person' here

class IAP : public AserveComs  {
public:
  
    //---------------------------------------------------------------------
    // SHARED VARIABLES (IAP member variables)
    // ...delete this line and add your own variables below
    // ...perhaps your own variables like 'currentNote' or 'wave'
  
    //---------------------------------------------------------------------
    // FUNCTIONS (IAP class methods)
    // ...delete this line and add your own functions below
    // ...perhaps your own functions like 'mtof()' or 'minorChord()'
    void run ();
  
    //---------------------------------------------------------------------
    // CALLBACK FUNCTIONS 
    void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackCCValueChanged (int cc, int value);
    //void callbackMIDIReceived (MIDI message);
    //void callbackPixelGrid (int x, int y);

private:

};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */

```


Now, we're going to add in an mtof function to handle converting midi notes to frequency for us. The prototype for our mtof function looks like this. 

```cpp
float mtof (int note);
```

Our mtof function takes an int (midi note number) as its argument and returns a float (frequency).  

You can do these steps below in almost any order, but if you follow them as written, you'll have an iapProj that converts note numbers to frequencies simply, and using a function called `mtof`.

1. Add the mtof function **declaration** to the IAP.h file.
2. Add the mtof function **definition** to the IAP.cpp file.
3. Put the relevant code from our note callback function into our mtof function.
4. You will need to use the return keyword to **return** the value of frequency.
5. Use the mtof function to calculate our frequency value.
6. Pass the frequency value to our oscillator function.	  

With our mtof function, it is now easy to add a second call for a **harmonised frequency value**  7 semitones higher than our original note, for example.

```cpp
float frequencyA = mtof(note);
float frequencyB = mtof(note + 7);
```

## Exercise 3: Chord Machine 

We will now create two more functions, called **majorChord** and **minorChord**. These functions will take a single argument (a note number) but not return anything. 

The **major** function will covert three note numbers to frequencies and supply these to three separate oscillators. The first frequency value will be calculated on the supplied note number, the second frequency will be calculated based on the supplied note number + 4, and the third note number + 7.

The minor function is the same except oscillator two will be calculated based on the original note number + 3.

The code for the note callback function is supplied bellow, **ensure that you have correctly added the two chord functions before trying to run the code**. The bottom 4 drum pads on the impulse control correspond to the 4 chords. 

```cpp
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (note == 60)
    {
        majorChord(60); // C Major
    }
    else if (note == 62)
    {
        majorChord(65); // F Major
    }
    else if (note == 64)
    {
        majorChord(67); // G Major
    }
    else if (note == 65)
    {
        minorChord(69); // A Minor
    }
}
```

## Exercise 4: More Chords

Add 2 or more chord functions, some suggestions for chords are given bellow. You should map these chords to the other 4 drum pads.

| Chord Name | Intervals |
| --- | --- |
| Major 7 | +4, +7, +11 |
| Minor 7 | +3, +7, +10 |
| Dominant 7 | +4, +7, +10 |
| Diminished | +3, +6 |
| Maj7 add6 | +4, +7, +9 |
| Min7 add6 | +3, +7, +9 |
| Sus4 | +5, +7 |
| Sus2 | +2, +7 |

## Debug Exercise.

Below is some code that is broken, and it's your job to fix it! Can you figure out what is wrong? Replace your IAP.cpp file with this code and have a go!a
```cpp
//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>

// This is our main function code. Nearly Everything goes in here..

void IAP::run ()
{
    
    /*
     The following program gives intructions to the user depending on the time of day entered.
     
     If the time of day is after 600 then the program should print "open windows"
     If the time of day is after 900 but before 2000 then the program should print "unlock doors"
     If the time of day is after 1800 then the program should print "close windows"
     If the time of day is after 2000 then the program should print "lock doors"
     If the time of day is after 2200 then the program should print "set alarm"
     
     You need to fix the following broken program.
     
     There are both compile time errors x3
     and run time errors x2
     
     */
    
    int timeOfDay;

    std::cout << "Enter time of day: \n";
    std::cin >> time;
    
    std::cout << "Tasks to do are as follows:\n";

    if (timeOfDay < 1800)
    {
        std::cout << "close windows\n";
    }
    else if (timeOfDay > 600)
    {
        std::cout << "open windows\n";
    }
    
    if (timeOfDay > 900 ) {
        if (timeOfDay < 2000) {
            std::cout << "unlock doors\n";
        }
        if else (timeOfDay > 2000) {
            std::cout << "lock windows\n";
        }
        
    }
    
    if (timeOfDay > 2200) {
        std::cout "set alarm\n";
    }
    
    
}
```

Download: [Tutorial 05 Debug code](../../Code%20Exercises/Tutorial%205/Debug)

## Challenge Exercise: 

Add a nested if statement to the note callback function in exercise 4 so that chords are only switched on when the velocity value is greater than 0, otherwise turn off all the current oscillators. 

## Important Material:

Further practicals assume knowledge of functions so please ensure you have completed this week’s practical. This is a very IMPORTANT practical!

Understanding of the following will be assumed next week: 

1. How programs can be organized into functions.
2. How to declare, define and call your own functions.
3. How to pass values into functions. 

## Videos

The following videos may help during this session:

### Functions

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/Cbj72bZrxaE/0.jpg)](http://www.youtube.com/watch?v=Cbj72bZrxaE)
