//
//  IAP.h
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

class IAPSynth : public AserveComs {
public:
    void playNote (int note, int velocity)
    {
        float freq = mtof(note);
        float amp = velocity / 127.0;
        lastNote = note;
        aserveOscillator(0, freq, amp, currentWavetype);
    }
    void stopNote (int note)
    {
        if (lastNote == note) {
            aserveOscillator(0, 0, 0, 0);
            lastNote = 0;
        }
    }
    void setWaveType (int wave)
    {
        currentWavetype = wave;
    }
    float mtof (int note)
    {
        return 440.0 * pow(2.0, (note - 69.0)/ 12.0);
    }
private:
    int lastNote = 0;
    int currentWavetype = 0;
};

class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES
    IAPSynth synth;
    
    int slider1, slider2, slider3, slider4;
    
    //---------------------------------------------------------------------------------
    // FUNCTIONS
    void run ();

    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    
    //void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    void callbackCCValueChanged (int cc, int value);
    
    //void callbackMIDIRecived (MIDI message);
    //void callbackPixelGrid (int x, int y);

private:
    
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
