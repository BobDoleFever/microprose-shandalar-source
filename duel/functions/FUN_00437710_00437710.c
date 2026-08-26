/*
 * Decompiled function: FUN_00437710
 * Entry Point: 00437710
 * Size: 1013 bytes
 */
#include "duel.h"


undefined4 FUN_00437710(char *param_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined1 local_118 [264];
  undefined4 local_10;
  HDC local_c;
  int local_8;
  
  local_10 = 1;
  FUN_0047076e(&DAT_005f76e0);
  __chdir(&DAT_005f76e0);
  FUN_004d9630(&DAT_00664a60,&DAT_005f76e0);
  FUN_004d9640(&DAT_00664a60,s__PlayDeck_004f6a98);
  FUN_004d9630(&DAT_00617470,&DAT_005f76e0);
  FUN_004d9640(&DAT_00617470,s__Faces_004f6aa4);
  FUN_004d9630(&DAT_005f7800,&DAT_005f76e0);
  FUN_004d9640(&DAT_005f7800,s__CardArt_004f6aac);
  FUN_004d9630(&DAT_006189a0,&DAT_005f76e0);
  FUN_004d9640(&DAT_006189a0,s__DuelArt_004f6ab8);
  FUN_004d9630(&DAT_0060d4a0,&DAT_005f76e0);
  FUN_004d9640(&DAT_0060d4a0,s__DuelSounds_004f6ac4);
  FUN_004d9630(&DAT_00664c40,&DAT_006189a0);
  FUN_004d9640(&DAT_00664c40,s__Duel_dat_004f6ad0);
  FUN_004d9630(&DAT_00615350,&DAT_005f76e0);
  FUN_004d9640(&DAT_00615350,s__SaveGame_004f6adc);
  FID_conflict___mkdir(&DAT_00615350);
  FUN_004d9630(local_118,&DAT_005f76e0);
  FUN_004d9640(local_118,s__CARDS_DAT_004f6ae8);
  DAT_0061743c = FUN_0043c4d0(local_118);
  if (DAT_0061743c == 0) {
    local_10 = 0;
    puVar9 = local_118;
    pcVar7 = s_Couldn_t_find_raw_card_data_file_004f6af4;
    sVar1 = _strlen(param_1);
    _sprintf(param_1 + sVar1,pcVar7,puVar9);
  }
  FUN_004d9630(local_118,&DAT_005f76e0);
  FUN_004d9640(local_118,s__LEGACY_CSV_004f6b1c);
  iVar2 = FUN_0043ce77(local_118);
  if (iVar2 == 0) {
    local_10 = 0;
    puVar9 = local_118;
    pcVar7 = s_Couldn_t_find_raw_special_card_d_004f6b28;
    sVar1 = _strlen(param_1);
    _sprintf(param_1 + sVar1,pcVar7,puVar9);
  }
  FUN_004b8bf0();
  local_c = GetDC((HWND)0x0);
  if (local_c == (HDC)0x0) {
    local_10 = 0;
    FUN_004d9640(param_1,s_Not_enough_system_resources_to_d_004f6b88);
  }
  else {
    iVar2 = GetDeviceCaps(local_c,0xc);
    iVar3 = GetDeviceCaps(local_c,0xe);
    DAT_00664c30 = iVar2 * iVar3;
    ReleaseDC((HWND)0x0,local_c);
  }
  iVar2 = FUN_00471426();
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640(param_1,s_Couldn_t_create_the_palette_004f6bc8);
  }
  puVar10 = &DAT_0061897c;
  puVar8 = &DAT_00664db0;
  puVar6 = &DAT_00664c00;
  puVar5 = &DAT_00617440;
  puVar4 = &DAT_0060157c;
  iVar2 = GetSystemMetrics(1);
  iVar3 = GetSystemMetrics(0);
  iVar2 = FUN_004707f3(iVar3,iVar2,puVar4,puVar5,puVar6,puVar8,puVar10);
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640(param_1,s_Couldn_t_create_the_app_wide_mem_004f6be8);
  }
  iVar2 = FUN_0041eb80();
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640(param_1,s_Couldn_t_initialize_for_card_dra_004f6c1c);
  }
  iVar2 = FUN_004706d0();
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640(param_1,s_Couldn_t_initialize_for_utility_d_004f6c44);
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00664870 + local_8 * 0x18) = 0;
  }
  DAT_005f76d4 = 0;
  for (local_8 = 0; local_8 < 2000; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0060d5b0 + local_8 * 0x10) = 0;
  }
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00616a10 + local_8 * 0x18) = 0;
  }
  DAT_00663df8 = 0;
  FUN_004520a8();
  return local_10;
}


