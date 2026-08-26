/*
 * Decompiled function: Prompts_Load_004fe9b6
 * Entry Point: 004fe9b6
 * Size: 1451 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_004fe9b6(int spell_id,int target_id,int flags)

{
  int y;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (iVar1 = FUN_0040d949(spell_id,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      if ((g_PlayerHandCardCount._1_1_ & 4) == 0) {
        g_TurnCounter = 0;
        Ai_CalcManaRequirement_004ba890(spell_id,1,-1);
        if (g_ActivePlayer == 1) {
          return 0;
        }
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             g_TurnCounter;
      }
      else {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
             *(undefined4 *)
              (&g_CardSlot_ConvertedManaCost + DAT_006b2d2c * 0x120 + DAT_006b2d3c * 0x5b20);
      }
      Pic_Subsystem_00424500(s_prompts_txt_00530968,s_DRAIN_LIFE_0053095c);
      Card_DirectDamage_EvaluateBestTarget(spell_id,target_id);
    }
    if (flags == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20);
      y = *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20);
      iVar3 = Card_DirectDamage_PromptAndDealDamage
                        (spell_id,target_id,0x71,
                         *(int *)(&g_CardSlot_ConvertedManaCost +
                                 target_id * 0x120 + spell_id * 0x5b20));
      if ((iVar3 == 0) ||
         (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) < 1)) {
        *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      else {
        if (y == -1) {
          local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
          if ((int)(&g_PlayerCreatureCount)[iVar1] <=
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)) {
            local_8 = (&g_PlayerCreatureCount)[iVar1];
          }
        }
        else {
          iVar3 = FUN_00473179(iVar1,y,0x33,0xffffffff);
          if (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) <
              iVar3) {
            local_8 = *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20
                              );
          }
          else {
            local_8 = FUN_00473179(iVar1,y,0x33,0xffffffff);
          }
        }
        if (local_8 < 0) {
          local_8 = 0;
        }
        iVar1 = Pic_Subsystem_00451291(spell_id,DAT_006fdbd0);
        if (iVar1 != -1) {
          *(undefined4 *)(&g_ActiveCardsInPlay + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(undefined4 *)(&g_CardSlot_CardId + target_id * 0x120 + spell_id * 0x5b20);
          *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + spell_id * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + spell_id * 0x5b20) | 2;
          *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + spell_id * 0x5b20) = 0x44;
          *(undefined4 *)(&DAT_006a5f80 + iVar1 * 0x120 + spell_id * 0x5b20) = 0xd7;
          *(int *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + spell_id * 0x5b20) = local_8;
          FUN_00476482(spell_id,iVar1);
          (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + spell_id * 0x5b20] = (undefined1)spell_id;
          *(int *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + spell_id * 0x5b20) = target_id;
        }
      }
      (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      Pic_Subsystem_0044867e(spell_id,target_id,1);
    }
    if (((flags == 0x6e) &&
        (*(int *)(&g_CardSlot_CardId + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                 ) == DAT_006ff2e0)) &&
       ((*(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) == -1 &&
        ((((char)(&g_CardSlot_DamageReceived)
                 [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] == spell_id &&
          (*(int *)(&g_CardSlot_TypeFlags +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) == target_id)) &&
         (*(int *)(&g_CardSlot_ConvertedManaCost +
                  g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) != 0)))))) {
      (&g_CardSlot_DamageReceived)[target_id * 0x120 + spell_id * 0x5b20] =
           (undefined1)g_OverworldPlayerCoordX;
      *(int *)(&g_CardSlot_TypeFlags + target_id * 0x120 + spell_id * 0x5b20) = g_OverworldMapGrid;
    }
    uVar2 = 0;
  }
  return uVar2;
}


