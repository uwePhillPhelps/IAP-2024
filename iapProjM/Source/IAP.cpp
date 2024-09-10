//  IAP.cpp
//  Last updated 2024 aug 20

#include "IAP.h"
#include <iostream>

/* **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** ****

 Welcome to the Introductory Audio Programming demo!
 Here we have developed a synthesiser and sample playback system for you to experiment with.
 Below are a series of DEFINITIONS you can change to affect how the system works.
 You can do this by altering the relevant piece of code. For example:
 
 #define BPM 180
 #define BPM 120
 #define BPM 1000 (the skys the limit!)
 
 #define USE_DRUMS true
 #define USE_DRUMS false
 
 #define USE_CHORDS true
 #define USE_CHORDS false
 
 #define USE_HIGH_OCTAVE true
 #define USE_HIGH_OCTAVE false
 
 #define USE_LOW_OCTAVE true
 #define USE_LOW_OCTAVE false

 std::string keySignature = "E Minor";
 std::string keySignature = "B Major";
 std::string keySignature = "B Careful to use the correct formatting!"; (This would not work...)

 **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** */

#define BPM 160

#define USE_DRUMS true
#define USE_CHORDS true

#define USE_HIGH_OCTAVE true
#define HIGH_OCTAVE_MOD 12

#define USE_LOW_OCTAVE true
#define LOW_OCTAVE_MOD -12

std::string keySignature = "C Minor";


/* **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** ****

 If you wish, you may enable the USE_DESKTOP_SOUNDS feature below
 Please make a folder on your desktop called 'sounds' and place 4 samples in it.
 
 0.wav
 1.wav
 2.wav
 3.wav
 
 These samples will play sequentially at crotchet rhythm based on your BPM above.
 If you have additional samples to the ones provided, please use them too!
*/

#define USE_DESKTOP_SOUNDS false

/* **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** ****
 
 Below here is the rest of the code that makes our project work!
 We'll get to this throughout the course of IAP so venture at your own peril.
 
 It it crucial to note here that the code might look scary and overwhelming at first.
 Through slow, bitesize practicals and awesome results, this will become familiar in no time :D
 
**** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** **** */

void IAP::run ()
{
    if( USE_DESKTOP_SOUNDS )
    {
        aserveLoadSample(0, "~/Desktop/sounds/0.wav");
        aserveLoadSample(1, "~/Desktop/sounds/1.wav");
        aserveLoadSample(2, "~/Desktop/sounds/2.wav");
        aserveLoadSample(3, "~/Desktop/sounds/3.wav");
    }
    else
    {
        aserveLoadDefaultSounds();
    }
    
    musicTools.currentKeySignature = keySignature;
    musicTools.getPitchClassesOfKey(musicTools.currentKeySignature);
    
    while(true)
    {
        if(USE_DRUMS)
        {
            aservePlaySample(0, 1.0);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(1, 1.0);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(2, 1.0);
            aserveSleep( BPMToMS(BPM) );
            aservePlaySample(3, 1.0);
            aserveSleep( BPMToMS(BPM) );
        }
        else
        {
            aserveSleep( BPMToMS(BPM*4) );
        }
    }
}

void IAP::callbackNoteReceived(int note, int velocity, int channel)
{
    if(velocity > 0) //Note on message received
    {
        if (USE_CHORDS)
        {
            int transposedNoteRoot = musicTools.transposeNotesToPitchClass(note);
            int transposedNoteFifth = musicTools.transposeNotesToPitchClass(note + 7);
            
            int transposedNoteThird = musicTools.transposeNotesToPitchClass(note + 3);
            if(musicTools.isMajor){ transposedNoteThird = musicTools.transposeNotesToPitchClass(note + 3); }
                
            aserveOscillator(0, musicTools.mtof(transposedNoteRoot), 0.5, 1);
            if(USE_LOW_OCTAVE)  aserveOscillator(3, musicTools.mtof(transposedNoteRoot - LOW_OCTAVE_MOD), 0.25, 1);
            if(USE_HIGH_OCTAVE) aserveOscillator(4, musicTools.mtof(transposedNoteRoot + HIGH_OCTAVE_MOD), 0.25, 1);

            aserveOscillator(1, musicTools.mtof(transposedNoteThird), 0.5, 1);
            if(USE_LOW_OCTAVE)  aserveOscillator(5, musicTools.mtof(transposedNoteThird + LOW_OCTAVE_MOD), 0.25, 1);
            if(USE_HIGH_OCTAVE) aserveOscillator(6, musicTools.mtof(transposedNoteThird + HIGH_OCTAVE_MOD), 0.25, 1);

            aserveOscillator(2, musicTools.mtof(transposedNoteFifth), 0.5, 1);
            if(USE_HIGH_OCTAVE) aserveOscillator(7, musicTools.mtof(transposedNoteFifth + HIGH_OCTAVE_MOD), 0.25, 1);
            if(USE_LOW_OCTAVE)  aserveOscillator(8, musicTools.mtof(transposedNoteFifth - LOW_OCTAVE_MOD), 0.25, 1);
        }
        else
        {
            int transposedNote = musicTools.transposeNotesToPitchClass(note);
            aserveOscillator(0, musicTools.mtof(transposedNote), 0.5, 1);
            if(USE_HIGH_OCTAVE) aserveOscillator(3, musicTools.mtof(transposedNote + HIGH_OCTAVE_MOD), 0.25, 1);
            if(USE_LOW_OCTAVE)  aserveOscillator(4, musicTools.mtof(transposedNote - LOW_OCTAVE_MOD), 0.25, 1);
        }
    }
    else //Note off message received
    {
        aserveOscillator(0, 0, 0, 1);

        if(USE_CHORDS)
        {
            aserveOscillator(1, 0, 0, 1);
            aserveOscillator(2, 0, 0, 1);
        }
      
        if(USE_HIGH_OCTAVE)
        {
            aserveOscillator(4, 0, 0, 0);
            aserveOscillator(6, 0, 0, 0);
            aserveOscillator(8, 0, 0, 0);
        }
      
        if (USE_LOW_OCTAVE)
        {
            aserveOscillator(3, 0, 0, 0);
            aserveOscillator(5, 0, 0, 0);
            aserveOscillator(7, 0, 0, 0);
        }
        
    }
}

void IAP::callbackCCValueChanged(int cc, int value)
{
    if(cc == 51){ musicTools.changeKeySignature(); }
    if(cc == 52){ musicTools.toggleChordMode(); }
}

void IAP::callbackModWheelMoved (int value)
{
    aserveLPF( (value+5) * 100 );
}






