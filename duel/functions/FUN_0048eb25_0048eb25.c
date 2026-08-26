/*
 * Decompiled function: FUN_0048eb25
 * Entry Point: 0048eb25
 * Size: 142 bytes
 */
#include "duel.h"


int FUN_0048eb25(int arg1,int arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return -1;
    }
    if (*(int *)(&DAT_00690320 + local_8 * 4) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_00690320 + local_8 * 4) = arg1;
  *(int *)(&DAT_00681ee0 + local_8 * 4) = arg2;
  *(int *)(&DAT_006826f4 + arg2 * 0x120 + arg1 * 0x5b20) = local_8;
  return local_8;
}


