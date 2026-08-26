/*
 * Decompiled function: FUN_0047f6e7
 * Entry Point: 0047f6e7
 * Size: 105 bytes
 */
#include "duel.h"


bool FUN_0047f6e7(HWND hwnd)

{
  HDC hDC;
  HBRUSH hbr;
  tagRECT local_14;
  
  if (hwnd != (HWND)0x0) {
    hDC = GetDC(hwnd);
    GetClientRect(hwnd,&local_14);
    hbr = GetStockObject(0);
    FillRect(hDC,&local_14,hbr);
    ReleaseDC(hwnd,hDC);
  }
  return hwnd != (HWND)0x0;
}


