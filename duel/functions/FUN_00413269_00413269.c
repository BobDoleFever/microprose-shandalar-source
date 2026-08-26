/*
 * Decompiled function: FUN_00413269
 * Entry Point: 00413269
 * Size: 258 bytes
 */
#include "duel.h"


undefined4 FUN_00413269(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + (6 - (&DAT_0068ee78)[arg_1]) * 0xc;
  }
  if ((arg_3 == 0x77) &&
     (((&DAT_004ff594)
       [*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34] & 0x40) != 0)
     ) {
    iVar1 = FUN_0049b309(arg_1,7,3);
    if ((iVar1 != 0) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,3);
      if (DAT_00681ea4 != 1) {
        FUN_00487ce1(arg_1);
      }
    }
  }
  return 0;
}


