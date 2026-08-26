/*
 * Decompiled function: Card_LeyDruid_AiEvaluateLand
 * Entry Point: 004e4144
 * Size: 355 bytes
 */
#include "magic.h"


uint Card_LeyDruid_AiEvaluateLand(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) {
      if (arg_1 == g_CurrentTurnPhase) {
        uVar1 = (DAT_006a282c | DAT_006a2828) & 0x40;
      }
      else {
        uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 0x40;
      }
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
      if (local_8 == -1) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags +
                 *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags +
                      *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20)
             | 0x10;
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


