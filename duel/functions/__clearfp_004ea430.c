/*
 * Decompiled function: __clearfp
 * Entry Point: 004ea430
 * Size: 36 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __clearfp
   
   Library: Visual Studio 1998 Debug */

uint __cdecl __clearfp(void)

{
  uint uVar1;
  byte in_FPUStatusWord;
  
  uVar1 = __abstract_sw(in_FPUStatusWord);
  return uVar1;
}


