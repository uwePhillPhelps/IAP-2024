//
//  IAP.cpp
//

#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    // display a welcome message
    std::cout << "Welcome to the music sequencer\n"

    // these three lines setup our 'default' sequence
    // remove these if you want the program to start silent
    noteVector.push_back( 60 );
    noteVector.push_back( 64 );
    noteVector.push_back( 67 );

    playMode = true; // begin in play mode
    while (true) 
    {
        std::cout << "There are " << noteVector.size() << " notes in the sequence\n";
        if( playMode )
        {
            for(int i=0; i<noteVector.size(); i++) // process each note, in order
            {
                int note = noteVector[i];          // get note at index 'i'
                float frequency = 440 * pow(2, (note-69)/12.0); // calculate current note frequency
                float amplitude = 0.5;                          // fixed amplitude
                aserveOscillator(0, frequency, amplitude, 0);   // let's hear the current note
                aserveSleep( 500 );                             // wait for half a second
            }
        }
        aserveSleep( 500 ); // wait for half a second before repeating    
    }
}

void IAP::callbackCCValueChanged (int cc, int value)
{
    if( cc == 114 ) playMode = false; // stop playback if the stop button is pushed
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    noteVector.push_back( note ); // record received notes into the sequence
}
