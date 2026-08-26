/*
 * Decompiled function: Palette_Color_00495430
 * Entry Point: 00495430
 * Size: 1017 bytes
 */
#include "magic.h"


undefined4 Palette_Color_00495430(char *str_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined4 *arg_3;
  BITMAPINFO *arg_4;
  undefined4 *arg_5;
  char *pcVar4;
  undefined4 *arg_6;
  char *pcVar5;
  int *arg_7;
  char local_118 [264];
  undefined4 local_10;
  HDC local_c;
  int local_8;
  
  local_10 = 1;
  FUN_004f391e(&DAT_006807a0);
  _chdir(&DAT_006807a0);
  strcpy(&DAT_006ff1b0,&DAT_006807a0);
  strcat(&DAT_006ff1b0,s__PlayDeck_0052b030);
  strcpy(&DAT_006a4a50,&DAT_006807a0);
  strcat(&DAT_006a4a50,s__Faces_0052b03c);
  strcpy(&DAT_006808d0,&DAT_006807a0);
  strcat(&DAT_006808d0,s__CardArt_0052b044);
  strcpy(&DAT_006b2e90,&DAT_006807a0);
  strcat(&DAT_006b2e90,s__DuelArt_0052b050);
  strcpy(&DAT_00696910,&DAT_006807a0);
  strcat(&DAT_00696910,s__DuelSounds_0052b05c);
  strcpy(&DAT_006ff570,&DAT_006b2e90);
  strcat(&DAT_006ff570,s__Duel_dat_0052b068);
  strcpy(&DAT_006a28c0,&DAT_006807a0);
  strcat(&DAT_006a28c0,s__SaveGame_0052b074);
  _mkdir(&DAT_006a28c0);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__CARDS_DAT_0052b080);
  DAT_006a49f4 = FUN_004f6180(local_118);
  if (DAT_006a49f4 == 0) {
    local_10 = 0;
    pcVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_card_data_file_0052b08c;
    sVar1 = strlen(str_1);
    sprintf(str_1 + sVar1,pcVar4,pcVar5);
  }
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__LEGACY_CSV_0052b0b4);
  iVar2 = FUN_004f6b33(local_118);
  if (iVar2 == 0) {
    local_10 = 0;
    pcVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_special_card_d_0052b0c0;
    sVar1 = strlen(str_1);
    sprintf(str_1 + sVar1,pcVar4,pcVar5);
  }
  Palette_Subsystem_004966a0();
  local_c = GetDC((HWND)0x0);
  if (local_c == (HDC)0x0) {
    local_10 = 0;
    strcat(str_1,s_Not_enough_system_resources_to_d_0052b120);
  }
  else {
    iVar2 = GetDeviceCaps(local_c,0xc);
    iVar3 = GetDeviceCaps(local_c,0xe);
    DAT_006ff554 = iVar2 * iVar3;
    ReleaseDC((HWND)0x0,local_c);
  }
  iVar2 = FUN_004f45da();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_create_the_palette_0052b160);
  }
  arg_7 = &DAT_006b2e1c;
  arg_6 = (undefined4 *)&DAT_007006dc;
  arg_5 = &DAT_006ff384;
  arg_4 = (BITMAPINFO *)&DAT_006a4a20;
  arg_3 = &g_HdcBackBuffer;
  iVar2 = GetSystemMetrics(1);
  iVar3 = GetSystemMetrics(0);
  iVar2 = FUN_004f39a4(iVar3,iVar2,arg_3,arg_4,arg_5,arg_6,arg_7);
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_create_the_app_wide_mem_0052b180);
  }
  iVar2 = Palette_Color_0049ae00();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_initialize_for_card_dra_0052b1b4);
  }
  iVar2 = FUN_004f3880();
  if (iVar2 == 0) {
    local_10 = 0;
    strcat(str_1,s_Couldn_t_initialize_for_utility_d_0052b1dc);
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006fefb0 + local_8 * 0x18) = 0;
  }
  DAT_00680778 = 0;
  for (local_8 = 0; local_8 < 2000; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00696a20 + local_8 * 0x10) = 0;
  }
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_006a3f80 + local_8 * 0x18) = 0;
  }
  DAT_006fe404 = 0;
  Timer_InitVxD();
  return local_10;
}


