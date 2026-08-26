/*
 * Decompiled function: Minit_Subsystem_0045e071
 * Entry Point: 0045e071
 * Size: 395 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045e071(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((&g_PlayerCreatureCount)[arg_1] - (&g_PlayerCreatureCount)[1 - arg_1]) * 0x18;
  }
  if (((arg_3 == 2) || (arg_3 == 3)) &&
     ((g_OverworldMapGrid == arg_2 &&
      ((g_OverworldPlayerCoordX == arg_1 &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))))) {
    g_ActivePalette = g_ActivePalette | 2;
  }
  if (((((arg_3 == 4) || (arg_3 == 5)) || (arg_3 == 199)) &&
      ((g_OverworldMapGrid == arg_2 && (g_OverworldPlayerCoordX == arg_1)))) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    Mem_AllocOrFree_0041df33(g_DefendingPlayer,1,arg_1,arg_2);
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


