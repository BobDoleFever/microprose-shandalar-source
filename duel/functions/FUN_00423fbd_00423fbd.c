/*
 * Decompiled function: FUN_00423fbd
 * Entry Point: 00423fbd
 * Size: 343 bytes
 */
#include "duel.h"


undefined4 FUN_00423fbd(HDC hdc,int arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  char local_1c [8];
  tagRECT local_14;
  
  if ((hdc == (HDC)0x0) || (arg_2 == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    FUN_00424114(&local_14,(int *)arg_2);
    uVar1 = FUN_00470c78(hdc,&local_14,DAT_0050b1f8);
    _sprintf(local_1c,&DAT_004f3610,arg_3);
    SelectObject(hdc,DAT_0050abd8);
    SetTextAlign(hdc,0);
    SetBkMode(hdc,1);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    SetTextColor(hdc,DAT_0050ade0);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    OffsetRect(&local_14,-2,-2);
    SetTextColor(hdc,DAT_0050adc8);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}


