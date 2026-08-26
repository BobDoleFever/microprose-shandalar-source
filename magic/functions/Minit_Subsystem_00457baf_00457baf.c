/*
 * Decompiled function: Minit_Subsystem_00457baf
 * Entry Point: 00457baf
 * Size: 428 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00457baf(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((arg_3 == 199) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
    iVar1 = (&DAT_006b3008)[arg_1] + -4;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    if (arg_1 == 0) {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * -0x18;
    }
    else {
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      g_SpellStackDepth = g_SpellStackDepth + iVar1 * 0x18;
    }
  }
  if (((((g_PlayerManaPool == 0xc9) && (arg_2 == g_OverworldMapGrid)) &&
       (arg_1 == g_OverworldPlayerCoordX)) &&
      ((arg_1 == g_DefendingPlayer && (DAT_006a4b5c == arg_1)))) &&
     ((4 < (int)(&DAT_006b3008)[arg_1] &&
      ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
       (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))))) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) && (4 < (int)(&DAT_006b3008)[arg_1])) {
      (&g_PlayerCreatureCount)[arg_1] =
           (&g_PlayerCreatureCount)[arg_1] + (&DAT_006b3008)[arg_1] + -4;
    }
  }
  return 0;
}


