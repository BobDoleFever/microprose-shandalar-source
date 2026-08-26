/*
 * Decompiled function: __ismbbkana
 * Entry Point: 004e7b30
 * Size: 68 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ismbbkana
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkana(uint arg_1)

{
  int iVar1;
  
  if ((DAT_0050a304 == 0x3a4) && (iVar1 = x_ismbbtype((byte)arg_1,0,3), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


