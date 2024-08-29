# Workshop 1 – Playful and creative exploration

Welcome to IAP (Introductory audio programming)

<img src="images/start-ignition.jpeg" alt="ignition" height="200px"></img><img src="images/filestruct.png" alt="screenshot of the file and folder structure of the downloaded materials" height="200px"></img>

This workshop will introduce the tools used on the module in a creative and playful way. The idea is to familiarise you with the lab machines, and how we will use the hardware and software on the Introductory Audio Programming module. 

## Getting started

Your **first task** is to download the IAP repository (which contains all of the required materials and applications for the module)

::➡️:: [Download master branch zip file](../../../archive/refs/heads/master.zip) ::⬅️::

Staff can help you set up your own machine for working off-campus, but for now, let's use the lab machines. **University lab machines already have almost everything installed and ready to roll** 😊👍 

## Aserve and the IAP project working together

Once you have downloaded the repository, the next step is to open the Aserve application which looks like the screenshot below.

<img src="images/aserve_screen_shot_a.png" alt="screenshot of the aserve application window"></img>

1. Navigate to the apps folder of the IAP materials that you have downloaded and
2. Open the `Aserve226` application **by right-clicking and choosing the `OPEN` menu option**
3. You may see security warnings (shown below)
   a. please accept the security warnings to open the application

<img src="images/AserveRightclick.png" alt="use the right-click menu to open the aserve226 application" height="300px"></img>
<img src="images/AserveTrust.png" alt="you may safely accept a warning to open the files downloaded" height="300px"></img>

If successful, the Aserve application window will open, but you'll quickly notice that there is no sound (nor much of a response at all!) when you move controls, dials, sliders, or press keys. 

<img src="images/AserveXcodeYourProgram.png" alt="diagram showing how the aserve application works in tandem with the iapProj materials provided - on this module we will introduce audio programming concepts"></img>

The aserve application works in tandem with the iapProj materials provided, and on this module we will teach you how to design and write programs that control how Aserve makes sound in response to your controls. 😀

Code that you write on the module will act as a "decision maker". When you move controls and press keys, code will tell Aserve to generate sound.

## Opening the IAP Project

For this session, we'll use ready-made code. We'll explore it more deeply in later sessions, but for now we'll use it to demonstrate some Aserve features and to explore some of the creative potential. 

The next step is to open the "iapProj" in the Apple Xcode editor softwar.

<img src="images/filestruct.png" alt="screenshot of the file and folder structure of the downloaded materials" height="200px"></img>

1. Look for the iapProj-M folder (the IAP project for Apple M-series CPUs)
2. Expand the folder structure until you can see the Builds > MacOSX > iapProj.xcodeproj file
3. Double click this to open the Xcode editor application automatically load in our project

You may need to accept and close various warnings and welcoming information screens and messages shown below.

<img src="images/IAPprojTrust.png" alt="you may safely accept a warning to open the files downloaded" height="300px"></img><img src="images/WhatsNewInXcode.png" alt="you may safely close any welcoming information screen explaining 'what is new in xcode'" height="300px"></img>

After the Xcode editor application has loaded

1. Expand the project hierarchy until you can see the file `IAP.cpp`
4. **Single click** on `IAP.cpp` to open it for viewing

If you double-click by mistake, close the separate window that will appear, and try again. Ensure your Xcode window looks the same as the screenshot below. 

<img src="images/xcode.png" />
