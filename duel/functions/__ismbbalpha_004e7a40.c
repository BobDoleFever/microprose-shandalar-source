/*
 * Decompiled function: __ismbbalpha
 * Entry Point: 004e7a40
 * Size: 35 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ismbbalpha
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbalpha(uint arg_1)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)arg_1,0x103,1);
  return iVar1;
}


