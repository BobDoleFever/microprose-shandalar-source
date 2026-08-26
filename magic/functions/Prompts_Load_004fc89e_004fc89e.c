/*
 * Decompiled function: Prompts_Load_004fc89e
 * Entry Point: 004fc89e
 * Size: 711 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fc89e(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  uint local_10;
  int local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
        (spell_id == g_OverworldPlayerCoordX)) &&
       ((spell_id == g_ActivePlayerPriority && (*(int *)(&DAT_0069e730 + spell_id * 2000) == -1))))
    {
      g_ActivePlayer = 1;
    }
    if (flags == 0x71) {
      if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_0053066c,s_DEMONIC_TUTOR_0053065c);
        local_8 = Pic_Load_004509e8(spell_id,(int)(&DAT_0069e730 + spell_id * 2000),500,
                                    &g_OverworldGoldAmount,1);
        if ((local_8 != -1) && (*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000) != -1)) {
          Pic_Subsystem_00451291(spell_id,*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,local_8);
        }
      }
      else {
        if (spell_id == g_CurrentTurnPhase) {
          local_10 = 0x42;
        }
        else {
          if (g_IsAiThinking == 1) {
            g_AiDecisionScore = FUN_0040a1d2(4);
            Ai_EvaluateCreaturePower();
          }
          else {
            Ai_CalcCardAdvantage();
          }
          switch(g_AiDecisionScore) {
          case 0:
            local_10 = 2;
            break;
          case 1:
            local_10 = 0x40;
            break;
          case 2:
            local_10 = 8;
            break;
          case 3:
            local_10 = 0x10;
          }
        }
        local_8 = FUN_004fdad2(spell_id,spell_id,local_10);
        if (local_8 == -1) {
          local_8 = FUN_004fdad2(spell_id,spell_id,0xffffffff);
        }
        if ((local_8 != -1) && (*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000) != -1)) {
          Pic_Subsystem_00451291(spell_id,*(int *)(&DAT_0069e730 + local_8 * 4 + spell_id * 2000));
          Pic_Subsystem_004523fd(spell_id,local_8);
        }
      }
      if (local_8 != -1) {
        Ai_Subsystem_004cc9c5(0,0x30);
        Pic_Subsystem_00452276(spell_id);
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


