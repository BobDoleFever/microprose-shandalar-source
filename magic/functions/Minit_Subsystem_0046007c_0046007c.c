/*
 * Decompiled function: Minit_Subsystem_0046007c
 * Entry Point: 0046007c
 * Size: 825 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0046007c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x90;
  }
  if (((arg_3 == 0x77) &&
      ((&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] != '\0')) &&
     ((((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20
                 ) * 0x34] & 2) != 0 &&
      ((&DAT_006a5f50)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] != '\x04'))))
  {
    if (((&DAT_006a5f55)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    else {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    }
  }
  if (((g_PlayerManaPool == 0xd5) && (g_OverworldMapGrid == arg_2)) &&
     ((arg_1 == g_OverworldPlayerCoordX &&
      (((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0' &&
       (arg_1 == DAT_006a4b5c)))))) {
    *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
    if ((arg_3 == 0x7d) && (iVar1 = FUN_0040d949(arg_1,7,1), iVar1 != 0)) {
      if ((arg_1 == g_ActivePlayerPriority) &&
         ((int)(&g_PlayerCreatureCount)[arg_1] < (&g_PlayerCreatureCount)[1 - arg_1] + 8)) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      else {
        g_ActivePalette = g_ActivePalette | 1;
      }
    }
    if (arg_3 == 0x7e) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      if (g_ActivePlayer == 1) {
        g_ActivePlayer = -1;
      }
      else {
        (&g_PlayerCreatureCount)[arg_1] = (&g_PlayerCreatureCount)[arg_1] + 1;
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + -1;
      }
    }
    if ((&g_CardSlot_ConvertedManaCost)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0') {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffeff;
    }
  }
  return 0;
}


