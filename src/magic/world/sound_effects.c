/*
 * magic/world/sound_effects.c - Shandalar Audio - Sound Effects & Music Triggers
 * Reconstructed Module containing 11 functions
 */
#include "magic.h"

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0040b00c
 * Entry Point: 0040b00c
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_0040b00c(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0051732c,0xf,100,100,0);
  DAT_005384d0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_DuelSounds_artifact_0040de30
 * Entry Point: 0040de30
 * Size: 3070 bytes
 */


/* WARNING: Removing unreachable block (ram,0x0040e7aa) */

void Sound_LoadWav_x_DuelSounds_artifact_0040de30(int player_id)

{
  int val_1;
  int val_2;
  int val_3;
  char *pcVar4;
  uint32_t local_2c;
  int local_24;
  uint32_t loop_idx;
  uint32_t auStack_1c [4];
  int match_count;
  int slot_idx;
  
  FUN_0040abf9((&PTR_DAT_00517538)[arg_1]);
  FUN_0050b9d5(g_DisplaySurfaceScreen);
  for (loop_idx = 1; (int)loop_idx < 4; loop_idx = loop_idx + 1) {
    do {
      val_1 = Util_GetRandomNumber(3);
      if (val_1 == 0) {
        local_2c = Pic_Subsystem_00451d90(0x40,1);
      }
      else {
        local_2c = Pic_Subsystem_00451d90(0x3f,1 << ((uint8_t)arg_1 & 0x1f));
      }
      val_1 = File_Load_Info(local_2c);
    } while ((((val_1 != loop_idx) || (val_1 = Glue_Subsystem_004f0b50(local_2c), val_1 < 0)) ||
             (((&g_MasterCardFlagsTable)[local_2c * 0x34] & 9) != 0)) ||
            (val_1 = FUN_00485005(local_2c), val_1 == 0));
    if ((loop_idx == 1) && (val_1 = Util_GetRandomNumber(2), val_1 != 0)) {
      local_2c = arg_1 - 1;
    }
    auStack_1c[loop_idx] = local_2c;
  }
  do {
    do {
      val_1 = Util_GetRandomNumber(500);
    } while (*(int *)(&deck + val_1 * 4) == -1);
    val_2 = File_Load_Info(*(uint32_t *)(&deck + val_1 * 4) & 0xfff);
  } while ((val_2 < 2) || (val_2 = FUN_00485005(val_1), val_2 == 0));
  Glue_Subsystem_004eadb7(1);
  do {
    if ((int)(CONCAT44(DAT_0067f37c >> 0x1f,DAT_0067f37c >> 2) % 3) != 0) {
      val_1 = Util_GetRandomNumber(2);
      if (val_1 == 0) {
        do {
          do {
            loop_idx = Util_GetRandomNumber(g_MasterCardCount + -0x29);
            val_1 = Pic_Subsystem_004521a6
                              ((int)(char)(&g_MasterCardColorTable)[loop_idx * 0x34],1 << ((uint8_t)arg_1 & 0x1f)
                               ,1);
          } while (val_1 == 0);
        } while ((((&g_MasterCardFlagsTable)[loop_idx * 0x34] & 1) != 0) ||
                (val_1 = FUN_00485005(loop_idx), val_1 == 0));
      }
      else {
        loop_idx = arg_1 - 1;
      }
      goto switchD_0040e766_default;
    }
    val_2 = Util_GetRandomNumber(0xe);
    val_3 = val_2 + 5;
    FUN_0040b3c2(5,val_3);
    Util_GetRandomNumber(2);
  } while ((g_AiManaColorCost_Blue != -1) && ((val_3 == 0xb || (val_3 == 0x11))));
  strcpy(&g_OverworldWorldState,s_You_happen_upon_a_00518dc8);
  FUN_0040eb04(val_3);
  strcat(&g_OverworldWorldState,&DAT_00518ddc);
  FUN_00489710(&g_OverworldWorldState,0x5a,100);
  loop_idx = 0xffffffff;
  val_3 = Util_GetRandomNumber(4);
  if (val_3 == 0) {
    loop_idx = FUN_0040eab1();
  }
  switch(val_2) {
  case 0:
    match_count = FUN_0050b00c();
    if (match_count != -1) {
      FUN_0048ea81(match_count);
      break;
    }
  case 1:
    val_1 = Palette_Subsystem_00498a18();
    if (val_1 != 0) {
      loop_idx = auStack_1c[3];
    }
    break;
  case 2:
    val_1 = Util_GetRandomNumber(2);
    if ((val_1 == 0) && (0x7f < DAT_0052f004)) {
      strcpy(&g_OverworldWorldState,s_Thieves_take_half_your_gold__00518e0c);
      Gold = Gold / 2;
      loop_idx = FUN_0040eab1();
    }
    else {
      Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_00518de0,0xf,100,100,0);
      strcpy(&g_OverworldWorldState,s_You_get_500_gold__00518df8);
      Gold = Gold + 500;
      loop_idx = 0xffffffff;
    }
    FUN_00489710(&g_OverworldWorldState,0x5a,100);
    break;
  case 3:
    do {
      val_1 = Bazaar_TradeCardDialogue(-1,-1);
    } while (val_1 != 0);
    break;
  case 4:
    Glue_Subsystem_004ebcdc(s_x_Duelsounds_aswanjag_wav_00518e2c,0x97,100,100,0);
    if (DAT_0052f004 < 0x100) {
      Pic_Load_winbak01_0040eb5a(8,2);
    }
    else {
      Pic_Load_winbak01_0040eb5a(0xd,3);
    }
    break;
  case 5:
    Glue_Subsystem_004ebcdc(s_x_Duelsounds_aswanjag_wav_00518e48,0x97,100,100,0);
    Pic_Load_winbak01_0040eb5a(0x12,4);
    break;
  case 6:
    g_AiManaColorCost_Blue = Pic_Subsystem_0045268f(0x1b4);
    Glue_Subsystem_004ebcdc(s_x_Duelsounds_aswanjag_wav_00518e64,0x97,100,100,0);
    Pic_Load_winbak01_0040eb5a(0xd,2);
    break;
  case 7:
    Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_00518e80,0xf,100,100,0);
    do {
      strcpy(&g_OverworldWorldState,s_You_may_buy_amulets_for_200_gold_00518e98);
      for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
        strcat(&g_OverworldWorldState,s_Buy_a_00518ed0);
        pcVar4 = (char *)Mem_AllocOrFree_00473d7e(local_24 + 1);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,s_amulet___you_have_00518ed8);
        pcVar4 = _itoa((&DAT_0067bdc0)[local_24],&DAT_00538610,10);
        strcat(&g_OverworldWorldState,pcVar4);
        strcat(&g_OverworldWorldState,&DAT_00518eec);
      }
      val_1 = FUN_00489710(&g_OverworldWorldState,0x5a,100);
      if ((val_1 < 1) || (Gold < 200)) break;
      Gold = Gold + -200;
      *(int *)(&DAT_0067bdbc + val_1 * 4) = *(int *)(&DAT_0067bdbc + val_1 * 4) + 1;
    } while (199 < Gold);
    break;
  case 8:
    slot_idx = Util_GetRandomNumber(DAT_00523524 + -3);
    slot_idx = slot_idx + 1;
    (&DAT_00522628)[(DAT_00523524 + -1) * 0x44] = 0x10;
    *(int32_t *)(&DAT_0052262c + (DAT_00523524 + -1) * 0x44) =
         *(int32_t *)(&DAT_0052262c + slot_idx * 0x44);
    Mem_AllocOrFree_0040a4d4(&DAT_00522600 + slot_idx * 0x44,&g_OverworldWorldState,0x14);
    Mem_AllocOrFree_0040a4ac(&g_OverworldWorldState,&DAT_00522600 + (DAT_00523524 + -1) * 0x44,0x14)
    ;
    Glue_Subsystem_004ebcdc(s_x_Duelsounds_aswanjag_wav_00518ef0,0x97,100,100,0);
    Pic_Load_winbak01_0040eb5a(0x10,3);
    break;
  case 9:
    val_1 = Palette_Subsystem_00498a18();
    if (val_1 != 0) {
      loop_idx = FUN_0040eab1();
    }
    break;
  case 10:
    val_1 = Util_GetRandomNumber(2);
    if ((val_1 == 0) && (0x7f < DAT_0052f004)) {
      strcpy(&g_OverworldWorldState,s_Thieves_take_half_your_amulets__00518f48);
      for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
        (&DAT_0067bdc0)[local_24] = ((&DAT_0067bdc0)[local_24] + 1) / 2;
      }
      loop_idx = FUN_0040eab1();
    }
    else {
      Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_00518f0c,0xf,100,100,0);
      strcpy(&g_OverworldWorldState,s_You_find_an_amulet_of_each_color_00518f24);
      for (local_24 = 0; local_24 < 5; local_24 = local_24 + 1) {
        (&DAT_0067bdc0)[local_24] = (&DAT_0067bdc0)[local_24] + 1;
      }
      loop_idx = 0xffffffff;
    }
    FUN_00489710(&g_OverworldWorldState,0x5a,100);
    break;
  case 0xb:
    local_2c = 0;
    do {
      val_1 = Util_GetRandomNumber(5);
      if ((&DAT_0067bdc0)[val_1] != 0) break;
      local_2c = local_2c + 1;
    } while ((int)local_2c < 99);
    if ((&DAT_0067bdc0)[val_1] != 0) {
      strcpy(&g_OverworldWorldState,s_For_one_00518f6c);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(val_1 + 1);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_amulet_I_will_reveal_the_deck_of_00518f78);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_creature__Never_mind__See_a_deck_00518fa0);
      val_2 = FUN_00489710(&g_OverworldWorldState,0x5a,100);
      if (val_2 == 1) {
        (&DAT_0067bdc0)[val_1] = (&DAT_0067bdc0)[val_1] + -1;
        UI_PromptDeckInspection((uint8_t)arg_1);
      }
    }
    break;
  case 0xc:
    strcpy(&g_OverworldWorldState,s_You_may_trade_your_00518fc8);
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (*(uint32_t *)(&deck + val_1 * 4) & 0xfff) * 0x34);
    strcat(&g_OverworldWorldState,s_for_a_five_extra_life_in_the_nex_00518fdc);
    val_2 = FUN_00489710(&g_OverworldWorldState,100,100);
    if (val_2 == 1) {
      Pic_Subsystem_00452065(val_1);
      g_AiManaColorCost_Blue = 5;
    }
    break;
  case 0xd:
    do {
      val_1 = Bazaar_TradeCardDialogue(0,-1);
    } while (val_1 != 0);
    FUN_0040a566();
  }
switchD_0040e766_default:
  if (loop_idx != 0xffffffff) {
    if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 2) == 0) {
      if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 0x40) == 0) {
        if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 4) == 0) {
          if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 0x10) == 0) {
            if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 0x20) == 0) {
              if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 8) == 0) {
                if (((&g_MasterCardColorTable)[loop_idx * 0x34] & 1) == 0) {
                  Glue_Subsystem_004ebcdc(s_x_sound_treasure_wav_00519158,0xf,100,100,0);
                }
                else {
                  switch((&g_MasterCardColorTable)[loop_idx * 0x34]) {
                  case 2:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_black_wav_005190c8,0xf,100,100,0);
                    break;
                  default:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_grey_wav_00519140,0xf,100,100,0);
                    break;
                  case 4:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_blue_wav_005190e0,0xf,100,100,0);
                    break;
                  case 8:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_green_wav_005190f8,0xf,100,100,0);
                    break;
                  case 0x10:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_red_wav_00519110,0xf,100,100,0);
                    break;
                  case 0x20:
                    Glue_Subsystem_004ebcdc(s_x_DuelSounds_white_wav_00519128,0xf,100,100,0);
                  }
                }
              }
              else {
                Glue_Subsystem_004ebcdc(s_x_DuelSounds_sorcery_wav_005190ac,0xf,100,100,0);
              }
            }
            else {
              Glue_Subsystem_004ebcdc(s_x_DuelSounds_interupt_wav_00519090,0xf,100,100,0);
            }
          }
          else {
            Glue_Subsystem_004ebcdc(s_x_DuelSounds_instant_wav_00519074,0xf,100,100,0);
          }
        }
        else {
          Glue_Subsystem_004ebcdc(s_x_DuelSounds_enchant_wav_00519058,0xf,100,100,0);
        }
      }
      else {
        Glue_Subsystem_004ebcdc(s_x_DuelSounds_artifact_wav_0051903c,0xf,100,100,0);
      }
    }
    else {
      Glue_Subsystem_004ebcdc(s_x_DuelSounds_summon_wav_00519024,0xf,100,100,0);
    }
    Ai_Subsystem_004cc50a(loop_idx,0xd0,s_Found_this_card__00519170);
    val_1 = Pic_Subsystem_00451e40(loop_idx);
    if (val_1 != -1) {
      *(uint32_t *)(&deck + val_1 * 4) = *(uint32_t *)(&deck + val_1 * 4) | 0x4000;
    }
    Ai_Subsystem_004cd1d1();
  }
  return;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0041ed86
 * Entry Point: 0041ed86
 * Size: 78 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_0041ed86(int player_id)

{
  FUN_0040a3e1();
  if (DAT_00640f08 == 0) {
    DAT_00640f08 = *(int *)(arg_1 + 0x2c);
  }
  g_MouseCursorButtonState = 0;
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0051a060,0xf,100,100,0);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0041fe70
 * Entry Point: 0041fe70
 * Size: 59 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_0041fe70(int32_t arg1,int arg2)

{
  if (arg2 == 2) {
    Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0051a424,0xf,100,100,0);
    DAT_005387b0 = 0xe;
  }
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_004212b4
 * Entry Point: 004212b4
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_004212b4(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0051a4a4,0xf,100,100,0);
  DAT_005387b0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_00421655
 * Entry Point: 00421655
 * Size: 144 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_00421655(int player_id)

{
  uint32_t uval_1;
  
  uval_1 = *(int *)(arg_1 + 0x2c) - 0xf;
  if (((*(int *)(arg_1 + 0x2c) < 0xf) || ((int)uval_1 < 2)) || ((uval_1 & 1) != 0)) {
    Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0051ac88,0xf,100,100,0);
  }
  else {
    Glue_Subsystem_004ebcdc
              ((&PTR_s_x_sound_blackwm_wav_00519fe0)[(*(int *)(arg_1 + 0x2c) + -0x11) / 2],0xf,100,
               100,0);
  }
  DAT_00538a28 = *(int32_t *)(arg_1 + 0x2c);
  return *(int32_t *)(arg_1 + 0x2c);
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0048ec68
 * Entry Point: 0048ec68
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_0048ec68(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00528534,0xf,100,100,0);
  DAT_0054aae0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_0048f343
 * Entry Point: 0048f343
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_0048f343(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00528548,0xf,100,100,0);
  DAT_0054aae0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_00490c01
 * Entry Point: 00490c01
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_00490c01(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00528628,0xf,100,100,0);
  DAT_0054aae0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_00490d49
 * Entry Point: 00490d49
 * Size: 50 bytes
 */


int32_t Sound_LoadWav_x_sound_button2_00490d49(int player_id)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_0052863c,0xf,100,100,0);
  DAT_0054aae0 = *(int32_t *)(arg_1 + 0x2c);
  return 0;
}

/*
 * Decompiled function: Sound_LoadWav_x_sound_button2_00507b1a
 * Entry Point: 00507b1a
 * Size: 42 bytes
 */


void Sound_LoadWav_x_sound_button2_00507b1a(void)

{
  Glue_Subsystem_004ebcdc(s_x_sound_button2_wav_00531f30,0xf,100,100,0);
  DAT_006265fc = 0xffffffff;
  return;
}

