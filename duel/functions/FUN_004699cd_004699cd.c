/*
 * Decompiled function: FUN_004699cd
 * Entry Point: 004699cd
 * Size: 312 bytes
 */
#include "duel.h"


int FUN_004699cd(int arg_1,int arg_2,int arg_3)

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
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_10 * 0x120) * 0x34] & 2
          ) != 0)) {
        uVar1 = FUN_004521e2(arg_1,arg_2);
        if ((*(uint *)(&DAT_006826fc + local_8 * 0x5b20 + local_10 * 0x120) & uVar1) == 0) {
          *(int *)(arg_3 + local_c * 8) = local_8;
          *(int *)(arg_3 + 4 + local_c * 8) = local_10;
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}


