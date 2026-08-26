/*
 * Decompiled function: thunk_FUN_1001df0d
 * Entry Point: 100015fa
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001df0d(HDC hdc,RECT *arg_2,WPARAM *arg_3,int arg_4,int arg_5)

{
  HGDIOBJ h;
  int val_1;
  tagRECT tStack_44;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) && (arg_3 != (WPARAM *)0x0)) {
    iStack_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,arg_2->left,arg_2->top,(LPPOINT)0x0);
    thunk_FUN_1001e1a3(hdc,arg_2,(int)arg_3);
    thunk_FUN_1001f83a(hdc,&arg_2->left,(char *)arg_3[2],0,1);
    h = GetStockObject(5);
    SelectObject(hdc,h);
    SelectObject(hdc,DAT_1013e5d4);
    Rectangle(hdc,0,0,200,0x118);
    if (DAT_101628dc != 0) {
      SetMapMode(hdc,1);
      iStack_28 = arg_2->right - arg_2->left;
      iStack_2c = arg_2->bottom - arg_2->top;
      iStack_30 = (iStack_28 * 0x12) / 0xe4;
      iStack_34 = (iStack_2c * 0xb) / 100 + (iStack_2c * 8) / 100 + -2;
      iStack_1c = ((iStack_28 * 0xd3) / 0xe4 - iStack_30) + 1;
      iStack_24 = (iStack_2c * 0xb2) / 0xbf - iStack_34;
      SetRect(&tStack_44,iStack_30,iStack_34,iStack_30 + iStack_1c,iStack_24 + iStack_34);
      val_1 = thunk_FUN_10028c81(*arg_3,arg_4);
      if (val_1 == 0) {
        thunk_FUN_10028a10(*arg_3,arg_4,iStack_1c,iStack_24);
      }
      else if (arg_5 != 0) {
        thunk_FUN_10028def(*arg_3,arg_4,iStack_1c,iStack_24);
      }
      iStack_20 = thunk_FUN_10028d12(hdc,&tStack_44,*arg_3,arg_4);
      if (iStack_20 == 0) {
        thunk_FUN_10013b53(hdc,&tStack_44,*arg_3,arg_4);
      }
    }
    RestoreDC(hdc,iStack_8);
  }
  return;
}


