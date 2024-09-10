// Unit Test copy: DO NOT EDIT THIS HEADER 
// Failed_IAP.cpp
// IAPProject 
// 				 		
// Created by p3-phelps
// Created by Philip Phelps
// Tested On 14 Aug 2024 12:15:41pm
// End of Header;


#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    aserveBeginUnitTest(7); // hidden test 8
  
    while (true)
    {
        if (playBtn == true)
        {
            for(int i = 0; i < noteList.size() && playBtn == true; i++)
            {
                int note = noteList[i];
                synth.playNote(note, 127);
                aserveSleep(250);
            }
            playBtn = false;
        }
        else
        {
            aserveSleep(1);
        }
    }
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (velocity > 0)
    {
        noteList.push_back(note);
        synth.playNote(note, velocity);
    }
    else
    {
        synth.stopNote(note);
    }
}

void IAP::callbackCCValueChanged (int cc, int value)

{
    if (cc == 114)
    { //stop
        playBtn = false;
    }
  
    if (cc == 115 && value == 127)
    { //play
        playBtn = true;
    }
  
    if (cc == 117 && value == 127)
    { //erase
        noteList.clear();
    }
  
    if (cc == 112 && value == 127)
    { //fwd
        std::sort(noteList.begin(), noteList.end());
    }
  
    if (cc == 113 && value == 127)
    { //back
        std::reverse(noteList.begin(), noteList.end());
    }
  
    if (cc == 116 && value == 127)
    { //rand
        std::random_shuffle(noteList.begin(), noteList.end());
    }
  
}

