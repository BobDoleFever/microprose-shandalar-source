/*
 * Decompiled function: FUN_1001df0d
 * Entry Point: 1001df0d
 * Size: 662 bytes
 */
#include "deckdll.h"


void FUN_1001df0d(HDC hdc,RECT *arg_2,WPARAM *arg_3,int arg_4,int arg_5)

{
  HGDIOBJ h;
  int val_1;
  tagRECT local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) && (arg_3 != (WPARAM *)0x0)) {
    local_8 = SaveDC(hdc);
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
      local_28 = arg_2->right - arg_2->left;
      local_2c = arg_2->bottom - arg_2->top;
      local_30 = (local_28 * 0x12) / 0xe4;
      local_34 = (local_2c * 0xb) / 100 + (local_2c * 8) / 100 + -2;
      local_1c = ((local_28 * 0xd3) / 0xe4 - local_30) + 1;
      local_24 = (local_2c * 0xb2) / 0xbf - local_34;
      SetRect(&local_44,local_30,local_34,local_30 + local_1c,local_24 + local_34);
      val_1 = thunk_FUN_10028c81(*arg_3,arg_4);
      if (val_1 == 0) {
        thunk_FUN_10028a10(*arg_3,arg_4,local_1c,local_24);
      }
      else if (arg_5 != 0) {
        thunk_FUN_10028def(*arg_3,arg_4,local_1c,local_24);
      }
      local_20 = thunk_FUN_10028d12(hdc,&local_44,*arg_3,arg_4);
      if (local_20 == 0) {
        thunk_FUN_10013b53(hdc,&local_44,*arg_3,arg_4);
      }
    }
    RestoreDC(hdc,local_8);
  }
  return;
}


