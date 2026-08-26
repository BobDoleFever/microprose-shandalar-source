/*
 * Decompiled function: FUN_00415a9c
 * Entry Point: 00415a9c
 * Size: 608 bytes
 */
#include "duel.h"


undefined4 FUN_00415a9c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ed2c + DAT_00676504 * 0x20) * 3 + -0xc) * 4;
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,2);
    if ((iVar1 == 0) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(1);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      FUN_00461047(arg_1,arg_2);
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      FUN_004612b0(arg_1,arg_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] = 0;
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffffffef;
    }
    if (((arg_3 == 0x22) || (arg_3 == 199)) &&
       (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      FUN_0046e571(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


