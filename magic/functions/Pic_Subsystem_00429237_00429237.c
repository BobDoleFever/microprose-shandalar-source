/*
 * Decompiled function: Pic_Subsystem_00429237
 * Entry Point: 00429237
 * Size: 1462 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00429237(int spell_id,int target_id,int flags)

{
  undefined4 uVar1;
  int iVar2;
  int local_10c;
  uint local_104;
  int local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4 [30];
  int aiStack_7c [30];
  
  if (flags == 0x74) {
    uVar1 = 1;
  }
  else {
    if (flags == 0x6c) {
      g_SpellStackDepth = g_SpellStackDepth + 0x30;
    }
    if ((((flags == 0x73) && (g_DefendingPlayer == spell_id)) &&
        (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) &&
       (g_ScWillyScore == 10)) {
      iVar2 = FUN_00473cc5((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
      if ((*(int *)(&DAT_006330d0 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0040dcca(spell_id,target_id,7,0), iVar2 != 0)) {
        if (spell_id == g_ActivePlayerPriority) {
          DAT_006a4920 = DAT_006a4920 | 3;
        }
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((flags == 0x6d) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) == 0)) {
        iVar2 = FUN_00473cc5((&DAT_006a5f4d)[spell_id * 0x5b20 + target_id * 0x120]);
        if (*(int *)(&DAT_006330d0 + iVar2 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 1
          ;
        }
      }
      if ((flags == 0x72) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) != 0)) {
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          FUN_0046f5d1(g_DefendingPlayer);
        }
        for (local_f8 = 0; local_f8 < 2; local_f8 = local_f8 + 1) {
          local_10c = 0;
          for (local_100 = 0; local_100 < (int)(&g_PlayerActiveCardCount)[spell_id];
              local_100 = local_100 + 1) {
            if (((*(int *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20) != -1) &&
                (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 1) != 0)) &&
               (((&g_CardSlot_Flags)[local_100 * 0x120 + spell_id * 0x5b20] & 2) == 0)) {
              local_f4[local_10c] =
                   *(undefined4 *)(&g_CardSlot_CardId + local_100 * 0x120 + spell_id * 0x5b20);
              aiStack_7c[local_10c] = local_100;
              local_10c = local_10c + 1;
            }
          }
          local_fc = 0;
          if (0x12 < (int)(&g_PlayerCreatureCount)[spell_id]) {
            local_fc = (&g_PlayerCreatureCount)[spell_id] + 0x1e;
          }
          if ((int)(&DAT_006b3008)[spell_id] < 7) {
            local_fc = local_fc + (7 - (&DAT_006b3008)[spell_id]) * 5 + 10;
          }
          if ((0 < local_f8) && (local_104 == 0)) {
            local_fc = local_fc / 2;
          }
          if ((int)(&g_PlayerCreatureCount)[spell_id] < 4) {
            local_fc = 0;
          }
          iVar2 = FUN_0040a1d2(100);
          local_104 = (uint)(local_fc <= iVar2);
          iVar2 = Ai_Subsystem_004cc56d
                            (spell_id,g_DialogPromptHwnd,g_DuelArenaHwnd,-1,-1,
                             s_Lose_4_life__Put_back_on_library_00521134,local_104);
          if (iVar2 == 0) {
            (&g_PlayerCreatureCount)[spell_id] = (&g_PlayerCreatureCount)[spell_id] + -4;
          }
          else if (((spell_id == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) &&
                  (DAT_006fedc0 == 0)) {
            Pic_Subsystem_00424500(s_prompts_txt_00521168,s_SYLVAN_LIBRARY_00521158);
            iVar2 = Pic_Load_004509e8(spell_id,(int)local_f4,local_10c,&g_OverworldGoldAmount,1);
            Pic_Subsystem_004524db(spell_id,local_f4[iVar2]);
            *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_006b3008)[spell_id] = (&DAT_006b3008)[spell_id] + -1;
          }
          else if (0 < local_10c) {
            iVar2 = FUN_0040a1d2(local_10c);
            Pic_Subsystem_004524db(spell_id,local_f4[iVar2]);
            *(undefined4 *)(&g_CardSlot_CardId + spell_id * 0x5b20 + aiStack_7c[iVar2] * 0x120) =
                 0xffffffff;
            (&DAT_006b3008)[spell_id] = (&DAT_006b3008)[spell_id] + -1;
          }
        }
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + spell_id * 0x5b20 + target_id * 0x120) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


