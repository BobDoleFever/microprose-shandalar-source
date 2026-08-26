/*
 * Decompiled function: FUN_00468b20
 * Entry Point: 00468b20
 * Size: 408 bytes
 */
#include "duel.h"


int FUN_00468b20(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint uVar2;
  int local_14;
  int local_10;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  do {
    if ((1 < local_8) || (local_10 != 0)) {
      return local_10;
    }
    local_14 = 0;
    while ((local_14 < (int)(&DAT_00666408)[local_8] && (local_10 == 0))) {
      if ((*(int *)(&DAT_006826c4 + local_14 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&DAT_006826cc)[local_14 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        if (*(int *)(&DAT_00618ad8 +
                    *(int *)(&DAT_004ff590 +
                            *(int *)(&DAT_006826c4 + local_14 * 0x120 + local_8 * 0x5b20) * 0x34) *
                    0x98) != arg_3) {
          iVar1 = FUN_00468cb8(*(int *)(&DAT_00618ad8 +
                                       *(int *)(&DAT_004ff590 +
                                               *(int *)(&DAT_006826c4 +
                                                       local_14 * 0x120 + local_8 * 0x5b20) * 0x34)
                                       * 0x98));
          if (iVar1 != arg_3) goto LAB_00468b5f;
        }
        if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_14 * 0x120 + local_8 * 0x5b20) * 0x34] &
            2) != 0) {
          uVar2 = FUN_004521e2(arg_1,arg_2);
          if ((*(uint *)(&DAT_006826fc + local_14 * 0x120 + local_8 * 0x5b20) & uVar2) == 0) {
            local_10 = 1;
          }
        }
      }
LAB_00468b5f:
      local_14 = local_14 + 1;
    }
    local_8 = local_8 + 1;
  } while( true );
}


