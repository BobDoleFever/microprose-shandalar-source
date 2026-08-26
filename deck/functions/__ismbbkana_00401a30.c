/*
 * Decompiled function: __ismbbkana
 * Entry Point: 00401a30
 * Size: 68 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ismbbkana
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkana(uint32_t arg_1)

{
  int val_1;
  
  if ((DAT_00412c6c == 0x3a4) && (val_1 = x_ismbbtype((uint8_t)arg_1,0,3), val_1 != 0)) {
    return 1;
  }
  return 0;
}


