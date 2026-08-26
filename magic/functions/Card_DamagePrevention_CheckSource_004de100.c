/*
 * Decompiled function: Card_DamagePrevention_CheckSource
 * Entry Point: 004de100
 * Size: 192 bytes
 */
#include "magic.h"


undefined4 Card_DamagePrevention_CheckSource(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((&DAT_0051aebd)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] == '\x03') &&
     (((&g_CardSlot_Flags)[g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] & 2) != 0)
     ) {
    if (arg_3 == 0x34) {
      cVar1 = FUN_0041d963(arg_1,arg_2,4);
      g_ActivePalette = g_ActivePalette | 1 << (cVar1 - 1U & 0x1f);
    }
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  return 0;
}


