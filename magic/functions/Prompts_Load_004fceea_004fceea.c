/*
 * Decompiled function: Prompts_Load_004fceea
 * Entry Point: 004fceea
 * Size: 561 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fceea(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      Pic_Subsystem_00424500(s_prompts_txt_005306ac,s_VISIONS_005306a4);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,1 - spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,
                         0,&g_OverworldGoldAmount,1,&local_c);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
      }
    }
    if (flags == 0x71) {
      if (((spell_id == 0) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Pic_Subsystem_00424500(s_prompts_txt_005306c0,s_VISIONS_005306b8);
        Pic_Load_004509e8(0,(int)(&DAT_0069e730 +
                                 *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120) * 2000),5,
                          &DAT_0069f84a,0);
      }
      iVar2 = Ai_Subsystem_004cc56d
                        (spell_id,spell_id,target_id,-1,-1,
                         s_Shuffle_library__Don_t_shuffle__005306d4,1);
      if (iVar2 == 0) {
        Pic_Subsystem_00452276
                  (*(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20));
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


