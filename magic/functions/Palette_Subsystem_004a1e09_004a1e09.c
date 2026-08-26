/*
 * Decompiled function: Palette_Subsystem_004a1e09
 * Entry Point: 004a1e09
 * Size: 1528 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a1e09(HDC hdc,int *y,int width,int height)

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
  WPARAM local_a4;
  char *local_a0;
  char *local_9c;
  int local_94;
  int local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (local_8 = Ai_Subsystem_004b5cbb(width,height), local_8 != -1)) {
    local_a8 = SaveDC(hdc);
    memcpy(&local_a4,&DAT_006b3070 + local_8 * 0x98,0x98);
    local_b0 = local_94;
    arg_1 = Ai_Subsystem_004b6356(width,height);
    local_ac = FUN_00473cc5(arg_1);
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
      local_9c = s_Activation_0052c280;
      local_a0 = s_Activation_0052c280;
      local_94 = -1;
    }
    if (in_stack_00000024 != 0) {
      local_9c = s_Upkeep_0052c28c;
      local_a0 = s_Upkeep_0052c28c;
      local_94 = -1;
    }
    local_c = FUN_00478aa4(local_8,width,height);
    Palette_Subsystem_0049f8cd(hdc,y,&local_a4,local_c,1);
    Palette_Subsystem_004a2401(hdc,y,width,height);
    if ((DAT_006fe428 != 0) && (uVar1 = Ai_Subsystem_004b613b(width,height), (uVar1 & 2) != 0)) {
      uVar1 = Ai_Subsystem_004b621a(width,height);
      width_00 = Ai_Subsystem_004b61ac(width,height);
      Palette_Subsystem_0049fee7(hdc,y,width_00,uVar1);
    }
    uVar1 = Ai_Subsystem_004b613b(width,height);
    if ((((uVar1 & 2) != 0) || (DAT_006fe440 != 0)) &&
       (uVar1 = Ai_Subsystem_004b5de4(width,height), (uVar1 & 1) != 0)) {
      Palette_Subsystem_004a26f8(hdc,y);
    }
    uVar1 = Ai_Subsystem_004b613b(width,height);
    if (((uVar1 & 2) != 0) && (iVar2 = Ai_Subsystem_004b6eab(width,height), iVar2 == 2)) {
      Palette_Subsystem_004a277f(hdc,y);
    }
    local_b4 = Ai_Subsystem_004b6288(width,height);
    if ((DAT_006fe42c != 0) && (local_b4 != 0)) {
      Palette_Subsystem_004a0d00(hdc,y,local_b4);
    }
    local_b8 = Ai_Subsystem_004b5bdd(width,height);
    if (local_b8 != 0) {
      Palette_Subsystem_004a023a(hdc,(int)y,local_b8);
    }
    local_c8 = *y + ((y[2] - *y) * 7) / 100;
    local_c0 = y[2] - ((y[2] - *y) * 10) / 100;
    local_c4 = y[1] + ((y[3] - y[1]) * 8) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    iVar2 = Ai_Subsystem_004b5a46(width,height);
    local_cc = iVar2;
    if (iVar2 != 0) {
      width_01 = Palette_Subsystem_004a2b7e(local_8);
      Palette_Subsystem_004a068a((int)hdc,(int)y,width_01,iVar2);
    }
    local_c4 = y[1] + ((y[3] - y[1]) * 0x23) / 100;
    local_bc = y[1] + ((y[3] - y[1]) * 0x3e) / 100;
    Ai_Subsystem_004b5ab8(width,height,&local_d0,&local_d4,&local_d8);
    Palette_Subsystem_004a09c9((int)hdc,&local_c8,local_d0,local_d4,local_d8);
    iVar2 = Ai_Subsystem_004b65bf(width,height);
    uVar1 = (uint)(iVar2 == width);
    iVar2 = Ai_Subsystem_004b673e(width,height);
    Palette_Subsystem_004a11fa(hdc,y,local_9c,iVar2,uVar1);
    if ((width == 0) && (uVar1 = Ai_Subsystem_004b6432(0,height), (uVar1 & 0x40000) != 0)) {
      SelectObject(hdc,DAT_0054b970);
      h = GetStockObject(5);
      SelectObject(hdc,h);
      Rectangle(hdc,*y,y[1],y[2],y[3]);
    }
    RestoreDC(hdc,local_a8);
  }
  return;
}


