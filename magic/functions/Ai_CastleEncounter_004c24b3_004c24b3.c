/*
 * Decompiled function: Ai_CastleEncounter_004c24b3
 * Entry Point: 004c24b3
 * Size: 5604 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_CastleEncounter_004c24b3(int arg_1)

{
  byte arg_1_00;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_dc;
  int local_d4 [7];
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4 [8];
  int aiStack_84 [7];
  uint local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28 [9];
  
  local_2c = 1;
  local_4c = 0;
  local_64 = arg_1;
  local_a4[0] = 0xd2;
  local_a4[1] = 0;
  local_a4[2] = 0x40;
  local_a4[3] = 0xd0;
  local_a4[4] = 0xbe;
  local_a4[5] = 3;
  local_44 = -1;
  local_48 = -1;
  Adventure_LoadFacePalette(0);
  if (arg_1 == 4) {
    arg_1 = 0;
  }
  Mem_AllocOrFree_00510e20(1,s_mapbttns_pic_0052dd7c);
  Mem_AllocOrFree_0050fc00();
  for (local_5c = 0; local_5c < 5; local_5c = local_5c + 1) {
    for (local_54 = 0; local_54 < 3; local_54 = local_54 + 1) {
      uVar1 = Sprite_EncodeFromSurface(1,local_54 * 0x5e + 1,local_5c * 0x1c + 1,0x5d,0x1b);
      (&DAT_00641890)[local_54 + local_5c * 3] = (void *)uVar1;
    }
  }
  DAT_0055748c = Sprite_EncodeFromSurface(1,1,0x8d,0x2b,0xe9);
  DAT_00556c50 = Sprite_EncodeFromSurface(1,0x2d,0x8d,0xd1,0x1c);
  DAT_00641878 = Sprite_EncodeFromSurface(1,0xe8,0xaa,0x13,0x117);
  DAT_006498e4 = Sprite_EncodeFromSurface(1,0xfc,0xaa,0xf,0x46);
  FUN_0050fc20();
  if (DAT_0052d8a8 == DAT_0052d898) {
    for (local_54 = 0; local_54 < 5; local_54 = local_54 + 1) {
      uVar1 = Ai_Util_004c3bc4((&DAT_0052d8a8)[local_54 * 0x15]);
      (&DAT_0052d8a8)[local_54 * 0x15] = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8ac + local_54 * 0x54));
      *(undefined4 *)(&DAT_0052d8ac + local_54 * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8b0 + local_54 * 0x54));
      *(undefined4 *)(&DAT_0052d8b0 + local_54 * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_0052d8b4 + local_54 * 0x54));
      *(undefined4 *)(&DAT_0052d8b4 + local_54 * 0x54) = uVar1;
    }
  }
  do {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    FUN_0050d560(*(int *)g_DisplaySurfaceScreen,0);
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_mapback_pic_0052dd8c,(short *)&DAT_0070a130);
    if (DAT_00522458 != 0x1e0) {
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
    }
    local_a8 = FUN_0041f354();
    Mem_AllocOrFree_0041f12b(local_a8);
    if (arg_1 == 0) {
      _DAT_0052d8fc = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d900 = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d8ec,1,local_a8);
      _DAT_0052d950 = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d954 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d940,1,local_a8);
    }
    else if (arg_1 == 1) {
      DAT_0052d8a8 = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d8ac = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d898,1,local_a8);
      _DAT_0052d8fc = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d900 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d8ec,1,local_a8);
    }
    else if (arg_1 == 2) {
      DAT_0052d8a8 = Ai_Util_004c3bc4(DAT_0052d860);
      _DAT_0052d8ac = Ai_Util_004c3bc4(DAT_0052d864);
      FUN_0041f17e(0x52d898,1,local_a8);
      _DAT_0052d950 = Ai_Util_004c3bc4(DAT_0052d868);
      _DAT_0052d954 = Ai_Util_004c3bc4(DAT_0052d86c);
      FUN_0041f17e(0x52d940,1,local_a8);
    }
    FUN_0041f17e(0x52d994,1,local_a8);
    FUN_0041f17e(0x52d9e8,1,local_a8);
    local_a4[6] = 0;
    for (local_50 = 0; local_50 < 0x40; local_50 = local_50 + 1) {
      for (local_58 = 0; local_58 < 0x40; local_58 = local_58 + 1) {
        local_a4[7] = FUN_0040c7c0(local_50,local_58);
        local_40 = local_a4[7] & 0xf;
        if (((((local_a4[7] & 0x80U) != 0) || (DAT_0067b9a4 != 0)) &&
            (Ai_Subsystem_004c3aa1(local_50,local_58,local_28,&local_34),
            local_28[0] <= (int)(DAT_00522458 - 8))) &&
           (((7 < local_28[0] && (local_34 <= (int)(DAT_0052245c - 8))) && (7 < local_34)))) {
          iVar3 = local_34 + 0x40;
          if ((6 < local_28[0]) && (6 < iVar3)) {
            iVar2 = local_34 + 0x3a;
            local_34 = iVar3;
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_28[0] + -6,iVar2,
                       *(undefined4 *)
                        (&DAT_00678560 +
                        local_40 * 4 +
                        ((*(int *)(&DAT_0052da40 + ((local_58 + local_50) % 6) * 4) *
                         *(int *)(&DAT_0052da40 + ((local_58 * local_50) % 6) * 4)) % 3) * 0x40),0xe
                       ,0xe);
            iVar3 = local_34;
          }
          local_34 = iVar3;
          local_28[0] = (int)(DAT_00522458 * local_28[0]) / 0x280;
          local_34 = (int)((local_34 + -0x40) * DAT_0052245c) / 0x1e0;
          iVar3 = Ai_Util_004c3bc4(0x40);
          local_34 = local_34 + iVar3;
          for (local_54 = 1; local_54 < 9; local_54 = local_54 + 1) {
            iVar3 = FUN_0040cb4f(local_50,local_58,((byte)local_54 & 7) + 1);
            if (iVar3 != 0) {
              iVar11 = 0xd2;
              iVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_005223e0 + local_54 * 4) * 7);
              iVar3 = local_34 + iVar3;
              iVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00522378 + local_54 * 4) * 7);
              Surface_DrawLine((int *)g_DisplaySurfaceScreen,local_28[0],local_34,
                               local_28[0] + iVar2,iVar3,iVar11);
              iVar11 = 0xd2;
              iVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_005223e0 + local_54 * 4) * 7);
              iVar3 = local_34 + iVar3;
              iVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00522378 + local_54 * 4) * 7);
              Surface_DrawLine((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34,
                               local_28[0] + -1 + iVar2,iVar3,iVar11);
            }
          }
        }
      }
    }
    for (local_54 = 0; local_54 < 7; local_54 = local_54 + 1) {
      aiStack_84[local_54] = 0;
    }
    local_38 = 0xffffffff;
    if (DAT_0067f35c != -1) {
      local_38 = Duel_GetCardDrawOriginY
                           ((int)(DAT_0067f360 + (DAT_0067f360 >> 0x1f & 0x1fU)) >> 5,
                            (int)(DAT_0067f364 + (DAT_0067f364 >> 0x1f & 0x1fU)) >> 5);
    }
    for (local_50 = 0; local_50 < 0x40; local_50 = local_50 + 1) {
      for (local_58 = 0; local_58 < 0x40; local_58 = local_58 + 1) {
        local_a4[7] = FUN_0040c7c0(local_50,local_58);
        local_40 = local_a4[7] & 0xf;
        Ai_Subsystem_004c3aa1(local_50,local_58,local_28,&local_34);
        local_28[0] = (int)(DAT_00522458 * local_28[0]) / 0x280;
        local_34 = (int)(local_34 * DAT_0052245c) / 0x1e0;
        iVar3 = Ai_Util_004c3bc4(0x40);
        local_34 = local_34 + iVar3;
        if ((((local_28[0] <= (int)(DAT_00522458 - 8)) && (-1 < local_28[0])) &&
            (local_34 <= (int)(DAT_0052245c - 8))) && (-1 < local_34)) {
          if ((local_a4[7] & 0x10U) != 0) {
            local_30 = Duel_GetCardDrawOriginX(local_50,local_58);
            if ((&DAT_0067be01)[local_30 * 100] != '\0') {
              local_68 = *(int *)(&DAT_0067be00 + local_30 * 100) >> 8;
              aiStack_84[*(int *)(&DAT_0067be00 + local_30 * 100) >> 8] =
                   aiStack_84[*(int *)(&DAT_0067be00 + local_30 * 100) >> 8] + 1;
            }
            if (((arg_1 == 0) && (((&DAT_0067be00)[local_30 * 100] & 1) != 0)) &&
               (1 < *(int *)(&DAT_0067bdf0 + local_30 * 100))) {
              local_a4[6] = local_a4[6] + 1;
            }
            if (((local_a4[7] & 0x80U) == 0) && (DAT_0067b9a4 == 0)) goto LAB_004c2cf3;
            if (*(int *)(&DAT_0067bdf0 + local_30 * 100) == 1) {
              local_dc = 0;
            }
            else if ((*(int *)(&DAT_0067bdf0 + local_30 * 100) == 4) ||
                    (*(int *)(&DAT_0067bdf0 + local_30 * 100) == 5)) {
              local_dc = 2;
            }
            else {
              local_dc = 1;
            }
            iVar3 = *(int *)(&DAT_00677970 + local_dc * 4);
            iVar4 = Ai_Util_004c3bc4(0x14);
            iVar5 = Ai_Util_004c3bc4(0xd);
            iVar2 = local_34;
            iVar6 = Ai_Util_004c3bc4(0x12);
            iVar11 = local_28[0];
            iVar2 = iVar2 - iVar6;
            iVar6 = Ai_Util_004c3bc4(7);
            Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar11 - iVar6,iVar2,iVar5,iVar4,iVar3);
            if ((local_30 != 0xffffffff) && (1 < *(int *)(&DAT_0067bdf0 + local_30 * 100))) {
              if (((&DAT_0067be00)[local_30 * 100] & 1) == 0) {
                local_3c = 0xe3;
              }
              else {
                local_3c = 0xff;
              }
              if (local_38 == local_30) {
                local_3c = 0xbe;
              }
              if ((&DAT_0067be01)[local_30 * 100] != '\0') {
                local_68 = *(int *)(&DAT_0067be00 + local_30 * 100) >> 8;
                local_3c = local_a4[*(int *)(&DAT_0067be00 + local_30 * 100) >> 8];
              }
              if (arg_1 == 1) {
                local_b0 = 0;
                local_d4[6] = (int)*(short *)(DAT_006776a0 + 4);
                local_b8 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                uVar1 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_30 * 100),
                                     *(int *)(&DAT_0067bdf8 + local_30 * 100));
                local_68 = Adventure_GetLocationEncounterIndex(uVar1);
                for (local_54 = 1; local_54 < 6; local_54 = local_54 + 1) {
                  if ((local_68 & 1 << ((byte)local_54 & 0x1f)) != 0) {
                    local_b0 = local_b0 + 1;
                  }
                }
                local_ac = (local_28[0] + ((local_b0 + -1) * local_d4[6]) / 2) - local_d4[6] / 2;
                for (local_54 = 1; local_54 < 6; local_54 = local_54 + 1) {
                  local_d4[1] = 2;
                  local_d4[2] = 1;
                  local_d4[3] = 4;
                  local_d4[4] = 3;
                  local_d4[5] = 0;
                  if ((local_68 & 1 << ((byte)local_54 & 0x1f)) != 0) {
                    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_ac,local_34 + 0xc,
                                      (&DAT_006776a0)[local_d4[local_54]]);
                    local_ac = local_ac - local_d4[6];
                  }
                }
                if ((&DAT_0067bdfc)[local_30 * 100] == '\0') {
                  g_OverworldWorldState = 0;
                  FUN_00484c45(1 << ((char)((uint)*(undefined4 *)(&DAT_0067bdfc + local_30 * 100) >>
                                           8) - 1U & 0x1f));
                  strcat(&g_OverworldWorldState,&DAT_0052dda0);
                }
                else {
                  local_68 = FUN_00473cc5((byte)*(undefined4 *)(&DAT_0067bdfc + local_30 * 100));
                  pcVar7 = (char *)Mem_AllocOrFree_00473d7e(local_68);
                  strcpy(&g_OverworldWorldState,pcVar7);
                  strcat(&g_OverworldWorldState,s_cards_0052dd98);
                }
                local_b4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                uVar10 = (uint)(local_4c == 0);
                uVar9 = 0x3f3f3f;
                iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((undefined4 *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_b4 / 2,
                           local_34 + -2,local_b4 + 4,iVar3 + 2,uVar9,uVar10);
                local_4c = 1;
                FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34,local_3c);
                for (local_54 = 0; local_54 < 0xc; local_54 = local_54 + 1) {
                  if ((local_30 != 0) && (*(uint *)(&DAT_005224e8 + local_54 * 0x10) == local_30)) {
                    local_60 = Bazaar_GetCardBaseValue(local_54);
                    strcpy(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_54]);
                    local_b4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                    uVar10 = (uint)(local_4c == 0);
                    uVar9 = 0x3f3f3f;
                    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                    Ai_Subsystem_004c2340
                              ((undefined4 *)g_DisplaySurfaceScreen,
                               (local_28[0] + -2) - local_b4 / 2,local_34 + local_b8,local_b4 + 4,
                               iVar3 + 2,uVar9,uVar10);
                    FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34 + local_b8,local_3c);
                  }
                }
              }
              if ((arg_1 == 0) || ((arg_1 == 1 && (*(int *)(&DAT_0067bdf0 + local_30 * 100) == 4))))
              {
                iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                g_OverworldWorldState = 0;
                if ((*(int *)(&DAT_0067bdf0 + local_30 * 100) == 4) ||
                   (*(int *)(&DAT_0067bdf0 + local_30 * 100) == 5)) {
                  uVar1 = FUN_0040c761(local_50,local_58);
                  arg_1_00 = Adventure_GetLocationEncounterIndex(uVar1);
                  iVar2 = FUN_00473cc5(arg_1_00);
                  pcVar7 = (char *)Mem_AllocOrFree_00473d7e(iVar2);
                  strcpy(&g_OverworldWorldState,pcVar7);
                }
                else {
                  iVar2 = local_30 + ((int)local_30 >> 0x1f & 7U);
                  uVar10 = iVar2 >> 0x1f;
                  strcpy(&g_OverworldWorldState,
                         (&PTR_s_Amanaxis_00522460)
                         [((iVar2 >> 3 ^ uVar10) - uVar10 & 0xf ^ uVar10) - uVar10]);
                }
                sVar8 = strlen(&g_OverworldWorldState);
                if ((&DAT_0062684f)[sVar8] == ' ') {
                  sVar8 = strlen(&g_OverworldWorldState);
                  (&DAT_0062684f)[sVar8] = 0;
                }
                local_d4[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                uVar10 = (uint)(local_4c == 0);
                uVar9 = 0x4f4f4f;
                iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((undefined4 *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_d4[0] / 2
                           ,local_34 + -2,local_d4[0] + 4,iVar2 + 2,uVar9,uVar10);
                local_4c = 1;
                FUN_0040c421(&g_OverworldWorldState,local_28[0],local_34,local_3c);
                g_OverworldWorldState = 0;
                if ((*(int *)(&DAT_0067bdf0 + local_30 * 100) == 4) ||
                   (*(int *)(&DAT_0067bdf0 + local_30 * 100) == 5)) {
                  strcpy(&g_OverworldWorldState,s_Castle_0052dda4);
                }
                else {
                  uVar10 = (int)local_30 >> 0x1f;
                  strcpy(&g_OverworldWorldState,
                         (&PTR_s_Tower_005224a0)
                         [((local_30 ^ uVar10) - uVar10 & 0xf ^ uVar10) - uVar10]);
                }
                local_d4[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
                iVar11 = 0;
                uVar10 = 0x4f4f4f;
                iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
                Ai_Subsystem_004c2340
                          ((undefined4 *)g_DisplaySurfaceScreen,(local_28[0] + -2) - local_d4[0] / 2
                           ,iVar3 + local_34,local_d4[0] + 4,iVar2,uVar10,iVar11);
                FUN_0040c421(&g_OverworldWorldState,local_28[0],iVar3 + local_34,local_3c);
              }
            }
          }
          if ((DAT_0067b9a4 != 0) && ((local_a4[7] & 0x40U) != 0)) {
            Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + 1,local_34 + 1,2,2,0xf6);
          }
        }
LAB_004c2cf3:
      }
    }
    iVar3 = DAT_00556c50;
    iVar2 = Ai_Util_004c3bc4((int)*(short *)(DAT_00556c50 + 6));
    iVar11 = Ai_Util_004c3bc4((int)*(short *)(DAT_00556c50 + 4));
    iVar4 = Ai_Util_004c3bc4(0x36);
    iVar5 = Ai_Util_004c3bc4(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar11,iVar2,iVar3);
    if (local_64 != 4) {
      iVar3 = DAT_0055748c;
      iVar2 = Ai_Util_004c3bc4((int)*(short *)(DAT_0055748c + 6));
      iVar11 = Ai_Util_004c3bc4((int)*(short *)(DAT_0055748c + 4));
      iVar4 = Ai_Util_004c3bc4(0x85);
      iVar5 = Ai_Util_004c3bc4(0);
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5,iVar4,iVar11,iVar2,iVar3);
      for (local_54 = 0; local_54 < 5; local_54 = local_54 + 1) {
        FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xfe,0x18,local_54 * 0x1a + 0xc6);
      }
    }
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
    if (local_64 == 4) {
      FUN_0041f391();
      return;
    }
    FUN_0041f213();
    Ai_Subsystem_004c3aa1(DAT_00641010,DAT_00641014,local_28,&local_34);
    local_28[0] = (int)(DAT_00522458 * local_28[0]) / 0x280;
    iVar3 = Ai_Util_004c3bc4(0x40);
    local_34 = iVar3 + (int)(local_34 * DAT_0052245c) / 0x1e0;
    DAT_00556c58 = -1;
    local_2c = 1;
    Mem_AllocOrFree_005016f9();
    local_48 = -1;
    local_44 = -1;
    do {
      iVar3 = Mem_AllocOrFree_00501721();
      if ((iVar3 % 0x14 < 10) && (local_2c != 0)) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1,4,4,0xff);
        local_2c = 0;
      }
      else {
        iVar3 = Mem_AllocOrFree_00501721();
        if ((9 < iVar3 % 0x14) && (local_2c == 0)) {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1,4,4,0);
          local_2c = 1;
        }
      }
      Pic_Subsystem_0044b84b();
      if (DAT_007039c4 == 0) {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,0);
      }
      else {
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        if (((DAT_007039c4 != 0) && (DAT_0067b9a4 != 0)) && (DAT_00556c58 < 0)) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_28[0] - 1,local_34 + -1,4,4,
                       (int *)g_DisplaySurfaceScreen,local_28[0] + -1,local_34 + -1);
          iVar3 = DAT_0067bda8;
          local_28[0] = DAT_0067bda4;
          local_48 = DAT_0067bda8;
          local_34 = DAT_0067bda8;
          local_44 = (DAT_0067bda4 * 0x280) / (int)DAT_00522458;
          iVar2 = Ai_Util_004c3bc4(0x40);
          local_48 = ((iVar3 - iVar2) * 0x1e0) / (int)DAT_0052245c;
          Ai_Subsystem_004c3ad4(local_44,local_48,&DAT_00641010,&DAT_00641014);
          DAT_0052eff0 = DAT_00641010 * 0x20 + 0x10;
          DAT_0052eff4 = DAT_00641014 * 0x20 + 0x10;
          Ai_Subsystem_004c3aa1(DAT_00641010,DAT_00641014,local_28,&local_34);
          local_28[0] = (int)(DAT_00522458 * local_28[0]) / 0x280;
          iVar3 = Ai_Util_004c3bc4(0x40);
          local_34 = iVar3 + (int)(local_34 * DAT_0052245c) / 0x1e0;
          DAT_00641884 = 0;
        }
      }
    } while (DAT_00556c58 == -1);
    if (DAT_00556c58 == 3) {
      FUN_0040a3e1();
      Town_Process_00490d7b(1);
      arg_1 = 0;
      FUN_0041f391();
    }
    else {
      if (DAT_00556c58 == 4) {
        FUN_0041f391();
        Mem_AllocOrFree_0050fc50(DAT_00641890);
        FUN_0040a3e1();
        return;
      }
      arg_1 = DAT_00556c58;
      FUN_0040a3e1();
      FUN_0041f391();
    }
  } while( true );
}


