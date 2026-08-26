/*
 * Decompiled function: FUN_004670b0
 * Entry Point: 004670b0
 * Size: 269 bytes
 */
#include "duel.h"


undefined4 FUN_004670b0(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (iVar1 = FUN_0049b309(arg_1,2,1), iVar1 != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
        (iVar1 = FUN_0049b309(arg_1,2,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,2,1), DAT_00681ea4 != 1)) {
      FUN_0049b2c1(arg_1,0,3);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_0068f0f4 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


