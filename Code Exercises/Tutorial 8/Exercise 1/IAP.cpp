//
//  IAP.cpp
//  Starting point for Tutorial 8, Exercise 1
//

#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    std::cout << "Please move the modwheel to start\n";

    // pause until shared modwheel value changes
    sharedModwheel = 0;
    while( sharedModwheel == 0 )
    {
       aserveSleep( 1000 );
    }
    std::cout << "Thanks!\n";

    // make a short rising tone using a do-while loop
    float frequency = 200;
    do
    {
      std::cout << ".";                        // display progress
      aserveOscillator(0, frequency, 0.5, 0);  // make a sound
      aserveSleep( 50 );                       // very short delay

      frequency = frequency + 50;              // higher frequency next loop
    }
    while( frequency < 2000 );                 // until maximum reached
    std::cout << "Goodbye\n";

}

void IAP::callbackModWheelMoved (int value)
{
    // when the modwheel moves, share it's value
    sharedModwheel = value; 
}
