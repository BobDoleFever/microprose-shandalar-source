/*
 * Decompiled function: Minit_Subsystem_0046736a
 * Entry Point: 0046736a
 * Size: 258 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0046736a(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_PlayerHandCardCount = g_PlayerHandCardCount | 0x800 << ((byte)arg_1 & 0x1f);
  }
  if (((arg_3 == 0x1f) && (g_DefendingPlayer == arg_1)) &&
     ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)))) {
    g_ActivePalette = g_ActivePalette + 1;
  }
  if (((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_PlayerHandCardCount = g_PlayerHandCardCount & ~(0x800 << ((byte)arg_1 & 0x1f));
  }
  return 0;
}


