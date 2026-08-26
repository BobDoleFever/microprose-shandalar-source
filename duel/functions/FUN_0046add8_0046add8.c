/*
 * Decompiled function: FUN_0046add8
 * Entry Point: 0046add8
 * Size: 351 bytes
 */
#include "duel.h"


int FUN_0046add8(int x,int y,int width,uint height)

{
  uint uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
      if (((*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_10 * 0x120) != -1) &&
          (((&DAT_006826cc)[local_8 * 0x5b20 + local_10 * 0x120] & 2) != 0)) &&
         ((height & (byte)(&DAT_004ff594)
                          [*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_10 * 0x120) * 0x34]) !=
          0)) {
        uVar1 = FUN_004521e2(x,y);
        if ((*(uint *)(&DAT_006826fc + local_8 * 0x5b20 + local_10 * 0x120) & uVar1) == 0) {
          *(int *)(width + local_c * 8) = local_8;
          *(int *)(width + 4 + local_c * 8) = local_10;
          local_c = local_c + 1;
        }
      }
    }
    if ((height & 0x100) != 0) {
      *(int *)(width + local_c * 8) = local_8;
      *(undefined4 *)(width + 4 + local_c * 8) = 0xffffffff;
      local_c = local_c + 1;
    }
  }
  return local_c;
}


