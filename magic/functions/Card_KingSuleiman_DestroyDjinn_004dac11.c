/*
 * Decompiled function: Card_KingSuleiman_DestroyDjinn
 * Entry Point: 004dac11
 * Size: 613 bytes
 */
#include "magic.h"


undefined4 Card_KingSuleiman_DestroyDjinn(int spell_id,int target_id,int flags)

{
  undefined4 local_8;
  
  if ((flags == 0x73) || (flags == 0x6d)) {
    Pic_Subsystem_00424500(s_prompts_txt_0052ebc4,s_KING_SULEIMAN_0052ebb4);
    local_8 = Card_Targeting_PromptCreature(spell_id,target_id,flags,1 - spell_id);
  }
  if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    local_8 = 0;
  }
  else if ((flags == 0x72) &&
          (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
    if (((&DAT_0051aebd)
         [*(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                  0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                          0x5b20) * 0x34] == '\x05') ||
       ((&DAT_0051aebd)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) *
                 0x120 + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] *
                         0x5b20) * 0x34] == '\x06')) {
      Pic_Subsystem_0044867e
                ((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                 *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),2);
    }
    else {
      g_ActivePlayer = 1;
    }
    (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] = 0xff;
    *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
         (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20];
    *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
  }
  return local_8;
}


