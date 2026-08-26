/*
 * Decompiled function: __allmul
 * Entry Point: 1003d900
 * Size: 52 bytes
 */
#include "deckdll.h"


/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint32_t x,int y,uint32_t width,int height)

{
  if (height == 0 && y == 0) {
    return (ulonglong)x * (ulonglong)width;
  }
  return CONCAT44((int)((ulonglong)x * (ulonglong)width >> 0x20) + y * width + x * height,
                  (int)((ulonglong)x * (ulonglong)width));
}


