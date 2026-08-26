/*
 * Decompiled function: FUN_1000370a
 * Entry Point: 1000370a
 * Size: 145 bytes
 */
#include "deckdll.h"


int32_t FUN_1000370a(int32_t arg_1,HWND hwnd,int32_t arg_3,DWORD arg_4,DWORD arg_5)

{
  int reg_eax;
  void *lpvBits;
  BITMAPINFO *lpbmi;
  HDC hdc;
  bool in_ZF;
  
  if (in_ZF) {
    return 0;
  }
  lpvBits = (void *)thunk_FUN_100034d0((int32_t *)0x0,reg_eax,arg_4,arg_5);
  lpbmi = (BITMAPINFO *)thunk_FUN_10003410(arg_4,arg_5,0x18);
  hdc = GetDC(hwnd);
  SetDIBitsToDevice(hdc,0,0,arg_4,arg_5,0,0,0,arg_5,lpvBits,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  free(lpvBits);
  return 1;
}


