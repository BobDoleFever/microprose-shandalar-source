/*
 * Decompiled function: Pic_Subsystem_00429e7d
 * Entry Point: 00429e7d
 * Size: 601 bytes
 */
#include "magic.h"


int Pic_Subsystem_00429e7d(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    iVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      iVar1 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                            spell_id * 0x5b20 + target_id * 0x120),-1);
      if (iVar1 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
    }
    if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
       (spell_id == g_OverworldPlayerCoordX)) {
      Pic_Subsystem_00424500(s_prompts_txt_005211c0,s_KISMET_005211b8);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(int *)(&g_CardSlot_CombatTarget + spell_id * 0x5b20 + target_id * 0x120) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + spell_id * 0x5b20 + target_id * 0x120) = local_8;
        (&g_CardSlot_TurnPlayed)[spell_id * 0x5b20 + target_id * 0x120] = 1;
      }
    }
    iVar1 = target_id * 0x120;
    if (((((&g_CardSlot_Flags)[spell_id * 0x5b20 + iVar1] & 0x20) == 0) && (flags == 0x6c)) &&
       ((iVar1 = target_id * 0x120,
        *(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + iVar1) ==
        g_OverworldPlayerCoordX &&
        (iVar1 = *(int *)(&g_CardSlot_CardId +
                         g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0xd,
        ((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x43) !=
        0)))) {
      iVar1 = g_OverworldMapGrid * 0x120;
      *(uint *)(&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + iVar1) =
           *(uint *)(&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + iVar1) | 0x10;
    }
  }
  return iVar1;
}


