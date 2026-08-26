/*
 * Decompiled function: FUN_100346fd
 * Entry Point: 100346fd
 * Size: 830 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_100346fd(HWND hwnd,uint32_t y,HDC hdc,LPARAM arg_4)

{
  HDC pHVar1;
  size_t len_2;
  LRESULT LVar3;
  tagRECT *ptVar4;
  UINT UVar5;
  uint8_t local_7c [4];
  int local_78;
  int local_74;
  tagPAINTSTRUCT local_64;
  tagRECT local_24;
  tagRECT local_14;
  
  if (y < 0x10) {
    if (y == 0xf) {
      pHVar1 = BeginPaint(hwnd,&local_64);
      thunk_FUN_10031425(pHVar1);
      GetClientRect(hwnd,&local_14);
      InflateRect(&local_14,-5,-5);
      CopyRect(&local_24,&local_14);
      len_2 = strlen(&DAT_10162630);
      if (len_2 < 0xc) {
        SelectObject(pHVar1,DAT_1013eba8);
      }
      else {
        SelectObject(pHVar1,DAT_1013ebec);
      }
      SetBkMode(pHVar1,1);
      SetMapMode(pHVar1,8);
      SetWindowExtEx(pHVar1,local_24.right - local_24.left,0x46,(LPSIZE)0x0);
      SetViewportExtEx(pHVar1,local_24.right - local_24.left,local_24.bottom - local_24.top,
                       (LPSIZE)0x0);
      local_24.left = local_24.left + 3;
      local_24.top = local_24.top + 3;
      SetTextColor(pHVar1,0x24d2e14);
      UVar5 = 0x25;
      ptVar4 = &local_24;
      len_2 = strlen(&DAT_10162630);
      DrawTextA(pHVar1,&DAT_10162630,len_2,ptVar4,UVar5);
      local_24.left = local_24.left + -3;
      local_24.top = local_24.top + -3;
      SetTextColor(pHVar1,0x2afd1f3);
      UVar5 = 0x25;
      ptVar4 = &local_24;
      len_2 = strlen(&DAT_10162630);
      DrawTextA(pHVar1,&DAT_10162630,len_2,ptVar4,UVar5);
      EndPaint(hwnd,&local_64);
      return 0;
    }
    if (y == 1) {
      memcpy(&DAT_1013ebb0,&DAT_10046790,0x3c);
      strcpy(&DAT_1013ebcc,s_Cheltenham_ITC_Bold_BT_100467e4);
      _DAT_1013ebb0 = 0x32;
      DAT_1013eba8 = CreateFontIndirectA((LOGFONTA *)&DAT_1013ebb0);
      _DAT_1013ebb0 = 0x1e;
      DAT_1013ebec = CreateFontIndirectA((LOGFONTA *)&DAT_1013ebb0);
      return 0;
    }
    if (y == 2) {
      DeleteObject(DAT_1013eba8);
      DeleteObject(DAT_1013ebec);
      return 0;
    }
  }
  else {
    if (y == 0x14) {
      thunk_FUN_10031425(hdc);
      pHVar1 = CreateCompatibleDC(hdc);
      thunk_FUN_10031425(pHVar1);
      SelectObject(pHVar1,DAT_101cfb90);
      GetClientRect(hwnd,&local_14);
      GetObjectA(DAT_101cfb90,0x18,local_7c);
      StretchBlt(hdc,0,0,local_14.right,local_14.bottom,pHVar1,0,0,local_78,local_74,0xcc0020);
      DeleteDC(pHVar1);
      return 1;
    }
    if ((y == 0x201) || (y == 0x204)) {
      if ((DAT_1017646c & 1) != 0) {
        return 0;
      }
      thunk_FUN_1000b097();
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar3 = DefWindowProcA(hwnd,y,(WPARAM)hdc,arg_4);
  return LVar3;
}


