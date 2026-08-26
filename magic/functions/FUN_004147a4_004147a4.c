/*
 * Decompiled function: FUN_004147a4
 * Entry Point: 004147a4
 * Size: 189 bytes
 */
#include "magic.h"


undefined4 FUN_004147a4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x72) || (arg_3 == 0x86)) || (arg_3 == 0x7e)) {
    g_DialogPromptHwnd = *(undefined4 *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20);
    g_DuelArenaHwnd = *(undefined4 *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20);
    uVar1 = (**(code **)(&DAT_0051aec8 +
                        *(int *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


