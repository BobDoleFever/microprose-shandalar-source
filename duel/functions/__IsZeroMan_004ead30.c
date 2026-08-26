/*
 * Decompiled function: __IsZeroMan
 * Entry Point: 004ead30
 * Size: 77 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 1998 Debug */

undefined4 __IsZeroMan(int arg_1)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 1;
    }
    if (*(int *)(arg_1 + local_8 * 4) != 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}


