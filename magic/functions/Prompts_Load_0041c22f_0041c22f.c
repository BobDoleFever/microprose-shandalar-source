/*
 * Decompiled function: Prompts_Load_0041c22f
 * Entry Point: 0041c22f
 * Size: 1704 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_0041c22f(int spell_id,int target_id,int flags)

{
  int iVar1;
  undefined4 uVar2;
  int local_524;
  int local_520;
  int local_51c;
  int local_518;
  int local_514 [80];
  int local_3d4;
  int local_3d0;
  int local_3cc;
  int aiStack_3c8 [160];
  undefined4 local_148 [80];
  int local_8;
  
  if (flags == 0x74) {
    Ai_GetOpponentPlayerScore(0);
    if (((byte)g_PlayerHandCardCount & 4) == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_00403250((int *)0x0,0,spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,0xffffffff,
                           0xffffffff,0xffffffff,0x20,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if ((((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
        (g_OverworldPlayerCoordX == spell_id)) && (((byte)g_PlayerHandCardCount & 4) != 0)) {
      Pic_Subsystem_00424500(s_prompts_txt_00519b98,s_SAMITE_HEALER_00519b88);
      iVar1 = Action_ValidateTarget_00405802
                        (spell_id,2,2,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,0
                         ,0,&g_OverworldGoldAmount,1,&local_524);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_524;
        *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_520;
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
      }
    }
    if (flags == 0x71) {
      if (((byte)g_PlayerHandCardCount & 4) == 0) {
        local_3d4 = 0;
        local_51c = 0;
        for (local_3d0 = 0; local_3d0 < 2; local_3d0 = local_3d0 + 1) {
          for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
            if ('\0' < (char)(&DAT_00700ec0)[spell_id + local_3d0 * 0xa0 + local_8 * 2]) {
              aiStack_3c8[local_3d4 * 2] = local_3d0;
              aiStack_3c8[local_3d4 * 2 + 1] = local_8;
              local_514[local_3d4] =
                   (int)(char)(&DAT_00700ec0)[spell_id + local_3d0 * 0xa0 + local_8 * 2];
              if (*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + local_3d0 * 0x5b20) == -1) {
                local_148[local_3d4] =
                     *(undefined4 *)(&g_ActiveCardsInPlay + local_8 * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
              else {
                local_148[local_3d4] =
                     *(undefined4 *)(&g_CardSlot_CardId + local_8 * 0x120 + local_3d0 * 0x5b20);
                local_3d4 = local_3d4 + 1;
              }
            }
          }
        }
        if (0 < local_3d4) {
          if ((spell_id == 1) || (g_IsAiThinking == 1)) {
            local_51c = 0;
            for (local_518 = 0; local_518 < local_3d4; local_518 = local_518 + 1) {
              if (local_51c < local_514[local_518]) {
                local_51c = local_518;
              }
            }
            local_3cc = local_51c;
          }
          else {
            local_3cc = Pic_Subsystem_004509a1
                                  (spell_id,local_148,local_514,local_3d4,
                                   s_Select_the_card_that_has_damaged_00519ba8,1,&DAT_00519ba4);
          }
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               (char)(&DAT_00700ec0)
                     [spell_id +
                      aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] * 2;
          (&DAT_00700ec0)
          [spell_id + aiStack_3c8[local_3cc * 2] * 0xa0 + aiStack_3c8[local_3cc * 2 + 1] * 2] = 0;
        }
        if ((int)(&g_PlayerCreatureCount)[1 - spell_id] < 1) {
          g_SpellStackDepth = g_SpellStackDepth + 1000;
        }
        else {
          g_SpellStackDepth =
               g_SpellStackDepth +
               (local_51c * 100) / (int)(&g_PlayerCreatureCount)[1 - spell_id] + -100;
        }
      }
      else {
        local_524 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
        local_520 = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
        iVar1 = Rules_ParseFilter_0040360b
                          (local_524,local_520,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                           DAT_006ff2e0,-1,0xffffffff,0xffffffff,0x20,0,0);
        if (iVar1 == 0) {
          g_ActivePlayer = 1;
        }
        else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120) !=
                 0) {
          (&g_PlayerCreatureCount)[spell_id] =
               (&g_PlayerCreatureCount)[spell_id] +
               (char)(&DAT_00700ec0)
                     [spell_id +
                      (char)(&g_CardSlot_DamageReceived)[local_524 * 0x5b20 + local_520 * 0x120] *
                      0xa0 + *(int *)(&g_CardSlot_TypeFlags + local_524 * 0x5b20 + local_520 * 0x120
                                     ) * 2] * 2 +
               *(int *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120);
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + local_524 * 0x5b20 + local_520 * 0x120) =
               0;
        }
        (&g_CardSlot_TurnPlayed)
        [*(int *)(&g_CardSlot_TapState + target_id * 0x120 + spell_id * 0x5b20) * 0x5b20 +
         *(int *)(&g_CardSlot_SicknessState + target_id * 0x120 + spell_id * 0x5b20) * 0x120] = 0;
      }
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


