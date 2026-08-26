/*
 * Decompiled function: Palette_Subsystem_004a2ef0
 * Entry Point: 004a2ef0
 * Size: 4766 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a2ef0(int arg_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  int local_460;
  void *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  int local_8;
  
  local_c = s_x_sound_damb1_wav_0052c370;
  local_18 = 0;
  local_8 = 0;
  if (arg_1 < 5) {
    FUN_0040b3c2(4,arg_1);
  }
  else {
    FUN_0040b3c2(3,arg_1);
  }
  DAT_00649c1c = 0;
  FUN_0040a2c0();
  Palette_Subsystem_004a5f7c();
  *(int *)(&DAT_0067f018 + arg_1 * 0x30) = *(int *)(&DAT_0067f018 + arg_1 * 0x30) + 1;
  DAT_0054bd24 = arg_1;
  DAT_006498fc = 0;
  for (local_2c = 0; local_2c < 0xd; local_2c = local_2c + 1) {
    for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
      uVar2 = rand();
      *(uint *)(&DAT_0054ba18 + local_2c * 0x34 + local_24 * 4) = uVar2 & 3;
    }
  }
  if (arg_1 < 5) {
    Sprite_LoadCount(&DAT_006786b0,
                     (&PTR_s_dungeon3_spr_0052c2b0)[(char)(&DAT_0067f00c)[arg_1 * 0x30]],0x3c);
  }
  else {
    iVar4 = FUN_0040a1d2(3);
    Sprite_LoadAll(&DAT_006786b0,(&PTR_s_dungeon1_spr_0052c2a8)[iVar4]);
  }
  Adventure_Audio_SetPlaybackPosition(s_x_sound_dambloop_wav_0052c384,100);
  Adventure_Audio_PlayEffectLooped(100,0x50,0);
  Pic_Subsystem_00423f10(100,1);
  Mem_AllocOrFree_00510e20(2,s_CaveBkgd_pic_0052c39c);
  Sprite_LoadAll(&local_450,s_dungbutt_spr_0052c3ac);
  DAT_0054ba14 = local_450;
  DAT_0054be30 = local_44c;
  DAT_0054be34 = local_448;
  DAT_0054be38 = local_444;
  for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
    do {
      switch((((byte)(&DAT_0067f00d)[arg_1 * 0x30] & 0x80) >> 6) + local_10) {
      case 0:
        local_50 = 4;
        break;
      case 1:
        local_50 = 6;
        break;
      case 2:
        local_50 = 8;
        break;
      case 3:
        local_50 = 0xc;
        break;
      case 4:
        local_50 = 0x10;
        break;
      case 5:
        local_50 = 0x12;
        break;
      case 6:
        local_50 = 0x12;
      }
      if (arg_1 < 5) {
        uVar3 = FUN_0040a1d2(6);
        switch(uVar3) {
        case 0:
          local_50 = 10;
          break;
        case 1:
          local_50 = 0xb;
          break;
        case 2:
          local_50 = 0xc;
          break;
        case 3:
          local_50 = 0xd;
          break;
        case 4:
          local_50 = 0xe;
          break;
        case 5:
          local_50 = 0x10;
        }
        if (local_10 == 4) {
          local_50 = 0x12;
        }
      }
      uVar3 = Adventure_CheckMonsterEncounter((int)(char)(&DAT_0067f00c)[arg_1 * 0x30],local_50);
      *(undefined4 *)(&DAT_0054ba00 + local_10 * 4) = uVar3;
    } while (*(int *)(&DAT_0054ba00 + local_10 * 4) == 0);
    FUN_0046e70d(local_10,local_10 + 8);
    Sprite_Load_BK_AMG_0046d333(*(undefined4 *)(&DAT_0054ba00 + local_10 * 4),local_10,local_10 + 8)
    ;
    if ((arg_1 < 5) && (local_10 == 4)) {
      uVar3 = Adventure_CheckMonsterEncounter((int)(char)(&DAT_0067f00c)[arg_1 * 0x30],0x14);
      *(undefined4 *)(&DAT_0054ba00 + local_10 * 4) = uVar3;
    }
    *(undefined4 *)(&DAT_0067f2d0 + local_10 * 0x14) = 0xffffffff;
  }
  for (local_20 = 0; (int)local_20 < 0xf; local_20 = local_20 + 1) {
    for (local_28 = 0; (int)local_28 < 0xd; local_28 = local_28 + 1) {
      *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 1;
      if ((((local_20 == 0) || (local_28 == 0)) || (0xd < (int)local_20)) || (0xb < (int)local_28))
      {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((local_20 & 1) == 0) && ((local_28 & 1) == 0)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((int)local_20 < 3) && ((int)local_28 < 3)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if (((int)local_20 < 3) && (9 < (int)local_28)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if ((0xb < (int)local_20) && ((int)local_28 < 3)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
      if ((0xb < (int)local_20) && (9 < (int)local_28)) {
        *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
      }
    }
  }
  local_48 = 7;
  DAT_0054bd28 = 7;
  DAT_00649900 = 7;
  local_44 = 0xc;
  DAT_0054bd2c = 0xc;
  DAT_00649904 = 0xc;
  DAT_00649dbc = 1;
  do {
    iVar4 = FUN_0040a1d2(7);
    local_20 = iVar4 * 2;
    iVar4 = FUN_0040a1d2(6);
    local_28 = iVar4 * 2;
    iVar4 = FUN_0040a1d2(2);
    if (iVar4 == 0) {
      local_28 = local_28 + 1;
    }
    else {
      local_20 = local_20 + 1;
    }
    memcpy(&DAT_00649910,&DAT_00649c20,0x30c);
    *(undefined4 *)(&DAT_00649c20 + local_20 * 0x34 + local_28 * 4) = 0;
    local_38 = Palette_Subsystem_004a41fd();
    if (local_38 == 0) {
      memcpy(&DAT_00649c20,&DAT_00649910,0x30c);
    }
  } while (local_38 < 2);
  DAT_0054bd2c = DAT_0054bd2c + -1;
  Palette_Subsystem_004a5603(DAT_0054bd28,DAT_0054bd2c);
  Palette_Subsystem_004a4a47(0,1,arg_1);
  Ai_Subsystem_004cd1d1();
  Palette_Subsystem_004a4a47(0,0,arg_1);
  local_3c = FUN_0040a1d2(0x5a);
  local_3c = local_3c + 0x5a;
  Mem_AllocOrFree_005016f9();
  local_38 = 1;
  do {
    iVar4 = Mem_AllocOrFree_00501721();
    if (local_3c < iVar4) {
      if ((local_c[0xc] != '5') || (local_18 == 0)) {
        do {
          local_30 = FUN_0040a1d2(5);
          local_30 = local_30 + 0x31;
        } while (local_c[0xc] == local_30);
        local_c[0xc] = (char)local_30;
        Pic_Subsystem_00423b93(0x65);
        Adventure_Audio_InitSoundTrack(local_c,0x65,0);
        iVar4 = FUN_0040a1d2(100);
        iVar4 = iVar4 + -0x32;
        iVar8 = 100;
        iVar5 = FUN_0040a1d2(0x14);
        Adventure_Audio_PlayEffectAtVolume(0x65,iVar5 + 0x50,iVar8,iVar4);
        if ((local_c[0xc] == '5') && (local_18 == 0)) {
          local_18 = FUN_0040a1d2(3);
          local_18 = local_18 + 2;
          local_3c = FUN_0040a1d2(0x1e);
          local_3c = local_3c + 0x3c;
        }
        else {
          local_3c = FUN_0040a1d2(0x5a);
          local_3c = local_3c + 0x78;
        }
        Mem_AllocOrFree_005016f9();
        goto LAB_004a36e4;
      }
      local_18 = local_18 + -1;
      iVar4 = FUN_0040a1d2(100);
      iVar4 = iVar4 + -0x32;
      iVar8 = 100;
      iVar5 = FUN_0040a1d2(0x14);
      Adventure_Audio_PlayEffectAtVolume(0x65,iVar5 + 0x50,iVar8,iVar4);
      local_3c = FUN_0040a1d2(0x3c);
      local_3c = local_3c + 0x1e;
      Mem_AllocOrFree_005016f9();
    }
    else {
LAB_004a36e4:
      Pic_Subsystem_0044b84b();
      iVar4 = Mem_AllocOrFree_0040810f();
      if ((iVar4 == 0) || (DAT_0067bda0 != 0)) {
        if (DAT_0067bda0 != 0) {
          local_38 = Palette_Subsystem_004a610e(DAT_0067bda4,DAT_0067bda8);
        }
        local_40 = -1;
        local_30 = FUN_0048ac2f();
        if (local_30 < 0x4701) {
          if (local_30 != 0x4700) {
            if (local_30 == 0x1b) {
              local_38 = 0;
            }
            goto LAB_004a403e;
          }
          local_14 = DAT_0054bd28;
          local_1c = DAT_0054bd2c + -1;
          DAT_0052c2a0 = 3;
          local_40 = 1;
        }
        else if (local_30 == 0x4900) {
          local_1c = DAT_0054bd2c;
          local_14 = DAT_0054bd28 + 1;
          DAT_0052c2a0 = 5;
          local_40 = 3;
        }
        else if (local_30 == 0x4f00) {
          local_1c = DAT_0054bd2c;
          local_14 = DAT_0054bd28 + -1;
          DAT_0052c2a0 = 1;
          local_40 = 7;
        }
        else {
          if (local_30 != 0x5100) goto LAB_004a403e;
          local_14 = DAT_0054bd28;
          local_1c = DAT_0054bd2c + 1;
          DAT_0052c2a0 = 7;
          local_40 = 5;
        }
        if ((((-1 < local_14) && (local_14 < 0xf)) && (-1 < local_1c)) &&
           ((local_1c < 0xd && (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) != 0)))) {
          if (((&DAT_00649c20)[local_1c * 4 + local_14 * 0x34] & 0xf0) != 0) {
            if (local_40 != 0) {
              Palette_Subsystem_004a486f(local_40,1);
            }
            local_34 = (int)(*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) +
                            (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) >> 0x1f & 0xfU
                            )) >> 4 & 0xf;
            if (DAT_00649c1c != 0) {
              local_34 = 0xf;
            }
            switch(local_34) {
            case 1:
              Adventure_Audio_PlayEffect(s_x_sound_dice_wav_0052c3bc,0xf,100,100,0);
              uVar2 = rand();
              if ((uVar2 & 1) == 0) goto LAB_004a38ef;
              iVar4 = FUN_0040a1d2(3);
              DAT_006498fc = DAT_006498fc + iVar4 + 1U;
              uVar2 = iVar4 + 1U;
              while( true ) {
                DAT_00522454 = uVar2;
                strcpy(&g_OverworldWorldState,s_You_get_0052c3d0);
                Palette_Subsystem_004a5e4c();
                strcat(&g_OverworldWorldState,s_in_the_next_duel__0052c3dc);
                if (DAT_00522454 != 0xffffffff) break;
LAB_004a38ef:
                do {
                  do {
                    iVar4 = FUN_0040a1d2(500);
                    local_34 = *(uint *)(&deck + iVar4 * 4);
                  } while ((int)local_34 < 6);
                } while (((local_34 & 0x4000) != 0) ||
                        (local_34 = local_34 & 0xfff, uVar2 = local_34,
                        ((&g_MasterCardColorTable)[local_34 * 0x34] & 0x42) == 0));
              }
              FUN_004896be(&g_OverworldWorldState,100,0x50);
              *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              Palette_Subsystem_004a4a47(0,0,arg_1);
              break;
            case 2:
              Adventure_Audio_PlayEffect(s_x_sound_scroll_wav_0052c3f0,0xf,100,100,0);
              iVar4 = Palette_Subsystem_00498a18();
              if (iVar4 == 0) {
                Adventure_Audio_PlayEffect(s_x_sound_dsummon_wav_0052c404,0xf,100,100,0);
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x61;
                local_14 = DAT_0054bd28;
                local_1c = DAT_0054bd2c;
                local_40 = 0;
              }
              else {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              }
              Palette_Subsystem_004a4a47(0,0,arg_1);
              break;
            case 3:
            case 4:
            case 5:
            case 6:
              iVar4 = Palette_Subsystem_004a5722(arg_1,local_34 - 3,0);
              if (iVar4 == 0) {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0;
                local_14 = DAT_0054bd28;
                local_1c = DAT_0054bd2c;
                local_40 = 0;
                if (((&DAT_0067f014)[arg_1 * 0x30] & 1) != 0) {
                  local_38 = 0;
                  local_8 = 1;
                  Ai_Subsystem_004c05ba();
                }
                FUN_0040b3c2(2,*(undefined4 *)(&DAT_0054b9f4 + local_34 * 4));
              }
              else {
                *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
                FUN_0040b3c2(2,*(uint *)(&DAT_0054b9f4 + local_34 * 4) | 0x80);
              }
              Palette_Subsystem_004a4a47(0,0,arg_1);
              break;
            case 7:
              local_4c = 0;
              do {
                local_34 = FUN_0040a1d2(3);
                if (*(int *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30) != -1) break;
                local_4c = local_4c + 1;
              } while (local_4c < 100);
              if (*(int *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30) == -1) {
                iVar4 = FUN_0040a1d2(100);
                iVar4 = iVar4 * (DAT_0067f380 + 2) + 100;
                bVar1 = false;
                iVar4 = iVar4 - iVar4 % 10;
                Adventure_Audio_PlayEffect(s_x_sound_treasure_wav_0052c454,0xf,100,100,0);
                Gold = Gold + iVar4;
                sprintf(&g_OverworldWorldState,s_Found__d_Gold_and_bag_with_0052c46c,iVar4);
                for (local_460 = 1; local_460 < 6; local_460 = local_460 + 1) {
                  iVar5 = FUN_0040a1d2(2);
                  if (iVar5 != 0) {
                    uVar3 = Mem_AllocOrFree_00473d7e(local_460);
                    pcVar7 = s__d__s_0052c488;
                    iVar8 = iVar5;
                    sVar6 = strlen(&g_OverworldWorldState);
                    sprintf(&g_OverworldWorldState + sVar6,pcVar7,iVar8,uVar3);
                    bVar1 = true;
                    *(int *)(&DAT_0067bdbc + local_460 * 4) =
                         *(int *)(&DAT_0067bdbc + local_460 * 4) + iVar5;
                  }
                }
                if (bVar1) {
                  pcVar7 = s_Jewels_0052c490;
                  sVar6 = strlen(&g_OverworldWorldState);
                  sprintf(&DAT_0062684f + sVar6,pcVar7);
                }
                else {
                  sprintf(&g_OverworldWorldState,s_Found__d_Gold_0052c49c,iVar4);
                }
                FUN_0040b3c2(0x13,100);
                FUN_004896be(&g_OverworldWorldState,100,0x50);
              }
              else {
                Adventure_Audio_PlayEffect(s_x_sound_findcard_wav_0052c418,0xf,100,100,0);
                FUN_0040acfd(s_staceybk_pic_0052c430);
                FUN_0040b3c2(0x13,*(uint *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30) | 0x10000);
                FUN_0050b3de(*(int *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30),0x22,0x53,0x4b,
                             0x70,1,&DAT_0052c440);
                FUN_0040d4d1((int)g_DisplaySurfaceScreen,0x1b,0x90,0x93);
                FUN_0040a3e1();
                Ai_Subsystem_004cd1d1();
                Palette_Subsystem_004a4a47(0,0,arg_1);
                iVar4 = Pic_Subsystem_00451e40
                                  (*(uint *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30));
                *(uint *)(&deck + iVar4 * 4) = *(uint *)(&deck + iVar4 * 4) | 0x4000;
                *(undefined4 *)(&DAT_0067eff0 + local_34 * 4 + arg_1 * 0x30) = 0xffffffff;
              }
              *(undefined4 *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) = 0x101;
              Palette_Subsystem_004a4a47(0,0,arg_1);
              break;
            case 0xf:
              if (arg_1 < 5) {
                Mem_AllocOrFree_0050fc50(DAT_0054ba14);
                Mem_AllocOrFree_0050fc50(DAT_006786b0);
                iVar4 = Palette_Subsystem_004a5722(arg_1,4,1);
                if (iVar4 != 0) {
                  Action_PromptTarget_0049239e(arg_1);
                }
                Ai_Subsystem_004c05ba();
                Palette_Subsystem_004a5fdc();
                DAT_00522454 = 0xffffffff;
                DAT_00627a7c = 0;
                DAT_006498fc = 0;
                return 0;
              }
            }
            Palette_Subsystem_004a5603(local_14,local_1c);
            if (DAT_0054be2c != 0) {
              Palette_Subsystem_004a4a47(0,0,arg_1);
            }
            SetFocus(_hwndScreen);
          }
          if (local_40 != 0) {
            Palette_Subsystem_004a486f(local_40,0);
          }
          FUN_0040a3e1();
          DAT_0054bd28 = local_14;
          DAT_0054bd2c = local_1c;
          Palette_Subsystem_004a5603(local_14,local_1c);
          if (DAT_0054be2c != 0) {
            Palette_Subsystem_004a4a47(0,0,arg_1);
          }
          if ((DAT_0054bd28 == local_48) && (DAT_0054bd2c == local_44)) {
            local_38 = 0;
          }
        }
      }
    }
LAB_004a403e:
    if (local_38 == 0) {
      if (arg_1 < 5) {
        if (local_8 != 0) {
          strcpy(&g_OverworldWorldState,s_You_are_unceremoniously_booted_f_0052c4ac);
          pcVar7 = (char *)Mem_AllocOrFree_00473d7e(arg_1 + 1);
          strcat(&g_OverworldWorldState,pcVar7);
          strcat(&g_OverworldWorldState,s_Wizard__0052c4f0);
          Adventure_Audio_PlayEffect(s_x_sound_dsummon_wav_0052c4fc,0xf,100,100,0);
          FUN_004896be(&g_OverworldWorldState,0xa0,0x78);
        }
      }
      else {
        FUN_0040c889(0x40,*(int *)(&DAT_0067f000 + arg_1 * 0x30),
                     *(int *)(&DAT_0067f004 + arg_1 * 0x30));
        *(uint *)(&DAT_0067f010 + arg_1 * 0x30) =
             *(uint *)(&DAT_0067f010 + arg_1 * 0x30) & 0xfffffffe;
        *(uint *)(&DAT_0067f010 + arg_1 * 0x30) = *(uint *)(&DAT_0067f010 + arg_1 * 0x30) | 6;
        do {
          do {
            local_20 = FUN_0040a1d2(0x40);
            local_28 = FUN_0040a1d2(0x40);
            FUN_0040c7c0(local_20,local_28);
            iVar4 = FUN_0040c761(local_20,local_28);
          } while (iVar4 == 0);
          uVar2 = FUN_0040c7c0(local_20,local_28);
        } while ((uVar2 & 0x30) != 0);
        *(uint *)(&DAT_0067f000 + arg_1 * 0x30) = local_20;
        *(uint *)(&DAT_0067f004 + arg_1 * 0x30) = local_28;
        FUN_0040c81c(0x40,local_20,local_28);
      }
      DAT_00627a7c = 0;
      DAT_00522454 = 0xffffffff;
      DAT_006498fc = 0;
      Mem_AllocOrFree_0050fc50(DAT_0054ba14);
      Mem_AllocOrFree_0050fc50(DAT_006786b0);
      Ai_Subsystem_004c05ba();
      Palette_Subsystem_004a5fdc();
      Pic_Subsystem_00423c82(100);
      uVar3 = Pic_Subsystem_00423b93(100);
      return uVar3;
    }
  } while( true );
}


