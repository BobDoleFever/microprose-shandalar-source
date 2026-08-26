/*
 * Decompiled function: __ismbbalnum
 * Entry Point: 00401910
 * Size: 35 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ismbbalnum
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbalnum(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x107,1);
  return val_1;
}


