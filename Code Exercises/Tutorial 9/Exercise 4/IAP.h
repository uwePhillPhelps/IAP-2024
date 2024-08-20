//
//  IAP.h
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

//---------------------------------------------------------------------
// USER CREATED CLASS
// You might add your own classes, like 'IAPSynth' or 'Person'
class IAPSynth : public AserveComs  {
public:
    //---------------------------------------------------------------------
    // SHARED VARIABLES (member variables)
    // You might add your own variables, like 'wave' or 'currentNote'
  
    //---------------------------------------------------------------------
    // FUNCTIONS (class methods)
    // You might add your own functions, like 'mtof()' or 'playNote()'
    void introduceYourself()
    {
        std::cout << "Hi, I'm an IAPSynth \n";
        std::cout << "I don't make noise yet... but I will soon! \n";
    }
};

class IAP : public AserveComs  {
public:
  
    //---------------------------------------------------------------------
    // SHARED VARIABLES (IAP member variables)
    // You might add your own variables, like 'wave' or 'currentNote'
    IAPSynth synth;
  
    //---------------------------------------------------------------------
    // FUNCTIONS (IAP class methods)
    // You might add your own functions, like 'mtof()' or 'minorChord()'
    void run ();
  
    //---------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    void callbackNoteReceived  (int note, int velocity, int channel);
    void callbackCCValueChanged (int cc, int value);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackMIDIReceived (MIDI message);
    //void callbackPixelGrid (int x, int y);

private:

};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
