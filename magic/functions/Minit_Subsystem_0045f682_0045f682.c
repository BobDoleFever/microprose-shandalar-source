/*
 * Decompiled function: Minit_Subsystem_0045f682
 * Entry Point: 0045f682
 * Size: 425 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045f682(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) -
         *(int *)(&DAT_0063ee4c + g_CurrentTurnPhase * 0x20)) * 0xc;
  }
  if (((((g_PlayerManaPool == 0xdb) || (g_PlayerManaPool == 0xd3)) &&
       ((arg_2 == g_OverworldMapGrid &&
        ((arg_1 == g_OverworldPlayerCoordX && (DAT_006a4b5c == g_DefendingPlayer)))))) &&
      (*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) != -1)) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] & 1) !=
       0 && ((((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) == 0 ||
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) != 0)))))
     ) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      Mem_AllocOrFree_0041df33(DAT_00695f08,2,arg_1,arg_2);
    }
  }
  return 0;
}


