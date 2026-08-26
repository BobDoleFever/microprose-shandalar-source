/*
 * Decompiled function: Card_RodOfRuin_SelectTarget
 * Entry Point: 004e095b
 * Size: 348 bytes
 */
#include "magic.h"


undefined4 Card_RodOfRuin_SelectTarget(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       ((*(byte *)(&DAT_006a2828 + arg_1) & 0x40) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = CardTarget_HasValidPlayerOrCreatureTarget(arg_1);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_DirectDamage_EvaluateBestTarget(arg_1,arg_2);
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(arg_1,arg_2,0x72,2);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


