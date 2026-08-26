/*
 * Decompiled function: __allmul
 * Entry Point: 004e0730
 * Size: 52 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio 1998 Debug */

longlong __allmul(uint x,int y,uint width,int height)

{
  if (height == 0 && y == 0) {
    return (ulonglong)x * (ulonglong)width;
  }
  return CONCAT44((int)((ulonglong)x * (ulonglong)width >> 0x20) + y * width + x * height,
                  (int)((ulonglong)x * (ulonglong)width));
}


