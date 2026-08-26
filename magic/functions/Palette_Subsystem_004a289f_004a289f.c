/*
 * Decompiled function: Palette_Subsystem_004a289f
 * Entry Point: 004a289f
 * Size: 294 bytes
 */
#include "magic.h"


uint Palette_Subsystem_004a289f(HDC hdc,int *y,int width,int height)

{
  int nSavedDC;
  uint uVar1;
  uint local_1c;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((hdc == (HDC)0x0) || (y == (int *)0x0)) {
    local_1c = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    local_14 = *y + ((y[2] - *y) * 10) / 100;
    local_c = y[2] - ((y[2] - *y) * 10) / 100;
    local_10 = y[1] + ((y[3] - y[1]) * 10) / 100;
    local_8 = y[3] - ((y[3] - y[1]) * 10) / 100;
    local_1c = 1;
    if (width != 0) {
      local_1c = FUN_004f3e29(hdc,&local_14,DAT_0054b598);
      local_1c = local_1c & 1;
    }
    if (height == 0) {
      uVar1 = FUN_004f3e29(hdc,&local_14,DAT_0054b98c);
      local_1c = local_1c & uVar1;
    }
    RestoreDC(hdc,nSavedDC);
  }
  return local_1c;
}


