/*
 * Decompiled function: Prompts_Load_0041b98a
 * Entry Point: 0041b98a
 * Size: 2213 bytes
 */
#include "magic.h"


undefined4 Prompts_Load_0041b98a(int spell_id,int target_id,int flags,int height)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (flags == 0x74) {
    if ((g_ActivePlayerPriority == spell_id) && (height == 0)) {
      uVar2 = 0;
    }
    else if (((byte)g_PlayerHandCardCount & 4) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 99;
    }
  }
  else {
    if (((flags == 0x6c) && (g_OverworldMapGrid == target_id)) &&
       (g_OverworldPlayerCoordX == spell_id)) {
      g_SpellStackDepth = g_SpellStackDepth + -0x60;
      if (((byte)g_PlayerHandCardCount & 4) == 0) {
        Pic_Subsystem_00424500(s_prompts_txt_00519af4,s_HEALING_SALVE_00519ae4);
        iVar3 = Action_ValidateTarget_00405802
                          (spell_id,2,spell_id,0x1000,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                           &g_OverworldGoldAmount,1,&local_18);
        if (iVar3 == 0) {
          g_ActivePlayer = 1;
        }
        else {
          *(int *)(&g_CardSlot_CombatTarget + target_id * 0x120 + spell_id * 0x5b20) = local_18;
          *(int *)(&g_CardSlot_AttachedAura + target_id * 0x120 + spell_id * 0x5b20) = local_14;
          (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 1;
          *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = height;
        }
      }
      else {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
        cVar1 = -1;
        local_8 = 0;
        g_ActivePlayer = -1;
        local_10 = 0;
        while ((((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] < height &&
                (local_8 == 0)) && ((g_ActivePlayer != 1 && (local_10 == 0))))) {
          Pic_Subsystem_00424500(s_prompts_txt_00519b10,s_HEALING_SALVE_00519b00);
          sprintf(&g_OverworldWorldState,&DAT_0069f84a,
                  (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + 1,height);
          iVar3 = Action_ValidateTarget_00405802
                            (spell_id,2,spell_id,0x200,0,0,0,0,0,0,DAT_006ff2e0,-1,0xffffffff,
                             0xffffffff,0,0,0,&g_OverworldWorldState,3,&local_18);
          if (iVar3 == 0) {
            if (local_14 == -1) {
              g_ActivePlayer = 1;
            }
            else {
              local_8 = 1;
            }
          }
          else if ((((&g_CardSlot_Toughness)[local_18 * 0x5b20 + local_14 * 0x120] == cVar1) &&
                   (*(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x5b20 + local_14 * 0x120) ==
                    local_1c)) || (cVar1 == -1)) {
            cVar1 = (&g_CardSlot_Toughness)[local_18 * 0x5b20 + local_14 * 0x120];
            local_1c = *(int *)(&g_CardSlot_OriginalCardId + local_18 * 0x5b20 + local_14 * 0x120);
            *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + local_18 * 0x5b20 + local_14 * 0x120) | 0x200000;
            Ai_Subsystem_004cc9c5(0,0x20);
            *(int *)(&g_CardSlot_CombatTarget +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 local_18;
            *(int *)(&g_CardSlot_AttachedAura +
                    target_id * 0x120 +
                    spell_id * 0x5b20 +
                    (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                 local_14;
            (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                 (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
            if ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
              local_10 = local_10 + 1;
            }
            if (DAT_00627864 == 1) {
              while (((char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] < height
                     && (local_10 == 0))) {
                *(int *)(&g_CardSlot_CombatTarget +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                     local_18;
                *(int *)(&g_CardSlot_AttachedAura +
                        target_id * 0x120 +
                        spell_id * 0x5b20 +
                        (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8) =
                     local_14;
                (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
                     (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + '\x01';
                if ((&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] == '\x13') {
                  local_10 = 1;
                }
              }
            }
          }
          else if (g_IsAiThinking != 1) {
            Ai_Util_004cc42d(s_Illegal_target__prevent_damage_t_00519b1c);
            Sleep(2000);
            Ai_Util_004cc42d(&DAT_00519b4c);
          }
        }
        for (local_c = 0;
            local_c < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20];
            local_c = local_c + 1) {
          *(uint *)(&g_CardSlot_Flags +
                   *(int *)(&g_CardSlot_AttachedAura +
                           local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                   *(int *)(&g_CardSlot_CombatTarget +
                           local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) =
               *(uint *)(&g_CardSlot_Flags +
                        *(int *)(&g_CardSlot_AttachedAura +
                                local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x120 +
                        *(int *)(&g_CardSlot_CombatTarget +
                                local_c * 8 + spell_id * 0x5b20 + target_id * 0x120) * 0x5b20) &
               0xffcfffff;
        }
        if ((local_10 != 0) && (local_10 = 0, g_IsAiThinking != 1)) {
          Ai_Util_004cc42d(s_WARNING___target_array_overflow_i_00519b50);
          Sleep(5000);
          Ai_Util_004cc42d(&DAT_00519b84);
        }
      }
      if (g_ActivePlayer == 1) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] = 0;
      }
    }
    if (flags == 0x71) {
      while ('\0' < (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20]) {
        (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] =
             (&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] + -1;
        local_18 = *(int *)(&g_CardSlot_CombatTarget +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8
                           );
        local_14 = *(int *)(&g_CardSlot_AttachedAura +
                           target_id * 0x120 +
                           spell_id * 0x5b20 +
                           (char)(&g_CardSlot_TurnPlayed)[target_id * 0x120 + spell_id * 0x5b20] * 8
                           );
        if (((byte)g_PlayerHandCardCount & 4) == 0) {
          (&g_PlayerCreatureCount)[local_18] =
               (&g_PlayerCreatureCount)[local_18] +
               *(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20);
        }
        else {
          iVar3 = Rules_ParseFilter_0040360b
                            (local_18,local_14,(char *)0x0,spell_id,2,2,0x200,0,0,0,0,0,0,
                             DAT_006ff2e0,-1,0xffffffff,0xffffffff,0,0,0);
          if (iVar3 == 0) {
            g_ActivePlayer = 1;
          }
          else if (*(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) !=
                   0) {
            *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) =
                 *(int *)(&g_CardSlot_ConvertedManaCost + local_18 * 0x5b20 + local_14 * 0x120) + -1
            ;
          }
        }
      }
      Pic_Subsystem_0044867e(spell_id,target_id,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


