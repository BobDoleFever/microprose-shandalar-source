/*
 * Decompiled function: thunk_FUN_1002c220
 * Entry Point: 10001320
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1002c220(HDC hdc,int *y,LPRECT arg_3,int height)

{
  HBRUSH pHVar1;
  tagRECT tStack_14;
  
  if (height == 0) {
    SetRect(&tStack_14,*y,y[1],y[2],y[1] + 1);
    pHVar1 = GetStockObject(0);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,*y,y[1],*y + 1,y[3]);
    pHVar1 = GetStockObject(0);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,y[2] + -2,y[1] + 1,y[2] + -1,y[3]);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,y[2] + -1,y[1] + 2,y[2],y[3]);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,*y + 1,y[3] + -2,y[2],y[3] + -1);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,*y + 1,y[3] + -1,y[2],y[3]);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    if (arg_3 != (LPRECT)0x0) {
      SetRect(arg_3,*y + 1,y[1] + 1,y[2] + -2,y[3] + -2);
    }
    pHVar1 = GetStockObject(1);
    FillRect(hdc,arg_3,pHVar1);
  }
  else {
    SetRect(&tStack_14,*y + 1,y[1] + 1,y[2],y[1] + 3);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    SetRect(&tStack_14,*y + 1,y[1] + 1,*y + 2,y[3]);
    pHVar1 = GetStockObject(3);
    FillRect(hdc,&tStack_14,pHVar1);
    if (arg_3 != (LPRECT)0x0) {
      SetRect(arg_3,*y + 3,y[1] + 3,y[2],y[3]);
    }
    pHVar1 = GetStockObject(1);
    FillRect(hdc,arg_3,pHVar1);
  }
  return;
}


