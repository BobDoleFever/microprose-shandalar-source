/*
 * Decompiled function: Prompts_Load_00416f1a
 * Entry Point: 00416f1a
 * Size: 908 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_00416f1a(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_8;
  
  if ((flags == 0x74) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
    bVar1 = false;
    Ai_GetOpponentPlayerScore(0);
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      local_8 = 0;
      while ((local_8 < (int)(&g_PlayerActiveCardCount)[local_10] && (!bVar1))) {
        if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_10 * 0x5b20) != -1) &&
           (((((byte)*(undefined4 *)(&g_CardSlot_Flags + local_8 * 0x120 + local_10 * 0x5b20) & 0x22
              ) == 2 &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_10 * 0x5b20) * 0x34] & 2) != 0
             )) && ((&DAT_006a5f50)[local_8 * 0x120 + local_10 * 0x5b20] == '\x02')))) {
          bVar1 = true;
        }
        local_8 = local_8 + 1;
      }
    }
    if (bVar1) {
      uVar2 = 99;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((flags == 0x6c) &&
       (((g_OverworldMapGrid == target_id && (g_OverworldPlayerCoordX == spell_id)) &&
        ((g_PlayerHandCardCount._1_1_ & 2) != 0)))) {
      bVar1 = false;
      do {
        Pic_Subsystem_00424500(s_prompts_txt_00519918,s_DEATH_WARD_0051990c);
        iVar3 = CardTarget_SetTargetCreature(spell_id,spell_id,target_id);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        if ((&DAT_006a5f50)
            [*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
             *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) * 0x120] ==
            '\x02') {
          bVar1 = true;
        }
        else if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_Illegal_target__not_dying___00519924);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_00519940);
        }
      } while ((g_ActivePlayer != 1) && (!bVar1));
    }
    if ((flags == 0x71) && ((g_PlayerHandCardCount._1_1_ & 2) != 0)) {
      iVar3 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0);
      if (iVar3 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        Card_GenericCreature_CanRegenerate
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                   *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


