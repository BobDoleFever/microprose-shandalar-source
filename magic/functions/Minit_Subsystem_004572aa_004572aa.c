/*
 * Decompiled function: Minit_Subsystem_004572aa
 * Entry Point: 004572aa
 * Size: 1181 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004572aa(int spell_id,int target_id,int flags)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  if ((flags == 0x82) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
    *(uint *)(&DAT_006a6038 + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&DAT_006a6038 + spell_id * 0x5b20 + target_id * 0x120) & 0xfffffffc;
  }
  if (((flags == 0x6c) && (target_id == g_OverworldMapGrid)) &&
     (spell_id == g_OverworldPlayerCoordX)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x18;
    *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
         *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1;
  }
  if (((flags == 0x6a) && (spell_id == g_DefendingPlayer)) &&
     ((((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) != 0 &&
      (iVar2 = Card_GetCounters(spell_id,target_id), iVar2 == 0)))) {
    Pic_Subsystem_0042475a(s_prompts_txt_00524218,s_TIME_VAULT_0052420c);
    iVar2 = FUN_0040a1d2(5);
    iVar2 = Ai_Subsystem_004cc56d
                      (spell_id,spell_id,target_id,-1,-1,&g_OverworldGoldAmount,(uint)(iVar2 < 1));
    if (iVar2 != 0) {
      g_PlayerHandCardCount = g_PlayerHandCardCount | 0x8000;
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) & 0xffffffef;
      Card_IncrementCounter(spell_id,target_id);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
    }
  }
  if (flags == 0x73) {
    if ((((((&DAT_006a5f3e)[spell_id * 0x5b20 + target_id * 0x120] & 3) == 0) ||
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + target_id * 0x120) * 0x34] & 2) == 0))
        && (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar2 = Card_GetCounters(spell_id,target_id), iVar2 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((flags == 0x6d) &&
        (((&g_CardSlot_Flags)[spell_id * 0x5b20 + target_id * 0x120] & 0x10) == 0)) &&
       (iVar2 = Card_GetCounters(spell_id,target_id), iVar2 != 0)) {
      *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) =
           *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + target_id * 0x120) | 0x10;
    }
    if (flags == 0x72) {
      iVar2 = rand();
      if (iVar2 % 5 < 1) {
        g_SpellStackDepth = g_SpellStackDepth + 0x30;
      }
      if (DAT_006ff2d8 == -1) {
        bVar1 = false;
        local_c = 0;
        while ((local_c < 2 && (!bVar1))) {
          for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c];
              local_8 = local_8 + 1) {
            if ((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_c * 0x5b20) == DAT_006a4b64)
               && (((&DAT_006a5f69)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              bVar1 = true;
            }
          }
          local_c = local_c + 1;
        }
        if (!bVar1) {
          DAT_006ff2d8 = spell_id;
        }
      }
      Card_DecrementCounter(g_DialogPromptHwnd,g_DuelArenaHwnd);
      *(undefined4 *)
       (&g_CardSlot_ConvertedManaCost +
       *(int *)(&g_CardSlot_TapState + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20 +
       *(int *)(&g_CardSlot_SicknessState + spell_id * 0x5b20 + target_id * 0x120) * 0x120) = 1;
      iVar2 = FUN_00410cc0(g_DialogPromptHwnd,g_DuelArenaHwnd,DAT_006a4b64,-1,-1);
      *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + spell_id * 0x5b20) | 0x120;
    }
    uVar3 = 0;
  }
  return uVar3;
}


