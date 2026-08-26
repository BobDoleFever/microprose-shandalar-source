/*
 * Decompiled function: FUN_0044e141
 * Entry Point: 0044e141
 * Size: 1004 bytes
 */
#include "duel.h"


void FUN_0044e141(POINT *x,RECT *arg_2,undefined4 *arg_3,int *height)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  POINT pt_14;
  BOOL BVar1;
  undefined4 local_34;
  tagRECT local_28;
  tagRECT local_18;
  int local_8;
  
  CopyRect(&local_28,arg_2);
  pt_14 = *x;
  pt_13 = *x;
  pt_12 = *x;
  pt_11 = *x;
  pt_10 = *x;
  pt_09 = *x;
  pt_08 = *x;
  pt_07 = *x;
  pt_06 = *x;
  pt_05 = *x;
  pt_04 = *x;
  pt_03 = *x;
  pt_02 = *x;
  pt_01 = *x;
  pt_00 = *x;
  pt = *x;
  local_8 = -1;
  local_34 = 1;
  FUN_0044e52d(&local_18,1,1,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt);
  if (BVar1 != 0) {
    local_8 = 1;
  }
  FUN_0044e52d(&local_18,1,4,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_00);
  if (BVar1 != 0) {
    local_8 = 4;
  }
  FUN_0044e52d(&local_18,1,10,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_01);
  if (BVar1 != 0) {
    local_8 = 10;
  }
  FUN_0044e52d(&local_18,1,0x14,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_02);
  if (BVar1 != 0) {
    local_8 = 0x14;
  }
  FUN_0044e52d(&local_18,1,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_03);
  if (BVar1 != 0) {
    local_8 = 0x16;
  }
  FUN_0044e52d(&local_18,1,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_04);
  if (BVar1 != 0) {
    local_8 = 0x1e;
  }
  FUN_0044e52d(&local_18,1,0x1f,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_05);
  if (BVar1 != 0) {
    local_8 = 0x1f;
  }
  FUN_0044e52d(&local_18,1,0x20,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_06);
  if (BVar1 != 0) {
    local_8 = 0x20;
  }
  if (local_8 == -1) {
    local_34 = 0;
    FUN_0044e52d(&local_18,0,1,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_07);
    if (BVar1 != 0) {
      local_8 = 1;
    }
    FUN_0044e52d(&local_18,0,4,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_08);
    if (BVar1 != 0) {
      local_8 = 4;
    }
    FUN_0044e52d(&local_18,0,10,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_09);
    if (BVar1 != 0) {
      local_8 = 10;
    }
    FUN_0044e52d(&local_18,0,0x14,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_10);
    if (BVar1 != 0) {
      local_8 = 0x14;
    }
    FUN_0044e52d(&local_18,0,0x15,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_11);
    if (BVar1 != 0) {
      local_8 = 0x15;
    }
    FUN_0044e52d(&local_18,0,0x1e,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_12);
    if (BVar1 != 0) {
      local_8 = 0x1e;
    }
    FUN_0044e52d(&local_18,0,0x1f,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_13);
    if (BVar1 != 0) {
      local_8 = 0x1f;
    }
    FUN_0044e52d(&local_18,0,0x20,local_28.right,local_28.bottom);
    BVar1 = PtInRect(&local_18,pt_14);
    if (BVar1 != 0) {
      local_8 = 0x20;
    }
  }
  *arg_3 = local_34;
  *height = local_8;
  return;
}


