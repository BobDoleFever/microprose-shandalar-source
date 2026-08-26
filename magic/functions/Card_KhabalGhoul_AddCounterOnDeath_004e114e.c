/*
 * Decompiled function: Card_KhabalGhoul_AddCounterOnDeath
 * Entry Point: 004e114e
 * Size: 385 bytes
 */
#include "magic.h"


undefined4 Card_KhabalGhoul_AddCounterOnDeath(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 local_8;
  
  if ((arg_3 == 0x73) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
    local_8 = Card_GenericCreature_Regenerate(arg_1,arg_2,0x73,0,0);
    iVar1 = Card_GetCounters(arg_1,arg_2);
    if (iVar1 == 0) {
      local_8 = 0;
    }
  }
  else if ((arg_3 == 0x6d) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
    local_8 = Card_GenericCreature_Regenerate(arg_1,arg_2,0x6d,0,0);
    Card_RemoveCounters(arg_1,arg_2,1);
  }
  else if ((arg_3 == 0x72) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
    local_8 = Card_GenericCreature_Regenerate(arg_1,arg_2,0x72,0,0);
  }
  else {
    if (((g_PlayerManaPool == 0xcd) || (arg_3 == 199)) &&
       ((((arg_2 == g_OverworldMapGrid && (arg_1 == g_OverworldPlayerCoordX)) && (DAT_006b303c != 0)
         ) && (DAT_006a4b5c == arg_1)))) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Card_AddCounters(arg_1,arg_2,DAT_006b303c);
      }
    }
    local_8 = 0;
  }
  return local_8;
}


