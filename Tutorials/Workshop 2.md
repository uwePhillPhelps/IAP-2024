# Workshop 2 – Playful and creative extension

This workshop will extend the materials provided in workshop 1 earlier. The idea is to XYZ . By the end of this session you should be familiar with: 

1.	FOO.
2.	BAR.
3.	BAZ. 

## Getting started

The following assumes you have set your `IAP.cpp` and `IAP.h` files to the <a href="../iapProjM/Source/IAP.cpp">starting point CPP</a> and the <a href="../iapProjM/Source/IAP.h"> starting point H file</a> provided. Copy and replace your current files with these to get started 😊

## Drums please!

Your first task is probably to scroll down to the drum sequence section which looks like this

```cpp
  thing
  stuff
  blah
```

...and to **add an extra beat** to turn our 4/4 rhythm into a 5/4 rhythm.

## Broken beat 

Let's adjust the rhythm to make the timing between beats uneven. Adjust the `aserveSleep()` values so that some are shorter, and some are longer... perhaps

```cpp
   sample
   sleep( 100 )
   sample
   sleep( 110 )
   sample
   sleep( 90 )
```

## Pixel fun

Why not make use of the Aserve Pixel Grid display area... add this to your cc callback 

```cpp
void IAP::callbackCCValueChanged (int cc, int value)
{
  if( cc == 51 )               // left most button under the sliders
  {
    aserveSetPixelGrid(0, 15);
    aserveSetPixelGrid(1, 9);
    aserveSetPixelGrid(2, 9);
    aserveSetPixelGrid(3, 9);
    aserveSetPixelGrid(4, 15);
   }
  
  if( cc == 52)                // button under the second slider from the left
  {
    aserveSetPixelGrid(0, 1);
    aserveSetPixelGrid(1, 1);
    aserveSetPixelGrid(2, 1);
    aserveSetPixelGrid(3, 1);
    aserveSetPixelGrid(4, 1);
  }
}
```
