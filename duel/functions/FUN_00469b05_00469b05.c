/*
 * Decompiled function: FUN_00469b05
 * Entry Point: 00469b05
 * Size: 311 bytes
 */
#include "duel.h"


int FUN_00469b05(int arg1,int arg2)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_c == 0))) {
    local_10 = 0;
    while ((local_10 < (int)(&DAT_00666408)[local_8] && (local_c == 0))) {
      if (((*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&DAT_006826cc)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2
          ) != 0)) {
        uVar1 = FUN_004521e2(arg1,arg2);
        if ((*(uint *)(&DAT_006826fc + local_10 * 0x120 + local_8 * 0x5b20) & uVar1) == 0) {
          local_c = 1;
        }
      }
      local_10 = local_10 + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_c;
}


