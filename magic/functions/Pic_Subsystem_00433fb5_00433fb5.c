/*
 * Decompiled function: Pic_Subsystem_00433fb5
 * Entry Point: 00433fb5
 * Size: 1401 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00433fb5(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  undefined1 local_8;
  
  if (flags == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    uVar1 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar1,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005214ec,&DAT_005214e4);
      iVar2 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (flags == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
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
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    if ((g_PlayerManaPool == 0xda) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 1;
      g_PlayerManaPool = 0xffffffff;
      if (((((char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] ==
             g_DefendingPlayer) &&
           ((((&g_CardSlot_Flags)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] & 4)
             != 0 && (((&g_CardSlot_Flags)
                       [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 2) != 0))))
          && ((&g_CardSlot_ColorMask)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120]
              == -1)) && (g_OverworldPlayerCoordX != g_DefendingPlayer)) {
        iVar2 = Pic_Subsystem_0043452e
                          (g_OverworldPlayerCoordX,g_OverworldMapGrid,
                           (int)(char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20]
                           ,*(undefined4 *)
                             (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20));
        if (iVar2 != 0) {
          if ((&g_CardSlot_ColorMask)
              [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20) * 0x120
               + (char)(&g_CardSlot_Toughness)[target_id * 0x120 + spell_id * 0x5b20] * 0x5b20] ==
              -1) {
            local_8 = (undefined1)
                      *(undefined4 *)
                       (&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20);
          }
          else {
            local_8 = (&g_CardSlot_ColorMask)
                      [*(int *)(&g_CardSlot_OriginalCardId + target_id * 0x120 + spell_id * 0x5b20)
                       * 0x120 + (char)(&g_CardSlot_Toughness)
                                       [target_id * 0x120 + spell_id * 0x5b20] * 0x5b20];
          }
          if (flags == 0x7d) {
            g_ActivePalette = g_ActivePalette | 2;
          }
          if (flags == 0x7e) {
            (&g_CardSlot_ColorMask)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
                 local_8;
            *(uint *)(&g_CardSlot_Flags +
                     g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
                 *(uint *)(&g_CardSlot_Flags +
                          g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x8008;
          }
        }
      }
      g_PlayerManaPool = 0xda;
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


