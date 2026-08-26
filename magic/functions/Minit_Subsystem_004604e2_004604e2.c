/*
 * Decompiled function: Minit_Subsystem_004604e2
 * Entry Point: 004604e2
 * Size: 258 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004604e2(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + (6 - (&DAT_006b3008)[arg_1]) * 0xc;
  }
  if ((arg_3 == 0x77) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    iVar1 = FUN_0040d949(arg_1,7,3);
    if ((iVar1 != 0) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,3);
      if (g_ActivePlayer != 1) {
        FUN_0046f5d1(arg_1);
      }
    }
  }
  return 0;
}


