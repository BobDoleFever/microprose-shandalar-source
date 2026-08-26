/*
 * Decompiled function: FUN_00412246
 * Entry Point: 00412246
 * Size: 461 bytes
 */
#include "magic.h"


undefined4 FUN_00412246(int arg_1,int arg_2,int arg_3)

{
  if ((((g_PlayerManaPool == 0xcc) || (arg_3 == 199)) && (arg_2 == g_OverworldMapGrid)) &&
     (arg_1 == g_OverworldPlayerCoordX)) {
    if (arg_3 == 0x7d) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
        Mem_AllocOrFree_0041df33(arg_1,5,arg_1,arg_2);
      }
      if ((*(int *)(&g_CardSlot_CardId +
                   *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                   (char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) !=
           -1) && (((&g_CardSlot_Flags)
                    [*(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
                     (char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20] &
                   2) != 0)) {
        Pic_Subsystem_0044867e
                  ((int)(char)(&g_CardSlot_DamageReceived)[arg_1 * 0x5b20 + arg_2 * 0x120],
                   *(int *)(&g_CardSlot_TypeFlags + arg_1 * 0x5b20 + arg_2 * 0x120),1);
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
  }
  return 0;
}


