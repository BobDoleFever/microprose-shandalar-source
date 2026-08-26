/*
 * Decompiled function: __statusfp
 * Entry Point: 004ea400
 * Size: 35 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __statusfp
   
   Library: Visual Studio 1998 Debug */

uint __cdecl __statusfp(void)

{
  uint uVar1;
  byte in_FPUStatusWord;
  
  uVar1 = __abstract_sw(in_FPUStatusWord);
  return uVar1;
}


