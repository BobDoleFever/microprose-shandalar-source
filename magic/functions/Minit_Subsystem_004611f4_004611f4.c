/*
 * Decompiled function: Minit_Subsystem_004611f4
 * Entry Point: 004611f4
 * Size: 412 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004611f4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (int)(0xc0 / (longlong)(*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) + 1));
  }
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      g_SpellStackDepth = g_SpellStackDepth + -0xc;
      FUN_0040d901(arg_1,0,2);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 0;
    }
    if (((arg_3 == 0x7f) && (arg_2 == g_OverworldMapGrid)) &&
       ((arg_1 == g_OverworldPlayerCoordX &&
        (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)))) {
      FUN_0040d7e9(arg_1,0,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


