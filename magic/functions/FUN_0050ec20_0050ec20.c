/*
 * Decompiled function: FUN_0050ec20
 * Entry Point: 0050ec20
 * Size: 104 bytes
 */
#include "magic.h"


int FUN_0050ec20(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int iVar1;
  
  lpbmi = (BITMAPINFO *)FUN_0050ec90(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  iVar1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  return iVar1;
}


