/*
 * Decompiled function: FUN_1001e87a
 * Entry Point: 1001e87a
 * Size: 344 bytes
 */
#include "deckdll.h"


int32_t FUN_1001e87a(HDC hdc,int *arg_2,int32_t arg_3)

{
  int32_t uval_1;
  int nSavedDC;
  char local_1c [8];
  tagRECT local_14;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) {
    uval_1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    thunk_FUN_1001e9d2(&local_14,arg_2);
    uval_1 = thunk_FUN_100318f9(hdc,&local_14,DAT_1013e610);
    sprintf(local_1c,&DAT_100438e4,arg_3);
    SelectObject(hdc,DAT_1013dff0);
    SetTextAlign(hdc,0);
    SetBkMode(hdc,1);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    SetTextColor(hdc,DAT_1013e1f8);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    OffsetRect(&local_14,-2,-2);
    SetTextColor(hdc,DAT_1013e1e0);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    RestoreDC(hdc,nSavedDC);
  }
  return uval_1;
}


