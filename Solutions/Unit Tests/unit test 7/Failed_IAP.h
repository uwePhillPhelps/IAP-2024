// Unit Test copy: DO NOT EDIT THIS HEADER 
// Failed_IAP.h
// IAPProject 
// 				 		
// Created by p3-phelps
// Created by Philip Phelps
// Tested On 14 Aug 2024 12:15:41pm
// End of Header;


#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

class IAP : public AserveComs  {
public:
    class IAPSynth : public AserveComs {
    public:
        int currentWaveType, lastNote;
        void setWaveType (int wavetype);
        void playNote (int note, int velocity)
        {
            if (velocity > 0){
                aserveOscillator(0, mtof(note), 1.0, wavetype);
            }
        }
        void stopNote (int note)
        {
            if (note == lastNote) {
                aserveClearOscillator(0);
            }
        }
        float mtof(int note)
        {
            return 440.0 * pow(2.0, (note-69)/12.0);
        }
      
        int lastnote = -1;
        int wavetype = 0;
      
    };
  
    //--------------------------------------
    // SHARED VARIABLES
    IAPSynth synth;
    std::vector<int> noteList;
    bool playBtn = false;
  
    //--------------------------------------
    // FUNCTIONS
    void run ();
  
    //--------------------------------------
    // CALLBACK FUNCTIONS
    void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    void callbackCCValueChanged (int cc, int value);
    //void callbackMIDIRecived (MIDI message);
    //void callbackPixelGrid (int x, int y);
  
private:
  
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
