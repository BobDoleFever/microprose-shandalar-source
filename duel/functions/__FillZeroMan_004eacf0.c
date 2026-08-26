/*
 * Decompiled function: __FillZeroMan
 * Entry Point: 004eacf0
 * Size: 57 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __FillZeroMan
   
   Library: Visual Studio 1998 Debug */

void __FillZeroMan(int arg_1)

{
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    *(undefined4 *)(arg_1 + local_8 * 4) = 0;
  }
  return;
}


