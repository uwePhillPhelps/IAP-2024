# Tutorial 1 – Familiarisation 

This practical is designed to help familiarise you with the development tools that will be used for Introductory Audio Programming. You will be developing software in the programming language C++ using the Apple Integrated Development Environment (IDE) called Xcode or, on Windows, the Microsoft Visual Studio IDE. By the end of this session you should be familiar with: 

1.	The Apple workstations in the faculty labs. 
2.	The Xcode or Visual Studio development environment.
3.	The Aserve application.
4.	The structure of a basic C++ program. 

## Getting started

If you have not already done so, please follow the [getting started guide](../Getting%20Started.md) before attempting this practical.

## What is all this stuff?

You will write code in one of two places.

-	The header `IAP.h` files 
-	and a c++ `IAP.cpp` file. 

For this first task, we will only use the `IAP.cpp` file, single click on this file to open it now.
If you accidentally double-click, close the separate window that will appear and try again.

`IAP.cpp` is where you will be writing most of your C++ programs for this module. Files can be identified as C++ programs by either their, .cpp or .h extension. C++ program files are written in plain text so they may be opened using any ordinary text editor (including word, textedit, notepad, and so forth.). However, Xcode takes care of many other operations needed for creating and running a program.

The code for this file will be broken down and explained below.

## Comments

The first line of the program is a comment. You can write anything you like between the /* and */ and it will be ignored when the program is built. Comments may be written anywhere in your program and should be used judiciously to explain what’s going on and to make the code easier to understand and read. You will also see comments written by //. 

-	Use /* */ for writing comments across multiple lines
-	Use // for writing single line comments.


## Include files

```cpp
#include "IAP.h"
#include <iostream>
```

These two lines tell the compiler to include the information contained in the files IAP.h and iostream. 

-	Quotation marks (“ “) are used to include files that we write ourselves.
-	Triangle brackets (< >) are used to include C++ library files.

C++ programs often include a lot of code behind the scenes. We keep each part separated into different files to avoid having one massive document!

## Run loop

```cpp
void IAP::run () 
{

}
```

The run function is where our code gets executed. The opening brace of the `run()` function is where program execution begins and the closing brace } is where execution ends and the program stops.

**Any code that you add to this program should go after opening brace { and before the  closing brace. }**

## Exercise 1: Hello World 

Modify the run function so it matches the following:

```cpp
void IAP::run ()
{
    std::cout << "Hello World! \n";
}
```

Rebuild and run your program by pressing the ‘Run’ icon again (or cmd + r ). Should you encounter any errors, read the error message for clues as to what the problem might be and check that you have written the line exactly as shown.

When ever we want to print text we use the std::cout command

```cpp
std::cout 
```

The two triangles arranged like this are used to direct data, i.e. we are directing the text we want to print to the std::cout command.

```cpp
<<
```

Finally, we put the text we want to display inside a pair of quotation marks. 

```cpp
"Hello World! \n"
```
**Oh and one more thing… We must end our line of code with a semi-colon. Many programming mistakes are caused by forgetting to put it!**

```cpp
;
```

Other important things to note:

1.	The std::cout command can be used because the header file <iostream> was included, which is where std::cout is declared.
2.	The C++ compiler is case sensitive. That is, std::cout is valid and std::CoUt is not.
3.	C++ statements are terminated with a semi-colon (;).
4.	std::cout will be used every week.
5.	Code that is enclosed by braces { } should be indented one tab space.

Now modify your program so that it greets you by your first name. You may also wish to experiment with some other text to give your program a more colourful character. 

std::cout displays the text enclosed by quotation marks on the console; however, there are exceptions. For example, \n does not appear. Try moving \n between the words Hello and World, to establish what it does. 

\n is what’s called an escape sequence and lets us print characters that cannot be represented easily in code. \t is another useful escape sequence. Insert it in a few places to work out what it does. 

## Keeping a reference archive of your work

To help you keep a reference of your work to help with future practicals and assignments, we recommend you store your code from each week's exercise on your student OneDrive storage. If you are unsure on the UWE OneDrive service, you can ask a staff member or [you can read more online here](https://www.uwe.ac.uk/study/it-services/data-storage#onedrive).

We recommend using the following method to store your work:
1. Create a folder for your IAP work called "IAP"
2. Each week, add a new folder to your IAP folder and name it the same name as the exercise. For example, week one is called "Part 1 - Familiarisation".
3. In this folder, you can add the .cpp and .h files for each excersie you complete. You should rename these .cpp and .h files to match the name of the exercise you have most recently completed. In "Part 1 - Familiarisation" for example, you might call your files "Exercise 1: Hello World".
4. Each time you complete an exercise, you can then upload the .cpp and .h files from your project and rename them accordingly.

To see this in action, please see the GIF below:

![a gif showing the creation of folders on onedrive in the following hierarchy: IAP -> Part 1 Familiarisation. 2 text files are then added to this folder and renamed to "Exercise 1 - Hello World IAP.cpp" and "Exercise 1 - Hello World IAP.h"  ](../images/saving_code.gif)



## Aserve 2.0

From your Documents/iap/ folder, find and launch Aserve. You should see the following interface: 

[![A screenshot of the software Aserve. On the left side of the interface, there are 24 oscillator states, labelled from 0 to 23. They all feature an oscillator index, the current frequency, the amplitude and the wavetype index. In the upper centre, there is an oscillator visualiser, currently showing no oscillation, alongside a reset button. The lower middle shows an empty console window. The right side shows 3 sections, the state of 4 sampler tracks, the states of 4 pitched sample tracks, and a crosshatched pixel grid. The lower section shows a full musical MIDI keyboard featuring many octaves of keys, a pitch bend, a modulation wheel, 9 sliders, 9 toggle buttons, 8 radial dials, 8 pads, and 6 transport buttons showing rewind, fast forward, stop, play, loop and record in that order.](../images/aserve_screen_shot_a.png)

# How Xcode and Aserve work together

To produce sound in a musical context Aserve and your Xcode program work together as a 'client and server'. This is very similar to how a client at a restaurant might request food from the serving staff. Okay maybe that's a silly analogy - but it's not too bad!

Broadly speaking:

* your `iapproj` program will always run inside Xcode 
   * your `iapproj` program can tell Aserve to make sound automatically ... or ... 
* Aserve will send messages to your Xcode program when MIDI keyboard controls are moved
    * your `iapproj` program can respond by telling Aserve to make sound or become silent
    
![A flowchat showing functionality between XCode and Aserve. A box labelled "Your Program" points from XCode to Aserve. As a result, AServe oscillators and samples make noise. A MIDI Keyboard flows from AServe to "Your Program" in XCode"](../images/AserveXcodeYourProgram.png)

We'll explore the second scenario (responding to MIDI controls) in later practicals, for now let's start with something simple.

## Exercise 2: Test Tone

Return to Xcode and and delete the std::cout line and replace it with the following: 

```cpp
aserveOscillator(0, 1000.0, 1.0, 0);
aserveSleep(1000);
```

As before, click the Run button, if there are any errors, fix them and try again. When the program runs successfully, you should hear a one second tone. 

The function call that starts the tone is: 
```cpp
aserveOscillator(0, 1000.0, 1.0, 0);
```

aserveOscillator() switches on an oscillator with the settings that are specified as its four arguments. 

-	Argument 1 has a value of 0
-	Argument 2 has a value of 1000.0 
-	Argument 3 has a value of 1.0
-	Argument 4 has a value of 0 


Experiment with different values for arguments 2 - 4 and complete the table below with argument descriptions. Keep an eye on aserve for any errors!


Argument | Description of what this argument controls 
--- | ---
2 | 
3 | 
4 |

The oscillator function call is followed by a call to aserveSleep(), which causes program execution to pause for the time specified as its argument in milliseconds (i.e. aserveSleep(1000); will pause the program for 1 second). This causes the tone to be sustained for one second before the program exits (and the tone is stopped). 


Make sure you save your solution to this exercise to codeBook before moving on.

## Exercise 3: Sequential Programming

![A musical score representing the song Greensleeves. This is notated as text after this image.](../images/score_greensleves.png)

The score for the first four bars of Greensleeves is shown above. Program the score using the aserveOscillator(), and aserveSleep() functions. Do not worry if you are unable to read music, the note names and durations are indicated below and a table showing the standard piano note names, frequencies, and durations are provided at the end of this practical. 

Order | Note | Duration
--- | --- | ---
1 | A4 | Quaver 
2 | C5 | Crotchet 
3 | D5 | Quaver 
4 | E5 | Dotted Quaver 
5 | F5 | Semiquaver 
6 | E5 | Quaver 
7 | D5 | Crotchet 
8 | B4 | Quaver 
9 | G4 | Dotted Quaver 
10 | A4 | Semiquaver 
11 | B4 | Quaver 
12 | C5 | Crotchet 
13 | A4 | Quaver 
14 | A4 | Dotted Quaver 
15 | Ab4 | Semiquaver 
16 | A4 | Quaver 
17 | B4 | Crotchet 
18 | Ab4 | Quaver 
19 | E4 | Crotchet 
20 | A4 | Semiquaver 

For the purposes of this exercise you can use the duration values given in appendix item B.

Make sure you save your solution to this exercise to codeBook before moving on.

## Exercise 4: Playing Chords 

So far we have only experimented with turning on one oscillator at a time. We can stack notes by adding them on more channels, note that the channel is specified by argument 1.

```cpp
aserveOscillator(0, 1000.0, 1.0, 0);
aserveOscillator(1, 2000.0, 1.0, 0);
aserveOscillator(2, 4000.0, 1.0, 0);
aserveSleep(1000);
```
The following code will now play a 1kz, 2khz and 4kz tone at the same time. Using this technique program in the following chord sequence. 

![Music notation showing 4 semibreve chords on a treble clef stave. These chords are notated as text after this image.](../images/metascore.png)

Chords | Note
--- | ---
Chord 1 | E4 G4 B4
Chord 2 | D4 G4 B4
Chord 3 | C4 G4 B4
Chord 4 | C4 E4 Bb4

## Debug exercise

Each week you will also be given a debugging challenge, whereby you have to fix broken code. Give the reason as to why this code will produce an error.

```cpp
void IAP::run ()
{
    std::cout << "Hello World! \n"
}
```
## Challenge exercise: What about adding rests!
In the previous exercise each note flowed from one to the next without any rests, in this exercise we will need to program in gaps in our music. The simplest way of doing is to to simply make a call to aserveOscillator with 0 for all arguments. Following this with a aserve sleep will give us a rest with a duration equivalent to the value we supply.

```cpp
aserveOscillator(0, 1000.0, 1.0, 0);
aserveSleep(1000);
aserveOscillator(0, 0, 0, 0); //turn off oscillator
aserveSleep(1000); //rest duration
```

## Mario Theme
Lets program something a little more modern. Do not worry if you do not get time to complete this exercise.

![A musical score showing the Mario theme tune. A table of events is given in the appendix.
 ](../images/marioscore.png)

A table of events is given in the appendix.

## Challenge Exercise: Program a song of your chocie!
Each week, we will provide you with a challenge exercise to complete. These are NOT compulsary, however they are a great way for you to solidify your skills from each week or to practice further.  

Your challenge exercise for this week is to program in your own choice of music using what we have learned in this session.

## Finishing Up

Make sure that you have saved your work to OneDrive using the previously outlined method. Ask a member of staff or a friend if you are unsure!

## Important Material 

Make sure that you have a good understanding of the following before we return next week: 

1.	The use of the Xcode IDE for loading, editing, building and running projects.
2.	The use of the std::cout command.
3.	The use of indentation in C programs.
4.	The Aserve application, and the aserveOscillator() function.
5.	The use and meanings of terms call and argument in C programs. 

## Appendix Item A: Standard Piano Note Names and Frequencies 

![A chart showing note octaves to frequencies. A table represents this after this image.](../images/freq_note_map.png)

| Note  | Octave 0 | Octave 1 | Octave 2  | Octave 3  | Octave 4  | Octave 5  | Octave 6   | Octave 7   | Octave 8   |
| ----- | -------- | -------- | --------- | --------- | --------- | --------- | ---------- | ---------- | ---------- |
| C     | 16.35 Hz | 32.70 Hz | 65.41 Hz  | 130.81 Hz | 261.63 Hz | 523.25 Hz | 1046.50 Hz | 2093.00 Hz | 4186.01 Hz |
| C#/Db | 17.32 Hz | 34.65 Hz | 69.30 Hz  | 138.59 Hz | 277.18 Hz | 554.37 Hz | 1108.73 Hz | 2217.46 Hz | 4434.92 Hz |
| D     | 18.35 Hz | 36.71 Hz | 73.42 Hz  | 146.83 Hz | 293.66 Hz | 587.33 Hz | 1174.66 Hz | 2349.32 Hz | 4698.63 Hz |
| D#/Eb | 19.45 Hz | 38.89 Hz | 77.78 Hz  | 155.56 Hz | 311.13 Hz | 622.25 Hz | 1244.51 Hz | 2489.02 Hz | 4978.03 Hz |
| E     | 20.60 Hz | 41.20 Hz | 82.41 Hz  | 164.81 Hz | 329.63 Hz | 659.25 Hz | 1318.51 Hz | 2637.02 Hz | 5274.04 Hz |
| F     | 21.83 Hz | 43.65 Hz | 87.31 Hz  | 174.61 Hz | 349.23 Hz | 698.46 Hz | 1396.91 Hz | 2793.83 Hz | 5587.65 Hz |
| F#/Gb | 23.12 Hz | 46.25 Hz | 92.50 Hz  | 185 Hz    | 369.99 Hz | 739.99 Hz | 1479.98 Hz | 2959.96 Hz | 5919.91 Hz |
| G     | 24.50 Hz | 49 Hz    | 98 Hz     | 196 Hz    | 392 Hz    | 783.99 Hz | 1567.98 Hz | 3135.96 Hz | 6271.93 Hz |
| G#/Ab | 25.96 Hz | 51.91 Hz | 103.83 Hz | 207.65 Hz | 415.30 Hz | 830.61 Hz | 1661.22 Hz | 3322.44 Hz | 6644.88 Hz |
| A     | 27.50 Hz | 55 Hz    | 110 Hz    | 220 Hz    | 440 Hz    | 880 Hz    | 1760 Hz    | 3520 Hz    | 7040 Hz    |
| A#/Bb | 29.14 Hz | 58.27 Hz | 116.54 Hz | 233.08 Hz | 466.16 Hz | 932.33 Hz | 1864.66 Hz | 3729.31 Hz | 7458.62 Hz |
| B     | 30.87 Hz | 61.74 Hz | 123.47 Hz | 246.94 Hz | 493.88 Hz | 932.33 Hz | 1975.53 Hz | 3951.07 Hz | 7902.13 Hz |


## Appendix Item B: Note Durations

Note Type | Duration in ms
--- | ---
Crotched | 500
Quaver | 250
Dotted Quaver | 375
Semiquaver | 125
Triplet Crotchet | 333

## Appendix item C: Mario Theme Table of events



Order |	Note | Duration | Order | Note | Duration
--- | --- | --- | --- | --- | --- 
1 |	E5 | Quaver | 19 | Rest | Quaver 
2 |	E5 | Quaver | 20 | B4 | Quaver
3 |	Rest | Quaver | 21 | Rest | Quaver
4 |	E5  | Quaver | 22 | Bb4 | Quaver
5 |	Rest | Quaver | 23 | A4 | Crotchet
6 |	C5 | Quaver | 24 | G4 | Triplet Crotchet
7 |	E5 | Crotchet | 25 | E5 | Triplet Crotchet
8 |	G5 | Crotchet | 26 | G5 | Triplet Crotchet
9 |	Rest | Crotchet | 27 | A5 | Crotchet
10 | G5 | Crotchet | 28 | F5 | Quaver
11 | Rest | Crotchet | 29 | G5 | Quaver
12 | C5 | Crotchet | 30 | Rest | Quaver
13 | Rest | Quaver | 31 | E5 | Quaver
14 | G4 | Quaver | 32 | Rest | Quaver
15 | Rest | Crotchet | 33 | C5 | Quaver
16 | E4 | Crotchet | 34 | D5 | Quaver
17 | Rest | Quaver | 35 | B4 | Quaver
18 | A4 | Quaver | 36 | Rest | Crotchet





## Videos

The following videos may help you during this session:

### Printing text
![A video link to YouTube for "Printing Text"](http://img.youtube.com/vi/oAFGNsZ6MPc/0.jpg)](http://www.youtube.com/watch?v=oAFGNsZ6MPc)


### Programming Aserve
![A video link to YouTube for "Programming AServe"](http://img.youtube.com/vi/Pfclu24116U/0.jpg)](http://www.youtube.com/watch?v=Pfclu24116U)
