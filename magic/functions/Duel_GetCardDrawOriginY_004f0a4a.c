/*
 * Decompiled function: Duel_GetCardDrawOriginY
 * Entry Point: 004f0a4a
 * Size: 172 bytes
 */
#include "magic.h"


int Duel_GetCardDrawOriginY(int arg1,int arg2)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = -1;
  local_14 = 0x7fff;
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    if ((*(int *)(&DAT_0067bdf0 + local_c * 100) != -1) &&
       (iVar1 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_c * 100) - arg1,
                             *(int *)(&DAT_0067bdf8 + local_c * 100) - arg2), iVar1 < local_14)) {
      local_10 = local_c;
      local_14 = iVar1;
    }
  }
  return local_10;
}


