/*
 * Decompiled function: Action_PromptTarget_0049239e
 * Entry Point: 0049239e
 * Size: 2323 bytes
 */
#include "magic.h"


void Action_PromptTarget_0049239e(int spell_id)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 local_98;
  char local_90 [100];
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  LPVOID local_14;
  uint auStack_10 [3];
  
  local_24 = (int)(char)(&DAT_0067f00c)[spell_id * 0x30];
  FUN_0040b3c2(2,(*(int *)(&DAT_005283a0 + spell_id * 4) + 1) * 7 | 0x80);
  Adventure_Map_UpdateLightingAndPalette(1,(int)(char)(&DAT_0067f00c)[spell_id * 0x30]);
  LoadPalNoPic(s_advfac64_pic_005286e8);
  Mem_AllocOrFree_00510e20(1,s_tradscrn_pic_005286f8);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Adventure_Audio_PlayCastleVictory(spell_id + 1);
  strcpy(&g_OverworldWorldState,s_You_have_defeated_the_dreaded_00528708);
  pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_24);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_wizard__No_longer_shall_00528728);
  strcat(&g_OverworldWorldState,
         &DAT_00528744 + ((*(int *)(&DAT_00528384 + local_24 * 4) != 0) - 1 & 8));
  strcat(&g_OverworldWorldState,s_evil_creatures_oppress_00528754);
  strcat(&g_OverworldWorldState,s_the_good_people_of_Shandalar__0052876c);
  for (local_1c = 0; (int)local_1c < 0x80; local_1c = local_1c + 1) {
    if ((*(uint *)(&DAT_0067be00 + local_1c * 100) & 0xff00) == local_24 << 8) {
      *(uint *)(&DAT_0067be00 + local_1c * 100) =
           *(uint *)(&DAT_0067be00 + local_1c * 100) & 0xffff00ff;
      Ai_TownEncounter_004c3b19(local_1c);
      strcat(&g_OverworldWorldState,s_freed__0052878c);
    }
  }
  FUN_0040d469((int)g_DisplaySurfaceScreen,0xfe,0x140,0x72);
  DAT_0067bdb4 = DAT_0067bdb4 | 1 << ((byte)local_24 & 0x1f);
  local_18 = Duel_GetCardDrawOriginX
                       (*(int *)(&DAT_0067f000 + spell_id * 0x30),
                        *(int *)(&DAT_0067f004 + spell_id * 0x30));
  *(undefined4 *)(&DAT_0067bdf0 + local_18 * 100) = 5;
  for (local_1c = 0; (int)local_1c < 8; local_1c = local_1c + 1) {
    if (*(int *)(&DAT_0067f2dc + local_1c * 0x14) == local_24) {
      FUN_0046e70d(local_1c,local_1c + 8);
      *(undefined4 *)(&DAT_0067f2d0 + local_1c * 0x14) = 0xffffffff;
    }
  }
  local_2c = 1;
  strcpy(&g_OverworldWorldState,s_You_may_take_any_three_different_00528798);
  pcVar1 = (char *)Mem_AllocOrFree_00473d7e(local_24);
  strcat(&g_OverworldWorldState,pcVar1);
  strcat(&g_OverworldWorldState,s_cards__005287bc);
  FUN_0040d469((int)g_DisplaySurfaceScreen,0xfe,0x140,200);
  FUN_0040a3e1();
  Ai_Subsystem_004cd1d1();
  PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
  iVar2 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar2);
  Adventure_ReloadWorldPalette(1);
  DAT_0067bdb4 = DAT_0067bdb4 & ~(1 << ((byte)local_24 & 0x1f));
  local_1c = 0;
  do {
    if (2 < (int)local_1c) {
      for (local_1c = 0; (int)local_1c < 3; local_1c = local_1c + 1) {
        *(uint *)(&DAT_0051aed0 + auStack_10[local_1c] * 0x34) =
             *(uint *)(&DAT_0051aed0 + auStack_10[local_1c] * 0x34) & 0xfffffeff;
      }
      FUN_0041f391();
      DAT_0067bdb4 = DAT_0067bdb4 | 1 << ((byte)local_24 & 0x1f);
      PTR_FUN_00527b3c = FUN_0048a3cc;
      if (DAT_0067bdb4 != 0x3e) {
        Pic_Subsystem_00423c82(0x10);
      }
      FUN_005112b0(0,(short)DAT_00530d9c);
      if (DAT_0067bdb4 != 0x3e) {
        return;
      }
      FUN_00501736(0x3c);
      Mem_AllocOrFree_00510de0(1,s_5thwiz_pic_0052880c);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      strcpy(&g_OverworldWorldState,s_You_have_defeated_all_five_wizar_00528818);
      strcat(&g_OverworldWorldState,s_Shandalar_is_free__Prepare_to_fa_00528840);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
      FUN_0040d469((int)g_DisplaySurfaceScreen,99,0x140,0x100);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      local_20 = FUN_004922dc();
      strcpy(&g_OverworldWorldState,s_Your_battles_so_far_will_banish_t_0052887c);
      iVar2 = local_20;
      if (local_20 < 1) {
        iVar2 = 0;
      }
      pcVar1 = _itoa(iVar2,&DAT_0054aae8,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_years__Each_life_it_loses_in_the_005288c0);
      strcat(&g_OverworldWorldState,s_will_banish_it_for_10_additional_005288f0);
      FUN_0040d469((int)g_DisplaySurfaceScreen,99,0x140,0x15e);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)DAT_00530d9c);
      DeckBuilderMain(_hwndScreen,1,1);
      Pic_Load_advfac64_0040a4fc();
      local_14 = (LPVOID)Adventure_CheckMonsterEncounter(0,100);
      (&DAT_00522628)[(int)local_14 * 0x44] =
           (&DAT_00522628)[(int)local_14 * 0x44] * ((char)DAT_0067f380 + '\x01');
      FUN_004909d3((int)local_14,0,0,-1);
      DAT_006b2d64 = local_24;
      DAT_0063ee24 = 0;
      DAT_00695df0 = 3;
      DAT_00627a7c = 0;
      Pic_Subsystem_00423c82(0x10);
      DAT_006b2fe0 = Pic_Subsystem_0045268f(0x11);
      DAT_0068a64c = Pic_Subsystem_0045268f(0x1d);
      Pic_Load_0044ef70(0,local_14);
      FUN_0040b3c2(2,0xb7);
      FUN_005112b0(0,(short)DAT_00530d9c);
      FUN_0050d560(0,0);
      LoadPalNoPic(s_advfac64_pic_00528924);
      FUN_00409e6d(s_mtgend_avi_00528934,(DAT_00522458 + -0x230) / 2,(DAT_0052245c + -0x1a4) / 2,0);
      SetForegroundWindow(_hwndScreen);
      BringWindowToTop(_hwndScreen);
      SetFocus(_hwndScreen);
      LoadPalNoPic(s_advfac64_pic_00528940);
      Catalog_LoadPaletteMap(s_todpal_tr_00528950,(char *)0x0);
      SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
      RealizePalette(*(HDC *)(DAT_0070a850 + 4));
      Adventure_Audio_PlayCastleVictory(6);
      local_20 = local_20 + (100 - DAT_006a4a04) * 10;
      LoadPalNoPic(s_wingame_pic_0052895c);
      if (DAT_00522458 == 0x280) {
        local_98 = 3;
      }
      else if (DAT_00522458 == 800) {
        local_98 = 4;
      }
      else {
        local_98 = 6;
      }
      FUN_0040adaf(s_wingame_pic_00528968,local_98,local_98);
      strcpy(&g_OverworldWorldState,s_You_have_protected_the_plane_of_S_00528974);
      pcVar1 = _itoa(local_20,&DAT_0054aae8,10);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,s_years__005289ac);
      strcat(&g_OverworldWorldState,s_The_people_rejoice__Life_is_good_005289b8);
      FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd8,0x140,0x81);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
      FUN_005112b0(0,(short)DAT_00530d9c);
      LoadPalNoPic(s_advfac64_pic_005289dc);
      Palette_Subsystem_004a5fdc();
      Castle_Process_00421b32();
      DAT_006fe3f0 = 1;
      FUN_00409db6();
      Palette_Util_00496d20();
                    /* WARNING: Subroutine does not return */
      exit(0xff);
    }
    sprintf(local_90,s_Pick_a_card____d_left_005287c8,3 - local_1c);
    local_28 = Palette_Color_0049716e(local_90,1 << ((byte)local_24 & 0x1f),0xffffffff,local_2c,0);
    if (local_28 == 0xffffffff) {
      local_1c = local_1c + -1;
LAB_004927e6:
      FUN_00501736(0xf);
    }
    else {
      strcpy(&g_OverworldWorldState,s_Will_you_take_this_card____Yes_N_005287e0);
      do {
        iVar2 = Ai_Util_004c3bc4(0x15c);
        iVar2 = iVar2 + 10;
        iVar3 = Ai_Util_004c3bc4(0xf4);
        iVar2 = FUN_00489710(&g_OverworldWorldState,iVar3 + 10,iVar2);
      } while (iVar2 < 0);
      if (iVar2 == 0) {
        local_18 = Pic_Subsystem_00451e40(local_28);
        if (local_18 != -1) {
          *(uint *)(&deck + local_18 * 4) = *(uint *)(&deck + local_18 * 4) | 0x4000;
        }
        auStack_10[local_1c] = local_28;
        *(uint *)(&DAT_0051aed0 + local_28 * 0x34) =
             *(uint *)(&DAT_0051aed0 + local_28 * 0x34) | 0x100;
        goto LAB_004927e6;
      }
      local_1c = local_1c + -1;
    }
    local_1c = local_1c + 1;
  } while( true );
}


