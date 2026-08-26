/*
 * Decompiled function: Card_DamagePrevention_ClearAtCleanup
 * Entry Point: 004ddf98
 * Size: 199 bytes
 */
#include "magic.h"


undefined4 Card_DamagePrevention_ClearAtCleanup(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  
  if (((&DAT_0051aebd)
       [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
        * 0x34] == '\x02') && (arg_3 == 0x34)) {
    cVar1 = FUN_0041d963(arg_1,arg_2,1);
    g_ActivePalette = g_ActivePalette | (1 << (cVar1 - 1U & 0x1f)) + 0x200U;
  }
  if (((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    CardQuery_ForEachPermanent(Card_DamagePrevention_QueryAmount,-1);
    Ai_Subsystem_004cc9c5(0,0xff);
  }
  return 0;
}


