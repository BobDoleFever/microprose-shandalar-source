/*
 * Decompiled function: FUN_00464325
 * Entry Point: 00464325
 * Size: 230 bytes
 */
#include "duel.h"


int FUN_00464325(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while ((local_c < (int)(&DAT_00666408)[arg1] && (local_8 == 0))) {
    if ((((*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_c * 0x120) != -1) &&
         (((&DAT_006826cc)[arg1 * 0x5b20 + local_c * 0x120] & 2) != 0)) &&
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg1 * 0x5b20 + local_c * 0x120) * 0x34] & 2) !=
         0)) && (local_c != arg2)) {
      local_8 = 1;
    }
    local_c = local_c + 1;
  }
  return local_8;
}


