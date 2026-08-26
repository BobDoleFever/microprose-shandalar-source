/*
 * Decompiled function: Card_SamiteHealer_PreventDamage
 * Entry Point: 004dd632
 * Size: 861 bytes
 */
#include "magic.h"


undefined1 Card_SamiteHealer_PreventDamage(int spell_id,int target_id,int flags)

{
  undefined1 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (flags == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0 &&
        ((byte)g_PlayerHandCardCount & 4) != 0) {
      iVar2 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,0xffffffff,
                           0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 99;
      }
    }
  }
  else if (flags == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if (flags == 0x6d) {
      Pic_Subsystem_00424500(s_prompts_txt_0052ec84,s_SAMITE_HEALER_0052ec74);
      iVar2 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,0,
                         &g_OverworldGoldAmount,1,&local_c);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_c;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x72) {
      local_c = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      local_8 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar2 = Rules_ParseFilter_0040360b
                        (local_c,local_8,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,
                         0xffffffff,0xffffffff,0,0,0);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) != 0) {
        *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) =
             *(int *)(&g_CardSlot_ConvertedManaCost + local_c * 0x5b20 + local_8 * 0x120) + -1;
      }
      (&g_CardSlot_TurnPlayed)
      [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
    }
    if ((flags == 0x3b) &&
       ((*(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) & 0x20010) == 0)) {
      *(int *)(&DAT_00695eb8 + spell_id * 4) = *(int *)(&DAT_00695eb8 + spell_id * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


