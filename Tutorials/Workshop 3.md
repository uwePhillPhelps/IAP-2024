# Workshop 3 – Audio processing

This workshop will introduce audio effect processing. The idea is to record your own audio and/or use the supplied recordings for creative and playful exploration. By the end of this session you should be familiar with: 

1.	Recording audio and audio effect plugins
2.	Basic digital signal processing concepts
3.	Building and installing audio plugin .components

The workshop text assumes you understand what Digital Audio Workstations (DAW) is and how audio effect plugins can be inserted onto audio tracks/channels within a DAW. Step by step instructions are provided, so even if you're not totally familiar with these concepts yet, you can still have fun in this workshop. 😊

## Putting the puzzle pieces together

![a diagram of required tools and elements](./images/IAPaudioplug_elements.png) 

You'll use Xcode to build the `IAPAudioPlug` audio plugin `.component`...

...then use Logic to record your own audio onto the timeline and...

...load the `IAPaudioplug` as an insert effect in Logic to...

...process your sound with an audio plugin that **you have designed**... 👍

## Getting started

We provide several files as a starting point. These files are compatible with the MacOS software on lab machines. All files are zipped for convenient distribution.

1. Download `IAPAudioPlug.zip` from designated download location 
2. Download `Logic_DAW_Project.zip` from designated download location
   a. Put this file aside for later. We will need it soon, but not initially

## A word of warning

If you accidentally open the supplied Logic DAW project before the plugin is ready, an error message will warn you of a required, missing component.

![a screenshot of the error message](./images/IAPaudioplug_missing.png) 

The supplied xcode project and code will build this missing component, allowing you to experiment with simple audio effect processing such as:
* Gain
* Panning
* Distortion
* Delay
* Tremolo
* ...and more (if you desire!)!

## Exercise 1 - Build

1. Unzip the `IAPAudioPlug.zip`, navigate to the folder `builds > MacOSX` and load the `IAPAudioPlug.xcodeproj` with xcode.
2. Use the menu to select `Product > Scheme > IAPAudioPlug-ALL`

   a. For the curious: different schemes configure different types of plugin technology.

   b. The icons for various schemes are different. The desired scheme has a dart-board target icon similar to this 🎯
   
3. Build the project – await success  <img height="80px" src="./images/xcodeBuildSucceded.png" alt="xcode build success"></img>

4. Examine the files within the `IAPAudioPlug > builds > MacOSX` folder

   a. there should now be a `build -> Debug` folder containing a variety of files

   b. focus your attention on the `IAPAudioPlug.component` - confirm the date modified matches todays date and time

! a screenshot showing the xcode build folder ] ( ./images/IAPaudioplug_buildfolder.png

## Exercise 2 - Install

On MacOS there are several places one may install an audio plugin component. The most convenient is within your personal 'home' Library folder.
We need to drag the `IAPAudioPlug.component` into this 'home' library folder, so we'll need a secondary Finder window.

1. Select the Finder and use the menu `Finder > New Finder Window`
2. Then use the menu `Go > Go to Folder...`
3. Search for `~/Library/Audio/Plug-ins/Components`

   a. Be **absolutely sure to use the `~` symbol in the search path here**

   b. Finder will not permit you to access the 
   'root' Library folder

   c. The `~` symbol indicates you wish to access your personal 'home' Library folder

   d. Ask a member of staff if you need assistance

4. Drag the `IAPAudioPlug.component` into your personal 'home' Library of audio plugin components.

! animation showing installation of IAPaudioplug.component ] ( ./images/IAPaudioplug_install.gif

## Exercise 3 - Creative exploration!

1. Open the downloaded Logic DAW project
2. Voila! Plugin do the things. Happy fun time exploration yay! 😊

If everything has gone well, you will see the IAPaudioplug controls, similar to the screenshot below.

![a screenshot of the IAPaudioplug controls](./images/IAPaudioplug.png)

---
Congratulations on building your first audio plugin 😀🎉

Now begins the fun!

# Creative prompts

* Play with the plugin to hear what it does to the sound

   * You can use the recording provided...
   
   * ...or you can record your own sound in logic to experiment

   * ...or you can use "monitor" mode to hear the effect on the live microphone input

   * Change the plugin `choiceParam` to different settings. All choices do something, and there is room for *creative opportunities* and improvements that you can decide 😊

* Read our helpful code comments provided in the xcode project

   * Focus your attention on the `PluginProcessor.cpp` and `PluginProcessor.h` files

* Read the guidance in the sections below for further inspiration and guidance

## Gain

In this mode, the starting point code adjusts gain (turns up and down the volume) according to the slider `floatParam` value.

Here are some questions to ask yourself:

1. Which part of `PluginProcessor.cpp` does the audio processing code appear?

2. Which part of the code runs when the `choiceParam` is set to `GAIN`?

3. What happens when you adjust the lines which say `*channel... *= stereoGain;` to `*channel... *= 2 * stereoGain;`

   * Remember that there are **two signals**, one for the left channel, one for the right.

   * Remember to rebuild the component and reload the logic project to test your changes 👍

4. Find and **uncomment** the code for a stereo panner effect.

   * When you rebuild and test the plugin, this **should** be stereo panner **BUT ITS NOT**. Can you figure out why? 
   
   * Hint: Why is it not possible hear a stereo-pan for a silent signal?

## Distortion

In this mode, the starting point code distorts the sound according to the slider `floatParam` value.

* Which part of `PluginProcessor.cpp` is the distortion processing code?

* The distortion is **deliberately soft**; is it too weak? how to make it stronger? 

* What happens to the sound when you comment out one of the `if` statements? Can you hear the difference?

## Delay

* Delay -> non-Feedback vs Feedback – differences? Change delay time? 

## Tone

* Tone gen modify`+=` symbols to `*=` for tone vs ring modulation

* Tone gen modify oscillator frequency for tremolo
