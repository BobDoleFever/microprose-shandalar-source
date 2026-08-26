/*
 * Decompiled function: Adventure_PlayLocationMusic
 * Entry Point: 004e7f51
 * Size: 5122 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Adventure_PlayLocationMusic(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int height;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_58;
  int local_44;
  int local_40;
  int local_34;
  int local_30;
  int local_2c;
  int local_10;
  int local_c;
  
  iVar2 = Mem_AllocOrFree_0040810f();
  if (iVar2 != 0) goto LAB_004e8570;
  local_34 = FUN_0048ac2f();
  DAT_005659bc = 0;
  if (local_34 < 0x21) {
    if (local_34 == 0x20) {
      DAT_0052f010 = 0;
    }
    else if (local_34 == 0x1b) goto LAB_004e7f84;
  }
  else if (local_34 < 0x52) {
    if (local_34 == 0x51) {
LAB_004e7f84:
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
      strcpy(&g_OverworldWorldState,s_Ready_to_Quit__No__Yes__0052f1b0);
      iVar2 = FUN_004896be(&g_OverworldWorldState,100,0x50);
      if (iVar2 == 1) {
        DAT_006fe3f0 = 1;
      }
      else {
        Ai_Subsystem_004c05ba();
      }
      FUN_0048c970(3);
    }
    else if ((0x30 < local_34) && (local_34 < 0x36)) {
LAB_004e8168:
      iVar2 = local_34 + -0x30;
      if ((*(int *)(&DAT_0067bdbc + iVar2 * 4) != 0) &&
         ((_DAT_0067f374 & 1 << ((char)iVar2 * '\x02' & 0x1fU)) != 0)) {
        iVar4 = FUN_0040a1d2(4 - DAT_0067f380);
        if (iVar4 == 0) {
          *(int *)(&DAT_0067bdbc + iVar2 * 4) = *(int *)(&DAT_0067bdbc + iVar2 * 4) + -1;
        }
        Ai_Subsystem_004c05ba();
        switch(local_34) {
        case 0x31:
          FUN_005112b0(0,(short)DAT_00530d9c);
          DeckBuilderMain(_hwndScreen,1,1);
          Pic_Load_advfac64_0040a4fc();
          FUN_0050d560(0,7);
          Ai_Subsystem_004c05ba();
          break;
        case 0x32:
          do {
            iVar2 = FUN_0040a1d2(0x40);
            iVar4 = FUN_0040a1d2(0x40);
            iVar5 = FUN_0040c761(iVar2,iVar4);
          } while (iVar5 == 0);
          FUN_0040b3c2(0x12,2);
          DAT_0052eff0 = iVar2 * 0x20 + 0x10;
          DAT_0052eff4 = iVar4 * 0x20 + 0x10;
          Ai_Subsystem_004c05ba();
          DAT_0064101c = 1;
          break;
        case 0x33:
          *(undefined4 *)(&DAT_005224ec + iVar2 * 0x20) = 0x96;
          FUN_0040b3c2(0x12,3);
          break;
        case 0x34:
          local_44 = 0x7fff;
          local_10 = -1;
          for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
            if ((0 < *(int *)(&DAT_0067f2d0 + local_2c * 0x14)) &&
               (iVar2 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14),
                                     DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14)),
               iVar2 < local_44)) {
              local_10 = local_2c;
              local_44 = iVar2;
            }
          }
          if (local_10 != -1) {
            FUN_0046e70d(local_10,local_10 + 8);
            FUN_0040b3c2(0x12,CONCAT31((int3)((uint)(*(int *)(&DAT_0067f2d0 + local_10 * 0x14) <<
                                                    0x10) >> 8),4));
            *(undefined4 *)(&DAT_0067f2d0 + local_10 * 0x14) = 0xffffffff;
          }
          break;
        case 0x35:
          if (DAT_0067f35c != -1) {
            DAT_0052eff0 = (DAT_0067f360 & 0xffe0) + 0x10;
            DAT_0052eff4 = (DAT_0067f364 & 0xffe0) + 0x1f;
            FUN_0040b3c2(0x12,5);
          }
          DAT_0064101c = 1;
        }
      }
    }
  }
  else if (local_34 < 0x72) {
    if (local_34 == 0x71) goto LAB_004e7f84;
    if (local_34 == 0x53) {
      DAT_0052f010 = 0;
      iVar2 = Mem_AllocOrFree_0048e0ee();
      if (iVar2 != -1) {
        FUN_0048c970(iVar2);
      }
      LoadPalNoPic(s_advfac64_pic_0052f1cc);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x55) {
      DAT_00532550 = DAT_00532550 ^ 1;
      goto LAB_004e8168;
    }
  }
  else if (local_34 < 0x3c01) {
    if (local_34 == 0x3c00) {
      FUN_0040a3e1();
      Ai_CastleEncounter_004c24b3(0);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3b00) {
      if ((_DAT_0067f374 & 8) != 0) {
        local_34 = 0x31;
        goto LAB_004e8168;
      }
      FUN_005112b0(0,(short)DAT_00530d9c);
      DeckBuilderMain(_hwndScreen,1,0);
      Pic_Load_advfac64_0040a4fc();
      Ai_Subsystem_004c05ba();
    }
  }
  else if (local_34 < 0x3e01) {
    if (local_34 == 0x3e00) {
      FUN_0040a3e1();
      Castle_Process_0048f523(1);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3d00) {
      FUN_0040a3e1();
      Town_Process_00490d7b(1);
      Ai_Subsystem_004c05ba();
    }
  }
  else if (local_34 < 0x4001) {
    if (local_34 == 0x4000) {
      FUN_0040a3e1();
      Adventure_Map_UpdateLightingAndPalette(0,0xffffffff);
      Ai_Subsystem_004c05ba();
    }
    else if (local_34 == 0x3f00) {
      Castle_Process_00421b32();
      Ai_Subsystem_004c05ba();
    }
  }
  else if (local_34 < 0x4801) {
    if (local_34 == 0x4800) {
      DAT_0052f010 = 2;
    }
    else if (local_34 == 0x4700) {
      DAT_0052f010 = 1;
    }
  }
  else if (local_34 < 0x4b01) {
    if (local_34 == 0x4b00) {
      DAT_0052f010 = 8;
    }
    else if (local_34 == 0x4900) {
      DAT_0052f010 = 3;
    }
  }
  else if (local_34 < 0x4f01) {
    if (local_34 == 0x4f00) {
      DAT_0052f010 = 7;
    }
    else if (local_34 == 0x4d00) {
      DAT_0052f010 = 4;
    }
  }
  else if (local_34 == 0x5000) {
    DAT_0052f010 = 6;
  }
  else if (local_34 == 0x5100) {
    DAT_0052f010 = 5;
  }
  Adventure_LoadFacePalette(0);
LAB_004e8570:
  if ((DAT_005659b8 != 0) && (DAT_005659bc = DAT_005659bc + 1, 500 < DAT_005659bc)) {
    Ai_Subsystem_004cd20e();
    DAT_005659bc = 300;
  }
  iVar2 = FUN_0040c761((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + DAT_0052eff0 +
                            ((int)(*(int *)(&DAT_00522378 + DAT_0052f010 * 4) + DAT_0052eff0) >>
                             0x1f & 0x1fU)) >> 5,
                       (int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + DAT_0052eff4 +
                            ((int)(*(int *)(&DAT_005223e0 + DAT_0052f010 * 4) + DAT_0052eff4) >>
                             0x1f & 0x1fU)) >> 5);
  uVar3 = Adventure_GetLocationEncounterIndex(iVar2);
  if (uVar3 == 0) {
    local_40 = 0;
  }
  else {
    do {
      local_40 = FUN_0040a1d2(5);
      local_40 = local_40 + 1;
    } while ((uVar3 & 1 << ((byte)local_40 & 0x1f)) == 0);
  }
  local_c = 1;
  DAT_00641010 = (int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
  DAT_00641014 = (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
  if (((iVar2 == 2) || ((iVar2 == 3 && ((_DAT_0067f374 & 8) == 0)))) ||
     ((iVar2 == 4 && ((_DAT_0067f374 & 0x200) == 0)))) {
    local_c = 3;
  }
  if ((iVar2 == 5) && ((_DAT_0067f374 & 0x200) == 0)) {
    local_c = 3;
  }
  iVar2 = FUN_0040cb4f(DAT_00641010,DAT_00641014,(char)DAT_0052f010);
  if (iVar2 != 0) {
    local_c = 1;
  }
  iVar2 = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1);
  if (iVar2 != 0) {
    local_c = 1;
  }
  if (DAT_00522448 == 0) {
    local_c = FUN_0040a305(local_c + 2,0,4);
  }
  uVar1 = DAT_0052eff4;
  uVar3 = DAT_0052eff0;
  iVar2 = DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU);
  iVar4 = DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU);
  iVar5 = (int)DAT_0067f37c / local_c;
  if ((int)DAT_0067f37c % local_c == 0) {
    if (local_c == 3) {
      iVar5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4) * 2;
    }
    else {
      iVar5 = *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
    }
    DAT_0052eff0 = DAT_0052eff0 + iVar5;
    if (local_c == 3) {
      iVar5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4) * 2;
    }
    else {
      iVar5 = *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    DAT_0052eff4 = DAT_0052eff4 + iVar5;
    DAT_006410dc = DAT_006410dc + 1;
    if (4 < (int)DAT_006410dc) {
      DAT_006410dc = 1;
    }
    if (DAT_0052f010 != 0) {
      height = 0;
      iVar5 = FUN_0040a1d2(0x28);
      iVar5 = iVar5 + 0x50;
      iVar6 = FUN_0040a1d2(0x19);
      Adventure_Audio_PlayEffectAtVolume
                (((DAT_006410dc & 1) - 2) + local_40 * 2,iVar6 + 0x4b,iVar5,height);
    }
    if (DAT_0052f010 == 0) {
      DAT_006410dc = 0;
    }
    else {
      DAT_006410d4 = DAT_0052f010;
    }
    if ((DAT_0052254c != 0) ||
       (((DAT_0067f37c & 1) != 0 &&
        (iVar5 = FUN_0040cb4f(DAT_00641010,DAT_00641014,((char)DAT_0052f010 + 3U & 7) + 1),
        iVar5 != 0)))) {
      DAT_0052eff0 = DAT_0052eff0 + *(int *)(&DAT_00522378 + DAT_0052f010 * 4);
      DAT_0052eff4 = DAT_0052eff4 + *(int *)(&DAT_005223e0 + DAT_0052f010 * 4);
    }
    iVar5 = FUN_0040c761((int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                         (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
    if ((iVar5 == 0) &&
       ((iVar6 = abs(DAT_0052eff0 - ((DAT_0052eff0 & 0xffffffe0) + 0x10)), iVar6 < 0xc ||
        (iVar6 = abs(DAT_0052eff4 - ((DAT_0052eff4 & 0xffffffe0) + 0x10)), iVar6 < 0xc)))) {
      DAT_0052f010 = 0;
      DAT_0052eff0 = uVar3;
      DAT_0052eff4 = uVar1;
    }
    iVar6 = FUN_0040a1d2(0x28);
    if ((iVar6 == 0) && (DAT_0052f008 == 0)) {
      Adventure_Audio_PlayTerrainAmbience(local_40);
    }
    if (((DAT_0067f37c & 0x1f) == 0) && (DAT_0052f010 != 0)) {
      if (DAT_00522448 != 0) {
        DAT_00522448 = DAT_00522448 + -1;
      }
      if ((DAT_00522558 == 0) && (iVar5 == 2)) {
        DAT_00522448 = DAT_00522448 + 2;
      }
      DAT_0052f004 = DAT_0052f004 + 1;
      DAT_00641020 = DAT_00641020 + 1;
      if ((DAT_0052f004 & 0x3f) == 0) {
        Adventure_NewsFlash_EnemyAttack();
        iVar5 = FUN_0040a305(DAT_0067f380 +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0xffU)) >> 8),0,0x10
                            );
        DAT_0052f004 = DAT_0052f004 + iVar5;
      }
      if (((byte)DAT_0052f004 & 0x3f) == 0x18) {
        Adventure_NewsFlash_DominionSpell();
        iVar5 = FUN_0040a305(DAT_0067f380 * 2 +
                             ((int)(DAT_0052f004 + ((int)DAT_0052f004 >> 0x1f & 0x3fU)) >> 6),0,0x20
                            );
        DAT_0052f004 = DAT_0052f004 + iVar5;
      }
      DAT_005659dc = 1;
      if (7 < (int)DAT_0052f004) {
        DAT_0052f00c = 1;
      }
    }
    DAT_00641010 = (int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
    DAT_00641014 = (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
    if ((DAT_00641010 != iVar2 >> 5) || (DAT_00641014 != iVar4 >> 5)) {
      DAT_005659b0 = 0;
    }
    if ((DAT_0067f37c & 1) == 0) {
      local_68 = 0x7fff;
      for (local_64 = 0; local_64 < 0x80; local_64 = local_64 + 1) {
        if ((*(int *)(&DAT_0067bdf0 + local_64 * 100) != -1) &&
           (iVar2 = FUN_0040a36f((*(int *)(&DAT_0067bdf4 + local_64 * 100) * 0x20 + 0x10) -
                                 DAT_0052eff0,
                                 (*(int *)(&DAT_0067bdf8 + local_64 * 100) * 0x20 + 0x10) -
                                 DAT_0052eff4), iVar2 < local_68)) {
          local_58 = local_64;
          local_68 = iVar2;
        }
      }
      iVar2 = FUN_0040a305(0x80 - local_68,0,100);
      if ((iVar2 < 0xb) || (*(int *)(&DAT_0067bdf0 + local_58 * 100) < 1)) {
        if (DAT_0052f014 != 0) {
          Pic_Subsystem_00423c82(0x10);
        }
        DAT_0052f014 = 0;
        DAT_0052f064 = -1;
      }
      else {
        if (local_58 == DAT_0052f064) {
          Pic_Subsystem_00423dc2(0x10,iVar2 << 2);
        }
        else {
          DAT_0052f064 = local_58;
          if (*(int *)(&DAT_0067bdf0 + local_58 * 100) == 4) {
            for (local_30 = 0;
                (local_30 < 5 &&
                ((*(int *)(&DAT_0067bdf4 + local_58 * 100) !=
                  *(int *)(&DAT_0067f000 + local_30 * 0x30) ||
                 (*(int *)(&DAT_0067bdf8 + local_58 * 100) !=
                  *(int *)(&DAT_0067f004 + local_30 * 0x30))))); local_30 = local_30 + 1) {
            }
            iVar4 = DAT_0052f018;
            if (local_30 + 0x15 != DAT_0052f018) {
              if ((DAT_0052f018 != -1) && (local_30 + 0x15 != DAT_0052f018)) {
                Pic_Subsystem_00423b93(0x10);
              }
              switch(local_30) {
              case 0:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_bcastle_wav_0052f1dc,0x10);
                break;
              case 1:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_ucastle_wav_0052f1f0,0x10);
                break;
              case 2:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_gcastle_wav_0052f204,0x10);
                break;
              case 3:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_rcastle_wav_0052f218,0x10);
                break;
              case 4:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_wcastle_wav_0052f22c,0x10);
              }
              iVar4 = local_30 + 0x15;
            }
          }
          else if (*(int *)(&DAT_0067bdf0 + local_58 * 100) == 1) {
            if ((DAT_0052f018 != -1) && (DAT_0052f018 != 0x32)) {
              Pic_Subsystem_00423b93(0x10);
            }
            if (DAT_0052f018 != 0x32) {
              Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus0_wav_0052f240,0x10);
            }
            DAT_0052f018 = 0x32;
            iVar4 = DAT_0052f018;
          }
          else {
            iVar4 = local_58 % 0x14;
            if (iVar4 != DAT_0052f018) {
              if (DAT_0052f018 != -1) {
                Pic_Subsystem_00423b93(0x10);
              }
              switch(iVar4) {
              case 0:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus1_wav_0052f254,0x10);
                break;
              case 1:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus2_wav_0052f268,0x10);
                break;
              case 2:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus3_wav_0052f27c,0x10);
                break;
              case 3:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus4_wav_0052f290,0x10);
                break;
              case 4:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus5_wav_0052f2a4,0x10);
                break;
              case 5:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus6_wav_0052f2b8,0x10);
                break;
              case 6:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus7_wav_0052f2cc,0x10);
                break;
              case 7:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus8_wav_0052f2e0,0x10);
                break;
              case 8:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus9_wav_0052f2f4,0x10);
                break;
              case 9:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus10_wav_0052f308,0x10);
                break;
              case 10:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus11_wav_0052f320,0x10);
                break;
              case 0xb:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus12_wav_0052f338,0x10);
                break;
              case 0xc:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus13_wav_0052f350,0x10);
                break;
              case 0xd:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus14_wav_0052f368,0x10);
                break;
              case 0xe:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus15_wav_0052f380,0x10);
                break;
              case 0xf:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus16_wav_0052f398,0x10);
                break;
              case 0x10:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus17_wav_0052f3b0,0x10);
                break;
              case 0x11:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus18_wav_0052f3c8,0x10);
                break;
              case 0x12:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus19_wav_0052f3e0,0x10);
                break;
              case 0x13:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_tmplmus1_wav_0052f3f8,0x10);
                break;
              default:
                Adventure_Audio_SetPlaybackPosition(s_x_sound_locmus0_wav_0052f410,0x10);
              }
            }
          }
          DAT_0052f018 = iVar4;
          Adventure_Audio_PlayEffectLooped(0x10,iVar2,0);
          Pic_Subsystem_00423f10(0x10,1);
        }
        DAT_0052f014 = 1;
      }
    }
    if ((((DAT_005659b0 == 0) && (iVar2 = abs((DAT_0052eff0 & 0x1f) - 0x10), iVar2 < 0xc)) &&
        (iVar2 = abs((DAT_0052eff4 & 0x1f) - 0x10), iVar2 < 0xc)) &&
       (uVar3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uVar3 & 0x10) != 0)) {
      uVar3 = Duel_GetCardDrawOriginX(DAT_00641010,DAT_00641014);
      if (uVar3 == 0xffffffff) {
        FUN_0040c889(0x10,DAT_00641010,DAT_00641014);
      }
      else {
        Pic_Subsystem_00423dc2(0x10,400);
        Pic_Subsystem_00423f55(0x10,1);
        Town_Process_00506580(uVar3);
        DAT_0052f00c = 1;
        DAT_005659b0 = 1;
        DAT_0052f010 = 0;
        for (local_2c = 0; local_2c < 6; local_2c = local_2c + 1) {
          if ((0 < *(int *)(&DAT_0067f2d0 + local_2c * 0x14)) &&
             (iVar2 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14),
                                   DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14)),
             iVar2 < 0x60)) {
            iVar2 = DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_2c * 0x14);
            iVar4 = DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_2c * 0x14);
            iVar5 = abs(iVar4);
            iVar6 = abs(iVar2);
            if (iVar5 / 2 < iVar6) {
              local_6c = FUN_0040a33c(iVar2);
              local_6c = local_6c * 0x30;
            }
            else {
              local_6c = 0;
            }
            *(uint *)(&DAT_0067f2d4 + local_2c * 0x14) = DAT_0052eff0 - local_6c;
            iVar2 = abs(iVar2);
            iVar5 = abs(iVar4);
            if (iVar2 / 2 < iVar5) {
              local_70 = FUN_0040a33c(iVar4);
              local_70 = local_70 * 0x30;
            }
            else {
              local_70 = 0;
            }
            *(uint *)(&DAT_0067f2d8 + local_2c * 0x14) = DAT_0052eff4 - local_70;
          }
        }
        Palette_Subsystem_004981b5(0);
        FUN_0048c970(3);
        Adventure_LoadFacePalette(0);
        Ai_Subsystem_004c05ba();
        DAT_0067f37c = DAT_0067f37c | 0x1f;
      }
    }
    if (((DAT_005659b0 == 0) && ((DAT_0052eff0 - 8 & 0x10) == 0)) &&
       (((DAT_0052eff4 - 8 & 0x10) == 0 &&
        (uVar3 = FUN_0040c7c0(DAT_00641010,DAT_00641014), (uVar3 & 0x40) != 0)))) {
      iVar2 = FUN_0048ec9a(DAT_00641010,DAT_00641014);
      DAT_005659b0 = 1;
      if (((iVar2 != -1) && (*(int *)(&DAT_0067eff0 + iVar2 * 0x30) != -1)) &&
         (*(int *)(&DAT_0067f010 + iVar2 * 0x30) != 0)) {
        FUN_004909a0(iVar2);
      }
    }
    DAT_0067bde8 = 0;
    DAT_0067f3b8 = 0;
    for (local_2c = 0; local_2c < 500; local_2c = local_2c + 1) {
      if ((*(int *)(&deck + local_2c * 4) != -1) &&
         (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_2c * 4] & 0x40) == 0)) {
        DAT_0067f3b8 = DAT_0067f3b8 + 1;
      }
    }
    iVar5 = Mem_AllocOrFree_0040a422();
  }
  return iVar5;
}


