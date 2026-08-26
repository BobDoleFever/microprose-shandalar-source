/*
 * Decompiled function: Pic_Subsystem_004468dc
 * Entry Point: 004468dc
 * Size: 1142 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint Pic_Subsystem_004468dc(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint auStack_68 [20];
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if ((g_PlayerManaPool != -1) && (g_ActivePlayerPriority == DAT_006a4b5c)) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[local_10];
          local_14 = local_14 + 1) {
        if ((((&g_CardSlot_Flags)[local_14 * 0x120 + local_10 * 0x5b20] & 2) != 0) &&
           (iVar1 = Pic_Subsystem_004485d6(local_10,local_14,0x7d,arg_1), iVar1 == 2)) {
          _DAT_0063ee20 = local_10;
          DAT_00695f0c = 4;
          return local_14;
        }
        if ((((local_10 == arg_1) &&
             (*(int *)(&DAT_006a5f80 + local_14 * 0x120 + local_10 * 0x5b20) == g_PlayerManaPool))
            && (local_10 == DAT_006a4b5c)) && (g_PlayerManaPool != -1)) {
          DAT_00695f0c = DAT_00695f0c | 4;
          DAT_0068a714 = DAT_0068a714 + 1;
          _DAT_0063ee20 = local_10;
          return local_14;
        }
      }
    }
  }
  if (((((byte)DAT_0068a67c & 2) == 0) || (g_CurrentTurnPhase == arg_1)) || (DAT_0063ee70 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    _DAT_0063ee20 = arg_1;
    for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[arg_1];
        local_14 = local_14 + 1) {
      local_c = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + arg_1 * 0x5b20);
      if ((local_c != -1) && (local_18 = Pic_Subsystem_00446d52(arg_1,local_14), local_18 != 0)) {
        auStack_68[local_8] = local_14;
        local_8 = local_8 + 1;
        if (local_18 == 2) {
          return local_14;
        }
      }
    }
    if (DAT_00695ec4 == 4) {
      for (local_14 = 0; (int)local_14 < (int)(&g_PlayerActiveCardCount)[1 - arg_1];
          local_14 = local_14 + 1) {
        local_c = *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + (1 - arg_1) * 0x5b20);
        if (((local_c != -1) &&
            (local_18 = Pic_Subsystem_00446d52(1 - arg_1,local_14), local_18 != 0)) &&
           (local_18 == 2)) {
          _DAT_0063ee20 = 1 - arg_1;
          return local_14;
        }
      }
    }
    if (DAT_00695ec4 == 4) {
      uVar2 = 0xffffffff;
    }
    else {
      auStack_68[local_8] = 0xffffffff;
      local_8 = local_8 + 1;
      if (g_IsAiThinking == 1) {
        iVar1 = FUN_0040a1d2(2);
        if ((iVar1 == 0) || (iVar1 = Ai_Util_004ab510(), iVar1 == 0)) {
          g_AiDecisionScore = FUN_0040a1d2(local_8);
        }
        else {
          g_AiDecisionScore = local_8 + -1;
        }
        if ((DAT_006a2838 != 0) && (g_AiDecisionScore = local_8 + -1, DAT_006a2838 == 1)) {
          DAT_006a2838 = -1;
        }
        DAT_006fefa8 = (-(uint)((*(uint *)(&g_CardSlot_Flags +
                                          arg_1 * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120) &
                                2) == 0) & 0xfffff000) + 0x2000 | auStack_68[g_AiDecisionScore] |
                       (arg_1 == 0) - 1 & 0x100;
        DAT_0052ce1c = 4;
        Ai_EvaluateCreaturePower();
      }
      else {
        DAT_0052ce1c = 4;
        Ai_CalcCardAdvantage();
        if (local_8 <= g_AiDecisionScore) {
          g_AiDecisionScore = local_8 + -1;
        }
      }
      if (auStack_68[g_AiDecisionScore] != 0xffffffff) {
        if (0xf < DAT_006a2844) {
          DAT_006a2844 = DAT_006a2844 + -1;
        }
        *(undefined4 *)(&DAT_006fe3b0 + DAT_006a2844 * 4) =
             *(undefined4 *)
              (&g_CardSlot_CardId + arg_1 * 0x5b20 + auStack_68[g_AiDecisionScore] * 0x120);
        *(uint *)(&DAT_006966f0 + DAT_006a2844 * 4) = auStack_68[g_AiDecisionScore];
        DAT_006a2844 = DAT_006a2844 + 1;
      }
      uVar2 = auStack_68[g_AiDecisionScore];
    }
  }
  return uVar2;
}


