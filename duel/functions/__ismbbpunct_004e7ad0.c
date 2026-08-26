/*
 * Decompiled function: __ismbbpunct
 * Entry Point: 004e7ad0
 * Size: 32 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ismbbpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbpunct(uint arg_1)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)arg_1,0x10,2);
  return iVar1;
}


