# Tutorial 8 – Flow Control: Loops


In this practical you will learn how to control program flow using three different types of loops: 

1. the **while** loop.
2. the **do-while** loop. 
3. the **for** loop 

## While
In previous sessions the large majority of exercises have employed a ‘never-ending’ while(true) loop. Last week we learned that it was possible to control the number of times the loop cycled with a condition in place of the true keyword. 

In this tutorial we'll explore ways to control looping with a variety of conditional statements, methods for repeating code **until something changes**. 

## Exercise 1: Waiting for Aserve

Set your project to use the [starting point code provided](../../Code%20Exercises/Tutorial%208/Exercise%201/). You'll need to replace your `IAP.cpp` and `IAP.h` files.

The starting point code **waits until** the modwheel on the keyboard moves from it's lowest zero position before starting the rest of the program.

Examine run function code in the starting point `IAP.cpp` file:

```cpp
std::cout << "Please move the modwheel to start\n";

// pause until shared modwheel value changes
sharedModwheel = 0;
while( sharedModwheel == 0 )
{
   aserveSleep( 1000 );
}
std::cout << "Thanks!\n";

// make a short rising tone using a do-while loop
float frequency = 200;
do
{
   std::cout << ".";                        // display progress
   aserveOscillator(0, frequency, 0.5, 0);  // make a sound
   aserveSleep( 50 );                       // very short delay

   frequency = frequency + 50;              // higher frequency next loop
}
while( frequency < 2000 );                  // until maximum reached
std::cout << "Goodbye\n";
```

Run the program and move the modwheel when instructed. You should hear a short rising tone and the program will exit.

The tone will not play until the modwheel is moved.

The modwheel is closest to the keyboard keys on the left, often used to modulate or change the sound played. Here **the modwheel won't change the sound** but rather **start and stop** parts of your programs below.

## High frequency test

Adapt the starting point program to test the frequency range of your hearing. 

To do this you should edit the lower loop to meet the following specifications:

1. Edit the `aserveSleep` timing such that the frequency sweep lasts 20 seconds instead of 2.
2. Change the `std::cout` to display the current frequency instead of dots `...`
3. Set the maximum frequency to 20,000Hz, a generally accepted maximum for most humans.

**Run the program again and ensure you are using headphones**

You can monitor the displayed frequency and test your hearing with this program. 😀👍

*This will only provide an indication of your hearing range, results may not be accurate as the headphones you are using have a finite frequency response!*

## Exercise 2: High Frequency Test 2

You may have noticed in the last test that it is difficult to see the exact frequency at which the sweep is no longer audible. Adapt the program such that the sweep also checks for modulation wheel movement.

Modify the lower part of the program. You will need to 

1. Add a line to reset the `sharedModwheel` value to zero before the sweep loop runs
2. Modify the sweep loop condition to
    - stop when reaching the maximum frequency
    - but also stop when the `sharedModwheel` value is no longer zero
    - you should have two conditions in your while statement
    - a **logical** operator will join them. Should you join with `&&` or `||`?

When your modifications are complete, run the test with your eyes closed and find out the highest frequency that you can hear. 

You may want to add a `std::cout` instruction to move the modwheel back to the zero position at the appropriate time.

## Do while

A quick note about the 'do while' structure.

In a conventional while loop, the test condition appears at the beginning of the loop structure. The general form of the while loop is indicated below: 

<img src="../images/while.png" height=300/>

In a 'do while' structure, our test condition is positioned at the end of the loop, rather than at the beginning. The general form is as follows. 

<img src="../images/dowhile.png" height=300/>

It is more appropriate to use a do while rather than a while loop when the outcome of the condition is controlled by the statements within the loop. Or that you need to always do something once regardless of the condition.

## Exercise 3 : High Frequency Test 3

Modify the lower half of the program to repeat the frequency test if the user wishes to try again.

You will need to write a loop 'around' the code that exists already such that you

1. Add a `std::cout` line to ask the user if they want to repeat
2. Use a **string** to store the text response from the user with `std::cin`
3. Loop the entire frequency sweeping structure if the response is **‘yes’** 
4. Otherwise the program should exit. 

To do this you will need to place the code that implements the sweep within a second loop which checks for the ‘yes’ response.  

A general template for this program looks like this

```cpp
do 
{
  frequency = min
  do
  {
    // oscillator etc code here
    // ...
    // ...       
  }
  while( frequency < max )
  std::cout << "End of test"
        
  // code to ask user if they want to repeat
  // ...
  // ...
  // ...

} while ( response == 'yes' );
```

## For Loops

The for keyword provides the third looping construction in the C++ programming language. As well as the end condition, the for loop contains additional information about the parameters of the loop. 

For example, the following code fragment would produce the numbered sequence 0-4

```cpp
for (int count = 0; count < 5; count = count + 1) 
{
   std::cout << count << "\n";
}
```

The general form is

```cpp
for (initialisation; condition; increment;) 
{
   statements
}
```

-	The **initialization** statement is often used to initialize a variable (i.e. a counter). Think of this as what value do I want to start my loop at.
-	 The **condition** statement sets the condition that controls whether the loop should continue or stop, this is normally a conditional test to see whether the counting variable has reached the value you wish to count to. 
-	The **update** statement controls how the value of the counting variable is modified for each cycle of the loop. 


The process is as follows: 
1.	The initialisation statement sets the start value for the variable count. Initializes count to zero in the above example. Note that we can declare variables here for use in our loop. 
2.	The condition is tested to check the value of the counting variable to establish whether the loop should continue or exit. In this example the loop continues while count is less than 5.
3.	If the outcome of condition is true, the statements enclosed within the braces of the for loop are executed.
4.	The value of the counting variable is then changed by the update statement. In the above example the value of count is increased by one.
5.	Steps 2 - 4 then repeat until the outcome of the condition (step 2) is found to be false.

## Exercise 4: For loop MIDI – Frequency Table

Write a program that prints out a table of MIDI note numbers and their corresponding frequencies in Hz. 

MIDI note numbers are encoded into 7-bits, which gives the note range 0 to 127 (C-1 to G9). Use a for loop to count from 0 up to and including 127, printing the note number and converted frequency value at each cycle of the loop (recall the formula for converting note numbers to frequencies from earlier practical’s).  You may wish to use the mtof() function.

Once you have this working, modify the loop so that the table is displayed in descending order, from 127 to 0. 

## Important Material

In general a for loop is the most commonly used loop, and you are far more likely to see a while loop than a do-while.

Knowledge of the following will be assumed in the next practical: 

1.	while loops.
2.	do while loops.
3.	for loops. 




