/*
 * Decompiled function: Ai_CastleEncounter_004c0efe
 * Entry Point: 004c0efe
 * Size: 4369 bytes
 */
#include "magic.h"


void Ai_CastleEncounter_004c0efe
               (uint arg_1,uint arg_2,int arg_3,int arg_4,uint arg_5,int arg_6,int arg_7,int arg_8)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *str_2;
  uint uVar5;
  bool bVar6;
  undefined4 uVar7;
  int local_bc;
  int local_b4;
  int local_a0;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_20 = *(undefined4 *)g_DisplaySurfaceScreen;
  *(undefined4 *)g_DisplaySurfaceScreen = 2;
  DAT_006498d8 = arg_1;
  DAT_006498dc = arg_2;
  local_38 = arg_1 - (arg_1 & 0x1f);
  local_4c = arg_2 - (arg_2 & 0x1f);
  Ai_Subsystem_004be525(local_38,local_4c,&local_48,&local_54);
  for (local_8 = arg_5; (int)local_8 < arg_6; local_8 = local_8 + 1) {
    for (local_80 = arg_3; local_80 < arg_4; local_80 = local_80 + 1) {
      local_78 = local_80 * DAT_0055747c + local_48;
      local_24 = local_8 * DAT_005574b0 + local_54;
      if ((local_8 & 1) != 0) {
        local_78 = local_78 + DAT_0055747c / 2;
      }
      Ai_Subsystem_004be5ae(local_78 + 0x10,local_24,(int *)&local_14,&local_1c);
      local_14 = (int)(local_14 + ((int)local_14 >> 0x1f & 0x1fU)) >> 5;
      local_1c = (int)(local_1c + (local_1c >> 0x1f & 0x1fU)) >> 5;
      iVar2 = abs(local_8);
      if ((iVar2 < 8) && (iVar2 = abs(local_80), iVar2 < 4)) {
        FUN_0040c81c(0x80,local_14,local_1c);
      }
      local_58 = FUN_0040c7c0(local_14,local_1c);
      local_2c = local_58 & 0xf;
      if (arg_8 != 0) {
        *(int *)(&DAT_006418d0 + local_14 * 4 + local_1c * 0x100) = local_78;
        *(int *)(&DAT_006458d0 + local_14 * 4 + local_1c * 0x100) = local_24;
      }
      local_24 = local_24 - DAT_005574b0;
      local_50 = Adventure_GetLocationEncounterIndex(local_2c);
      if ((arg_7 != 2) && ((arg_8 == 0 || (arg_7 != 0)))) {
        if (((local_2c == 0) || (local_2c == 8)) && (arg_7 != 0)) {
          Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,DAT_00677654);
        }
        else if (arg_7 != 0) {
          if (local_2c == 1) {
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,DAT_00677658);
          }
          else {
            if (local_50 == 2) {
              local_a0 = DAT_00677660;
            }
            else {
              local_a0 = DAT_00677650;
            }
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,local_a0);
          }
          local_10 = 0;
          local_34 = 0;
          for (local_3c = 1; (int)local_3c < 9; local_3c = local_3c + 1) {
            local_34 = (int)local_34 >> 1;
            local_10 = (int)local_10 >> 1;
            local_60 = FUN_0040c761(*(int *)(&DAT_00522378 + local_3c * 4) + local_14,
                                    *(int *)(&DAT_005223e0 + local_3c * 4) + local_1c);
            local_68 = Adventure_GetLocationEncounterIndex(local_60);
            if (((local_60 == 0) || (local_60 == 8)) ||
               ((local_2c != local_60 && (((local_50 | local_68) & 4) != 0)))) {
              local_34 = local_34 | 0x80;
            }
            if ((local_50 != 2) && (local_68 == 2)) {
              local_10 = local_10 | 0x80;
            }
          }
          local_40 = local_10;
          local_10 = local_10 | local_10 << 8;
          if ((local_10 != 0) && (DAT_005239f0 == 0)) {
            for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
              switch(local_3c) {
              case 0:
                local_28 = local_10 & 7;
                break;
              case 1:
                local_28 = local_10 >> 4 & 7;
                break;
              case 2:
                local_28 = local_10 >> 6 & 7;
                break;
              case 3:
                local_28 = local_10 >> 2 & 7;
              }
              uVar5 = local_28 - 1;
              bVar6 = local_28 != 0;
              local_28 = uVar5;
              if (bVar6) {
                if ((int)local_3c < 2) {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + DAT_005574b0,
                                     (local_3c & 1) * DAT_005574b0 + local_24,
                                     *(int *)(&DAT_00677820 + (local_3c + 4) * 0x1c + uVar5 * 4));
                }
                else {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                                     (local_3c & 1) * DAT_005574b0 * 2 + local_78,
                                     local_24 + DAT_005574b0 / 2,
                                     *(int *)(&DAT_00677820 + (local_3c + 4) * 0x1c + uVar5 * 4));
                }
              }
            }
          }
          local_40 = local_34;
          local_34 = local_34 | local_34 << 8;
          if ((local_34 != 0) && (DAT_005239f0 == 0)) {
            for (local_3c = 0; (int)local_3c < 4; local_3c = local_3c + 1) {
              switch(local_3c) {
              case 0:
                local_28 = local_34 & 7;
                break;
              case 1:
                local_28 = local_34 >> 4 & 7;
                break;
              case 2:
                local_28 = local_34 >> 6 & 7;
                break;
              case 3:
                local_28 = local_34 >> 2 & 7;
              }
              uVar5 = local_28 - 1;
              bVar6 = local_28 != 0;
              local_28 = uVar5;
              if (bVar6) {
                if ((int)local_3c < 2) {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + DAT_005574b0,
                                     (local_3c & 1) * DAT_005574b0 + local_24,
                                     *(int *)(&DAT_00677820 + uVar5 * 4 + local_3c * 0x1c));
                }
                else {
                  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                                     (local_3c & 1) * DAT_005574b0 * 2 + local_78,
                                     local_24 + DAT_005574b0 / 2,
                                     *(int *)(&DAT_00677820 + uVar5 * 4 + local_3c * 0x1c));
                }
              }
            }
          }
        }
        iVar2 = FUN_0040cbbd(local_14,local_1c);
        if (iVar2 == 0) {
          local_44 = 0;
        }
        else {
          local_44 = Surface_GetPixelPtr((int *)g_DisplaySurfaceWork,local_14,local_1c + 0x40);
        }
        if (local_44 != 0) {
          for (local_3c = 0; (int)local_3c < 8; local_3c = local_3c + 1) {
            if (((local_44 & 1 << ((byte)local_3c & 0x1f)) != 0) && (arg_7 != 0)) {
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,local_24,
                                 *(int *)(&DAT_00677354 + (local_3c - 2 & 7) * 4));
            }
          }
        }
      }
      if (arg_7 != 1) {
        local_74 = local_24 + DAT_005574b0;
        if ((local_58 & 0x10) == 0) {
          local_70 = (uint)((-local_14 - local_1c & 2) != 0);
          iVar2 = abs(local_14);
          iVar3 = abs(local_1c);
          local_6c = iVar2 * 7 + iVar3 * 3;
          switch(local_2c) {
          case 0:
            local_5c = -1;
            break;
          case 1:
            local_5c = 1;
            break;
          case 2:
            local_5c = 2;
            break;
          case 3:
            local_5c = 0;
            break;
          default:
            local_5c = -1;
            break;
          case 5:
            local_5c = 3;
            break;
          case 6:
            local_5c = 4;
            break;
          case 8:
            local_5c = 5;
            break;
          case 10:
            local_5c = 7;
            break;
          case 0xd:
            local_5c = 6;
            break;
          case 0xf:
            local_5c = 8;
          }
          local_40 = 0;
          local_64 = DAT_0055747c / (((int)local_6c % 5) * 2 + 4);
          uVar5 = (int)local_6c >> 0x1f;
          local_7c = Ai_Util_004c3bc4((((local_6c ^ uVar5) - uVar5 & 3 ^ uVar5) - uVar5) * 2 + 5);
          if (local_2c == 1) {
            local_7c = 0;
            local_64 = 0;
          }
          if (-1 < local_5c) {
            local_30 = (int)local_6c % 0xb;
            if (4 < local_5c) {
              local_5c = local_5c % 5;
              local_30 = local_30 + 0xb;
            }
            if (*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) + 10) == 0xffff)
            {
              local_c = 0;
            }
            else {
              local_c = (int)*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) +
                                       10);
            }
            if (arg_8 != 0) {
              if (local_40 == 0) {
                iVar2 = -local_7c;
                local_b4 = local_64;
              }
              else {
                local_b4 = -local_64;
                iVar2 = local_7c;
              }
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78 + local_b4,(local_74 - local_c) + iVar2,
                         local_74 + iVar2,
                         *(undefined4 *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14));
            }
            if (arg_7 != 0) {
              if (local_40 == 0) {
                iVar2 = -local_7c;
                local_bc = local_64;
              }
              else {
                local_bc = -local_64;
                iVar2 = local_7c;
              }
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 + local_bc,
                                 (local_74 - local_c) + iVar2,
                                 *(int *)(&DAT_00678010 + local_5c * 4 + local_30 * 0x14));
            }
            local_40 = (uint)(local_40 == 0);
            local_30 = ((local_30 < 0xb) - 1 & 0xb) + (int)(local_14 + local_6c) % 0xb;
            if (*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) + 10) == 0xffff)
            {
              local_c = 0;
            }
            else {
              local_c = (int)*(short *)(*(int *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14) +
                                       10);
            }
            if (arg_8 != 0) {
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78 - local_64,(local_74 - local_c) + local_7c,
                         local_74 + local_7c,
                         *(undefined4 *)(&DAT_00677450 + local_5c * 4 + local_30 * 0x14));
            }
            if (arg_7 != 0) {
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78 - local_64,
                                 (local_74 - local_c) + local_7c,
                                 *(int *)(&DAT_00678010 + local_5c * 4 + local_30 * 0x14));
            }
          }
        }
        if ((((local_58 & 0x40) != 0) &&
            (local_3c = FUN_0048ec9a(local_14,local_1c), -1 < (int)local_3c)) &&
           (*(int *)(&DAT_0067f010 + local_3c * 0x30) != 0)) {
          local_40 = local_3c * 2 - 10;
          iVar2 = *(int *)(&DAT_00677a10 + *(int *)(&DAT_0052d7b8 + local_40 * 4) * 4);
          if (arg_8 != 0) {
            Ai_Subsystem_004be25f
                      (g_DisplaySurfaceScreen,local_78,
                       (local_74 - *(short *)(iVar2 + 6)) + DAT_005574b0,local_74,
                       *(undefined4 *)(&DAT_00677a10 + *(int *)(&DAT_0052d7b8 + local_40 * 4) * 4));
          }
          if (arg_7 != 0) {
            Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,
                               (local_74 - *(short *)(iVar2 + 6)) + DAT_005574b0,
                               *(int *)(&DAT_00677a10 + *(int *)(&DAT_0052d7bc + local_40 * 4) * 4))
            ;
          }
        }
        if ((local_58 & 0x10) != 0) {
          local_18 = Duel_GetCardDrawOriginX(local_14,local_1c);
          iVar2 = local_74;
          if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
            iVar3 = FUN_00473cc5((byte)local_50);
            iVar2 = local_74;
            local_50 = iVar3 - 1;
            if (arg_8 != 0) {
              uVar7 = *(undefined4 *)(&DAT_00678660 + (char)(&DAT_0052d818)[local_50 * 4] * 4);
              iVar3 = local_74;
              iVar4 = Ai_Util_004c3bc4(0xa0);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3,uVar7);
            }
            iVar2 = local_74;
            if (arg_7 != 0) {
              iVar3 = *(int *)(&DAT_00678660 + (char)(&DAT_0052d819)[local_50 * 4] * 4);
              iVar4 = Ai_Util_004c3bc4(0xa0);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3);
            }
          }
          else if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 5) {
            iVar3 = FUN_00473cc5((byte)local_50);
            iVar2 = local_74;
            local_50 = iVar3 - 1;
            if (arg_8 != 0) {
              uVar7 = *(undefined4 *)(&DAT_00678660 + (char)(&DAT_0052d832)[local_50 * 4] * 4);
              iVar3 = local_74;
              iVar4 = Ai_Util_004c3bc4(0xa0);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3,uVar7);
            }
            iVar2 = local_74;
            if (arg_7 != 0) {
              iVar3 = *(int *)(&DAT_00678660 + (char)(&DAT_0052d833)[local_50 * 4] * 4);
              iVar4 = Ai_Util_004c3bc4(0xa0);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3);
            }
          }
          else if ((&DAT_0067be01)[local_18 * 100] == '\0') {
            if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 1) {
              local_40 = (local_14 & 1) * 2 + 0x20;
            }
            else {
              uVar5 = (int)local_18 >> 0x1f;
              local_40 = (((local_18 ^ uVar5) - uVar5 & 0xf ^ uVar5) - uVar5) * 2;
            }
            sVar1 = *(short *)(*(int *)(&DAT_00677a10 + (char)(&DAT_0052d780)[local_40] * 4) + 6);
            if (arg_8 != 0) {
              uVar7 = *(undefined4 *)(&DAT_00677a10 + (char)(&DAT_0052d780)[local_40] * 4);
              iVar3 = Ai_Util_004c3bc4(0x18);
              Ai_Subsystem_004be25f
                        (g_DisplaySurfaceScreen,local_78,iVar3 + (local_74 - sVar1),iVar2,uVar7);
            }
            if (arg_7 != 0) {
              iVar2 = *(int *)(&DAT_00677a10 + *(char *)(local_40 + 0x52d781) * 4);
              iVar3 = Ai_Util_004c3bc4(0x18);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,iVar3 + (local_74 - sVar1),
                                 iVar2);
            }
          }
          else {
            if (arg_8 != 0) {
              uVar7 = *(undefined4 *)
                       (&DAT_00677ff0 + ((*(int *)(&DAT_0067be00 + local_18 * 100) >> 8) + -1) * 4);
              iVar3 = local_74;
              iVar4 = Ai_Util_004c3bc4(0xa6);
              Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3,uVar7);
            }
            iVar2 = local_74;
            if (arg_7 != 0) {
              iVar3 = DAT_006784f8;
              iVar4 = Ai_Util_004c3bc4(0xa6);
              Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_78,iVar2 - iVar4,iVar3);
            }
          }
          if ((local_18 == DAT_00522450) && (arg_7 != 0)) {
            *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
            if ((*(int *)(&DAT_0067bdf0 + local_18 * 100) < 2) && (local_18 != DAT_00522450)) {
              FUN_0040d201((int)g_DisplaySurfaceScreen,0xff,local_78 + DAT_0055747c / 2,
                           local_74 + DAT_005574b0 / 2);
            }
            else {
              if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
                local_40 = FUN_00473cc5((byte)local_50);
                str_2 = (char *)Mem_AllocOrFree_00473d7e(local_40);
                strcpy(&g_OverworldWorldState,str_2);
                *(uint *)(&DAT_0067f010 + (local_40 - 1) * 0x30) =
                     *(uint *)(&DAT_0067f010 + (local_40 - 1) * 0x30) | 1;
              }
              else {
                iVar2 = local_18 + ((int)local_18 >> 0x1f & 7U);
                uVar5 = iVar2 >> 0x1f;
                strcpy(&g_OverworldWorldState,
                       (&PTR_s_Amanaxis_00522460)
                       [((iVar2 >> 3 ^ uVar5) - uVar5 & 0xf ^ uVar5) - uVar5]);
              }
              if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 4) {
                strcat(&g_OverworldWorldState,s_Castle_0052dd4c);
              }
              else if (*(int *)(&DAT_0067bdf0 + local_18 * 100) < 2) {
                if (*(int *)(&DAT_0067bdf0 + local_18 * 100) == 1) {
                  strcat(&g_OverworldWorldState,s_Village_0052dd54);
                }
              }
              else {
                uVar5 = (int)local_18 >> 0x1f;
                strcat(&g_OverworldWorldState,
                       (&PTR_s_Tower_005224a0)[((local_18 ^ uVar5) - uVar5 & 0xf ^ uVar5) - uVar5]);
              }
              FUN_0040d201((int)g_DisplaySurfaceScreen,0xff,local_78 + DAT_0055747c / 2,
                           local_74 + DAT_005574b0 / 2);
            }
          }
        }
      }
    }
  }
  Ai_Subsystem_004be525(DAT_006498d8,DAT_006498dc,&local_78,&local_24);
  *(undefined4 *)g_DisplaySurfaceScreen = local_20;
  return;
}


