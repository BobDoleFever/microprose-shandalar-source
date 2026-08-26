/*
 * Decompiled function: thunk_FUN_1001ad0b
 * Entry Point: 1000121c
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001ad0b(HDC hdc,RECT *arg2)

{
  int val_1;
  int val_2;
  HBRUSH pHVar3;
  tagRECT tStack_14;
  
  if ((hdc != (HDC)0x0) && (arg2 != (RECT *)0x0)) {
    if (DAT_1013e590 == (HANDLE)0x0) {
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
    }
    else {
      val_1 = ((arg2->right - arg2->left) * 3) / 100;
      if (val_1 < 2) {
        val_1 = 1;
      }
      val_2 = ((arg2->bottom - arg2->top) * 2) / 100;
      if (val_2 < 2) {
        val_2 = 1;
      }
      pHVar3 = GetStockObject(4);
      FillRect(hdc,arg2,pHVar3);
      SetRect(&tStack_14,arg2->left + val_1,arg2->top + val_2,arg2->right - val_1,
              arg2->bottom - val_2);
      thunk_FUN_1003162f((int)hdc,(int)&tStack_14,DAT_1013e590);
    }
  }
  return;
}


