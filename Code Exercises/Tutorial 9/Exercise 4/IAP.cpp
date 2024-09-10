//
//  IAP.cpp
//

#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    while (true) {
        aserveSleep(1000);
        synth.introduceYourself();
    }
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (velocity > 0) {
        /*
         play note
         e.g. synth.playNote( note );
         */
    }
    else {
        /*
         stop note
         e.g. synth.stopNote();
         */
    }
}

void IAP::callbackCCValueChanged (int cc, int value)
{
    if (cc >= 51 && cc <= 56) {
        // Set wavetype to cc-51
        // e.g. synth.setWave( cc - 51 )
    }
}
