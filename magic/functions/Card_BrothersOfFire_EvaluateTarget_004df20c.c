/*
 * Decompiled function: Card_BrothersOfFire_EvaluateTarget
 * Entry Point: 004df20c
 * Size: 264 bytes
 */
#include "magic.h"


bool Card_BrothersOfFire_EvaluateTarget(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(1);
    bVar1 = false;
  }
  else {
    if (arg_3 == 0x6d) {
      Card_DirectDamage_EvaluateBestTarget(arg_1,arg_2);
    }
    if (arg_3 == 0x72) {
      Card_DirectDamage_PromptAndDealDamage(arg_1,arg_2,0x72,1);
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


