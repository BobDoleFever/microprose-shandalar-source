/*
 * Decompiled function: Minit_Subsystem_004603b5
 * Entry Point: 004603b5
 * Size: 301 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004603b5(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         (((&g_PlayerCreatureCount)[g_CurrentTurnPhase] + 4) -
         (&g_PlayerCreatureCount)[g_ActivePlayerPriority]) *
         *(int *)(&DAT_0063ee4c + g_ActivePlayerPriority * 0x20) * 6;
  }
  if (((arg_3 == 0x77) && (g_OverworldPlayerCoordX == arg_1)) &&
     (((&g_MasterCardColorTable)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] & 0x40) != 0)) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if ((iVar1 != 0) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      if (g_ActivePlayer != 1) {
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
      }
    }
  }
  return 0;
}


