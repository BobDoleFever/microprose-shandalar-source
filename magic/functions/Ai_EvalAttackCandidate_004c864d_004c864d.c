/*
 * Decompiled function: Ai_EvalAttackCandidate_004c864d
 * Entry Point: 004c864d
 * Size: 6381 bytes
 */
#include "magic.h"


void Ai_EvalAttackCandidate_004c864d(uint spell_id)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int local_e4 [9];
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac [16];
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_54;
  int local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  local_6c = 1 - spell_id;
  local_bc = 0;
  local_64 = 0;
  do {
    if (1 < local_64) {
      return;
    }
    if (local_64 == 0) {
      g_ScWillyScore = 0x19;
    }
    else {
      g_ScWillyScore = 0x1a;
    }
    Magic_CheckTurnTriggers(spell_id,g_ScWillyScore);
    for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id]; local_60 = local_60 + 1
        ) {
      if (((&g_CardSlot_ColorMask)[local_60 * 0x120 + spell_id * 0x5b20] == -1) ||
         ((char)(&g_CardSlot_ColorMask)[local_60 * 0x120 + spell_id * 0x5b20] == local_60)) {
        if ((local_bc == 0) && (g_IsAiThinking != 1)) {
          Magic_UpkeepPhase(0x14);
          local_bc = 1;
        }
        local_54 = 0;
        local_10 = 0;
        DAT_00559a94 = 0;
        local_e4[6] = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[spell_id];
            local_e4[7] = local_e4[7] + 1) {
          if ((((local_e4[7] == local_60) ||
               ((char)(&g_CardSlot_ColorMask)[spell_id * 0x5b20 + local_e4[7] * 0x120] == local_60))
              && (*(int *)(&g_CardSlot_CardId + spell_id * 0x5b20 + local_e4[7] * 0x120) != -1)) &&
             (((byte)*(undefined4 *)(&g_CardSlot_Flags + spell_id * 0x5b20 + local_e4[7] * 0x120) &
              6) == 6)) {
            (&DAT_005596b8)[DAT_00559a94] = local_e4[7];
            uVar1 = FUN_00473179(spell_id,local_e4[7],0x33,0xffffffff);
            (&DAT_00559808)[DAT_00559a94] = uVar1;
            uVar1 = FUN_00473179(spell_id,local_e4[7],0x34,0xffffffff);
            (&DAT_005595f8)[DAT_00559a94] = uVar1;
            local_b4 = 0;
            (&DAT_00559f88)[DAT_00559a94] = 0;
            iVar2 = Ai_Subsystem_004c9f3a(local_64,(&DAT_005595f8)[DAT_00559a94]);
            if (iVar2 != 0) {
              local_b4 = FUN_00473179(spell_id,local_e4[7],0x32,0xffffffff);
              if (local_b4 < 0) {
                local_b4 = 0;
              }
              (&DAT_00559f88)[DAT_00559a94] = local_b4;
              local_10 = local_10 + local_b4;
              if ((*(byte *)(&DAT_005595f8 + DAT_00559a94) & 0x80) != 0) {
                local_54 = local_54 + local_b4;
              }
            }
            DAT_00559a94 = DAT_00559a94 + 1;
            if (DAT_00559a94 == 0x10) break;
          }
        }
        if (1 < DAT_00559a94) {
          local_e4[6] = 1;
        }
        local_5c = 0;
        DAT_00559b1c = 0;
        local_b0 = 0;
        for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[local_6c];
            local_e4[7] = local_e4[7] + 1) {
          if (((*(int *)(&g_CardSlot_CardId + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
              ((char)(&g_CardSlot_ColorMask)[local_e4[7] * 0x120 + local_6c * 0x5b20] == local_60))
             && (((&g_CardSlot_Flags)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 2) != 0)) {
            (&DAT_0055a050)[DAT_00559b1c] = local_e4[7];
            iVar2 = FUN_00473179(local_6c,local_e4[7],0x33,local_60);
            (&DAT_00559848)[DAT_00559b1c] =
                 iVar2 - *(short *)(&g_CardSlot_Power + local_e4[7] * 0x120 + local_6c * 0x5b20);
            uVar1 = FUN_00473179(local_6c,local_e4[7],0x34,0xffffffff);
            (&DAT_00559638)[DAT_00559b1c] = uVar1;
            local_e4[4] = 0;
            (&DAT_0055a010)[DAT_00559b1c] = 0;
            if ((((&g_CardSlot_Flags)[local_e4[7] * 0x120 + local_6c * 0x5b20] & 0x10) == 0) &&
               (iVar2 = Ai_Subsystem_004c9f3a(local_64,(&DAT_00559638)[DAT_00559b1c]), iVar2 != 0))
            {
              local_e4[4] = FUN_00473179(local_6c,local_e4[7],0x32,local_60);
              if (local_e4[4] < 0) {
                local_e4[4] = 0;
              }
              (&DAT_0055a010)[DAT_00559b1c] = local_e4[4];
              local_5c = local_5c + local_e4[4];
            }
            if ((*(byte *)(&DAT_00559638 + DAT_00559b1c) & 0x40) != 0) {
              local_b0 = 1;
            }
            DAT_00559b1c = DAT_00559b1c + 1;
            if (DAT_00559b1c == 0x10) break;
          }
        }
        if (DAT_00559b1c != 0) {
          for (local_b8 = 0; local_b8 < DAT_00559a94; local_b8 = local_b8 + 1) {
            *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + (&DAT_005596b8)[local_b8] * 0x120) =
                 *(uint *)(&g_CardSlot_Flags + spell_id * 0x5b20 + (&DAT_005596b8)[local_b8] * 0x120
                          ) | 0x200;
          }
        }
        if ((DAT_00559a94 != 0) || (DAT_00559b1c != 0)) {
          if (DAT_00559b1c < 2) {
            if (DAT_00559b1c == 1) {
              for (local_b8 = 0; local_b8 < DAT_00559a94; local_b8 = local_b8 + 1) {
                iVar2 = Ai_Subsystem_004c9f3a(local_64,(&DAT_005595f8)[local_b8]);
                if ((iVar2 != 0) &&
                   (local_50[0] = FUN_0041db67(local_6c,DAT_0055a050,(&DAT_00559f88)[local_b8],
                                               spell_id,(&DAT_005596b8)[local_b8]),
                   local_c = local_50[0], local_50[0] != -1)) {
                  *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                       *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) |
                       0x40000;
                  if ((*(byte *)(&DAT_005595f8 + local_b8) & 0x80) != 0) {
                    *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20)
                         | 0x80000;
                  }
                  if (local_64 == 0) {
                    *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_50[0] * 0x120 + spell_id * 0x5b20)
                         | 0x100000;
                  }
                }
              }
            }
            else {
              for (local_b8 = 0; local_b8 < DAT_00559a94; local_b8 = local_b8 + 1) {
                iVar2 = Ai_Subsystem_004c9f3a(local_64,(&DAT_005595f8)[local_b8]);
                if ((iVar2 != 0) &&
                   ((((&DAT_006a5f3d)[spell_id * 0x5b20 + (&DAT_005596b8)[local_b8] * 0x120] & 2) ==
                     0 || ((*(byte *)(&DAT_005595f8 + local_b8) & 0x80) != 0)))) {
                  Mem_AllocOrFree_0041df33
                            (local_6c,(&DAT_00559f88)[local_b8],spell_id,(&DAT_005596b8)[local_b8]);
                }
              }
            }
          }
          else if (((g_IsAiThinking == 1) || ((local_b0 == 0 && (g_CurrentTurnPhase != spell_id))))
                  || ((local_b0 != 0 && (g_CurrentTurnPhase != local_6c)))) {
            local_e4[2] = 0x7fffffff;
            local_e4[3] = 0xffff8001;
            Ai_Subsystem_004ca07b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_50[local_68] = -1;
            }
            Ai_Subsystem_004ca0d9
                      (spell_id,0,local_b0,(int)local_50,local_64,0,local_e4 + 2,local_e4 + 3);
            Ai_Subsystem_004ca0d9
                      (spell_id,0,local_b0,(int)local_50,local_64,1,local_e4 + 2,local_e4 + 3);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_00559a94; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_50[local_68] = -1;
              }
              local_b4 = (&DAT_00559f88)[local_b8];
              while (local_b4 != 0) {
                if (DAT_006fe444 == 2) {
                  sprintf(&g_OverworldWorldState,s_Assign__d__sdamage_0052de74,local_b4,
                          s_trample_0052de64 +
                          (((*(byte *)(&DAT_005595f8 + local_b8) & 0x80) != 0) - 1 & 0xc));
                }
                else {
                  pcVar3 = s_trample_0052de24 +
                           (((*(byte *)(&DAT_005595f8 + local_b8) & 0x80) != 0) - 1 & 0xc);
                  iVar2 = local_b4;
                  uVar1 = Ai_Subsystem_004b8e4d(spell_id,(&DAT_005596b8)[local_b8]);
                  sprintf(&g_OverworldWorldState,s__s__Assign__sdamage_to_blockers__0052de34,uVar1,
                          pcVar3,iVar2);
                }
                Ai_Subsystem_004cad65(spell_id,(&DAT_005596b8)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  Action_ValidateTarget_00405802
                            (g_CurrentTurnPhase,local_6c,local_6c,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                             ,0xffffffff,0,0x10,0,&g_OverworldWorldState,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < DAT_00559b1c; local_68 = local_68 + 1) {
                    if ((&DAT_0055a050)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (g_IsAiThinking != 1)) {
                    Ai_Util_004cc42d(s_Illegal_target__wrong_attack_gro_0052de88);
                    Sleep(0x5dc);
                    Ai_Util_004cc42d(&DAT_0052deac);
                  }
                  if (((local_8 == 1) &&
                      (iVar2 = Ai_Subsystem_004cb1d6(local_e4[8],local_c0), iVar2 != 0)) &&
                     (local_8 = 0, g_IsAiThinking != 1)) {
                    Ai_Util_004cc42d(s_Illegal_target__gasseous_form__0052deb0);
                    Sleep(0x5dc);
                    Ai_Util_004cc42d(&DAT_0052ded0);
                  }
                }
                g_OverworldWorldState = 0;
                Ai_Subsystem_004cad65(spell_id,(&DAT_005596b8)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_00559b1c; local_68 = local_68 + 1) {
                    if ((&DAT_0055a050)[local_68] == local_c0) {
                      if (DAT_00627864 == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_b4;
                      }
                      if (local_50[local_68] == -1) {
                        local_c = FUN_0041db67(local_e4[8],local_c0,local_e4[5],spell_id,
                                               (&DAT_005596b8)[local_b8]);
                        local_50[local_68] = local_c;
                        if (local_c != -1) {
                          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20) =
                               *(uint *)(&g_CardSlot_Abilities1 +
                                        local_c * 0x120 + spell_id * 0x5b20) | 0x40000;
                          if ((*(byte *)(&DAT_005595f8 + local_b8) & 0x80) != 0) {
                            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + spell_id * 0x5b20) | 0x80000;
                          }
                          if (local_64 == 0) {
                            *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + spell_id * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + spell_id * 0x5b20) | 0x100000;
                          }
                        }
                      }
                      else {
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                spell_id * 0x5b20 + local_50[local_68] * 0x120) =
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     spell_id * 0x5b20 + local_50[local_68] * 0x120) + local_e4[5];
                      }
                      local_b4 = local_b4 - local_e4[5];
                    }
                  }
                }
              }
            }
          }
          if (DAT_00559a94 < 2) {
            if (DAT_00559a94 == 1) {
              for (local_b8 = 0; local_b8 < DAT_00559b1c; local_b8 = local_b8 + 1) {
                iVar2 = Ai_Subsystem_004c9f3a(local_64,(&DAT_00559638)[local_b8]);
                if (((iVar2 != 0) &&
                    (local_ac[0] = FUN_0041db67(spell_id,DAT_005596b8,(&DAT_0055a010)[local_b8],
                                                local_6c,(&DAT_0055a050)[local_b8]),
                    local_c = local_ac[0], local_ac[0] != -1)) &&
                   (*(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                         *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20)
                         | 0x40000, local_64 == 0)) {
                  *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) =
                       *(uint *)(&g_CardSlot_Abilities1 + local_ac[0] * 0x120 + local_6c * 0x5b20) |
                       0x100000;
                }
              }
            }
          }
          else if (((g_IsAiThinking == 1) ||
                   ((local_e4[6] == 0 && (g_CurrentTurnPhase != local_6c)))) ||
                  ((local_e4[6] != 0 && (g_CurrentTurnPhase != spell_id)))) {
            local_e4[0] = 0x7fffffff;
            local_e4[1] = 0xffffffff;
            Ai_Subsystem_004ca07b();
            for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
              local_ac[local_68] = -1;
            }
            Ai_Subsystem_004ca714
                      (spell_id,0,local_e4[6],(int)local_ac,local_64,0,local_e4,local_e4 + 1);
            Ai_Subsystem_004ca714
                      (spell_id,0,local_e4[6],(int)local_ac,local_64,1,local_e4,local_e4 + 1);
          }
          else {
            for (local_b8 = 0; local_b8 < DAT_00559b1c; local_b8 = local_b8 + 1) {
              for (local_68 = 0; local_68 < 0x10; local_68 = local_68 + 1) {
                local_ac[local_68] = -1;
              }
              local_e4[4] = (&DAT_0055a010)[local_b8];
              while (local_e4[4] != 0) {
                if (DAT_006fe444 == 2) {
                  sprintf(&g_OverworldWorldState,s_Assign__d_damage_0052df04,local_e4[4]);
                }
                else {
                  iVar2 = local_e4[4];
                  uVar1 = Ai_Subsystem_004b8e4d(local_6c,(&DAT_0055a050)[local_b8]);
                  sprintf(&g_OverworldWorldState,s__s__Assign_damage_to_attackers____0052ded4,uVar1,
                          iVar2);
                }
                Ai_Subsystem_004cadc5(local_6c,(&DAT_0055a050)[local_b8],1);
                local_8 = 0;
                while (local_8 == 0) {
                  Action_ValidateTarget_00405802
                            (g_CurrentTurnPhase,spell_id,spell_id,0x200,2,0,0,0,0,0,-1,-1,0xffffffff
                             ,0xffffffff,0,2,0,&g_OverworldWorldState,0,local_e4 + 8);
                  for (local_68 = 0; local_68 < DAT_00559a94; local_68 = local_68 + 1) {
                    if ((&DAT_005596b8)[local_68] == local_c0) {
                      local_8 = 1;
                    }
                  }
                  if ((local_8 == 0) && (g_IsAiThinking != 1)) {
                    Ai_Util_004cc42d(s_Illegal_target__wrong_attack_gro_0052df18);
                    Sleep(0x5dc);
                    Ai_Util_004cc42d(&DAT_0052df3c);
                  }
                  if (((local_8 == 1) &&
                      (iVar2 = Ai_Subsystem_004cb1d6(local_e4[8],local_c0), iVar2 != 0)) &&
                     (local_8 = 0, g_IsAiThinking != 1)) {
                    Ai_Util_004cc42d(s_Illegal_target__gasseous_form__0052df40);
                    Sleep(0x5dc);
                    Ai_Util_004cc42d(&DAT_0052df60);
                  }
                }
                g_OverworldWorldState = 0;
                Ai_Subsystem_004cadc5(local_6c,(&DAT_0055a050)[local_b8],0);
                if (((local_e4[8] != -1) && (local_c0 != -1)) && (local_c0 != -2)) {
                  for (local_68 = 0; local_68 < DAT_00559a94; local_68 = local_68 + 1) {
                    if ((&DAT_005596b8)[local_68] == local_c0) {
                      if (DAT_00627864 == 0) {
                        local_e4[5] = 1;
                      }
                      else {
                        local_e4[5] = local_e4[4];
                      }
                      if (local_ac[local_68] == -1) {
                        local_c = FUN_0041db67(spell_id,local_c0,local_e4[5],local_6c,
                                               (&DAT_0055a050)[local_b8]);
                        local_ac[local_68] = local_c;
                        if ((local_c != -1) &&
                           (*(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_6c * 0x5b20)
                                 = *(uint *)(&g_CardSlot_Abilities1 +
                                            local_c * 0x120 + local_6c * 0x5b20) | 0x40000,
                           local_64 == 0)) {
                          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + local_6c * 0x5b20) =
                               *(uint *)(&g_CardSlot_Abilities1 +
                                        local_c * 0x120 + local_6c * 0x5b20) | 0x100000;
                        }
                      }
                      else {
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_6c * 0x5b20 + local_ac[local_68] * 0x120) =
                             *(int *)(&g_CardSlot_ConvertedManaCost +
                                     local_6c * 0x5b20 + local_ac[local_68] * 0x120) + local_e4[5];
                      }
                      local_e4[4] = local_e4[4] - local_e4[5];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    DAT_00559b1c = 0;
    for (local_e4[7] = 0; local_e4[7] < (int)(&g_PlayerActiveCardCount)[local_6c];
        local_e4[7] = local_e4[7] + 1) {
      if ((*(int *)(&g_CardSlot_CardId + local_e4[7] * 0x120 + local_6c * 0x5b20) != -1) &&
         ((&g_CardSlot_ColorMask)[local_e4[7] * 0x120 + local_6c * 0x5b20] != -1)) {
        (&DAT_0055a050)[DAT_00559b1c] = local_e4[7];
        iVar2 = FUN_00473179(local_6c,local_e4[7],0x33,local_60);
        (&DAT_00559848)[DAT_00559b1c] =
             iVar2 - *(short *)(&g_CardSlot_Power + local_e4[7] * 0x120 + local_6c * 0x5b20);
        iVar2 = Ai_Subsystem_004cb1d6(local_6c,local_e4[7]);
        if (iVar2 != 0) {
          (&DAT_00559848)[DAT_00559b1c] = 0;
        }
        DAT_00559b1c = DAT_00559b1c + 1;
        if (DAT_00559b1c == 0x10) break;
      }
    }
    DAT_007006d0 = 0;
    DAT_00627860 = 0;
    if (g_IsAiThinking != 1) {
      DAT_0063ee1c = 0;
    }
    Pic_Subsystem_004475a4(spell_id);
    if (DAT_007006d0 == 0) {
      FUN_00505ea7(g_ScWillyScore);
      DAT_007006d0 = 1;
    }
    for (local_68 = 0; local_68 < DAT_00559b1c; local_68 = local_68 + 1) {
      local_e4[7] = (&DAT_0055a050)[local_68];
      local_e4[4] = (&DAT_00559848)[local_68];
      for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id];
          local_60 = local_60 + 1) {
        if (((((*(int *)(&g_ActiveCardsInPlay + local_60 * 0x120 + spell_id * 0x5b20) ==
                DAT_006ff2e0) &&
              ((int)(char)(&g_CardSlot_Toughness)[local_60 * 0x120 + spell_id * 0x5b20] == local_6c)
              ) && (*(int *)(&g_CardSlot_OriginalCardId + local_60 * 0x120 + spell_id * 0x5b20) ==
                    local_e4[7])) &&
            (((local_64 == 0 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))))) &&
           ((((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 4) != 0 &&
            (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 8) == 0)))) {
          local_e4[4] = local_e4[4] -
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_60 * 0x120 + spell_id * 0x5b20);
        }
      }
      for (local_60 = 0; local_60 < (int)(&g_PlayerActiveCardCount)[spell_id];
          local_60 = local_60 + 1) {
        if ((((*(int *)(&g_ActiveCardsInPlay + local_60 * 0x120 + spell_id * 0x5b20) == DAT_006ff2e0
              ) && ((int)(char)(&g_CardSlot_Toughness)[local_60 * 0x120 + spell_id * 0x5b20] ==
                    local_6c)) &&
            (*(int *)(&g_CardSlot_OriginalCardId + local_60 * 0x120 + spell_id * 0x5b20) ==
             local_e4[7])) &&
           ((((local_64 == 0 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) != 0)) ||
             ((local_64 == 1 &&
              (((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 0x10) == 0)))) &&
            ((((&DAT_006a5f6a)[local_60 * 0x120 + spell_id * 0x5b20] & 8) != 0 &&
             (local_e4[4] -
              ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20)) < 0)))
            ))) {
          iVar2 = -(local_e4[4] -
                   ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                   *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20)));
          if ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
              *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20) <=
              iVar2) {
            iVar2 = (int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                    *(int *)(&g_CardSlot_ConvertedManaCost + local_60 * 0x120 + spell_id * 0x5b20);
          }
          Mem_AllocOrFree_0041df33
                    (local_6c,iVar2,
                     (int)(char)(&g_CardSlot_DamageReceived)[local_60 * 0x120 + spell_id * 0x5b20],
                     *(int *)(&g_CardSlot_TypeFlags + local_60 * 0x120 + spell_id * 0x5b20));
          local_e4[4] = local_e4[4] -
                        ((int)(char)(&DAT_006a5f4f)[local_60 * 0x120 + spell_id * 0x5b20] +
                        *(int *)(&g_CardSlot_ConvertedManaCost +
                                local_60 * 0x120 + spell_id * 0x5b20));
        }
      }
    }
    Pic_Subsystem_004488a0();
    Pic_Subsystem_004475a4(spell_id);
    DAT_00627860 = 0;
    DAT_0063ee1c = 0;
    if (DAT_007006d0 == 0) {
      FUN_00505ea7(g_ScWillyScore);
    }
    local_64 = local_64 + 1;
  } while( true );
}


