/*
 * Decompiled function: Duel_GetCardDrawOriginX
 * Entry Point: 004f09c0
 * Size: 138 bytes
 */
#include "magic.h"


int Duel_GetCardDrawOriginX(int arg1,int arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x7f < local_8) {
      return -1;
    }
    if (((*(int *)(&DAT_0067bdf0 + local_8 * 100) != -1) &&
        (*(int *)(&DAT_0067bdf4 + local_8 * 100) == arg1)) &&
       (*(int *)(&DAT_0067bdf8 + local_8 * 100) == arg2)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


