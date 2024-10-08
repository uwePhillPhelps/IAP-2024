# Workshop 2 – Playful and creative extension

This workshop will extend the materials provided in workshop 1 earlier. The idea is to start with the same template synthesiser as last time, but this time, use your new found C++ knowledge to extend it! By the end of this session you should be familiar with: 

1.	Extending C++ code to develop sounds and ideas
2.	Adding new features to existing projects
3.	Bringing your own creative flair to synthesiser design in C++

## Getting started

The following assumes you have set your `IAP.cpp` and `IAP.h` files to the <a href="../iapProjM/Source/IAP.cpp">starting point CPP</a> and the <a href="../iapProjM/Source/IAP.h"> starting point H file</a> provided. Copy and replace your current files with these to get started 😊

## Drums please!

Your first task is probably to scroll down to the drum sequence section of our IAP::run() function. It should look like this:

```cpp
    while(true)
    {
        if(USE_DRUMS)
        {
            aservePlaySample(0, sampleVolume);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(1, sampleVolume);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(2, sampleVolume);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(3, sampleVolume);
            aserveSleep( BPMToMS(BPM) );
        }
        else
        {
            aserveSleep( BPMToMS(BPM*4) );
        }
    }
```

You should try to **add an extra beat** to turn our 4/4 rhythm into a 5/4 rhythm.  Think about _where_ each sample is played and then duplicate that section of code. 

### Extending this further...

* What other time signatures could you make?
* Maybe you could change samples during playback?
* Could the amount of beats be controlled by a MIDI CC message?

Take at look at how the `sampleVolume` is already controlled (line 185 in `IAP.cpp`):

```cpp
    if(cc == 21){ sampleVolume = value / 127.0; }
```

Could we do something similar using a _shared variable_ in the header (.h) file and a 'for loop' to help with this feature?

  ```cpp
    // in your .h file...
    int amountOfBeats = 4;
```

You **could add this code below** to your `callbackCCValueChanged()` function of the `IAP.cpp` file to complete this feature.

```cpp
    if(cc == 22){ amountOfBeats = value; }
```

Talk to one of the team if you want to explore this further...

## Broken beat 

Let's adjust the rhythm to make the timing between beats uneven. Adjust the `aserveSleep()` values so that some are shorter, and some are longer... perhaps

```cpp
   sample
   sleep( 100 )
   sample
   sleep( 110 )
   sample
   sleep( 90 )
```

### Extending this further...

* Could the aserveSleep() values still be related using + - * / ?
* Could you use a variable that increases/decreases over time?
* Maybe the aserveSleep() calls could be controlled using a MIDI CC message? This will be a similar principle as the `amountOfBeats` example above...

## Pixel fun

Why not make use of the Aserve Pixel Grid display area... **Try replacing your `callbackCCValueChanged()` with the starting point code below**

```cpp
void IAP::callbackCCValueChanged (int cc, int value)
{
  if( cc == 51 )               // left most button under the sliders
  {
    aserveSetPixelGrid(0, 15);
    aserveSetPixelGrid(1, 9);
    aserveSetPixelGrid(2, 9);
    aserveSetPixelGrid(3, 9);
    aserveSetPixelGrid(4, 15);
   }
  
  if( cc == 52)                // button under the second slider from the left
  {
    aserveSetPixelGrid(0, 1);
    aserveSetPixelGrid(1, 1);
    aserveSetPixelGrid(2, 1);
    aserveSetPixelGrid(3, 1);
    aserveSetPixelGrid(4, 1);
  }
}
```

## Additive synth

Here's a simple-ish additive synthesiser starting point. **Replace your `run()` function and your `callbackCCValueChanged()` with the starting point below**

```cpp
void IAP::run ()
{
    while(1){ aserveSleep(100); }
}

void IAP::callbackCCValueChanged (int cc, int value)
{
  float amp = value/127.0;                                  // calculate the amplitude of the partial
  float freq = 148.0;                                       // 148Hz is a good value for the Aserve waveform display

  if( cc == 41 ){ aserveOscillator(0, 1 * freq, amp, 0); }  // fundamental frequency
  if( cc == 42 ){ aserveOscillator(1, 2 * freq, amp, 0); }  // second harmonic
  if( cc == 43 ){ aserveOscillator(2, 3 * freq, amp, 0); }  // ... etc
  if( cc == 44 ){ aserveOscillator(3, 4 * freq, amp, 0); }
  if( cc == 45 ){ aserveOscillator(4, 5 * freq, amp, 0); }
}
```

## Resonant lowpass filter with envelope

This starting point generates a randomised filter sweep. **Replace your `run()` function with the starting point below**

```cpp
void IAP::run ()
{
    Random r;                            // we'll use this randomisation tool below

    aserveOscillator(0, 144, 0.8, 2);    // make a jazz noise here
  
    float freq = r.nextInt(5000) + 1000; // pick a random cutoff frequency
    while(1)
    {      
      aserveLPF( freq );                 // low pass filter
      aserveBPF( freq, 10, 2 );          // resonant peak

      freq *= 0.9;                       // slide down 
      if( freq < 100 )                   // lowest point in the sweep
      {
         freq = r.nextInt(5000) + 1000;  // pick a new random frequency
      }
      
      aserveSleep(100);                  // wait a bit
    }
}
```
# So why are we doing this???

Later on into IAP we will discuss the idea of an 'Extended Project'; a project of your design that incorporates your knowledge of C++ and Aserve to create an awesome synthesiser/sequencer/drum sampler.... the choice is yours!

By thinking about how we can develop, extend and invent new ideas for our work and then successfully implement them, we can hopefully start to imagine what our own synthesiser might look like for the Extended Project. 

This is also a great example of how to manage a larger project. C++ is a fantastic langauge for developing larger, complex projects, and as such, you can use this project as inspiration for:

* Naming and organising variables and functions
* Implementing and combining different ideas
* Layout and formatting code
* Commenting instructions
