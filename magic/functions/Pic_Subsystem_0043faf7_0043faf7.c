/*
 * Decompiled function: Pic_Subsystem_0043faf7
 * Entry Point: 0043faf7
 * Size: 639 bytes
 */
#include "magic.h"


uint Pic_Subsystem_0043faf7(int spell_id,int target_id,int flags)

{
  uint uVar1;
  int iVar2;
  
  if (flags == 0x74) {
    if (g_CurrentTurnPhase == spell_id) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 2;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_CurrentTurnPhase] & 2;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_00521924,s_EARTH_BIND_00521918);
    }
    iVar2 = CardTarget_PromptTargetCreature(spell_id,1 - spell_id,target_id);
    g_ActivePlayer = (uint)(iVar2 == 0);
    if ((flags == 0x71) &&
       (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      uVar1 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(int *)(&g_CardSlot_OriginalCardId +
                                    target_id * 0x120 + spell_id * 0x5b20),0x34,0xffffffff);
      if ((uVar1 & 0x20) != 0) {
        FUN_0041db67((int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20),2,
                     spell_id,target_id);
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0) &&
        (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         g_OverworldMapGrid)) &&
       (((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         g_OverworldPlayerCoordX && ((g_OverworldMapGrid != -1 && (flags == 0x34)))))) {
      g_ActivePalette = g_ActivePalette & 0xffffffdf;
    }
    uVar1 = 0;
  }
  return uVar1;
}


