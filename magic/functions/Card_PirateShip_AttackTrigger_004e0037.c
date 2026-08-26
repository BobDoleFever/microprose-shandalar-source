/*
 * Decompiled function: Card_PirateShip_AttackTrigger
 * Entry Point: 004e0037
 * Size: 176 bytes
 */
#include "magic.h"


undefined4 Card_PirateShip_AttackTrigger(int arg_1,int arg_2,int arg_3)

{
  if (((arg_3 == 0x1a) && (arg_1 != g_DefendingPlayer)) &&
     ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
  }
  if ((arg_3 == 0x79) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    g_ActivePalette = 1;
  }
  return 0;
}


