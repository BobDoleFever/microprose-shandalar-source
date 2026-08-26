/*
 * Decompiled function: FUN_004d7b2d
 * Entry Point: 004d7b2d
 * Size: 125 bytes
 */
#include "duel.h"


int FUN_004d7b2d(int arg1,undefined4 arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_006669f0 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(undefined4 *)(&DAT_006669f0 + local_8 * 4 + arg1 * 2000) = arg2;
  return local_8;
}


