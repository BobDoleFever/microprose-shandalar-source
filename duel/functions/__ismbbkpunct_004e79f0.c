/*
 * Decompiled function: __ismbbkpunct
 * Entry Point: 004e79f0
 * Size: 32 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ismbbkpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkpunct(uint arg_1)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)arg_1,0,2);
  return iVar1;
}


