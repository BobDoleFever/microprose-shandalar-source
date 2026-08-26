/*
 * Decompiled function: FUN_00411753
 * Entry Point: 00411753
 * Size: 341 bytes
 */
#include "magic.h"


undefined4 FUN_00411753(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x34) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) == g_OverworldMapGrid)
       ) && ((char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] ==
             g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) {
    g_ActivePalette =
         g_ActivePalette &
         ~*(uint *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120);
  }
  if ((arg_3 == 0x22) || (arg_3 == 199)) {
    if ((&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] != -1) {
      *(undefined4 *)
       (&g_CardSlot_Abilities2 +
       *(int *)(&g_CardSlot_OriginalCardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120 +
       (char)(&g_CardSlot_Toughness)[arg_1 * 0x5b20 + arg_2 * 0x120] * 0x5b20) = 0x8000000;
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,1);
  }
  return 0;
}


