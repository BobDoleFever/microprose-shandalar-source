/*
 * Decompiled function: Pic_Subsystem_00437df6
 * Entry Point: 00437df6
 * Size: 820 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00437df6(int spell_id,int target_id,int flags)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
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
    uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar3 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,2,0,0,uVar3,arg_11_00,arg_12_00,arg_13_00,
                         arg_14,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005215e0,s_SEEKER_005215d8);
      iVar4 = CardTarget_PromptTargetCreature(spell_id,spell_id,target_id);
      if (iVar4 == 0) {
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
      iVar4 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar4 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120),
                         *(int *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120),
                         (char *)0x0,spell_id,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar4,arg_15,
                         arg_16,arg_17,arg_18,arg_19,arg_20);
      if (iVar4 == 0) {
        Pic_Subsystem_0044867e(spell_id,target_id,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] =
             (&g_CardSlot_CombatTarget)[spell_id * 0x5b20 + target_id * 0x120];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120);
      }
      (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 0;
    }
    if (((flags == 0x78) &&
        (*(int *)(&g_CardSlot_OriginalCardId + spell_id * 0x5b20 + target_id * 0x120) ==
         DAT_006b2d5c)) &&
       (((char)(&g_CardSlot_Toughness)[spell_id * 0x5b20 + target_id * 0x120] == DAT_007006c8 &&
        ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x20) == 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      bVar2 = FUN_0041d9d2(spell_id,target_id,5);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) == 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


