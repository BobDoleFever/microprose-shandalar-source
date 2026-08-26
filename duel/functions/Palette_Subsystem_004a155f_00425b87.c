/*
 * Decompiled function: Palette_Subsystem_004a155f
 * Entry Point: 00425b87
 * Size: 1530 bytes
 */
#include "duel.h"


void Palette_Subsystem_004a155f(HDC hdc,int *y,int width,int arg_4)

{
  byte arg_1;
  uint uVar1;
  uint width_00;
  int iVar2;
  int width_01;
  HGDIOBJ h;
  int in_stack_00000020;
  int in_stack_00000024;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  undefined4 local_a4;
  char *local_a0;
  char *local_9c;
  int local_94;
  undefined4 local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (local_8 = FUN_00447184(width,arg_4), local_8 != -1)) {
    local_a8 = SaveDC(hdc);
    FID_conflict__memcpy(&local_a4,&DAT_00618ac0 + local_8 * 0x98,0x98);
    local_b0 = local_94;
    arg_1 = FUN_0044781f(width,arg_4);
    local_ac = FUN_0048c367(arg_1);
    if (((((local_b0 == 1) || (local_b0 == 8)) ||
         ((local_b0 == 7 || ((local_b0 == 5 || (local_b0 == 2)))))) ||
        ((local_b0 == 6 && (local_ac != 0)))) || ((local_b0 == 3 && (local_ac != 0)))) {
      if (local_ac == 1) {
        local_94 = 1;
      }
      else if (local_ac == 5) {
        local_94 = 8;
      }
      else if (local_ac == 3) {
        local_94 = 5;
      }
      else if (local_ac == 4) {
        local_94 = 7;
      }
      else if (local_ac == 2) {
        local_94 = 2;
      }
    }
    if (in_stack_00000020 != 0) {
      local_9c = s_Activation_004f3694;
      local_a0 = s_Activation_004f3694;
      local_94 = -1;
    }
    if (in_stack_00000024 != 0) {
      local_9c = s_Upkeep_004f36a0;
      local_a0 = s_Upkeep_004f36a0;
      local_94 = -1;
    }
    local_c = FUN_00486c12(local_8,width,arg_4);
    FUN_00423651(hdc,y,&local_a4,local_c,1);
    FUN_00426181(hdc,y,width,arg_4);
    if ((DAT_00663e08 != 0) && (uVar1 = FUN_00447604(width,arg_4), (uVar1 & 2) != 0)) {
      uVar1 = FUN_004476e3(width,arg_4);
      width_00 = FUN_00447675(width,arg_4);
      FUN_00423c6b(hdc,y,width_00,uVar1);
    }
    uVar1 = FUN_00447604(width,arg_4);
    if ((((uVar1 & 2) != 0) || (DAT_00663e20 != 0)) &&
       (uVar1 = FUN_004472ad(width,arg_4), (uVar1 & 1) != 0)) {
      FUN_00426479(hdc,y);
    }
    uVar1 = FUN_00447604(width,arg_4);
    if (((uVar1 & 2) != 0) && (iVar2 = FUN_00448374(width,arg_4), iVar2 == 2)) {
      FUN_00426500(hdc,y);
    }
    local_b4 = FUN_00447751(width,arg_4);
    if ((DAT_00663e0c != 0) && (local_b4 != 0)) {
      FUN_00424a81(hdc,y,local_b4);
    }
    local_b8 = FUN_004470a6(width,arg_4);
    if (local_b8 != 0) {
      FUN_00423fbd(hdc,(int)y,local_b8);
    }
    local_c8 = *y + ((y[2] - *y) * 7) / 100;
    local_c0 = y[2] - ((y[2] - *y) * 10) / 100;
    local_c4 = y[1] + ((y[3] - y[1]) * 8) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    iVar2 = FUN_00446f0f(width,arg_4);
    local_cc = iVar2;
    if (iVar2 != 0) {
      width_01 = FUN_00426901(local_8);
      FUN_0042440b((int)hdc,(int)y,width_01,iVar2);
    }
    local_c4 = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x3e) / 100;
    FUN_00446f81(width,arg_4,&local_d0,&local_d4,&local_d8);
    FUN_0042474a((int)hdc,&local_c8,local_d0,local_d4,local_d8);
    iVar2 = FUN_00447a88(width,arg_4);
    uVar1 = (uint)(iVar2 == width);
    iVar2 = FUN_00447c07(width,arg_4);
    FUN_00424f7b(hdc,y,(int)local_9c,iVar2,uVar1);
    if ((width == 0) && (uVar1 = FUN_004478fb(0,arg_4), (uVar1 & 0x40000) != 0)) {
      SelectObject(hdc,DAT_0050b1c8);
      h = GetStockObject(5);
      SelectObject(hdc,h);
      Rectangle(hdc,*y,y[1],y[2],y[3]);
    }
    RestoreDC(hdc,local_a8);
  }
  return;
}


