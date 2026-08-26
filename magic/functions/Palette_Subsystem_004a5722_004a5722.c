/*
 * Decompiled function: Palette_Subsystem_004a5722
 * Entry Point: 004a5722
 * Size: 1834 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Palette_Subsystem_004a5722(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int iVar2;
  undefined4 arg_2_00;
  int iVar3;
  uint width;
  int arg_4;
  char *str_5;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  LPVOID local_c;
  int local_8;
  
  for (local_14 = 0; local_14 < 500; local_14 = local_14 + 1) {
    local_10 = *(uint *)(&deck + local_14 * 4) & 0xfff;
    if ((((&DAT_0067f014)[arg_1 * 0x30] & 0x80) != 0) &&
       (_DAT_0063ee14 = 0, ((&g_MasterCardColorTable)[local_10 * 0x34] & 0x30) != 0)) {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
    if ((((&DAT_0067f014)[arg_1 * 0x30] & 0x40) != 0) &&
       (_DAT_0063ee14 = 0, ((&g_MasterCardColorTable)[local_10 * 0x34] & 0x40) != 0)) {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
    if ((((&DAT_0067f014)[arg_1 * 0x30] & 0x10) != 0) &&
       (_DAT_0063ee14 = 0,
       1 << ((&DAT_0067f00c)[arg_1 * 0x30] & 0x1f) == (int)(char)(&DAT_0051aebe)[local_10 * 0x34]))
    {
      *(uint *)(&deck + local_14 * 4) = *(uint *)(&deck + local_14 * 4) | 0x8000;
    }
  }
  DAT_006b2d64 = (int)(char)(&DAT_0067f00c)[arg_1 * 0x30];
  if (*(int *)(&DAT_0067effc + arg_1 * 0x30) != -1) {
    DAT_0068a64c = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_1 * 0x30));
  }
  local_c = *(LPVOID *)(&DAT_0054ba00 + arg_2 * 4);
  DAT_00695df0 = (int)(char)(&DAT_00522629)[(int)local_c * 0x44];
  DAT_0063ee24 = 0;
  if (arg_2 != 4) {
    _g_PlayerLifeTotals = 0x10;
  }
  if (arg_1 < 5) {
    DAT_00695df0 = 2;
    local_18 = arg_2 + DAT_0067f380 + -3;
    if (-1 < local_18) {
      cVar1 = (&DAT_0067f00c)[arg_1 * 0x30];
      iVar2 = FUN_0040a305(local_18,0,2);
      DAT_006b2fe0 = Pic_Subsystem_0045268f
                               (*(int *)(&DAT_00527f10 + (cVar1 * 3 + -3) * 4 + iVar2 * 4));
    }
  }
  iVar2 = -1;
  width = 0;
  arg_2_00 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_c * 0x44));
  FUN_004909d3((int)local_c,arg_2_00,width,iVar2);
  Adventure_Audio_PlayEffect(s_x_sound_dngnduel_wav_0052c528,0xf,100,100,0);
  if (arg_1 < 5) {
    strcpy(&g_OverworldWorldState,s_Exploring_the_Castle____0052c540);
  }
  else {
    strcpy(&g_OverworldWorldState,s_Exploring_the_Dungeon____0052c55c);
  }
  strcat(&g_OverworldWorldState,s_you_encounter_0052c578);
  Adventure_FormatNewsString((int)local_c,1,0);
  strcat(&g_OverworldWorldState,&DAT_0052c588);
  if (DAT_006b2fe0 != -1) {
    cVar1 = (&DAT_0067f00c)[arg_1 * 0x30];
    iVar2 = FUN_0040a305(local_18,0,2);
    local_18 = *(int *)(&DAT_00527f10 + (cVar1 * 3 + -3) * 4 + iVar2 * 4);
    strcat(&g_OverworldWorldState,&DAT_0052c58c);
    Adventure_FormatNewsString((int)local_c,0,0);
    strcat(&g_OverworldWorldState,s_has_a_0052c590);
    iVar2 = Pic_Subsystem_0045268f(local_18);
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
    strcat(&g_OverworldWorldState,&DAT_0052c598);
  }
  if (DAT_0068a64c != -1) {
    strcat(&g_OverworldWorldState,&DAT_0052c59c);
    iVar2 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_1 * 0x30));
    strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar2 * 0x34);
    strcat(&g_OverworldWorldState,s_starts_in_play__0052c5a0);
  }
  FUN_004896be(&g_OverworldWorldState,100,0x50);
  for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
    (&DAT_006b2dd0)[local_18] = 0xffffffff;
    (&DAT_006b2d90)[local_18] = (&DAT_006b2dd0)[local_18];
  }
  Adventure_ShowDefeatScreen();
  do {
    do {
      local_18 = FUN_0040a1d2(500);
    } while (*(int *)(&deck + local_18 * 4) == -1);
  } while ((((&DAT_00702151)[local_18 * 4] & 0x40) != 0) ||
          ((*(uint *)(&deck + local_18 * 4) & 0xfff) < 5));
  DAT_006b2d90 = *(uint *)(&deck + local_18 * 4) & 0xfff;
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    DAT_00522454 = -1;
  }
  g_PlayerCreatureCount = Minit_Subsystem_00452827();
  iVar2 = Minit_Subsystem_00452827();
  g_PlayerCreatureCount = iVar2 + DAT_00627a7c;
  g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_006498fc;
  if ((0 < DAT_00522454) && (DAT_00522454 < 6)) {
    g_PlayerCreatureCount = g_PlayerCreatureCount + DAT_00522454;
  }
  DAT_00627868 = g_PlayerCreatureCount;
  if (arg_3 == 0) {
    Pic_Subsystem_00423c82(100);
  }
  else {
    Pic_Subsystem_00423c82(100);
    do {
      Pic_Subsystem_00424020(100,&local_1c);
    } while (local_1c == 1);
    Pic_Subsystem_00423b93(100);
  }
  local_8 = Pic_Load_0044ef70(0xffffffff,local_c);
  LoadPalNoPic(s_advfac64_pic_0052c5b4);
  FUN_005115a0(0,(short)DAT_00530d9c);
  if ((local_8 != 1) && (local_8 == 0)) {
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      if ((&DAT_006b2d90)[local_14] != -1) {
        strcpy(&g_OverworldWorldState,s_Lost_this_card_0052c5c4);
        Mem_AllocOrFree_00510e20(1,s_losedul2_pic_0052c5d4);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
        str_5 = &g_OverworldWorldState;
        arg_4 = 1;
        iVar2 = Ai_Util_004c3bc4(10);
        iVar2 = FUN_0040a1d2(iVar2);
        iVar2 = iVar2 + 0x50;
        iVar3 = Ai_Util_004c3bc4(10);
        iVar3 = FUN_0040a1d2(iVar3);
        FUN_0050b206(DAT_006b2d90,iVar3 + local_14 * 0x62 + 0x21,iVar2,arg_4,str_5);
        FUN_0040a3e1();
        Ai_Subsystem_004cd1d1();
        FUN_00489630((&DAT_006b2d90)[local_14]);
      }
    }
  }
  if (((&DAT_0067f014)[arg_1 * 0x30] & 1) != 0) {
    DAT_006498fc = DAT_006498fc + (g_PlayerCreatureCount - DAT_00627868);
    DAT_00627a7c = 0;
  }
  if (((&DAT_0067f014)[arg_1 * 0x30] & 2) != 0) {
    DAT_00627a7c = 0;
    DAT_006498fc = 0;
  }
  DAT_00522454 = 0xffffffff;
  if (arg_3 == 0) {
    Adventure_Audio_SetPlaybackPosition(s_x_sound_dambloop_wav_0052c5e4,100);
    Adventure_Audio_PlayEffectLooped(100,0x50,0);
    Pic_Subsystem_00423f10(100,1);
  }
  return local_8;
}


