# Tutorial 10 – Sequencing with Arrays and Vectors

In this practical you will learn how to use arrays and vectors to sequence musical events. Both arrays, and their companions vectors are useful data structures that collect lots of values of the same type into a single named variable. We will learn: 

1. How to declare an array or vector
2. How to read and write data 
3. How to sequence notes using a loop

## Recap - Arrays

When writing a program that stores a single value, previously you have created a single variable specifically for the job. If it is necessary to store multiple values, multiple variables must be declared. For example, if a problem requires us to store four separate note numbers we could write the following declarations: 

```cpp
    int note1;
    int note2;
    int note3;
    int note4;
```

This method is acceptable, to a point, but becomes cumbersome when we require many more variables (imagine trying to store a sequence of 1000 integer notes!). Arrays allow us to create any number of variables of the same type in a single statement. For example, an array of integer variables for our four note numbers can be created by the following declaration: 

```cpp
std::array<int, 4> notes;
```

Now you must use an (**index**) enclosed within **square brackets []** to use a specific element of the array. Example code for storing and recalling elements is shown below. 

```cpp
notes[0] = 60; //set the first element to be 60
notes[3] = 67; //set the last element to be 67

std::cout << "The value of element 0 is " << notes[0] << "\n"; // display the first element
std::cout << "The value of element 3 is " << notes[3] << "\n"; // display the last element
```

Remember that arrays can only store values within their declared size...

```cpp
  notes[9] = 78;  //ERRROR! out of bounds
  notes[10] = 80; //ERRROR! out of bounds
```

We cannot therefore store more than 4 values in this array without creating another array. In situatins where it is impossible to pre-determine how many values to store, another storage data type is preferred.... the **vector!**

## Recap - Vectors

A vector does not have a fixed size, instead elements can be added (or removed) and the vector will resize automatically. To declare a vector type we do the following:

```cpp
  std::vector<int> noteVector;
```

std::vector is another template class, you must specify the type of data the vector will store within the triangle brackets. In this example the vector is specified to hold integers.

Vectors are like "stretchy arrays". They can automatically expand to hold more data as you add it. Here we use the class method push_back(), like so:

`noteVector.push_back(60);`
`noteVector.push_back(67);`
`noteVector.push_back(69);`
`noteVector.push_back(78);`

Each time we call `push_back()` the supplied value gets added to end of the list.

You can read and write to a vector using the same syntax we learned previously.

```cpp
  noteVector[0] = 10; //set first element
  int firstElement = noteVector[0]; //read first element
```

Vectors may be cleared and emptied (with their size set to zero) by using the class method `.clear()` function like this:

```cpp
  noteVector.clear(); // erase all elements, set size to zero
```

**We'll begin our tasks today using arrays and move onto vectors shortly afterward.**

## Recap - Sizes

To get the size of an array or vector you can use the class method `.size()`. The function returns the number as an integer. You might use it to display the number of elements available.

```cpp
std::cout << "The size of this array is " << array.size() << "\n";
```

Using the `.size()` is particularly useful when accessing elements as part of a loop. We simply make a loop 'index' variable that counts from 0 to the size of the array or vector. 

```cpp
std::array<int, 4> example = {60, 64, 67, 72}; // four example values

for(int i=0; i < example.size(); i++ ){        // process every element, in order
    std::cout << example[i] << "\n";           // print the element at index 'i'
}
```

If you want to store forty instead of four elements, you simply change the array size, and the loop code can stay exactly the same. Neat!

## Exercise 1: An array sequencer

The lines in the code below are deliberately scrambled, your task is to rearrange the lines. Place the lines inside your run() function. Read the code comments carefully for hints. The completed 'correct' program should use an array to hold a sequence of four notes, and play these back in order on an aserve oscillator. A gap of half a second should be heard between each note.

```cpp
1.   int note = notes[i];                            // get the note at index 'i'
2.   aserveSleep(500);                               // wait for half a second
3.   float frequency = 440 * pow(2, (note-69)/12.0); // calculate current note frequency
4.   float amplitude = 0.5;                          // fixed amplitude
5.   for (int i = 0; i < notes.size(); i++) {        // process every note, in order
6.   std::array<int, 4> notes = {60, 64, 67, 72};    // store four notes
7.   }                                               // time to loop back around
8.   aserveOscillator(0, frequency, amplitude, 1);   // let's hear the current note
```

## Exercise 2: Sorting

Standard algorithms exist to reverse and sort values stored in arrays, we simply need to include the algorithm library and call the appropriate function.

```cpp
  #include <algorithm>
```

Now, for example, to sort our array of notes into ascending order we can simply write

```cpp
  std::sort( notes.begin(), notes.end() );
```

This function takes two arguments called **iterators**. We will cover these in detail towards the end of this module, for now we can simply use them without worrying too much about them. As we want to sort the entire array we can use the **begin** and **end**  iterators. 

### Exercise 2a - Reverse and Shuffle

Extend the size of the array to store 10 integers and...

1.  Add more note values to the initialiser e.g. `{60, 64, 67, 72, 50, 49, 37, 52, 50, 54 }`
2.  Experiment with using `std::sort`, `std::reverse`, and `std::random_shuffle`

## Exercise 3: Building a vector music sequencer

Our knowledge of vectors will help to build a fully fledged note sequencer. The steps to achieve this are as follows. Use the [supplied starting point code](../../Code%20Exercises/Tutorial%2010/Exercise%203) and copy into your project overriding the contents of your existing .cpp and .h files.

Notice the following features in `IAP.h`:

1.	A shared variable of type std::vector called `noteVector` is declared
2.	A shared variable of type bool called `playMode` is declared
3.	The note and control change callbacks are enabled

And now explore the following features in `IAP.cpp`:

1.  The control change callback changes `playMode` to false when the stop button is pushed
2.  The note callback adds received notes to the `noteVector`

3.  The first few lines of the run() function set up a three note sequence in the `noteVector`
4.  The main while(true) loop contains an `if( playMode )` section inside which either
    *  plays all notes in the vector, in order, with a gap of half a second between each
    *  ...or waits for notes to be recorded simply displaying number of recorded notes so far

### Exercise 3a: Modify the note callback

Let's fix some deliberate problems with the supplied program. Right now, we only use aserve oscillators when we are in the playback loop, which makes it difficult to hear what we're recording!

Inside the note callback function add lines to play the currently received note on an oscillator.

```cpp
float frequency = ...  // calculate frequency
float amplitude = 0.5; // fixed amplitude
aserveOscillator(1, frequency, amplitude, 0); // let's hear the note
```

Let's fix another deliberate bug in the note callback... Use an if statement so that the received note number is recorded into the `noteVector` **only if the received velocity value is above 0**.

```cpp
if( velocity is above zero ){
    noteVector.push_back( note );
}
```

### Exercise 3b: Modify the CC callback

Now let's fix a deliberate problem with the supplied program. Right now, you can stop playback by pressing the stop button, but you may never restart it again.

Inside the CC callback set the `playMode` variable to be true if the incoming cc number matches that of the ‘play’ button.

Can you add a feature to clear the recording when the rewind button is pressed?
Do you remember how to erase and reset the size of a vector to zero?

**Before moving on, save your solution to your codebook.**

## Exercise 4: Refactoring 

It is quite common but **is bad practice and quickly leads to messy code** to copy-paste almost-identical steps to create a sequence, We want you to see **how easy it is to tidy messy copy-pasted code** into beautiful, elegant, and concise code.

Please download the [supplied starting point code](../../Code%20Exercises/Tutorial%2010/Exercise%204), and copy into your project overriding the contents of existing .cpp and .h files.

The supplied code is **deliberately repetitive and inelegant**. The purpose is for the first four slider values (CC41 – CC44) to be stored in 1 of 4 slider variables. These variables are then used as `note’ values to trigger notes in our synth. We therefore have a 4 beat step-sequencer. The program will work without error; however, it is inelegant. Follow the steps bellow to refactor this program using an array.

1.	Remove the 4 slider variable declarations from IAP.h and replace this with a single **std::array** declaration called sliderValues. This array should have 4 elements.
2.	Inside our CC callback replace each old slider variable to use the sliderValues array.
3.	Inside our run() function replace each old slider variable to use the sliderValues array.

Your program should operate as before, however it is now primed for steps to make it concise.

### Part 1
Think about how you might access array elements using a **for-loop index** 

1.	In the **run()** function add a for-loop from `0` to `sliderValues.size()`
2.	You can now reduce all of the repetition with a single call to **synth.playNote**, and **aserveSleep** inside the for-loop

### Part 2

Think about how the slider CC are numbered consecutively from 41. A simple calculation can determine the array element index. 

1.	Remove the switch case structure from the CC callback. 
2.	Replace it with the following code **inside the if-statement**

```cpp
sliderValues[cc-41] = value;
```

Here 41 is subtracted from the slider CC to get an array index between 0..3. Perfect.

### Wrapping up

Your finished program is now concise and elegant. Nice job!

The process of refactoring is about restructuring existing code so that it is cleaner and more concise without changing its functionality. If you compare the program you had at the start of this exercise with what we have ended up with, you should clearly see the difference.

**Before moving on and saving your solution to code book, ensure that your program is commented.**

## Extension suggestion: 8-step sequencer 

It should now be relatively easy to extend our program to use 8 rather than 4 steps. Something that would have been much harder had we used 8 variables and repetitive code. To achieve this:

1.	Expand your array size to contain 8 elements rather than 4
2.	Modify the the CC callback statement accordingly

By changing only two lines of code we have gone from having a 4-step sequencer to an 8-step sequencer. Using arrays allows our programs to scale very quickly and we end up writing a lot less code!

## Extension suggestion: Amplitude control

Add a second array called **rotaryValues**, that get their values from the 8 rotary controls on the impulse keyboard. These values should **control the velocity** of the synth.playNote function call.
