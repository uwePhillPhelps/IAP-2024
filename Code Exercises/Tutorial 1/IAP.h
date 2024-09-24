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
    //void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackCCValueChanged (int cc, int value);
    //void callbackMIDIReceived (MIDI message);
    //void callbackPixelGrid (int x, int y);

private:

};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
