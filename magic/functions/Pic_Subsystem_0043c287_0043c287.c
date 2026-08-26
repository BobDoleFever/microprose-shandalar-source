/*
 * Decompiled function: Pic_Subsystem_0043c287
 * Entry Point: 0043c287
 * Size: 1646 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043c287(int spell_id,int target_id,int flags,int height)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 arg_11;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_10;
  int local_8;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11,arg_12_00,arg_13_00,
                         arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005217dc,s_ANY_WARD_005217d0);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_ActivePlayerPriority) {
          iVar2 = *(int *)(&DAT_006b2e40 + height * 4 + g_CurrentTurnPhase * 0x20);
          iVar3 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)
                                          [target_id * 0x120 + spell_id * 0x5b20],
                               *(int *)(&g_CardSlot_OriginalCardId +
                                       target_id * 0x120 + spell_id * 0x5b20),0x32,0xffffffff);
          g_SpellStackDepth = g_SpellStackDepth + (iVar2 + 1) * iVar3 * 3;
        }
        if ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
            g_CurrentTurnPhase) {
          g_SpellStackDepth = g_SpellStackDepth + -0x60;
        }
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      iVar3 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar4 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,uVar4,arg_12,arg_13,iVar2,iVar3,arg_16
                         ,arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_CombatTarget)[target_id * 0x120 + spell_id * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
    }
    uVar4 = g_ActivePalette;
    if (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) != -1) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_8];
            local_10 = local_10 + 1) {
          if (((((((&g_CardSlot_Flags)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
                (*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
                 *(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + local_8 * 0x5b20))) &&
               (((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
                 (&g_CardSlot_Toughness)[local_10 * 0x120 + local_8 * 0x5b20] &&
                ((int)(char)(&DAT_006a5f4d)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 1 << ((byte)height & 0x1f))))) &&
              ((spell_id != local_8 || (target_id != local_10)))) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 4) != 0
             )) {
            g_ActivePalette = uVar4;
            Pic_Subsystem_0044867e(local_8,local_10,1);
          }
        }
      }
    }
    g_ActivePalette = uVar4;
    if ((((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
           g_OverworldMapGrid) &&
         ((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
          g_OverworldPlayerCoordX)) && (g_OverworldMapGrid != -1)) &&
       ((((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0 &&
        (height = FUN_0041d9d2(spell_id,target_id,height), flags == 0x34)))) {
      g_ActivePalette = g_ActivePalette | 0x800 << ((char)height - 1U & 0x1f);
    }
    if (((flags == 0x6c) &&
        ((&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
         (&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120])) &&
       ((*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) ==
         *(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) &&
        (((1 << ((byte)height & 0x1f) &
          (int)(char)(&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120])
          != 0 && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x20) == 0)))))) {
      g_ActivePalette = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


