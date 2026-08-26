/*
 * Decompiled function: __ismbbkpunct
 * Entry Point: 004018f0
 * Size: 32 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ismbbkpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkpunct(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,2);
  return val_1;
}


