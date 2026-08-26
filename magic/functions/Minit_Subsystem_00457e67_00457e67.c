/*
 * Decompiled function: Minit_Subsystem_00457e67
 * Entry Point: 00457e67
 * Size: 1839 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00457e67(int spell_id,int target_id,int flags)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int local_164;
  int local_160;
  int local_15c;
  int local_150 [80];
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if ((((g_PlayerManaPool == 0xcf) &&
       (((&g_CardSlot_Flags)[target_id * 0x120 + spell_id * 0x5b20] & 0x10) == 0)) &&
      (iVar3 = FUN_0040d949(spell_id,7,1), iVar3 != 0)) &&
     (((g_OverworldMapGrid == target_id && (g_OverworldPlayerCoordX == spell_id)) &&
      (DAT_006a4b5c == spell_id)))) {
    if (flags == 0x7d) {
      if (g_ActivePlayerPriority == spell_id) {
        if (((*(int *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) != 0)
            && (local_10 = FUN_0040d949(spell_id,7,3), local_10 != 0)) &&
           (g_ActivePalette = g_ActivePalette | 2,
           *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) == 0)) {
          iVar3 = FUN_0040a1d2(local_10 + -2);
          *(int *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = iVar3 + 2;
          DAT_0062785c = *(undefined4 *)
                          (&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20);
        }
      }
      else {
        g_ActivePalette = g_ActivePalette | 1;
      }
    }
    if (flags == 0x7e) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 0;
      iVar3 = g_TurnCounter;
      local_8 = g_OverworldPlayerCoordY;
      g_OverworldPlayerCoordY = 0xffffffff;
      if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
        Magic_CombatPhase(spell_id,target_id,0x72,0,0);
        Ai_CalcManaRequirement_004ba890(spell_id,0,-1);
        Magic_DiscardToHandSize();
        local_164 = g_TurnCounter;
      }
      else {
        local_164 = Ai_CalcManaRequirement_004ba890
                              (spell_id,0,
                               *(int *)(&g_CardSlot_TargetSlot +
                                       target_id * 0x120 + spell_id * 0x5b20));
        if (local_164 == 0) {
          g_ActivePlayer = 1;
        }
        *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
      }
      g_OverworldPlayerCoordY = local_8;
      g_TurnCounter = iVar3;
      if ((g_ActivePlayer == 1) || (local_164 < 1)) {
        g_ActivePlayer = -1;
      }
      else {
        *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + target_id * 0x120 + spell_id * 0x5b20) | 0x10;
        local_10 = 0;
        for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
          if (*(int *)(&DAT_0069e730 + local_160 * 4 + spell_id * 2000) != -1) {
            local_150[local_10] = *(int *)(&DAT_0069e730 + local_160 * 4 + spell_id * 2000);
            local_10 = local_10 + 1;
          }
        }
        local_150[local_10] = -1;
        if (((g_CurrentTurnPhase == spell_id) && (g_IsAiThinking != 1)) && (DAT_006fedc0 == 0)) {
          Pic_Subsystem_00424500(s_prompts_txt_00524234,s_ALADDINS_LAMP_00524224);
          local_15c = Pic_Load_004509e8(spell_id,(int)local_150,local_10,&g_OverworldGoldAmount,1);
        }
        else {
          local_15c = FUN_004fdc20(spell_id,spell_id,2,(int)local_150);
          if (local_15c == -1) {
            local_15c = 0;
          }
        }
        if (local_10 != 0) {
          Pic_Subsystem_00451291(spell_id,local_150[local_15c]);
          for (local_160 = 0; local_160 < local_10; local_160 = local_160 + 1) {
            Pic_Subsystem_004523fd(spell_id,0);
          }
          local_150[local_15c] = -1;
          bVar2 = false;
          while (!bVar2) {
            local_160 = 0;
            do {
              local_15c = FUN_0040a1d2(local_164);
              if (local_150[local_15c] != -1) break;
              bVar1 = local_160 < 999;
              local_160 = local_160 + 1;
            } while (bVar1);
            if (local_150[local_15c] == -1) {
              for (local_160 = 0; local_160 < local_164; local_160 = local_160 + 1) {
                if (local_150[local_160] != -1) {
                  local_15c = local_160;
                }
              }
            }
            if (local_150[local_15c] == -1) {
              bVar2 = true;
            }
            else {
              Pic_Subsystem_0045245e(spell_id,local_150[local_15c]);
              local_150[local_15c] = -1;
            }
          }
        }
        DAT_006fe408 = 1;
      }
    }
  }
  if ((flags == 0x6a) && (g_ActivePlayerPriority == spell_id)) {
    *(undefined4 *)(&g_CardSlot_TargetSlot + target_id * 0x120 + spell_id * 0x5b20) = 0;
    local_c = 0;
    local_10 = 0;
    for (local_160 = 0; local_160 < (int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
        local_160 = local_160 + 1) {
      if ((((*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) !=
             -1) && (((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2)
                     != 0)) &&
          (((&DAT_0051aed1)
            [*(int *)(&g_CardSlot_CardId + local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20) *
             0x34] & 0x10) != 0)) &&
         (local_10 = local_10 + 1,
         ((&g_CardSlot_Flags)[local_160 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 0x10) == 0)) {
        local_c = local_c + 1;
      }
    }
    if (0x50 < (local_c * 100) / local_10) {
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + target_id * 0x120 + spell_id * 0x5b20) = 2;
    }
  }
  return 0;
}


