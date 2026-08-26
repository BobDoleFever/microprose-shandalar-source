/*
 * Decompiled function: Prompts_Load_0046fa40
 * Entry Point: 0046fa40
 * Size: 1094 bytes
 */
#include "magic.h"


void Prompts_Load_0046fa40(int spell_id,int target_id,int flags)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((0 < (int)(&DAT_006b3008)[spell_id]) &&
     ((spell_id != g_ActivePlayerPriority || (0 < (&DAT_006b3008)[spell_id] + DAT_00627a14)))) {
    if ((spell_id == g_CurrentTurnPhase) && ((g_IsAiThinking != 1 && (target_id == 0)))) {
      Pic_Subsystem_00424500(s_prompts_txt_00525b70,s_DISCARD_00525b68);
      Action_ValidateTarget_00405802
                (spell_id,spell_id,spell_id,0x100,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                 &g_OverworldGoldAmount,0,&local_18);
      local_1c = local_14;
    }
    else {
      local_8 = 0;
      local_20 = 0;
      do {
        local_1c = FUN_0040a1d2((&g_PlayerActiveCardCount)[spell_id]);
        if (((*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + spell_id * 0x5b20) != -1) &&
            (((&g_CardSlot_Flags)[local_1c * 0x120 + spell_id * 0x5b20] & 2) == 0)) &&
           (((&g_CardSlot_Flags)[local_1c * 0x120 + spell_id * 0x5b20] & 0x20) == 0)) {
          local_8 = 1;
        }
      } while ((local_8 == 0) && (local_20 = local_20 + 1, local_20 < 999));
      if (local_8 == 0) {
        local_c = 0;
        while ((local_c < (int)(&g_PlayerActiveCardCount)[spell_id] && (local_8 == 0))) {
          if ((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + spell_id * 0x5b20) != -1) &&
             ((((&g_CardSlot_Flags)[local_c * 0x120 + spell_id * 0x5b20] & 2) == 0 &&
              (((&g_CardSlot_Flags)[local_c * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))) {
            local_8 = 1;
            local_1c = local_c;
          }
          local_c = local_c + 1;
        }
      }
    }
    if (((g_PlayerHandCardCount & 0x800 << ((byte)spell_id & 0x1f)) == 0) || (flags != 0)) {
      if ((spell_id == 1) && (g_IsAiThinking != 1)) {
        if (target_id == 0) {
          Ai_Subsystem_004cc56d(1,1,local_1c,-1,-1,s_to_discard__00525b94,0);
        }
        else {
          Ai_Subsystem_004cc56d(1,1,local_1c,-1,-1,s_at_random_to_discard__00525b7c,0);
        }
      }
      Magic_TriggerCardEvent(spell_id,local_1c,0x8d,1 - spell_id,0xffffffff);
      Pic_Subsystem_0044913a(spell_id,local_1c);
      *(undefined4 *)(&g_CardSlot_CardId + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
      Ai_Subsystem_004cc3f8(spell_id,local_1c,0xb,1);
    }
    else {
      local_10 = Ai_Subsystem_004cc56d
                           (spell_id,spell_id,local_1c,-1,-1,
                            s_Discard_to_Library__Discard_to_G_00525ba0,0);
      if (local_10 == 0) {
        Pic_Subsystem_004524db
                  (spell_id,*(undefined4 *)
                             (&g_CardSlot_CardId + local_1c * 0x120 + spell_id * 0x5b20));
        *(undefined4 *)(&g_CardSlot_CardId + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        Ai_Subsystem_004cc3f8(spell_id,local_1c,10,1);
      }
      else {
        Magic_TriggerCardEvent(spell_id,local_1c,0x8d,1 - spell_id,0xffffffff);
        Pic_Subsystem_0044913a(spell_id,local_1c);
        *(undefined4 *)(&g_CardSlot_CardId + local_1c * 0x120 + spell_id * 0x5b20) = 0xffffffff;
        Ai_Subsystem_004cc3f8(spell_id,local_1c,0xb,1);
      }
    }
    Magic_UpkeepPhase(0x18);
    (&DAT_006b3008)[spell_id] = (&DAT_006b3008)[spell_id] + -1;
  }
  return;
}


