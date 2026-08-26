/*
 * Decompiled function: Castle_Process_0046c8b0
 * Entry Point: 0046c8b0
 * Size: 2686 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Castle_Process_0046c8b0(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int local_fdc;
  undefined4 local_fd8 [200];
  int local_cb8;
  undefined4 local_cb4 [200];
  int local_994;
  int local_990;
  int local_98c;
  undefined4 local_988 [13];
  undefined1 auStack_954 [748];
  int local_668;
  int local_664;
  int local_660;
  undefined4 local_65c [200];
  int local_33c;
  undefined4 local_338 [201];
  int local_14;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_0050fc00();
  Mem_AllocOrFree_00510e20(1,s_endtop_pic_005250b0);
  DAT_00678514 = Sprite_EncodeFromSurface(1,0,0,0x95,0x13);
  FUN_0050fc20();
  Sprite_LoadAll((undefined4 *)&DAT_00677f44,s_gsprite_spr_005250bc);
  Sprite_LoadAll(&DAT_00677e10,s_questnew_spr_005250c8);
  Sprite_LoadAll((undefined4 *)&DAT_00678500,s_compnew_spr_005250d8);
  local_33c = 0;
  Sprite_LoadAll(local_338,s_worlds_spr_005250e4);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < 0xc; local_8 = local_8 + 1) {
      *(undefined4 *)(&DAT_006782a0 + local_8 * 4 + local_c * 0x30) = local_338[local_33c];
      local_33c = local_33c + 1;
    }
  }
  for (local_8 = 0; iVar2 = local_33c, local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0067f730 + local_8 * 4) = local_338[local_33c];
    local_33c = local_33c + 1;
    *(undefined4 *)(&DAT_0067f740 + local_8 * 4) = local_338[local_33c];
    local_33c = iVar2 + 2;
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    (&DAT_00677fa0)[local_8] = local_338[local_33c];
    local_33c = local_33c + 1;
  }
  Sprite_LoadAll((undefined4 *)&DAT_00677e20,s_asprite_spr_005250f0);
  local_668 = 0;
  Sprite_LoadAll(local_65c,s_ttsprite_spr_005250fc);
  for (local_664 = 0; local_664 < 3; local_664 = local_664 + 1) {
    for (local_660 = 0; local_660 < 0x10; local_660 = local_660 + 1) {
      *(undefined4 *)(&DAT_00678560 + local_660 * 4 + local_664 * 0x40) = local_65c[local_668];
      local_668 = local_668 + 1;
    }
  }
  for (local_660 = 0; local_660 < 6; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_00677970 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; local_660 < 8; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_00677800 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  for (local_660 = 0; iVar2 = local_668, local_660 < 10; local_660 = local_660 + 1) {
    *(undefined4 *)(&DAT_0067f390 + local_660 * 4) = local_65c[local_668];
    local_668 = local_668 + 1;
  }
  DAT_00677690 = local_65c[local_668];
  local_668 = local_668 + 1;
  DAT_006784f0 = local_65c[local_668];
  local_668 = iVar2 + 2;
  _DAT_006784f4 = local_65c[local_668];
  local_668 = iVar2 + 3;
  Sprite_LoadAll(&DAT_006776a0,s_amsprite_spr_0052510c);
  uVar3 = 0x54;
  pcVar1 = (char *)FUN_0046f172(s_cstline1_spr_0052511c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677820,pcVar1,uVar3);
  uVar3 = 0x10;
  pcVar1 = (char *)FUN_0046f172(s_landtile_spr_0052512c);
  local_8 = Sprite_LoadCount(&DAT_00677650,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)FUN_0046f172(s_land_spr_0052513c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677450,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)FUN_0046f172(s_sland_spr_00525148);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00678010,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)FUN_0046f172(s_land2_spr_00525154);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_0067752c,pcVar1,uVar3);
  uVar3 = 0x37;
  pcVar1 = (char *)FUN_0046f172(s_sland2_spr_00525160);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_006780ec,pcVar1,uVar3);
  uVar3 = 0xc;
  pcVar1 = (char *)FUN_0046f172(s_roads_spr_0052516c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677350,pcVar1,uVar3);
  pcVar1 = (char *)FUN_0046f172(s_locatn01_spr_00525178);
  local_8 = Sprite_LoadAll((undefined4 *)&DAT_00677a10,pcVar1);
  pcVar1 = (char *)FUN_0046f172(s_locatn02_spr_00525188);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  pcVar1 = (char *)FUN_0046f172(s_locatn03_spr_00525198);
  local_14 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_14 = local_8 + local_14;
  local_8 = local_14;
  pcVar1 = (char *)FUN_0046f172(s_locatn04_spr_005251a8);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  _DAT_00677ff4 = *(undefined4 *)(&DAT_00677a18 + local_14 * 4);
  _DAT_00678000 = *(undefined4 *)(&DAT_00677a1c + local_14 * 4);
  _DAT_00677ff8 = *(undefined4 *)(&DAT_00677a30 + local_14 * 4);
  _DAT_00677ff0 = *(undefined4 *)(&DAT_00677a38 + local_14 * 4);
  DAT_006784f8 = *(undefined4 *)(&DAT_00677a28 + local_14 * 4);
  pcVar1 = (char *)FUN_0046f172(s_locatn05_spr_005251b8);
  local_14 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_14 = local_8 + local_14;
  local_8 = local_14;
  pcVar1 = (char *)FUN_0046f172(s_locatn06_spr_005251c8);
  iVar2 = Sprite_LoadAll((undefined4 *)(&DAT_00677a10 + local_8 * 4),pcVar1);
  local_8 = local_8 + iVar2;
  _DAT_00677ffc = *(undefined4 *)(&DAT_00677a10 + local_14 * 4);
  local_98c = 0;
  Sprite_LoadAll(local_988,s_tsprite2_spr_005251d8);
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00677620 + local_8 * 8 + local_c * 4) = local_988[local_98c];
      local_98c = local_98c + 1;
    }
  }
  memcpy(&DAT_00677f10,local_988 + local_98c,0x34);
  memcpy(&DAT_00678540,auStack_954 + local_98c * 4,0x18);
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    *(undefined4 *)(&g_OverworldFoodAmount + local_8 * 0xb4) = 0;
  }
  pcVar1 = (char *)FUN_0046f172(s_ego_f_spr_005251e8 +
                                ((*(int *)(&DAT_00525070 + DAT_006ff678 * 4) != 0) - 1 & 0xc));
  local_8 = Sprite_LoadAll(&DAT_00679370,pcVar1);
  local_990 = DAT_00679370;
  DAT_00678430 = (int)*(short *)(DAT_00679370 + 4);
  DAT_006784b0 = (int)*(short *)(DAT_00679370 + 6);
  DAT_006779d0 = (int)*(short *)(DAT_00679370 + 10);
  if (DAT_006784b0 < DAT_006779d0) {
    DAT_006779d0 = (DAT_006784b0 * 2) / 3;
  }
  pcVar1 = (char *)FUN_0046f172(s_sego_f_spr_00525200);
  local_8 = Sprite_LoadAll(&DAT_00679424,pcVar1);
  local_994 = DAT_00679424;
  DAT_00678434 = (int)*(short *)(DAT_00679424 + 4);
  DAT_006784b4 = (int)*(short *)(DAT_00679424 + 6);
  DAT_006779d4 = (int)*(short *)(DAT_00679424 + 10);
  if (DAT_006784b4 < DAT_006779d4) {
    DAT_006779d4 = (DAT_006784b4 * 2) / 3;
  }
  pcVar1 = (char *)FUN_0046f172(s_castles1_spr_0052520c);
  local_8 = Sprite_LoadAll((undefined4 *)&DAT_00678660,pcVar1);
  uVar3 = 8;
  pcVar1 = (char *)FUN_0046f172(s_castles2_spr_0052521c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00678690,pcVar1,uVar3);
  uVar3 = 0xc;
  pcVar1 = (char *)FUN_0046f172(s_locatn07_spr_0052522c);
  local_8 = Sprite_LoadCount((undefined4 *)&DAT_00677420,pcVar1,uVar3);
  local_cb8 = 0;
  Sprite_LoadAll(local_cb4,s_dbox_spr_0052523c);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 9; local_c = local_c + 1) {
      (&DAT_006781d0)[local_8 * 9 + local_c] = local_cb4[local_cb8];
      local_cb8 = local_cb8 + 1;
    }
  }
  Sprite_LoadAll((undefined4 *)&DAT_00678390,s_icons_spr_00525248);
  local_fdc = 0;
  Sprite_LoadAll(local_fd8,s_iconb_spr_00525254);
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00678260 + local_8 * 0x10) = local_fd8[local_fdc];
    *(undefined4 *)(&DAT_00678264 + local_8 * 0x10) = local_fd8[local_fdc + 1];
    local_fdc = local_fdc + 2;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00678268 + local_c * 4 + local_8 * 0x10) = local_fd8[local_fdc];
      local_fdc = local_fdc + 1;
    }
  }
  if (DAT_0052f008 == 0) {
    Sprite_LoadAll(&DAT_00677fc0,s_clocknew_spr_00525260);
    Sprite_LoadAll((undefined4 *)&DAT_00678360,s_daysnew_spr_00525270);
    Sprite_LoadAll((undefined4 *)&DAT_00677f50,s_Sunmoon_spr_0052527c);
  }
  Mem_AllocOrFree_00510e20(1,s_tips_pic_00525288);
  Mem_AllocOrFree_0050fc00();
  if (DAT_00522458 == 0x280) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,1,5,0x10);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,1,3,2);
  }
  else if (DAT_00522458 == 800) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,0x1d,6,0x14);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,0x1d,5,3);
  }
  else if (DAT_00522458 == 0x400) {
    DAT_00677fb0 = Sprite_EncodeFromSurface(1,1,0x39,8,0x1b);
    DAT_00677fe4 = Sprite_EncodeFromSurface(1,10,0x39,6,9);
  }
  FUN_0050fc20();
  return;
}


