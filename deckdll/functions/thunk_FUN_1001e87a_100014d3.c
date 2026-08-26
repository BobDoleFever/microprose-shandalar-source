/*
 * Decompiled function: thunk_FUN_1001e87a
 * Entry Point: 100014d3
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001e87a(HDC hdc,int *arg_2,int32_t arg_3)

{
  int32_t uval_1;
  int nSavedDC;
  char acStack_1c [8];
  tagRECT tStack_14;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) {
    uval_1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    thunk_FUN_1001e9d2(&tStack_14,arg_2);
    uval_1 = thunk_FUN_100318f9(hdc,&tStack_14,DAT_1013e610);
    sprintf(acStack_1c,&DAT_100438e4,arg_3);
    SelectObject(hdc,DAT_1013dff0);
    SetTextAlign(hdc,0);
    SetBkMode(hdc,1);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,tStack_14.right - tStack_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,tStack_14.right - tStack_14.left,tStack_14.bottom - tStack_14.top,
                     (LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&tStack_14,2);
    SetTextColor(hdc,DAT_1013e1f8);
    DrawTextA(hdc,acStack_1c,-1,&tStack_14,0x25);
    OffsetRect(&tStack_14,-2,-2);
    SetTextColor(hdc,DAT_1013e1e0);
    DrawTextA(hdc,acStack_1c,-1,&tStack_14,0x25);
    RestoreDC(hdc,nSavedDC);
  }
  return uval_1;
}


