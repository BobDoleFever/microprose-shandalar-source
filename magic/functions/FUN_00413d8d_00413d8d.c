/*
 * Decompiled function: FUN_00413d8d
 * Entry Point: 00413d8d
 * Size: 551 bytes
 */
#include "magic.h"


undefined4 FUN_00413d8d(int arg_1,int arg_2,int arg_3)

{
  if ((arg_3 == 0x21) && ((g_ScWillyScore == 0x1a || (g_ScWillyScore == 0x19)))) {
    if (((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
         (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&g_CardSlot_OriginalCardId +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
    }
    if (((&g_CardSlot_DamageReceived)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
         == (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20]) &&
       (*(int *)(&g_CardSlot_TypeFlags +
                g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) = 0;
    }
  }
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


