/*
 * Decompiled function: Prompts_Load_004f8321
 * Entry Point: 004f8321
 * Size: 849 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004f8321(int spell_id,int target_id,int flags)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 arg_11;
  int iVar7;
  undefined4 arg_12;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    arg_19 = 1;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar2 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
    uVar2 = FUN_00403250((int *)0x0,0,spell_id,spell_id,spell_id,0x200,2,0,0,uVar2,arg_11,arg_12,
                         arg_13,arg_14,arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_0053041c,s_ENERGYTAP_00530410);
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = &g_OverworldGoldAmount;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar6 = Action_ValidateTarget_00405802
                        (spell_id,spell_id,spell_id,0x200,2,0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,
                         uVar9,uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar6 = -1;
      uVar5 = 0;
      uVar4 = 0;
      uVar3 = SpellChain_ProcessTriggerEvent(spell_id,target_id);
      iVar6 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,(byte)spell_id,(byte)spell_id,0x200,2,
                         0,0,uVar3,uVar4,uVar5,iVar6,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar6 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        FUN_00415d48(local_c,local_8);
        cVar1 = (&DAT_0051aebf)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34];
        iVar6 = FUN_0040a305((int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 local_c * 0x5b20 + local_8 * 0x120) * 0x34],0,99);
        *(int *)(&DAT_0063ee90 + spell_id * 0x20) =
             *(int *)(&DAT_0063ee90 + spell_id * 0x20) + cVar1 + iVar6;
        cVar1 = (&DAT_0051aebf)
                [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34];
        iVar6 = FUN_0040a305((int)(char)(&DAT_0051aec0)
                                        [*(int *)(&g_CardSlot_CardId +
                                                 local_c * 0x5b20 + local_8 * 0x120) * 0x34],0,99);
        *(int *)(&DAT_0063eeac + spell_id * 0x20) =
             *(int *)(&DAT_0063eeac + spell_id * 0x20) + cVar1 + iVar6;
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


