/*
 * Decompiled function: Pic_Subsystem_0043793a
 * Entry Point: 0043793a
 * Size: 387 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043793a(int spell_id,int target_id,int flags)

{
  int iVar1;
  
  if (flags != 0x74) {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215b8,s_INVISIBILITY_005215a8);
      iVar1 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         DAT_006b2d5c)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] == DAT_007006c8 &&
        ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
         ((&DAT_0051aebd)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] != '\0')))
        ))) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  return;
}


