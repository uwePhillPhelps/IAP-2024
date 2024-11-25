//
//  IAP.cpp
//

#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    while (true)
    {
        aserveSleep(1000);
    }
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    // in the first part of this exercise...
    // ...you might perform an adjustment to the 'note' value...
    // ...before calculating frequency...
    
    float frequency = 440.0 * pow(2.0, (note-69)/12.0);  // calculate frequency
  
    if (velocity > 0)
    {
        aserveOscillator(0, frequency, 1.0, 0);
    }
    else
    {
        aserveOscillator(0, 0, 0, 0);
    }
}

void IAP::callbackCCValueChanged (int cc, int value)
{
    // in the later parts of this exercise...
    // ...you might select between multiple possible scales like this
    //if (cc == 51 ) { desiredScale = 0; }
    //if (cc == 52 ) { desiredScale = 1; }
}
