/*
 * Decompiled function: FUN_00414875
 * Entry Point: 00414875
 * Size: 210 bytes
 */
#include "magic.h"


undefined4 FUN_00414875(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if ((((arg_3 == 0x73) && (g_ScWillyScore == 10)) && (DAT_0063edc0 == arg_1)) &&
     ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0 &&
      (g_PlayerManaPool == -1)))) {
    DAT_006a4920 = DAT_006a4920 | 3;
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    }
    if (arg_3 == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
      FUN_0046f5d1(arg_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


