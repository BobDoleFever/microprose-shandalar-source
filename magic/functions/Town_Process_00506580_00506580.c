/*
 * Decompiled function: Town_Process_00506580
 * Entry Point: 00506580
 * Size: 5505 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Town_Process_00506580(uint arg_1)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int arg_5;
  int arg_4;
  int arg_3;
  int arg_2;
  uint local_94;
  int local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64 [4];
  char *local_54;
  char *local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  LPVOID local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  DAT_0061e0d4 = arg_1;
  FUN_0040a3e1();
  if ((&DAT_0067be01)[arg_1 * 100] == '\0') {
    if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 4) {
      local_64[1] = s_0246_pic_00531a34;
      local_64[2] = s_0364_pic_00531a4c;
      local_64[3] = s_0335_pic_00531a64;
      local_54 = s_0737_pic_00531a7c;
      local_50 = s_0028_pic_00531a94;
      uVar4 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + arg_1 * 100),
                           *(int *)(&DAT_0067bdf8 + arg_1 * 100));
      bVar1 = Adventure_GetLocationEncounterIndex(uVar4);
      DAT_006b2d64 = FUN_00473cc5(bVar1);
      FUN_0040aaf1(local_64[DAT_006b2d64]);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
      strcpy(&g_OverworldWorldState,s_Who_dares_to_challenge_the_Might_00531aa0);
      pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,s_Wizard__Are_you_brave_enough_to_e_00531ac4);
      strcat(&g_OverworldWorldState,s_Well____No__Yes__enter_the_castl_00531af8);
      iVar3 = FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      if (iVar3 == 1) {
        Pic_Subsystem_00423c82(0x10);
        FUN_004909a0(DAT_006b2d64 + -1);
        if (((DAT_0067bdb4 & 1 << ((byte)DAT_006b2d64 & 0x1f)) == 0) && (DAT_0067f380 == 3)) {
          Adventure_NewsFlash_Retaliation(DAT_006b2d64);
        }
      }
      Palette_Subsystem_00496eaf();
      iVar3 = 0;
    }
    else if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 5) {
      local_74 = s_0246_pic_00531b2c;
      local_70 = s_0364_pic_00531b44;
      local_6c = s_0335_pic_00531b5c;
      local_68 = s_0737_pic_00531b74;
      local_64[0] = s_0028_pic_00531b8c;
      uVar4 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + arg_1 * 100),
                           *(int *)(&DAT_0067bdf8 + arg_1 * 100));
      bVar1 = Adventure_GetLocationEncounterIndex(uVar4);
      DAT_006b2d64 = FUN_00473cc5(bVar1);
      FUN_0040aaf1((&local_78)[DAT_006b2d64]);
      strcpy(&g_OverworldWorldState,s_The_Mighty_00531b98);
      pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_006b2d64);
      strcat(&g_OverworldWorldState,pcVar2);
      strcat(&g_OverworldWorldState,s_Wizard_was_crushed_in_epic_comba_00531ba4);
      FUN_004896be(&g_OverworldWorldState,0x2a,0x1a);
      Pic_Subsystem_00423c82(0x10);
      Palette_Subsystem_00496eaf();
      iVar3 = 0;
    }
    else {
      if ((DAT_00522450 == arg_1) && ((-1 < DAT_0067f2c0 || (DAT_0067f2c0 < -100)))) {
        FUN_0040a95d(s_village_pic_00531c0c +
                     ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
        local_c = 0;
        FUN_0040b3c2(0x10,DAT_0067f2c0);
        if ((DAT_0067f2c0 == 0) || (DAT_0067f2c0 == 2)) {
          strcpy(&g_OverworldWorldState,s_The_keeper_is_pleased_to_receive_00531c24);
          if (DAT_0067f2c0 == 0) {
            strcat(&g_OverworldWorldState,s_You_create_a_mana_link_here__00531c5c);
            Pic_Subsystem_00423b93(0xf);
            Adventure_Audio_InitSoundTrack(s_x_sound_manalink_wav_00531c7c,0xf,0);
            Adventure_Audio_PlayEffectAtVolume(0xf,100,100,0);
            *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
                 *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          }
          if (DAT_0067f2c0 == 2) {
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_a_fine_00531c94);
            pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_amulet__00531cb4);
            Pic_Subsystem_00423b93(0xf);
            Adventure_Audio_InitSoundTrack(s_x_sound_reward_wav_00531cc0,0xf,0);
            Adventure_Audio_PlayEffectAtVolume(0xf,100,100,0);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          }
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          local_c = 1;
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if ((DAT_0067f2c0 == 1) &&
           (iVar3 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3))),
           iVar3 != 0)) {
          local_30 = FUN_0050b0fc((byte)DAT_0067b9a0,(byte)(1 << ((byte)DAT_00522450 & 3)));
          *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
               *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + 1;
          strcpy(&g_OverworldWorldState,s_The_people_are_pleased_to_receiv_00531cd4);
          strcat(&g_OverworldWorldState,
                 s_Swamp_0051aea9 + ((&DAT_0070214c)[local_30] & 0xfff) * 0x34);
          strcat(&g_OverworldWorldState,s_spell__You_are_rewarded_with_a_f_00531cfc);
          pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
          strcat(&g_OverworldWorldState,pcVar2);
          strcat(&g_OverworldWorldState,s_amulet_and_a_mana_link__00531d24);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
          DAT_00676d3c = 1;
          FUN_004896be(&g_OverworldWorldState,0x50,0x50);
          *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
               *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          local_c = 1;
          Pic_Subsystem_00452065(local_30 + -1);
          Ai_Subsystem_004cd1d1();
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if (DAT_0067f2c0 < -100) {
          if (*(int *)(&DAT_0067bdf0 + DAT_00522450 * 100) < 2) {
            DAT_0067f2c0 = DAT_0067f2c0 + 100;
            local_20 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_village_is_glad_to_be_rid_of_00531de0);
            Adventure_FormatNewsString(-DAT_0067f2c0,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531e0c);
            pcVar2 = _itoa(local_20,&DAT_0061e0f0,10);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_fine_00531e24);
            pcVar2 = (char *)Mem_AllocOrFree_00473d7e(DAT_0067b9a0);
            strcat(&g_OverworldWorldState,pcVar2);
            strcat(&g_OverworldWorldState,s_amulet_00531e2c);
            strcat(&g_OverworldWorldState,&DAT_00531e34 + ((local_20 == 1) - 1 & 4));
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) =
                 *(int *)(&DAT_0067bdbc + DAT_0067b9a0 * 4) + local_20;
            *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) =
                 *(uint *)(&DAT_0067be00 + DAT_00522450 * 100) | 1;
          }
          else {
            local_78 = 1;
            DAT_0067f2c0 = DAT_0067f2c0 + 100;
            local_20 = (int)(char)(&DAT_00522628)[DAT_0067f2c0 * -0x44] / 7 + 1;
            strcpy(&g_OverworldWorldState,s_The_people_are_glad_to_be_rid_of_00531d40);
            Adventure_FormatNewsString(-DAT_0067f2c0,0,0);
            strcat(&g_OverworldWorldState,s_You_are_rewarded_with_00531d6c);
            FUN_0050a73e(DAT_00522450);
            strcat(&g_OverworldWorldState,s_of_your_choice__00531d88);
            FUN_004896be(&g_OverworldWorldState,0x50,0x50);
            PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
            local_40 = 0xffffffff;
            while (local_40 == 0xffffffff) {
              local_40 = Palette_Color_0049716e
                                   (s_Which_card_do_you_seek__00531d9c,
                                    *(uint *)(&DAT_0067bdfc + arg_1 * 100) & 0xff,
                                    (*(int *)(&DAT_0067bdfc + arg_1 * 100) >> 8) - 1,local_78,0);
              local_78 = 0;
              if (local_40 != 0xffffffff) {
                strcpy(&g_OverworldWorldState,s_Will_you_take_this_card____Yes_N_00531db4);
                do {
                  iVar3 = Ai_Util_004c3bc4(0x15c);
                  iVar3 = iVar3 + 10;
                  iVar5 = Ai_Util_004c3bc4(0xf4);
                  iVar3 = FUN_00489710(&g_OverworldWorldState,iVar5 + 10,iVar3);
                } while (iVar3 < 0);
                if (iVar3 == 0) {
                  local_30 = Pic_Subsystem_00451e40(local_40);
                  if (local_30 != -1) {
                    *(uint *)(&deck + local_30 * 4) = *(uint *)(&deck + local_30 * 4) | 0x4000;
                  }
                }
                else {
                  local_40 = 0xffffffff;
                }
              }
              FUN_00501736(0xf);
            }
            PTR_FUN_00527b3c = FUN_0048a3cc;
          }
          local_c = 1;
          if (DAT_00522450 == DAT_00531594) {
            DAT_00531594 = 0xffffffff;
          }
          DAT_00522450 = 0xffffffff;
          Ai_Subsystem_004c05ba();
          Ai_Subsystem_004c3c5c(1);
        }
        if (local_c == 0) {
          local_94 = arg_1;
        }
        else {
          local_94 = arg_1 | 0x80;
        }
        FUN_0040b3c2(1,local_94);
      }
      else {
        FUN_0040b3c2(1,arg_1);
      }
      *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) | 2;
      *(int *)(&DAT_0067be4c + arg_1 * 100) = *(int *)(&DAT_0067be4c + arg_1 * 100) + 1;
      FUN_0040a95d(s_village_pic_00531e3c + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc)
                  );
      Town_Process_00507c86(arg_1);
      *(int *)(&DAT_0067be50 + arg_1 * 100) = DAT_00641020;
      if ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 3) ||
         (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 2)) {
        local_10 = -1;
        local_38 = 999;
        for (local_28 = 0; local_28 < 0xc; local_28 = local_28 + 1) {
          if ((*(int *)(&DAT_005224e8 + local_28 * 0x10) != 0) &&
             (local_14 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + arg_1 * 100) -
                                      *(int *)(&DAT_0067bdf4 +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100),
                                      *(int *)(&DAT_0067bdf8 + arg_1 * 100) -
                                      *(int *)(&DAT_0067bdf8 +
                                              *(int *)(&DAT_005224e8 + local_28 * 0x10) * 100)),
             local_14 < local_38)) {
            local_10 = local_28;
            local_38 = local_14;
          }
        }
        if ((local_10 != -1) && ((_DAT_0067f374 & 1 << ((byte)local_10 & 0x1f)) == 0)) {
          Mem_AllocOrFree_00510e20(1,s_worlbak1_pic_00531e54);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
          local_30 = Bazaar_GetCardBaseValue(local_10);
          iVar3 = *(int *)(&DAT_006782a0 + local_10 * 4);
          local_24 = (0x4e - *(short *)(iVar3 + 6)) / 2 + 0x4c;
          local_1c = (0x4f - *(short *)(iVar3 + 4)) / 2 + 0x14f;
          iVar5 = *(int *)(&DAT_006782a0 + local_10 * 4);
          arg_5 = Ai_Util_004c3bc4((int)*(short *)(iVar3 + 6));
          arg_4 = Ai_Util_004c3bc4((int)*(short *)(iVar3 + 4));
          arg_3 = Ai_Util_004c3bc4(local_24);
          arg_2 = Ai_Util_004c3bc4(local_1c);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2,arg_3,arg_4,arg_5,iVar5);
          local_24 = (local_24 + *(short *)(iVar3 + 6) + 0x10) / 2;
          local_1c = (local_1c + (int)*(short *)(iVar3 + 4) / 2) / 2;
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,0x7b,0x176,0x4b);
          g_OverworldWorldState = 0;
          local_24 = local_24 + -5;
          strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_10]);
          FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x40);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,s_costs_00531e70);
          pcVar2 = _itoa(*(int *)(&DAT_005224e4 + local_10 * 0x10) / 2,&DAT_0061e0f0,10);
          strcat(&g_OverworldWorldState,pcVar2);
          strcat(&g_OverworldWorldState,s_gold_pieces__00531e78);
          FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x7b);
          local_24 = local_24 + 8;
          strcpy(&g_OverworldWorldState,&DAT_00531e88);
          strcat(&g_OverworldWorldState,(&PTR_s_A_clever_duelist_can_switch_ante_005225a0)[local_10]
                );
          strcat(&g_OverworldWorldState,&DAT_00531e8c);
          iVar3 = Ai_Util_004c3ba3(local_24);
          iVar5 = Ai_Util_004c3ba3(local_1c);
          FUN_0040d201((int)g_DisplaySurfaceScreen,0x7b,iVar5,iVar3);
          if (local_38 == 0) {
            if (Gold < *(int *)(&DAT_005224e4 + local_10 * 0x10) / 2) {
              local_24 = local_24 + 0x18;
              strcpy(&g_OverworldWorldState,s_Insufficient_Funds_00531f1c);
              FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0xbe);
              local_24 = local_24 + 8;
              FUN_0040a3e1();
              Ai_Subsystem_004cd1d1();
            }
            else {
              local_24 = local_24 + 0x10;
              strcpy(&g_OverworldWorldState,s_To_release_the_WORLDMAGIC_spell___00531ea4);
              strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_10]);
              strcat(&g_OverworldWorldState,s___from_00531ec8);
              Ai_TownEncounter_004c3b19(*(uint *)(&DAT_005224e8 + local_10 * 0x10));
              strcat(&g_OverworldWorldState,s___you_must_pay_00531ed4);
              pcVar2 = _itoa(*(int *)(&DAT_005224e4 + local_10 * 0x10) / 2,&DAT_0061e0f0,10);
              strcat(&g_OverworldWorldState,pcVar2);
              strcat(&g_OverworldWorldState,s_gold_pieces__00531ee4);
              strcat(&g_OverworldWorldState,s_Will_you____Never_mind_Pay_the_g_00531ef4);
              FUN_0040a3e1();
              local_30 = FUN_004896be(&g_OverworldWorldState,
                                      (-(uint)(DAT_00522458 == 0x280) & 0xffffffce) + 0xbe,0x88);
              DAT_00531590 = local_10;
              iVar3 = DAT_00531590;
              if (local_30 == 1) {
                Gold = Gold - *(int *)(&DAT_005224e4 + local_10 * 0x10) / 2;
                DAT_00531590._0_1_ = (byte)local_10;
                _DAT_0067f374 = _DAT_0067f374 | 1 << ((byte)DAT_00531590 & 0x1f);
                DAT_00531590 = iVar3;
                *(undefined4 *)(&DAT_005224e8 + local_10 * 0x10) = 0;
                FUN_0040b3c2(6,local_10);
              }
              DAT_00531590 = -1;
            }
          }
          else {
            local_48 = *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100) -
                       *(int *)(&DAT_0067bdf4 + arg_1 * 100);
            local_4c = *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100) -
                       *(int *)(&DAT_0067bdf8 + arg_1 * 100);
            local_24 = local_24 + 0x10;
            strcpy(&g_OverworldWorldState,s_Travel_00531e90);
            FUN_0050aef6(*(int *)(&DAT_0067bdf4 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100),
                         *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_005224e8 + local_10 * 0x10) * 100));
            strcat(&g_OverworldWorldState,&DAT_00531e98);
            Ai_TownEncounter_004c3b19(*(uint *)(&DAT_005224e8 + local_10 * 0x10));
            strcat(&g_OverworldWorldState,&DAT_00531ea0);
            local_24 = local_24 + 8;
            FUN_0040c336(&g_OverworldWorldState,local_1c,local_24,0x8d);
            local_24 = local_24 + 8;
            DAT_00531590 = local_10;
            FUN_0040a3e1();
            Ai_Subsystem_004cd1d1();
          }
        }
      }
      Palette_Subsystem_00496eaf();
      iVar3 = DAT_0067bddc;
      if (DAT_0067bddc < DAT_00641020) {
        DAT_00522450 = 0xffffffff;
      }
    }
  }
  else {
    FUN_0040a95d(s_village_pic_0053193c + ((*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) - 1 & 0xc));
    Adventure_LoadFacePalette(1);
    for (local_2c = 0; local_2c < 0x10; local_2c = local_2c + 1) {
      (&DAT_006b2dd0)[local_2c] = -1;
      (&DAT_006b2d90)[local_2c] = (&DAT_006b2dd0)[local_2c];
    }
    Adventure_ShowDefeatScreen();
    local_44 = *(int *)(&DAT_0067bdf8 + arg_1 * 100);
    for (local_2c = 0; local_2c < *(int *)(&DAT_0067bdf4 + arg_1 * 100) % 3 + 1;
        local_2c = local_2c + 1) {
      do {
        do {
          local_30 = local_44 % 500;
          local_44 = local_44 + 7;
        } while (*(int *)(&deck + local_30 * 4) == -1);
      } while ((((&DAT_00702151)[local_30 * 4] & 0x40) != 0) ||
              ((*(uint *)(&deck + local_30 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_2c] = *(uint *)(&deck + local_30 * 4) & 0xfff;
      FUN_0050b206(*(uint *)(&deck + local_30 * 4) & 0xfff,local_2c * 0x28 + 0x60,
                   local_2c * 3 + 0x80,1,s_Your_ANTE_00531954);
    }
    local_3c = *(int *)(&DAT_0067be00 + arg_1 * 100) >> 8;
    switch((int)(DAT_0052f004 + (DAT_0052f004 >> 0x1f & 0x7fU)) >> 7) {
    case 0:
      local_18 = (LPVOID)0x4;
      break;
    case 1:
      local_18 = (LPVOID)0x6;
      break;
    case 2:
      local_18 = (LPVOID)0x8;
      break;
    case 3:
      local_18 = (LPVOID)0xc;
      break;
    case 4:
      local_18 = (LPVOID)0x10;
      break;
    default:
      if (((&DAT_0067bdf8)[arg_1 * 100] & 1) == 0) {
        local_18 = (LPVOID)0xe;
      }
      else {
        local_18 = (LPVOID)0x12;
      }
    }
    local_18 = (LPVOID)Adventure_CheckMonsterEncounter(local_3c,(int)local_18);
    FUN_004909d3((int)local_18,0xffffffff,0,-1);
    do {
      do {
        DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
      } while (DAT_006b2dd0 < 5);
    } while (((&DAT_0051aed1)[DAT_006b2dd0 * 0x34] & 1) != 0);
    FUN_0050b206(DAT_006b2dd0,0xe0,0x40,1,s_Wizard_s_ANTE_00531960);
    Pic_Load_advfac64_00489188(local_18,0xa0,0x20,1,2);
    strcpy(&g_OverworldWorldState,s_This_place_is_ruled_by_the_00531970);
    pcVar2 = (char *)Mem_AllocOrFree_00473d7e(local_3c);
    strcat(&g_OverworldWorldState,pcVar2);
    strcat(&g_OverworldWorldState,s_Wizard_You_must_duel_0053198c);
    Adventure_FormatNewsString((int)local_18,1,0);
    strcat(&g_OverworldWorldState,s_to_free_the_city__Never_mind__Du_005319a4);
    iVar3 = FUN_004896be(&g_OverworldWorldState,0x78,0x38);
    if (iVar3 == 1) {
      iVar3 = FUN_0040a1d2(3);
      DAT_0068a64c = Pic_Subsystem_0045268f
                               (*(int *)(&DAT_00527f10 + iVar3 * 4 + (local_3c * 3 + -3) * 4));
      _DAT_0067f354 = local_3c;
      _DAT_0067f348 = local_18;
      local_40 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_18 * 0x44));
      FUN_004909d3((int)local_18,local_40,0,-1);
      DAT_006b2d64 = local_3c;
      DAT_0063ee24 = 0;
      DAT_00695df0 = 3;
      local_8 = Pic_Load_0044ef70(local_40,local_18);
      if (local_8 == 1) {
        Adventure_Audio_PlayDuelIntro(1);
        *(uint *)(&DAT_0067be00 + arg_1 * 100) = *(uint *)(&DAT_0067be00 + arg_1 * 100) & 0xffff00ff
        ;
        Mem_AllocOrFree_00510de0(1,s_celeb_pic_005319dc);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
        g_OverworldWorldState = 0;
        Ai_TownEncounter_004c3b19(arg_1);
        strcat(&g_OverworldWorldState,s_is_freed__The_people_rejoice__005319e8);
        FUN_004896be(&g_OverworldWorldState,0x14,0x14);
        FUN_0040b3c2(7,arg_1);
      }
      if (local_8 == 0) {
        Adventure_Audio_PlayDuelIntro(2);
        for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
          local_34 = (&DAT_006b2d90)[local_2c];
          if (local_34 != 0xffffffff) {
            Mem_AllocOrFree_00510de0(1,s_losedul2_pic_00531a08);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
            strcpy(&g_OverworldWorldState,s_Lost_this_card_00531a18);
            FUN_0050b206(local_34,0x17,0x50,1,&g_OverworldWorldState);
            FUN_0040a3e1();
            Ai_Subsystem_004cd1d1();
            FUN_00489630(local_34);
          }
        }
      }
    }
    Adventure_LoadFacePalette(0);
    Pic_Subsystem_00423c82(0x10);
    Palette_Subsystem_00496eaf();
    iVar3 = 0;
  }
  return iVar3;
}


