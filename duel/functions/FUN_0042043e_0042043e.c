/*
 * Decompiled function: FUN_0042043e
 * Entry Point: 0042043e
 * Size: 252 bytes
 */
#include "duel.h"


void FUN_0042043e(HDC hdc,RECT *arg2)

{
  int iVar1;
  int iVar2;
  HBRUSH pHVar3;
  tagRECT local_14;
  
  if ((hdc != (HDC)0x0) && (arg2 != (RECT *)0x0)) {
    if (DAT_0050b178 == (HANDLE)0x0) {
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
    }
    else {
      iVar1 = ((arg2->right - arg2->left) * 3) / 100;
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      iVar2 = ((arg2->bottom - arg2->top) * 2) / 100;
      if (iVar2 < 2) {
        iVar2 = 1;
      }
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
      SetRect(&local_14,arg2->left + iVar1,arg2->top + iVar2,arg2->right - iVar1,
              arg2->bottom - iVar2);
      FUN_004709ae((int)hdc,(int)&local_14,DAT_0050b178);
    }
  }
  return;
}


