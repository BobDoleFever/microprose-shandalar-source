/*
 * Decompiled function: Pic_Subsystem_00433334
 * Entry Point: 00433334
 * Size: 306 bytes
 */
#include "magic.h"


void Pic_Subsystem_00433334(int arg_1,undefined4 arg_2,int arg_3)

{
  if (arg_3 != 0x74) {
    if ((((arg_3 == 0x32) && (g_OverworldPlayerCoordX == arg_1)) &&
        ((&DAT_0051aebd)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] == '\0'))
       && (((byte)*(undefined4 *)
                   (&g_CardSlot_Flags +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) & 0x22) == 2)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    if (((arg_3 == 0x34) && (g_OverworldPlayerCoordX == arg_1)) &&
       (((&DAT_0051aebd)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] == '\0' &&
        (((byte)*(undefined4 *)
                 (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
         & 0x22) == 2)))) {
      g_ActivePalette = g_ActivePalette | 0x40;
    }
  }
  return;
}


