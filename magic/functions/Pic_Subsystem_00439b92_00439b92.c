/*
 * Decompiled function: Pic_Subsystem_00439b92
 * Entry Point: 00439b92
 * Size: 500 bytes
 */
#include "magic.h"


uint Pic_Subsystem_00439b92(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (spell_id == g_CurrentTurnPhase) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 2;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521664,s_COCOON_0052165c);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,1 - spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
          g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] ==
         g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0)))) {
      if (flags == 4) {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) + 1;
      }
      if (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) < 4) {
        *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
             *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
      }
      else {
        if (flags == 0x33) {
          g_ActivePalette = g_ActivePalette + 1;
        }
        if (flags == 0x32) {
          g_ActivePalette = g_ActivePalette + 1;
        }
        if (flags == 0x34) {
          g_ActivePalette = g_ActivePalette | 0x20;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


