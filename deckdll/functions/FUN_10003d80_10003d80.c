/*
 * Decompiled function: FUN_10003d80
 * Entry Point: 10003d80
 * Size: 214 bytes
 */
#include "deckdll.h"


int32_t FUN_10003d80(HWND hwnd,int y,DWORD arg_3,DWORD arg_4)

{
  uint32_t *arg_3_00;
  BITMAPINFO *lpbmi;
  HDC hdc;
  
  if (y == 0) {
    return 0;
  }
  arg_3_00 = (uint32_t *)thunk_FUN_100037d0(0,y,arg_3,arg_4);
  thunk_FUN_1000f104(DAT_10041580,DAT_10041584,arg_3_00,arg_4,arg_3,
                     (DAT_10040410 - (int)(arg_3 * 3) % DAT_10040410) % DAT_10040410);
  lpbmi = (BITMAPINFO *)thunk_FUN_10003410(arg_3,arg_4,0x18);
  hdc = GetDC(hwnd);
  SetDIBitsToDevice(hdc,0,0,arg_3,arg_4,0,0,0,arg_4,arg_3_00,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  if (*(uint32_t **)(y + 0x1ac) != arg_3_00) {
    free(arg_3_00);
  }
  return 1;
}


