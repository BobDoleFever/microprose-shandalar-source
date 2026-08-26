/*
 * Decompiled function: Minit_Subsystem_00460a22
 * Entry Point: 00460a22
 * Size: 472 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00460a22(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
     (((g_ActivePlayerPriority == arg_1 &&
       (iVar1 = FUN_004fa4b8(arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20),
                             arg_1), iVar1 != 0)) &&
      (3 < *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) / iVar1)))) {
    g_SpellStackDepth = g_SpellStackDepth + 0x30;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,4);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,4), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,4), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0046f5d1(arg_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


