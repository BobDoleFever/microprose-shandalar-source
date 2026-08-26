/*
 * Decompiled function: FUN_004137a7
 * Entry Point: 004137a7
 * Size: 470 bytes
 */
#include "duel.h"


undefined4 FUN_004137a7(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) &&
     (((arg_1 == DAT_00676504 &&
       (iVar1 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1),
       iVar1 != 0)) && (3 < *(int *)(&DAT_0068ef6c + DAT_00676504 * 0x20) / iVar1)))) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,4);
    if ((iVar1 == 0) ||
       (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) !=
          0)) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,4), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,4), DAT_00681ea4 != 1)) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_00487ce1(arg_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


