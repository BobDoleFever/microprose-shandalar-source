/*
 * Decompiled function: FUN_0046f18f
 * Entry Point: 0046f18f
 * Size: 164 bytes
 */
#include "duel.h"


void FUN_0046f18f(int arg1,int arg2)

{
  int local_8;
  
  if ((DAT_0066aaf4 != 1) && (((&DAT_004ff594)[arg2 * 0x34] & 2) != 0)) {
    FUN_0048d00c(0x17);
  }
  local_8 = 0;
  while( true ) {
    if (499 < local_8) {
      return;
    }
    if (*(int *)(&DAT_0068dd10 + local_8 * 4 + arg1 * 2000) == -1) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_0068dd10 + local_8 * 4 + arg1 * 2000) = arg2;
  return;
}


