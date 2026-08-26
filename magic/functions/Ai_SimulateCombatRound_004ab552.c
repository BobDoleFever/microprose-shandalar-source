/*
 * Decompiled function: Ai_SimulateCombatRound
 * Entry Point: 004ab552
 * Size: 2722 bytes
 */
#include "magic.h"


int Ai_SimulateCombatRound(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *str_2;
  bool bVar5;
  uint local_e4;
  uint local_d4 [2];
  byte local_cc [160];
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  DAT_0067bdb0 = 1;
  local_c = 0;
  local_28 = 1 - arg_1;
  Ai_FilterValidBlockers(local_d4,local_d4 + 1);
  memset(local_cc,0,0xa0);
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&g_PlayerCreatureCount)[arg_1]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  iVar1 = *(int *)(&g_PlayerLifeTotals + arg_1 * 4) * local_20;
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&g_PlayerCreatureCount)[local_28]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  local_c = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) -
            ((int)(*(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_20 +
                  (*(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_20 >> 0x1f & 7U)) >> 3);
  if ((int)(&g_PlayerCreatureCount)[arg_1] < 1) {
    local_c = local_c + ((&g_PlayerCreatureCount)[arg_1] * 4 + -8) * 0x4b;
  }
  if ((int)(&g_PlayerCreatureCount)[local_28] < 1) {
    local_c = local_c + ((&g_PlayerCreatureCount)[local_28] + -2) * -0x100;
  }
  if (DAT_0067b9a4 != 0) {
    g_OverworldWorldState = 0;
  }
  local_8 = 0;
  do {
    if (1 < local_8) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_8];
            local_1c = local_1c + 1) {
          if ((1 << ((byte)arg_1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0) {
            local_c = local_c + 2;
          }
          if ((1 << (1 - (byte)arg_1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0)
          {
            local_c = local_c + -2;
          }
        }
      }
      if ((DAT_00676c8c == 0) && (g_DefendingPlayer == arg_1)) {
        local_c = Ai_ChooseAttackers(arg_1,local_c);
      }
      DAT_0067bdb0 = 0;
      return local_c;
    }
    local_28 = 1 - local_8;
    local_10 = -(((-(uint)(g_ActivePlayerPriority == local_8) & 0x30) + 0x18) *
                *(int *)(&DAT_0063eeac + local_8 * 0x20));
    for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
      for (local_24 = 1; local_24 <= *(int *)(&DAT_0063ee30 + local_1c * 4 + local_8 * 0x20);
          local_24 = local_24 + 1) {
        local_10 = local_10 + (int)(0x30 / (longlong)local_24);
      }
    }
    for (local_1c = 0; local_1c < (int)(&g_PlayerActiveCardCount)[local_8]; local_1c = local_1c + 1)
    {
      if (*(int *)(&g_CardSlot_CardId + local_1c * 0x120 + local_8 * 0x5b20) != -1) {
        local_14 = *(int *)(&g_CardSlot_CardId + local_1c * 0x120 + local_8 * 0x5b20);
        if (((&g_MasterCardColorTable)[local_14 * 0x34] & 0x80) == 0) {
          local_2c = 1;
          if (((&g_MasterCardColorTable)[local_14 * 0x34] & 2) != 0) {
            uVar2 = FUN_00473179(local_8,local_1c,0x34,0xffffffff);
            uVar3 = FUN_00473179(local_8,local_1c,0x32,0xffffffff);
            local_18 = (uVar3 & 0xffffbfff) * 2;
            if ((&DAT_0051aebd)[local_14 * 0x34] == '\0') {
              local_18 = 0;
            }
            iVar1 = local_18;
            uVar3 = FUN_00473179(local_8,local_1c,0x33,0xffffffff);
            uVar3 = uVar3 & 0xffffbfff;
            local_2c = (int)((iVar1 + 3) * (uVar3 + 4)) / 2;
            if ((((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) != 0) &&
               (g_DefendingPlayer == local_8)) {
              local_2c = local_2c + -1;
            }
            if ((uVar2 & 0x80) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uVar2 & 0x100) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if (((&DAT_0051aed0)[local_14 * 0x34] & 3) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uVar2 & 0x40) != 0) {
              local_2c = (int)((uVar3 + 1) * local_2c) / 2;
            }
            if ((uVar2 & 0x200) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((((DAT_00676c8c == 0) && (local_8 != arg_1)) && (g_DefendingPlayer == arg_1)) &&
               (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
              local_e4 = 0;
              uVar2 = FUN_00473179(local_8,local_1c,0x34,0xffffffff);
              for (local_24 = 0; local_24 < (int)(&g_PlayerActiveCardCount)[local_28];
                  local_24 = local_24 + 1) {
                iVar4 = FUN_00472c0c(local_28,local_24,local_8,local_1c,uVar2,local_d4[local_8]);
                if (iVar4 != 0) {
                  local_e4 = 1;
                  iVar4 = FUN_00473179(local_28,local_24,0x33,local_1c);
                  if ((iVar1 < iVar4) ||
                     (iVar4 = FUN_00473179(local_28,local_24,0x32,local_1c), (int)uVar3 <= iVar4)) {
                    local_e4 = 3;
                    break;
                  }
                }
              }
              if ((local_e4 & 2) == 0) {
                iVar4 = *(int *)(&g_PlayerLifeTotals + local_28 * 4) * local_18 * 0x18;
                local_10 = local_10 + ((int)(iVar4 + (iVar4 >> 0x1f & 0xfU)) >> 4);
                if ((local_e4 == 0) && ((int)(&g_PlayerCreatureCount)[local_28] <= iVar1)) {
                  local_10 = local_10 + 0x100;
                }
              }
            }
            if (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              if (*(code **)(&DAT_0051aec8 + local_14 * 0x34) == Card_KormusBell_CheckSwampCreature)
              {
                local_2c = 1;
              }
            }
            else {
              local_2c = local_2c * 3;
            }
            local_2c = (int)(*(int *)(&DAT_00695e88 + local_8 * 4) * local_2c +
                            ((int)(*(int *)(&DAT_00695e88 + local_8 * 4) * local_2c) >> 0x1f & 7U))
                       >> 3;
          }
          if (((&g_MasterCardColorTable)[local_14 * 0x34] & 1) != 0) {
            if (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              local_2c = 2;
            }
            else {
              bVar5 = ((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) == 0;
              if (bVar5) {
                local_2c = 1;
              }
              else {
                local_2c = 0;
              }
              local_2c = (uint)bVar5;
            }
          }
          if (((&g_MasterCardColorTable)[local_14 * 0x34] == '@') &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
            local_2c = (((char)(&DAT_0051aec0)[local_14 * 0x34] * 3 + 3) * 4) / 2;
          }
          if (((((&g_MasterCardColorTable)[local_14 * 0x34] == '\x04') &&
               (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
              ((&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] != -1)) &&
             (*(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_8 * 0x5b20) != -1)) {
            local_cc[(char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50 +
                     *(int *)(&g_CardSlot_OriginalCardId + local_1c * 0x120 + local_8 * 0x5b20)] =
                 local_cc[(char)(&g_CardSlot_Toughness)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50
                          + *(int *)(&g_CardSlot_OriginalCardId +
                                    local_1c * 0x120 + local_8 * 0x5b20)] |
                 (byte)(1 << ((byte)local_8 & 0x1f));
          }
          if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 0x38) != 0) &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            iVar1 = Pic_Subsystem_00452551(local_14);
            local_2c = iVar1 * 0xc;
          }
          if ((((&g_MasterCardColorTable)[local_14 * 0x34] & 4) != 0) &&
             (((&g_CardSlot_Flags)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            local_2c = 3;
          }
          local_10 = local_10 + local_2c;
          if (((DAT_0067b9a4 & 2) != 0) && (local_8 + 2U == DAT_0067b9a4)) {
            Ai_Subsystem_004b90de(local_8,local_1c);
            strcat(&g_OverworldWorldState,&DAT_0052ce50);
            str_2 = _itoa(local_2c,&DAT_00553190,10);
            strcat(&g_OverworldWorldState,str_2);
            strcat(&g_OverworldWorldState,&DAT_0052ce54);
          }
        }
      }
    }
    (&DAT_006b2538)[local_8] = local_10;
    if (local_8 == arg_1) {
      local_c = local_c + local_10;
    }
    else {
      local_c = local_c - local_10;
    }
    local_8 = local_8 + 1;
  } while( true );
}


