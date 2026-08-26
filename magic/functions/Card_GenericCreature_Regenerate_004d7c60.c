/*
 * Decompiled function: Card_GenericCreature_Regenerate
 * Entry Point: 004d7c60
 * Size: 560 bytes
 */
#include "magic.h"


undefined4 Card_GenericCreature_Regenerate(int arg_1,int arg_2,int arg_3,uint arg_4,int arg_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((arg_3 == 0x73) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    bVar1 = (&DAT_006a5f50)[arg_2 * 0x120 + arg_1 * 0x5b20] == '\x02' &&
            (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0 &&
            ((&DAT_006a5f6d)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0);
    if ((bVar1) && (iVar2 = FUN_0040d949(arg_1,arg_4,arg_5), iVar2 == 0)) {
      bVar1 = false;
    }
    if (bVar1) {
      uVar3 = 99;
    }
    else {
      uVar3 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar3 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,arg_4,arg_5), g_ActivePlayer != 1)) {
      DAT_00695df8 = 1;
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
    }
    if ((arg_3 == 0x72) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_SicknessState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
       *(int *)(&g_CardSlot_TapState + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = 0;
      Card_GenericCreature_CanRegenerate(g_DialogPromptHwnd,g_DuelArenaHwnd);
    }
    uVar3 = 0;
  }
  return uVar3;
}


