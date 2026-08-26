/*
 * Decompiled function: FUN_004c5d78
 * Entry Point: 004c5d78
 * Size: 231 bytes
 */
#include "duel.h"


undefined4 FUN_004c5d78(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) -
                     *(int *)(&DAT_0068ef6c + DAT_00676510 * 0x20)) * 0x18;
    }
    if (((arg_3 == 0x81) &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 1) != 0)
        ) && (DAT_0068f0f4 != -1)) {
      Mem_AllocOrFree_004afd1c(DAT_0068ecb0,1,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


