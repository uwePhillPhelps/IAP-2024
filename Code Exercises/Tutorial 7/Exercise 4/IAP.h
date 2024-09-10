//
//  IAP.h
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

class IAP : public AserveComs  {
public:
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES
    // You might add your own variables, like 'wave' or 'currentNote' here
  
    // Later parts of the exercise select between multiple possible scales
    //int desiredScale = 0;
  
    //---------------------------------------------------------------------------------
    // FUNCTIONS
    void run ();

    // Later parts of the exercise use this for scale quantisation
    int  majorScale( int note )
    {
        int pitch = note % 12; // calculate pitch
        if( pitch == 0 ) {   } // edit and add scale quantisation code here
        return note;
    }
  
    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    void callbackNoteReceived  (int note, int velocity, int channel);
    void callbackCCValueChanged (int cc, int value);
  
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackMIDIRecived (MIDI message);
    //void callbackPixelGrid (int x, int y);
  
private:
  
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
