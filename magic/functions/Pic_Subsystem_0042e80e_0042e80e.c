/*
 * Decompiled function: Pic_Subsystem_0042e80e
 * Entry Point: 0042e80e
 * Size: 178 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042e80e(int arg_1,int arg_2,int arg_3)

{
  if (((*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid)
      && ((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX))
     && (g_OverworldMapGrid != -1)) {
    (**(code **)(&DAT_0051aec8 + arg_3 * 0x34))(arg_1,arg_2,0x79);
    if (g_ActivePlayer == 1) {
      g_ActivePalette = g_ActivePalette + 1;
      g_ActivePlayer = 0;
    }
  }
  return 0;
}


