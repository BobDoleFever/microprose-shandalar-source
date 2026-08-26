/*
 * Decompiled function: Card_Venom_AiCastScore
 * Entry Point: 004e592c
 * Size: 269 bytes
 */
#include "magic.h"


undefined4 Card_Venom_AiCastScore(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (iVar1 = FUN_0040d949(arg_1,2,1), iVar1 != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
        (iVar1 = FUN_0040d949(arg_1,2,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,2,1), g_ActivePlayer != 1)) {
      FUN_0040d901(arg_1,0,3);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


