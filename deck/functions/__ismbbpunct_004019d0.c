/*
 * Decompiled function: __ismbbpunct
 * Entry Point: 004019d0
 * Size: 32 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ismbbpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbpunct(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x10,2);
  return val_1;
}


