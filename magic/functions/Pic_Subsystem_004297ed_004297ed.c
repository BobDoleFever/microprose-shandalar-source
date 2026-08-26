/*
 * Decompiled function: Pic_Subsystem_004297ed
 * Entry Point: 004297ed
 * Size: 1675 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_004297ed(int spell_id,int target_id,int flags)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  if (flags == 0x74) {
    uVar2 = 1;
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) &&
       (iVar3 = FUN_004fa4b8(spell_id,*(int *)(&g_CardSlot_CardId +
                                              target_id * 0x120 + spell_id * 0x5b20),spell_id),
       iVar3 == 0)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           ((*(int *)(&DAT_0063ee4c + (1 - spell_id) * 0x20) -
            *(int *)(&DAT_0063ee4c + spell_id * 0x20)) * 3 + 6) * 4;
    }
    if (flags == 0x73) {
      if ((((g_ScWillyScore == 4) && (g_DefendingPlayer == spell_id)) && (spell_id == DAT_0063edc0))
         && ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) == 0
             && (*(int *)(&DAT_0063ee4c + spell_id * 0x20) <
                 *(int *)(&DAT_0063ee4c + (1 - spell_id) * 0x20))))) {
        iVar3 = FUN_00473cc5((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if ((*(int *)(&DAT_006330d0 + iVar3 * 4) == 0) ||
           (iVar3 = FUN_0040dcca(spell_id,target_id,7,0), iVar3 != 0)) {
          if ((g_CurrentTurnPhase != spell_id) && (*(int *)(&DAT_0069e740 + spell_id * 2000) != -1))
          {
            DAT_006a4920 = DAT_006a4920 | 3;
          }
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((flags == 0x6d) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        iVar3 = FUN_00473cc5((&DAT_006a5f4d)[target_id * 0x120 + spell_id * 0x5b20]);
        if (*(int *)(&DAT_006330d0 + iVar3 * 4) != 0) {
          Ai_Subsystem_004be192(spell_id,target_id,0,0);
        }
        if (g_ActivePlayer != 1) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
        }
      }
      if (flags == 0x72) {
        if ((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) {
          Pic_Subsystem_00424500(s_prompts_txt_005211ac,s_LANDTAX_005211a4);
          iVar3 = Ai_Subsystem_004b76a6(&DAT_0069e730 + spell_id * 2000,500,(int)local_14,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            Pic_Subsystem_00451291
                      (spell_id,*(int *)(&DAT_0069e730 + local_14[local_18] * 4 + spell_id * 2000));
          }
          if (iVar3 == 1) {
            Pic_Subsystem_004523fd(spell_id,local_14[0]);
          }
          if (iVar3 == 2) {
            iVar4 = local_14[1];
            if (local_14[1] <= local_14[0]) {
              iVar4 = local_14[0];
            }
            Pic_Subsystem_004523fd(spell_id,iVar4);
            iVar4 = local_14[1];
            if (local_14[0] <= local_14[1]) {
              iVar4 = local_14[0];
            }
            Pic_Subsystem_004523fd(spell_id,iVar4);
          }
          if (iVar3 == 3) {
            Pic_Subsystem_004523fd(spell_id,local_14[0]);
            if (local_14[0] < local_14[1]) {
              local_14[1] = local_14[1] + -1;
            }
            if (local_14[0] < local_14[2]) {
              local_14[2] = local_14[2] + -1;
            }
            iVar3 = local_14[1];
            if (local_14[1] <= local_14[2]) {
              iVar3 = local_14[2];
            }
            Pic_Subsystem_004523fd(spell_id,iVar3);
            iVar3 = local_14[1];
            if (local_14[2] <= local_14[1]) {
              iVar3 = local_14[2];
            }
            Pic_Subsystem_004523fd(spell_id,iVar3);
          }
          Ai_Subsystem_004cc9c5(0,0xff);
        }
        else {
          local_1c = 0;
          local_18 = 0;
          bVar1 = false;
          while ((local_18 < (int)(&DAT_006b3008)[spell_id] && (!bVar1))) {
            if (((&g_MasterCardColorTable)
                 [*(int *)(&g_CardSlot_CardId + local_18 * 0x120 + spell_id * 0x5b20) * 0x34] & 1)
                != 0) {
              bVar1 = true;
            }
            local_18 = local_18 + 1;
          }
          if (!bVar1) {
            g_SpellStackDepth = g_SpellStackDepth + 0x30;
          }
          iVar3 = FUN_0040a305(8 - (&DAT_006b3008)[spell_id],1,3);
          for (local_18 = 0; local_18 < iVar3; local_18 = local_18 + 1) {
            local_14[3] = FUN_004fdad2(spell_id,spell_id,1);
            if (4 < *(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000)) {
              local_14[3] = -1;
              local_18 = 0;
              while (((local_18 < 500 && (local_14[3] == -1)) &&
                     (*(int *)(&DAT_0069e730 + local_18 * 4 + spell_id * 2000) != -1))) {
                if (*(int *)(&DAT_0069e730 + local_18 * 4 + spell_id * 2000) < 5) {
                  local_14[3] = local_18;
                }
                local_18 = local_18 + 1;
              }
            }
            if ((local_14[3] != -1) &&
               (*(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000) != -1)) {
              local_14[local_1c] = *(int *)(&DAT_0069e730 + local_14[3] * 4 + spell_id * 2000);
              local_1c = local_1c + 1;
              Pic_Subsystem_004523fd(spell_id,local_14[3]);
            }
          }
          if (spell_id == 1) {
            Pic_Load_004509e8(0,(int)local_14,local_1c,s_Opponent_chose_these_basic_lands_00521180,0
                             );
          }
          for (local_18 = 0; local_18 < local_1c; local_18 = local_18 + 1) {
            Pic_Subsystem_00451291(spell_id,local_14[local_18]);
          }
        }
        Pic_Subsystem_00452276(spell_id);
      }
      if (((flags == 0x22) && (g_OverworldMapGrid == target_id)) &&
         (g_OverworldPlayerCoordX == spell_id)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


