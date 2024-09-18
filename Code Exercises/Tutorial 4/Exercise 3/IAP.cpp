//
//  IAP.cpp
//

#include "IAP.h"
#include <iostream>

/* This is our main function code. Nearly Everything goes in here. */
void IAP::run ()
{
    aserveLoadDefaultSounds();
    while (true) {
        aserveSleep(1000);
    }
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    std::cout << "Received " << note << "\n";

    if( note == 60 ) std::cout << "Boing\n";
    if( note == 61 ) std::cout << "Boom\n";
    if( note == 62 ) std::cout << "Tschak\n";
}
