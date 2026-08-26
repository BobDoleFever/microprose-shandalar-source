/*
 * Decompiled function: Minit_Subsystem_0045e1fc
 * Entry Point: 0045e1fc
 * Size: 169 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045e1fc(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (*(int *)(&DAT_006b3010 + arg_1 * 4) - *(int *)(&DAT_006b3000 + (5 - arg_1) * 4)) * 0xc;
  }
  if (((arg_3 == 0x32) &&
      (((&g_CardSlot_Flags)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] & 4) != 0
      )) && (g_DefendingPlayer == g_OverworldPlayerCoordX)) {
    g_ActivePalette = g_ActivePalette + 1;
  }
  return 0;
}


