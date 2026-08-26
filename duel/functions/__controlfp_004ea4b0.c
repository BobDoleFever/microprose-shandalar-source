/*
 * Decompiled function: __controlfp
 * Entry Point: 004ea4b0
 * Size: 37 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Debug */

uint __cdecl __controlfp(uint arg1,uint arg2)

{
  uint uVar1;
  
  uVar1 = __control87(arg1,arg2 & 0xfff7ffff);
  return uVar1;
}


