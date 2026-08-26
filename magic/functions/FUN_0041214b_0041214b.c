/*
 * Decompiled function: FUN_0041214b
 * Entry Point: 0041214b
 * Size: 251 bytes
 */
#include "magic.h"


undefined4 FUN_0041214b(int arg_1,int arg_2,int arg_3)

{
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


