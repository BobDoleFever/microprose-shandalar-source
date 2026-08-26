/*
 * Decompiled function: __ismbbalpha
 * Entry Point: 00401940
 * Size: 35 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ismbbalpha
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbalpha(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x103,1);
  return val_1;
}


