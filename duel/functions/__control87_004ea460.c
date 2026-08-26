/*
 * Decompiled function: __control87
 * Entry Point: 004ea460
 * Size: 79 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 1998 Debug */

uint __cdecl __control87(uint arg1,uint arg2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_14;
  
  local_14 = CONCAT22(local_14._2_2_,in_FPUControlWord);
  uVar1 = __abstract_cw(local_14);
  uVar1 = ~arg2 & uVar1 | arg1 & arg2;
  __hw_cw(uVar1);
  return uVar1;
}


