/*
 * Decompiled function: Card_DirectDamage_EvaluateBestTarget
 * Entry Point: 004df8ba
 * Size: 612 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool Card_DirectDamage_EvaluateBestTarget(int arg1,int arg2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (arg1 == g_CurrentTurnPhase) {
    if (g_IsAiThinking == 1) {
      local_14 = 0xffffffff;
      _DAT_0063ee20 = 1 - arg1;
    }
    else {
      piVar14 = &local_10;
      uVar13 = 1;
      puVar12 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg1,arg2);
      iVar5 = Action_ValidateTarget_00405802
                        (arg1,2,1 - arg1,0x1200,2,0,0,uVar1,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,puVar12,uVar13,piVar14);
      if (iVar5 == 0) {
        g_ActivePlayer = 1;
        local_14 = 0xffffffff;
        _DAT_0063ee20 = -1;
      }
      else {
        local_14 = local_c;
        _DAT_0063ee20 = local_10;
      }
    }
  }
  else {
    if (g_IsAiThinking == 1) {
      iVar5 = FUN_0040a1d2(3);
      g_AiDecisionScore = (uint)(iVar5 == 0);
      Ai_EvaluateCreaturePower();
    }
    else {
      Ai_CalcCardAdvantage();
    }
    if (g_AiDecisionScore == 0) {
      piVar14 = &local_10;
      uVar13 = 1;
      puVar12 = &g_OverworldGoldAmount;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg1,arg2);
      Action_ValidateTarget_00405802
                (arg1,2,1 - arg1,0x1200,2,0,0,uVar1,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10
                 ,uVar11,puVar12,uVar13,piVar14);
      local_14 = local_c;
      _DAT_0063ee20 = local_10;
    }
    else {
      local_14 = 0xffffffff;
      _DAT_0063ee20 = 1 - arg1;
      if (g_IsAiThinking == 1) {
        g_AiDecisionScore = 0;
        DAT_006fefa8 = CONCAT31((uint3)((_DAT_0063ee20 == 0) - 1 >> 8) & 1,0xff);
        Ai_EvaluateCreaturePower();
      }
      else {
        Ai_CalcCardAdvantage();
      }
    }
  }
  bVar2 = g_ActivePlayer != 1;
  if (bVar2) {
    *(undefined4 *)(&g_CardSlot_AttachedAura + arg2 * 0x120 + arg1 * 0x5b20) = local_14;
    *(int *)(&g_CardSlot_CombatTarget + arg2 * 0x120 + arg1 * 0x5b20) = _DAT_0063ee20;
    (&g_CardSlot_TurnPlayed)[arg2 * 0x120 + arg1 * 0x5b20] = 1;
  }
  return bVar2;
}


