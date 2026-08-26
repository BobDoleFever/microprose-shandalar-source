/*
 * Decompiled function: Card_KormusBell_CheckSwampCreature
 * Entry Point: 004e2fe8
 * Size: 320 bytes
 */
#include "magic.h"


undefined4 Card_KormusBell_CheckSwampCreature(int arg_1,int arg_2,int arg_3)

{
  if ((g_OverworldMapGrid == arg_2) && (g_OverworldPlayerCoordX == arg_1)) {
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
  }
  if (arg_3 == 199) {
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  if ((((g_PlayerManaPool == 0xcd) && (g_OverworldMapGrid == arg_2)) &&
      (g_OverworldPlayerCoordX == arg_1)) && (DAT_006a4b5c == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x7e) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  if (((arg_3 == 0x8a) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    DAT_006ff19c = DAT_006ff19c + -0x3c;
  }
  if (((arg_3 == 0x8b) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    DAT_006ff19c = DAT_006ff19c + 0x3c;
  }
  return 0;
}


