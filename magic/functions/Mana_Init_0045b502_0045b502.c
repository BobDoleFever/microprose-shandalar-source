/*
 * Decompiled function: Mana_Init_0045b502
 * Entry Point: 0045b502
 * Size: 727 bytes
 */
#include "magic.h"


undefined4 Mana_Init_0045b502(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  char *str_2;
  int local_8;
  
  if (flags == 0x73) {
    iVar1 = FUN_0040d949(spell_id,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[target_id * 0x120 + spell_id * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20) * 0x34] & 2) != 0))
        || (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((flags == 0x6d) && (iVar1 = FUN_0040d949(spell_id,7,2), iVar1 != 0)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x18;
      Ai_CalcManaRequirement_004ba890(spell_id,0,2);
      if (g_ActivePlayer != 1) {
        if (spell_id == g_CurrentTurnPhase) {
          local_8 = -1;
        }
        else if (g_IsAiThinking == 1) {
          local_8 = DAT_006b1580 % 5 + 1;
          g_AiDecisionScore = local_8;
          Ai_EvaluateCreaturePower();
        }
        else {
          Ai_CalcCardAdvantage();
          if (g_AiDecisionScore < 6) {
            local_8 = g_AiDecisionScore;
          }
          else {
            g_ActivePlayer = 1;
          }
        }
        if (g_ActivePlayer != 1) {
          Pic_Subsystem_00424500(s_prompts_txt_005243fc,s_CELESTIAL_PRISM_005243ec);
          iVar1 = Ai_Subsystem_004cc93d
                            (spell_id,&g_OverworldGoldAmount,1,local_8,
                             (int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20]);
          if (iVar1 == -1) {
            g_ActivePlayer = 1;
          }
          if (g_ActivePlayer != 1) {
            FUN_0040d875(spell_id,iVar1,1);
            FUN_0040d64c(spell_id,(int)(char)(&DAT_006a5f4c)[target_id * 0x120 + spell_id * 0x5b20],
                         1);
            *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
                 *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
            DAT_006ff2d4 = iVar1;
            if (spell_id != g_CurrentTurnPhase) {
              strcpy(&g_OverworldWorldState,s_to_produce_00524408);
              str_2 = (char *)Mem_AllocOrFree_00473d7e(iVar1);
              strcat(&g_OverworldWorldState,str_2);
              strcat(&g_OverworldWorldState,s_mana__00524414);
              Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,&g_OverworldWorldState,0);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


