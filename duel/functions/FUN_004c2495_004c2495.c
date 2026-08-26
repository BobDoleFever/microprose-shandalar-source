/*
 * Decompiled function: FUN_004c2495
 * Entry Point: 004c2495
 * Size: 249 bytes
 */
#include "duel.h"


undefined4 FUN_004c2495(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068ee70 + (7 - arg_1) * 4) - (&DAT_0068ee88)[arg_1]) * 0x18;
    }
    if (((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) && (arg_3 == 0x7c)) &&
       (((&DAT_004ff594)
         [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x40) !=
        0)) {
      Mem_AllocOrFree_004afd1c(DAT_0068ecb0,1,arg_1,arg_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


