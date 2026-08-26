/*
 * Decompiled function: FUN_00424a81
 * Entry Point: 00424a81
 * Size: 663 bytes
 */
#include "duel.h"


void FUN_00424a81(HDC hdc,undefined4 *arg_2,uint arg_3)

{
  int arg_5;
  undefined1 local_dc [4];
  int local_d8;
  int local_d4;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  undefined4 local_b0;
  uint local_ac [20];
  int local_5c [17];
  tagRECT local_18;
  int local_8;
  
  local_ac[0] = 0x20;
  local_ac[1] = 0x400;
  local_ac[2] = 0x40;
  local_ac[3] = 0x80;
  local_ac[4] = 0x100;
  local_ac[5] = 0x200;
  local_ac[6] = 1;
  local_ac[7] = 2;
  local_ac[8] = 4;
  local_ac[9] = 8;
  local_ac[10] = 0x10;
  local_ac[0xb] = 0x800;
  local_ac[0xc] = 0x1000;
  local_ac[0xd] = 0x2000;
  local_ac[0xe] = 0x4000;
  local_ac[0xf] = 0x8000;
  local_ac[0x10] = 0x10000;
  local_5c[0] = 0xb;
  local_5c[1] = 0x10;
  local_5c[2] = 0xd;
  local_5c[3] = 0xc;
  local_5c[4] = 0xe;
  local_5c[5] = 0xf;
  local_5c[6] = 3;
  local_5c[7] = 2;
  local_5c[8] = 0;
  local_5c[9] = 1;
  local_5c[10] = 4;
  local_5c[0xb] = 8;
  local_5c[0xc] = 7;
  local_5c[0xd] = 5;
  local_5c[0xe] = 6;
  local_5c[0xf] = 9;
  local_5c[0x10] = 10;
  local_ac[0x11] = 0x11;
  if (((hdc != (HDC)0x0) && (arg_2 != (undefined4 *)0x0)) && (arg_3 != 0)) {
    local_c0 = SaveDC(hdc);
    if (DAT_0050b1b8 != (HANDLE)0x0) {
      GetObjectA(DAT_0050b1b8,0x18,local_dc);
      local_b8 = local_d8;
      arg_5 = local_d4 / (int)(local_ac[0x11] + 1);
      local_8 = 0;
      local_b4 = local_d4 - arg_5;
      local_b0 = *arg_2;
      local_c4 = arg_2[3] - arg_5;
      for (local_bc = 0; local_bc < (int)local_ac[0x11]; local_bc = local_bc + 1) {
        if ((arg_3 & local_ac[local_bc]) != 0) {
          FUN_00424d18(&local_18,local_ac[local_bc],arg_2,arg_3);
          local_ac[0x12] = 0;
          local_ac[0x13] = local_5c[local_bc] * arg_5;
          FUN_00470cfa(hdc,&local_18.left,DAT_0050b1b8,local_b8,arg_5,0,local_ac[0x13],local_8,
                       local_b4);
        }
      }
    }
    RestoreDC(hdc,local_c0);
  }
  return;
}


