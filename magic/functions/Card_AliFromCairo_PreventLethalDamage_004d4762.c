/*
 * Decompiled function: Card_AliFromCairo_PreventLethalDamage
 * Entry Point: 004d4762
 * Size: 1469 bytes
 */
#include "magic.h"


undefined4 Card_AliFromCairo_PreventLethalDamage(int spell_id,int target_id,int flags)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    g_SpellStackDepth = g_SpellStackDepth + 0x30;
  }
  if ((flags == 0x25) && (0 < (int)(&g_PlayerCreatureCount)[spell_id])) {
    local_8 = 0;
    local_14 = 0;
    while( true ) {
      iVar1 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
      if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
          (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
        iVar1 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
      }
      if (iVar1 <= local_8) break;
      if ((((*(int *)(&g_CardSlot_CardId + g_CurrentTurnPhase * 0x5b20 + local_8 * 0x120) ==
             DAT_006ff2e0) &&
           (((&g_CardSlot_Flags)[g_CurrentTurnPhase * 0x5b20 + local_8 * 0x120] & 2) != 0)) &&
          ((char)(&g_CardSlot_Toughness)[g_CurrentTurnPhase * 0x5b20 + local_8 * 0x120] == spell_id)
          ) && (*(int *)(&g_CardSlot_OriginalCardId + g_CurrentTurnPhase * 0x5b20 + local_8 * 0x120)
                == -1)) {
        local_14 = local_14 +
                   *(int *)(&g_CardSlot_ConvertedManaCost +
                           g_CurrentTurnPhase * 0x5b20 + local_8 * 0x120);
      }
      if (((*(int *)(&g_CardSlot_CardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20) ==
            DAT_006ff2e0) &&
          (((&g_CardSlot_Flags)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0)) &&
         (((char)(&g_CardSlot_Toughness)[local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20] ==
           spell_id &&
          (*(int *)(&g_CardSlot_OriginalCardId + local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20)
           == -1)))) {
        local_14 = local_14 +
                   *(int *)(&g_CardSlot_ConvertedManaCost +
                           local_8 * 0x120 + g_ActivePlayerPriority * 0x5b20);
      }
      local_8 = local_8 + 1;
    }
    if ((0 < local_14) && ((int)(&g_PlayerCreatureCount)[spell_id] <= local_14)) {
      Ai_Subsystem_004cc56d(spell_id,spell_id,target_id,-1,-1,s_is_doin__his_thing__0052ea1c,0);
      local_14 = local_14 + (1 - (&g_PlayerCreatureCount)[spell_id]);
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      while (*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) <
             local_14) {
        Pic_Subsystem_00424500(s_prompts_txt_0052ea44,s_ALI_FROM_CAIRO_0052ea34);
        sprintf(&g_OverworldWorldState,&g_OverworldGoldAmount,
                *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1,
                local_14);
        Action_ValidateTarget_00405802
                  (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,0
                   ,&g_OverworldWorldState,0,&local_10);
        if (((char)(&g_CardSlot_Toughness)[local_10 * 0x5b20 + local_c * 0x120] == spell_id) &&
           (*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x5b20 + local_c * 0x120) == -1)) {
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) + 1;
          if (*(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) != 0) {
            *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) + -1;
          }
          if (DAT_00627864 == 1) {
            while ((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20)
                    < local_14 &&
                   (*(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) !=
                    0))) {
              *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) =
                   *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) +
                   1;
              *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) =
                   *(int *)(&g_CardSlot_ConvertedManaCost + local_10 * 0x5b20 + local_c * 0x120) +
                   -1;
            }
          }
          Ai_Subsystem_004cc9c5(0,0x20);
        }
        else if (g_IsAiThinking != 1) {
          Ai_Util_004cc42d(s_Illegal_target__prevent_damage_t_0052ea50);
          Sleep(2000);
          Ai_Util_004cc42d(&DAT_0052ea88);
        }
      }
    }
  }
  if (((flags == 0x8a) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    DAT_006ff19c = DAT_006ff19c + 0x18;
  }
  if (((flags == 0x8b) && (g_OverworldMapGrid == target_id)) &&
     (g_OverworldPlayerCoordX == spell_id)) {
    DAT_006ff19c = DAT_006ff19c + -0x18;
  }
  if ((flags == 199) && (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 2) != 0)) {
    if (spell_id == g_ActivePlayerPriority) {
      g_SpellStackDepth = g_SpellStackDepth + 0x1e0;
    }
    else {
      g_SpellStackDepth = g_SpellStackDepth + -0x1e0;
    }
  }
  return 0;
}


