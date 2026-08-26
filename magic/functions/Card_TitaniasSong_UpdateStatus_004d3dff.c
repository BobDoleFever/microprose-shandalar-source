/*
 * Decompiled function: Card_TitaniasSong_UpdateStatus
 * Entry Point: 004d3dff
 * Size: 418 bytes
 */
#include "magic.h"


undefined4 Card_TitaniasSong_UpdateStatus(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    arg_2 = Pic_Subsystem_00451291
                      (arg_1,*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20));
    if (arg_2 != -1) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      *(undefined4 *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) = 2;
      *(undefined4 *)(&g_CardSlot_Abilities2 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x8000000;
    }
  }
  if (((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
    if (arg_3 == 0x34) {
      g_ActivePalette = g_ActivePalette | 0x20;
    }
    if (arg_3 == 0x32) {
      g_ActivePalette = g_ActivePalette + 4;
    }
    if (arg_3 == 0x33) {
      g_ActivePalette = g_ActivePalette + 1;
    }
    if (arg_3 == 0x22) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
    }
  }
  return 0;
}


