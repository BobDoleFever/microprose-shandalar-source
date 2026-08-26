/*
 * Decompiled function: Card_NettlingImp_ForceAttack
 * Entry Point: 004db024
 * Size: 989 bytes
 */
#include "magic.h"


undefined4 Card_NettlingImp_ForceAttack(int spell_id,int target_id,int flags)

{
  undefined4 local_8;
  
  if (flags == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0) {
      if ((spell_id == g_DefendingPlayer) || (0x1a < g_ScWillyScore)) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
    else {
      local_8 = 0;
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    local_8 = 0;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ebe0,s_NETTLING_IMP_0052ebd0);
      local_8 = Card_Targeting_PromptCreature(spell_id,target_id,0x6d,1 - spell_id);
    }
    if (((flags == 0x72) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) &&
       ((&DAT_0051aebd)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) * 0x34] == '\0')) {
      (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
      *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0xffffffef;
    }
    if (((flags == 0x15) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) &&
       (spell_id != g_DefendingPlayer)) {
      *(uint *)(&g_CardSlot_Flags +
               *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags +
                    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                    0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                            0x5b20) | 4;
      DAT_006a5f20 = 1;
      (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
      *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
    }
    if (((flags == 0x1f) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) &&
       ((spell_id != g_DefendingPlayer &&
        (((&g_CardSlot_Flags)
          [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120 +
           (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 0x40) ==
         0)))) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),2);
    }
  }
  return local_8;
}


