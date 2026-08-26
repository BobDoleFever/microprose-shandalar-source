/*
 * Decompiled function: FUN_10020edf
 * Entry Point: 10020edf
 * Size: 294 bytes
 */
#include "deckdll.h"


uint32_t FUN_10020edf(HDC hdc,int *y,int width,int height)

{
  int nSavedDC;
  uint32_t uval_1;
  uint32_t local_1c;
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
      local_1c = thunk_FUN_100318f9(hdc,&local_14,DAT_1013e208);
      local_1c = local_1c & 1;
    }
    if (height == 0) {
      uval_1 = thunk_FUN_100318f9(hdc,&local_14,DAT_1013e5fc);
      local_1c = local_1c & uval_1;
    }
    RestoreDC(hdc,nSavedDC);
  }
  return local_1c;
}


