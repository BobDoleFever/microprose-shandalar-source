/*
 * Decompiled function: FUN_0040b327
 * Entry Point: 0040b327
 * Size: 322 bytes
 */
#include "duel.h"


undefined4 FUN_0040b327(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,2);
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
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
    }
    if (arg_3 == 0x72) {
      FUN_00487ce1(arg_1);
      Palette_Color_0049ae00(arg_1,0,0);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


