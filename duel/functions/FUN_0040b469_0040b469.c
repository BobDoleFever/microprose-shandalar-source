/*
 * Decompiled function: FUN_0040b469
 * Entry Point: 0040b469
 * Size: 445 bytes
 */
#include "duel.h"


undefined4 FUN_0040b469(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      FUN_0046e571(arg_1,arg_2,4);
    }
    if (arg_3 == 0x72) {
      for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) != -1) {
          FUN_004d7b2d(arg_1,*(undefined4 *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000));
          *(undefined4 *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
        }
      }
      FUN_00451482(0,0x30);
      FUN_004d7946(arg_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


