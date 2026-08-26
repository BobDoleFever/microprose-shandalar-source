/*
 * Decompiled function: Pic_Subsystem_0042784d
 * Entry Point: 0042784d
 * Size: 445 bytes
 */
#include "magic.h"


void Pic_Subsystem_0042784d(POINT *arg_1,RECT *arg_2,undefined4 *arg_3)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  BOOL BVar1;
  tagRECT local_28;
  tagRECT local_18;
  undefined4 local_8;
  
  CopyRect(&local_28,arg_2);
  pt_05 = *arg_1;
  pt_04 = *arg_1;
  pt_03 = *arg_1;
  pt_02 = *arg_1;
  pt_01 = *arg_1;
  pt_00 = *arg_1;
  pt = *arg_1;
  local_8 = 0xffffffff;
  Pic_Subsystem_00427a0a(&local_18,0x15,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt);
  if (BVar1 != 0) {
    local_8 = 0x15;
  }
  Pic_Subsystem_00427a0a(&local_18,0x16,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_00);
  if (BVar1 != 0) {
    local_8 = 0x16;
  }
  Pic_Subsystem_00427a0a(&local_18,0x17,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_01);
  if (BVar1 != 0) {
    local_8 = 0x17;
  }
  Pic_Subsystem_00427a0a(&local_18,0x18,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_02);
  if (BVar1 != 0) {
    local_8 = 0x18;
  }
  Pic_Subsystem_00427a0a(&local_18,0x19,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_03);
  if (BVar1 != 0) {
    local_8 = 0x19;
  }
  Pic_Subsystem_00427a0a(&local_18,0x1b,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_04);
  if (BVar1 != 0) {
    local_8 = 0x1a;
  }
  Pic_Subsystem_00427a0a(&local_18,0x1e,local_28.right,local_28.bottom);
  BVar1 = PtInRect(&local_18,pt_05);
  if (BVar1 != 0) {
    local_8 = 0x1e;
  }
  *arg_3 = local_8;
  return;
}


