/*
 * Decompiled function: Card_IslandSanctuary_AttackRestriction
 * Entry Point: 004d31a9
 * Size: 128 bytes
 */
#include "magic.h"


undefined4 Card_IslandSanctuary_AttackRestriction(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x78) && (DAT_006b2d5c == arg_2)) && (DAT_007006c8 == arg_1)) &&
     ((&DAT_0051aebd)
      [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
       * 0x34] == '\0')) {
    g_ActivePalette = 1;
  }
  return 0;
}


