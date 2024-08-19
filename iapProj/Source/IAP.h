//  IAP.h
//  Last updated 2024 aug 19

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"
#include <unordered_map>

//---------------------------------------------------------------------------------
// USER CREATED CLASS

class IAPMusicTools : public AserveComs
{
public:
    std::array<int, 7> currentPitchClassSet;
    std::string currentKeySignature = "G Minor";
    bool isMajor = false;
    bool isChordMode = false;
    
    std::unordered_map<std::string, int> KeySignatures = {
            {"Ab Major", 0},
            {"A Major", 1},
            {"A# Major", 2},
            {"Bb Major", 3},
            {"B Major", 4},
            {"C Major", 5},
            {"C# Major", 6},
            {"Db Major", 7},
            {"D Major", 8},
            {"D# Major", 9},
            {"Eb Major", 10},
            {"E Major", 11},
            {"F Major", 12},
            {"F# Major", 13},
            {"Gb Major", 14},
            {"G Major", 15},
            {"G# Major", 16},
            {"Ab Minor", 17},
            {"A Minor", 18},
            {"A# Minor", 19},
            {"Bb Minor", 20},
            {"B Minor", 21},
            {"C Minor", 22},
            {"C# Minor", 23},
            {"Db Minor", 24},
            {"D Minor", 25},
            {"D# Minor", 26},
            {"Eb Minor", 27},
            {"E Minor", 28},
            {"F Minor", 29},
            {"F# Minor", 30},
            {"Gb Minor", 31},
            {"G Minor", 32},
            {"G# Minor", 33}
        };
   
    std::unordered_map<std::string, std::array<int, 7>> majorScales = {
        {"Ab Major", {8, 10, 0, 1, 3, 5, 7}},
        {"A Major",  {9, 11, 1, 2, 4, 6, 8}},
        {"Bb Major", {10, 0, 2, 3, 5, 7, 9}},
        {"B Major",  {11, 1, 3, 4, 6, 8, 10}},
        {"C Major",  {0, 2, 4, 5, 7, 9, 11}},
        {"C# Major", {1, 3, 5, 6, 8, 9, 0 }},
        {"D Major",  {2, 4, 6, 7, 9, 11, 1}},
        {"Eb Major", {3, 5, 7, 8, 10, 0, 2}},
        {"E Major",  {4, 6, 8, 9, 11, 1, 3}},
        {"F Major",  {5, 7, 9, 10, 0, 2, 4}},
        {"F# Major", {6, 8, 10, 11, 1, 4, 5}},
        {"G Major",  {7, 9, 11, 0, 2, 4, 6}},
    };
    
    std::unordered_map<std::string, std::array<int, 7>> minorScales = {
           {"C Minor",  {0, 2,  3,  5, 7, 8, 10}},
           {"C# Minor", {1, 3,  4,  6, 8, 9, 11}},
           {"D Minor",  {2, 4,  5,  7, 9, 10, 0}},
           {"Eb Minor", {3, 5,  6,  8, 10, 11, 1}},
           {"E Minor",  {4, 6,  7,  9, 11, 0, 2}},
           {"F Minor",  {5, 7,  8,  10, 0, 1, 3}},
           {"F# Minor", {6, 8,  9,  11, 1, 2, 4}},
           {"G Minor",  {7, 9,  10, 0, 2, 3, 5}},
           {"Ab Minor", {8, 10, 11, 1, 3, 4, 6}},
           {"A Minor",  {9, 11, 0,  2, 4, 5, 7}},
           {"Bb Minor", {10, 0, 1,  3, 5, 6, 8}},
           {"B Minor",  {11, 1, 2,  4, 6, 7, 9}},
       };
    
    void getPitchClassesOfKey(std::string _currentKeySignature)
    {
        int index = KeySignatures.at(_currentKeySignature);
        if(index <= 16)
        {
            currentPitchClassSet = majorScales.at(_currentKeySignature);
            isMajor = true;
        }
        else
        {
            currentPitchClassSet = minorScales.at(_currentKeySignature);
            isMajor = false;
        }
        
        std::cout << "Your chosen scale is: " << currentKeySignature << "\n";
        
    }
    
    int transposeNotesToPitchClass(int note)
    {
        
    int pitchClass = note % 12;
    bool foundNote = false;
    
    for(int i = 0; i < currentPitchClassSet.size(); i++)
    {
        if(currentPitchClassSet[i] == pitchClass)
        {
            foundNote = true;
            break;
        }
    }
    
    if(!foundNote) note++;
    
    return note;
}
    
    float mtof(int note){
    return 440.0 * (pow(2, (note-69.0) / 12.0));
    
}
    
    void changeKeySignature()
    {
        std::cout << "Please enter a new Key Signature in the format 'KEY <space> Tonality' \n";
        std::getline(std::cin, currentKeySignature);
        std::cout << "Key Signature updated to " << currentKeySignature << "\n";
        getPitchClassesOfKey(currentKeySignature);

    }
    
    void toggleChordMode()
    {
        if(isChordMode) { isChordMode = false; std::cout << "Chord Mode Activated\n"; }
            else        { isChordMode = true;  std::cout << "Chord Mode Activated\n"; }
        
    }
  
};

class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES (IAP member variables)
    IAPMusicTools musicTools;
    
    //---------------------------------------------------------------------------------
    // FUNCTIONS (IAP class methods)
    void run ();
    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    void callbackNoteReceived  (int note, int velocity, int channel);
    // void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    void callbackCCValueChanged (int cc, int value);
    
    float BPMToMS(int bpm)
    {
        if (bpm > 10000) bpm = 10000;
        if (bpm < 1 ) bpm = 1;
        
        return 60000.0 / bpm;
        
    }
    
    //void callbackMIDIReceived (MIDI message);
    //void callbackPixelGrid (int x, int y);
  
private:
    
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
