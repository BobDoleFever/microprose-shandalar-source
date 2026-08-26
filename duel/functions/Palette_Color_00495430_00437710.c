/*
 * Decompiled function: Palette_Color_00495430
 * Entry Point: 00437710
 * Size: 1013 bytes
 */
#include "duel.h"


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
  uint *puVar5;
  int *arg_7;
  uint local_118 [66];
  undefined4 local_10;
  HDC local_c;
  int local_8;
  
  local_10 = 1;
  FUN_0047076e(&DAT_005f76e0);
  __chdir(&DAT_005f76e0);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00664a60,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_00664a60,(uint *)s__PlayDeck_004f6a98);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00617470,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_00617470,(uint *)s__Faces_004f6aa4);
  Mem_AllocOrFree_004d9630((uint *)&DAT_005f7800,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_005f7800,(uint *)s__CardArt_004f6aac);
  Mem_AllocOrFree_004d9630((uint *)&DAT_006189a0,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_006189a0,(uint *)s__DuelArt_004f6ab8);
  Mem_AllocOrFree_004d9630((uint *)&DAT_0060d4a0,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_0060d4a0,(uint *)s__DuelSounds_004f6ac4);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00664c40,(uint *)&DAT_006189a0);
  FUN_004d9640((uint *)&DAT_00664c40,(uint *)s__Duel_dat_004f6ad0);
  Mem_AllocOrFree_004d9630((uint *)&DAT_00615350,(uint *)&DAT_005f76e0);
  FUN_004d9640((uint *)&DAT_00615350,(uint *)s__SaveGame_004f6adc);
  FID_conflict___mkdir(&DAT_00615350);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__CARDS_DAT_004f6ae8);
  DAT_0061743c = Ai_CalcManaRequirement_004b9284((char *)local_118);
  if (DAT_0061743c == 0) {
    local_10 = 0;
    puVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_card_data_file_004f6af4;
    sVar1 = _strlen(str_1);
    _sprintf(str_1 + sVar1,pcVar4,puVar5);
  }
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__LEGACY_CSV_004f6b1c);
  iVar2 = FUN_0043ce77((LPCSTR)local_118);
  if (iVar2 == 0) {
    local_10 = 0;
    puVar5 = local_118;
    pcVar4 = s_Couldn_t_find_raw_special_card_d_004f6b28;
    sVar1 = _strlen(str_1);
    _sprintf(str_1 + sVar1,pcVar4,puVar5);
  }
  FUN_004b8bf0();
  local_c = GetDC((HWND)0x0);
  if (local_c == (HDC)0x0) {
    local_10 = 0;
    FUN_004d9640((uint *)str_1,(uint *)s_Not_enough_system_resources_to_d_004f6b88);
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
    FUN_004d9640((uint *)str_1,(uint *)s_Couldn_t_create_the_palette_004f6bc8);
  }
  arg_7 = &DAT_0061897c;
  arg_6 = (undefined4 *)&DAT_00664db0;
  arg_5 = &DAT_00664c00;
  arg_4 = (BITMAPINFO *)&DAT_00617440;
  arg_3 = &DAT_0060157c;
  iVar2 = GetSystemMetrics(1);
  iVar3 = GetSystemMetrics(0);
  iVar2 = FUN_004707f3(iVar3,iVar2,arg_3,arg_4,arg_5,arg_6,arg_7);
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640((uint *)str_1,(uint *)s_Couldn_t_create_the_app_wide_mem_004f6be8);
  }
  iVar2 = Palette_Color_0049ae00();
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640((uint *)str_1,(uint *)s_Couldn_t_initialize_for_card_dra_004f6c1c);
  }
  iVar2 = FUN_004706d0();
  if (iVar2 == 0) {
    local_10 = 0;
    FUN_004d9640((uint *)str_1,(uint *)s_Couldn_t_initialize_for_utility_d_004f6c44);
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
  Glue_Timer_004cd63b();
  return local_10;
}


