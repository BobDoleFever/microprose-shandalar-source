/*
 * Decompiled function: Card_SamiteHealer_CalculateHealAdvantage
 * Entry Point: 004dd98f
 * Size: 869 bytes
 */
#include "magic.h"


undefined4 Card_SamiteHealer_CalculateHealAdvantage(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((byte)g_PlayerHandCardCount & 4) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      if ((local_8 == -1) ||
         (*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) !=
          DAT_006ff2e0)) {
        g_ActivePlayer = 1;
      }
      else if ((*(int *)(&g_CardSlot_ConvertedManaCost +
                        *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120
                        + *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) *
                          0x5b20) == 0) ||
              (((&g_MasterCardColorTable)
                [*(int *)(&g_CardSlot_CardId +
                         *(int *)(&g_CardSlot_OriginalCardId +
                                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20)
                                 * 0x120 + *(int *)(&g_CardSlot_CombatTarget +
                                                   arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) * 0x120
                         + (char)(&g_CardSlot_Toughness)
                                 [*(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20
                                          ) * 0x120 +
                                  *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20
                                          ) * 0x5b20] * 0x5b20) * 0x34] & 0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        uVar1 = FUN_0040a305(*(int *)(&g_CardSlot_ConvertedManaCost +
                                     *(int *)(&g_CardSlot_AttachedAura +
                                             arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                     *(int *)(&g_CardSlot_CombatTarget +
                                             arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + -2,0,99);
        *(undefined4 *)
         (&g_CardSlot_ConvertedManaCost +
         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) = uVar1;
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      if (arg_1 == g_ActivePlayerPriority) {
        *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


