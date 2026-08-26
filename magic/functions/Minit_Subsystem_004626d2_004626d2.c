/*
 * Decompiled function: Minit_Subsystem_004626d2
 * Entry Point: 004626d2
 * Size: 824 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004626d2(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((byte)g_PlayerHandCardCount & 4) == 0) || (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 == 0))
       || (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      if ((local_8 == -1) ||
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) !=
          DAT_006ff2e0)) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (*(int *)(&g_CardSlot_ConvertedManaCost +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost +
                *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) + -1;
      }
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((arg_3 == 0x22) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      FUN_0041da41(arg_1,arg_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


