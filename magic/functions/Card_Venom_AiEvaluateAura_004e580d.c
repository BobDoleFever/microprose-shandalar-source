/*
 * Decompiled function: Card_Venom_AiEvaluateAura
 * Entry Point: 004e580d
 * Size: 287 bytes
 */
#include "magic.h"


bool Card_Venom_AiEvaluateAura(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if ((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0040d901(arg_1,4,1);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 4;
    }
    if ((((arg_3 == 0x7f) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX))
       && ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      FUN_0040d7e9(arg_1,4,1);
    }
    bVar1 = false;
  }
  return bVar1;
}


