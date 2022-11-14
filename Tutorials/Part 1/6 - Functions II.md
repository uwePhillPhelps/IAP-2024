
# Tutorial 6 - Functions II

Functions continue to be one of the most important concepts in building larger programs. In this practical we will focus on how to share variables between functions effectively. On successful completion of this practical you will have an understanding of:

1.	Variable scope
2.	Memory addresses
3.	When to declare shared variables in the IAP.h

## Getting started

Last practical we looked at functions and we will continue to do so in this practical also. **Please ensure you have completed last weeks practical, before attempting this one**. Reload your solution to practical 5 exercise 2: mtof function.

## Exercise 1: Variable scope

Add the following code to your IAP.cpp (bellow the run function) replacing the existing note callback function. 
Remember to uncomment the modwheel callback function from IAP.h 

```cpp
void IAP::callbackModWheelMoved (int value)
{
  int wave = 0;
  if (value >= 64)
	{
    wave = 1;
  }
	else 
	{
	  wave = 0;
	}
}
```

```cpp
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
  int wave = 0;
  if (velocity > 0)
	{
    float frequency = mtof(note);
    aserveOscillator(0, frequency, 1.0, wave);
  }
  else
	{
    aserveOscillator(0, 0, 0, 0);
  }
}
```

This code is designed to switch between a sine wave and a square wave depending on the position of the modwheel. Run the program and check that this works correctly.

# Error
If we look closely at our program, we can see that we have two variables with the same name but they not do refer to same variable. To verify this, we will print the address of the variable. The address of a variable is it’s location in the computers RAM (random access memory). Every variable in C++ has a unique memory address.

# Exercise 2: Printing address

The & symbol is used to get the address of a variable. 
To print the address of the modwheel callback `wave` variable:

```cpp
  std::cout << "Address of CallbackModWheelMoved wave : " << &wave << "\n";
```

Modify your code to print the address of BOTH of the variables named `wave`, in both `callbackModWheelMoved` and `callbackNoteReceived`.

Your output should look something like this (remember to move both the modwheel and press a key!).
The address of each wave variable is different.

```cpp
Address of callbackModWheelMoved wave: 0x1013d2990
Address of callbackNoteReceived wave: 0x1013d2988
```

## Exercise 3: Shared variables

To fix this issue we need to add a **shared variable** to our IAP.h file. Shared variables are variables that can be accessed between functions. Shared variables also retain their value while the program continues to run. Navigate to our IAP.h file and add a variable called **wave** of type **int**. Place this under the SHARED VARIABLES label.

```cpp
//-------------------------------------------------------------
// SHARED VARIABLES
int wave = 0;
```

Go back to our IAP.cpp file and delete both occasions where our old int wave variables were being declared. Re-run our program and check to ensure that our wave type switch code is working correctly. 

If you still have the address printing code, you should also see the same address value is now printed.

```cpp
Address of callbackModWheelMoved wave: 0x1013d2988
Address of callbackNoteReceived wave: 0x1013d2988
```

<img src="../images/sharedvariables.png" height=300/>

Note that in both functions they are now sharing the same single variable wave.

## Exercise 4: Fix noteoff - We have a problem!

For a number of weeks, you will have encountered a bug with the monophonic synths that we have been building. 

If you press and hold a note with your left hand and then a second note with your right hand, you will notice that the oscillator is stolen by the most recently pressed note - the right hand note. If you now release the left hand note the oscillator should stop, even though the right hand note is still pressed. 

In case it helps to visualise, below is an annotated screenshot of a pianoroll showing the events descried in the paragraph above.

<img src="../images/FixNoteOff-pianoroll.png" />

## Exercise 4: Fix noteoff - A possible solution

The cause of the problem is that our iapProj program cannot (yet) 'remember' that an earlier note is being held when the second note is released.  The iapProj simply switches off the oscillator if the note velocity is zero.

The desired behaviour is that the oscillator should be switched off only if the velocity is zero and the released note number matches the 'remembered' note being played by the oscillator. 

We can fix this by *adding a shared variable* to remember the last note number pressed between calls to callbackNoteReceived(). 

We will then *modify our if statement* inside the callbackNoteReceived(), such that the shared variable is checked to see if it matches the note number of the ‘note off’ message. 

## Exercise 4: Fix noteoff - Let's fix it!

The steps to complete this are as follows: 

1. Create a new shared variable in the IAP.h file called currentNote and set its initial value to be -1
2. When the oscillator is switched on (inside the callback) set currentNote to be equal to the note number.
3. When Note Off messages are received you can compare the Note Off number with the currentNote variable and if it matches you switch the oscillator off and set the currentNote back to -1, otherwise you leave it on. You will need to modify the *else* statement in the callback to use an *else if*

## Debug Exercise

For each of these functions give a single reason for why each one is incorrect. If you are unsure have a look back at examples from last weeks practical. 

**You can assume that the functions have been declared correctly inside IAP.h**

### 1:
```cpp
void IAP::getFrequencyValue ()
{
    float freq;
    std::cout << "Please enter a frequency";
    std::cin >> freq;
    return freq;
}
```

### 2:
```cpp
void IAP::calculateSum (int a, int b);
{
    int result = a+b + a*b;
    std::cout << "Result: " << result << "\n";
}
```

### 3:
```cpp
void IAP::playNote (float frequency, float amplitude)
{
    aserveOscillator(0, frequency, amp, 0);
}
```

### 4:
```cpp
float IAP::tuneNote (float frequency)

    frequency = frequency * 1.5123;
    return frequency;
}
```
*The most common programming mistakes, are: missing brackets, missing braces, spelling errors, and semi-colons where they are not supposed to be.*

## Challenge Exercise: Pitch bend

Using what we have learned so far, you need to add the following code to your project. Think carefully about where each piece of code needs to be placed. You are adding a pitch bend feature that will control the frequency of the oscillator in real time.

```cpp
1.	void callbackPitchbendWheelMoved (int value);
2.	void IAP::callbackPitchbendWheelMoved (int value)
	{
    
	}
3.	int pbValue = 0;
4.	pbValue = (value / 16383.0) * 24 - 12.0;
5.	float frequency = mtof(note + pbValue);
6.	float frequency = mtof(currentNote + pbValue);
7.	aserveOscillator(0, frequency, 1.0, wave);

```

You may notice that the pitchbend function steps, rather than glides smoothly, have a look through the code and see at what point integer arithmetic is being used, when floating point arithmetic should be used instead.

## Important Material

Understanding of the following will be assumed in next weeks practical: 

1. When to place variables inside the IAP.h file
2. How to share data between functions
3. Variable scope




