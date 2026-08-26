/*
 * Decompiled function: FUN_0048039e
 * Entry Point: 0048039e
 * Size: 193 bytes
 */
#include "duel.h"


undefined4 FUN_0048039e(HWND hwnd,int *y,DWORD arg_3,DWORD arg_4)

{
  undefined4 uVar1;
  uint *arg_3_00;
  
  if (y == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    arg_3_00 = (uint *)FUN_0047fc77((uint *)0x0,y,arg_3,arg_4);
    FUN_004356cf(DAT_004f4628,DAT_004f462c,arg_3_00,arg_4,arg_3,
                 (DAT_004f9d08 - (int)(arg_3 * 3) % DAT_004f9d08) % DAT_004f9d08);
    FUN_0047f750(hwnd,arg_3_00,0,0,arg_3,arg_4);
    if ((uint *)y[0x6b] != arg_3_00) {
      FUN_004db150(arg_3_00);
    }
    uVar1 = 1;
  }
  return uVar1;
}


