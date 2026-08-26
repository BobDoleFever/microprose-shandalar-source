/*
 * Decompiled function: Card_DwarvenDemolitionTeam_DestroyWall
 * Entry Point: 004daa50
 * Size: 449 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Card_DwarvenDemolitionTeam_DestroyWall(int spell_id,int target_id,int flags)

{
  int arg_2;
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052eba8,s_DWARVEN_DTEAM_0052eb98);
    local_8 = Card_Targeting_PromptCreature(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    local_8 = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    arg_2 = *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
    _DAT_0063ee20 = (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
    *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) = 0xffffffff
    ;
    *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
    if ((arg_2 != -1) &&
       ((&DAT_0051aebd)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20
                 + *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) *
                   0x120) * 0x34] == '\0')) {
      Pic_Subsystem_0044867e(_DAT_0063ee20,arg_2,2);
    }
  }
  return local_8;
}


