
# Tutorial 3 – Processing MIDI input 

In this practical we will focus on processing MIDI input data, and building our first synthesizer. By the end of this practical you should have knowledge of:

1.	Callback functions.
2.	Aserve filters.
3.	MIDI note numbers and note frequencies.

## Callbacks

In computer program design we have two opposing principles for dealing with input. Either continuously check if something has changed (known as *polling*). Or we can set things up to alert us when something has changed (we call this second method a *callback*).  

Previously we have used **std::cin** to wait for the user to enter some text that we could then process and display. This input method is sometimes called "blocking" or "busy waiting" - because the program cannot proceed until input is complete.

In this exercise we will use a *callback* to be alerted when MIDI information is received. This is sometimes called "interrupt driven" or "event driven" input - because our program can be interrupted by an event (e.g. someone pushing a MIDI key) to react accordingly. 

Programs with event driven input do not need to execute sequentially. That is to say, each section of the code deals with different inputs (QWERTY keyboard, MIDI keyboard, mouse, audio, touch, etc) and the flow of the actual program when it is running can jump between different sections as necessary.

## Exercise 1: Adding a callback

To add a callback to the IAPproj template, we need to make changes in **both** the IAP.h file and in the IAP.cpp file. Let's deal with the IAP.cpp file first.

1. Select the IAP.cpp file for editing
2. Add a busy-waiting loop inside IAP::run(), between the opening **{** and closing braces **}**. Your complete IAP::run() function should look like this.

```cpp
IAP::run() 
{
	while (true) 
	{
   		aserveSleep(1000);
	}
}
```

1. Keep the IAP.cpp file selected for editing
2. Add the following block of code **under** IAP::run(), **after the last closing brace }**

```cpp
void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
   	std::cout << "Note Received: " << note;
	std::cout <<  " Velocity: " << velocity << "\n";
}
```
**Make sure you type this code exactly, and that you've understood where it should be written in the IAP.cpp file.**

Now let's deal with the IAP.h file.

1. Select the IAP.h file for editing
2. Find the line ***callbackNoteRecived*** in IAP.h 
3. Remove the two // characters (single line comment) at the start

```cpp
//void callbackNoteReceived (int note, int velocity, int channel);
```
Should now look like:

```cpp
void callbackNoteReceived (int note, int velocity, int channel);
```

## Exercise 1 - Adding a callback - time to test!

Ensure that Aserve is open before running your program in Xcode.
When you push keys on either the virtual keyboard inside Aserve, or on the physical Impulse keyboard, the console window of the IAPproj program will show information about which key is being pressed.

You may wonder how our program can print values to the console if our main IAP::run() function is sleeping continuously. This is because we now have two threads going on at once. A technical definition of threads is beyond the scope of IAP - but we cover them in more detail in later years.

Part of our program is dealing with incoming MIDI, and the other part (our run loop) is free to do other things. In future we will use IAP::run() to process data and text input, and we will use callback functions such as callbackNoteReceived() for dealing with MIDI input.

Let’s look in more detail at the function we have just used. The first part of this is referred to as the return datatype (1), however will we not worry about this until the next practical. (2) refers to ownership (or namespace), again will not worry about this until future practicals, but for now ensure that this is added. (3) Is the name of our callback function, these must be typed exactly as they appear, other callback functions have similar names (i.e. for mod wheel). Finally, (4) is the parameters of our callback function, these are the pieces of data passed to us for processing.

```cpp
(1) void (2) IAP:: (3) callbackNoteReceived (4) (int note, int velocity, int channel)
```
Inside our note received function we simply print the values we receive. Do not worry if you do not fully grasp this concept yet.

## Exercise 2: Printing Values for Octave and Pitch

Inside our note callback we want to print two more useful pieces of information. We can use the following formulae to work out pitch and octave from the note number.

```cpp
octave = note / 12
pitch = note % 12
```

The above is **not** C++ code... but it's close. Your task now is to work out how to convert this to C++ code and print the values out inside our callback function. Add your code underneath the existing **std::cout** statements.

## Exercise 3: Our first monophonic synthesizer

Music, much like many other fields, involves some mathematical principles. One of these is the formula for converting MIDI note numbers into frequencies. We manually wrote note frequencies in practical 1 when programming our first sequence, however this is not effective when we do not know what MIDI notes we will receive. We can use the following formula to calculate note frequencies in real time.

<img src="../images/Screen%20Shot%202019-02-21%20at%2012.27.15.png" height=60/>

where 'f' is our frequency, and 'n' is our note number. You will need to use the power function to calculate the exponent (the part written above the number '2'). 

The pow() function takes two arguments x and y and returns the result of x to the power y. 
That is, the equation: 


<img src="../images/Screen%20Shot%202019-02-21%20at%2012.27.20.png" height=60/>

can be written in C++ as: 

```cpp
p = pow (x, y);
```

Do not worry if you do not understand this fully yet. Complete this exercise by arranging the following code in the correct order. If you are up for the challenge, have a go at implementing this yourself.

```cpp
1.	int freq = 440 * power;
2.	int power = pow(2, octave); 
3.	aserveOscillator (0, freq, 1.0, 1); // squarewave oscillator
4.	int octave = (note – 69) / 12;
```

Run and test your program before moving on.

## Error

You should notice that there is an error when we run our program. That is no matter what note we play, we hear the note A, in different octaves.

The reason that the program does not work correctly is due to using integers. Since note frequencies have decimal parts, we will need to replace some of the *int* datatypes with *float* datatypes. Think carefully about which ones to replace.

The last thing we need to do is to swap the 12 on statement 4, to be 12.0. The constant 12 is not the same as 12.0, to ensure we use floating point datatypes everywhere we have to specify 12.0. Try swapping these two values and witness the result.

**As an optional challenge try writing the frequency conversion equation on one line of code**

## Exercise 4: Filter Control

Lets now have a go at using a second callback function, this time for the modulation wheel, we will adapt this to control the Aserve built-in low pass filter.

Firstly in our IAP.h file we need to un-comment the callback function for modwheel events.

```cpp
    //void callbackModWheelMoved (int value);

    void callbackModWheelMoved (int value);
```

Return to the  IAP.cpp and add the following code **under the IAP::run() function** as you did above for the note callback.

```cpp
void IAP::callbackModWheelMoved (int value)
{
	std::cout << "Modwheel just moved - the value is " << value << "\n";
}
```

For this exercise, we want the modwheel to control the cutoff frequency of the built-in Aserve low pass filter. The cutoff frequency has a range from 20Hz to 20,000Hz... but our modwheel has a different range.

1. Run the program.
2. Move the modwheel to the lowest and highest position.
3. Write down the maximum values of the mod wheel value.
4. Use the formula below to scale and shift the value.

<img src="../images/cuttoff_a.png" height=60/>

```cpp
cutoff = ((value / [insert maximum value here and remove square brackets].0) * 19800) + 20;
aserveLPF(cutoff);
```

**Remember if you do not declare your maximum as a floating point number we will again use integer division, which will likely result in errors.**

All being well, you now have a working monophonic synth with a simple filter control assigned to the keyboards modwheel. If you can’t hear the effect taking place, try checking the wave type of your `aserveOscillator()`, a square (wave type 1) waveform will allow you to easily hear the effect.

## Debug Exercise

Give a single reason to why the following code will not work.

```cpp
        int number;
        std::cin >> number;
        std::cout << "this number doubled is << number * 2;
```

## Challenge Exercise: Better Filter Control

To improve the range of controls for the filter you may use the following formula:

<img src="../images/cuttoff_b.png" height=60/>

```cpp
cutoff = ( pow((value / [insert maximum value here and remove square brackets].0), 3.0) * 19800) + 20;
```

This will apply a non-linear scale to the filter control to gives us a more natural sounding filter sweep. You may also wish to adjust the constants 19800 and 20 and observe what effect this has.

## Homework
Add in a pitchbend callback,  use this to control one of the other aserve filters, remember to first print the pitchbend value to help you work out the min and max values for entering into the cutoff formula.  As an additional challenge work out how to get the synthesizer to react to velocity values.

## Conclusion
Ensure that you understand how to use callback functions before next weeks practical, as they will be used in every practical in future. 

## Important Material

Knowledge of the following will be assumed in next week’s practical:

1. How to use callback functions
2. How to convert note numbers to frequency values
3. The use of the pow function



## Videos

The following videos may help you during this session:

### Aserve Programming 2 - callbacks

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/ZJXi2eIq--0/0.jpg)](http://www.youtube.com/watch?v=ZJXi2eIq--0)

### Operators

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/yPNMVlxy1B0/0.jpg)](http://www.youtube.com/watch?v=yPNMVlxy1B0)


