/*
 * Decompiled function: Card_DamagePrevention_ApplyBubble
 * Entry Point: 004ddefa
 * Size: 81 bytes
 */
#include "magic.h"


undefined4 Card_DamagePrevention_ApplyBubble(int arg1,int arg2)

{
  if ((arg2 == g_OverworldMapGrid) && (arg1 == g_OverworldPlayerCoordX)) {
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x2000;
  }
  return 0;
}


