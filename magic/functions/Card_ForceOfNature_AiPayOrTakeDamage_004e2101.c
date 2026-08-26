/*
 * Decompiled function: Card_ForceOfNature_AiPayOrTakeDamage
 * Entry Point: 004e2101
 * Size: 433 bytes
 */
#include "magic.h"


bool Card_ForceOfNature_AiPayOrTakeDamage(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0040d901(arg_1,3,1);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 3;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX))
       && ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0040d7e9(arg_1,3,1);
    }
    if (((arg_3 == 0x8a) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c +
                     (int)(0x18 / (longlong)(*(int *)(&DAT_0063ee3c + arg_1 * 0x20) + 2));
    }
    if (((arg_3 == 0x8b) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
      DAT_006ff19c = DAT_006ff19c -
                     (int)(0x60 / (longlong)(*(int *)(&DAT_0063ee3c + arg_1 * 0x20) + 2));
    }
    bVar1 = false;
  }
  return bVar1;
}


