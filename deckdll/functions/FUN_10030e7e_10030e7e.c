/*
 * Decompiled function: FUN_10030e7e
 * Entry Point: 10030e7e
 * Size: 944 bytes
 */
#include "deckdll.h"


LRESULT FUN_10030e7e(HWND hwnd,uint32_t y,uint32_t width,LPCSTR str_4)

{
  WORD WVar1;
  int c;
  HWND pHVar2;
  LRESULT LVar3;
  tagSIZE *lpsz;
  tagRECT *lpRect;
  CHAR local_108 [100];
  HDC local_a4;
  tagPAINTSTRUCT local_a0;
  HBRUSH local_60;
  tagRECT local_5c;
  HBRUSH local_4c;
  tagRECT local_48;
  int local_38;
  HDC local_34;
  int local_30;
  uint32_t local_2c;
  uint32_t local_28;
  LPCSTR local_24;
  tagSIZE local_20;
  HFONT local_18;
  tagRECT local_14;
  
  if (y < 0x10) {
    if (y == 0xf) {
      WVar1 = GetWindowWord(hwnd,0);
      local_18 = (HFONT)(uint32_t)WVar1;
      local_a4 = BeginPaint(hwnd,&local_a0);
      if (local_a4 != (HDC)0x0) {
        thunk_FUN_10031425(local_a4);
        GetClientRect(hwnd,&local_48);
        local_60 = CreateSolidBrush(0x296bed2);
        local_4c = CreateSolidBrush(0x27f7f7f);
        SetRect(&local_5c,local_48.left,local_48.top,local_48.right + -2,local_48.bottom + -2);
        FillRect(local_a4,&local_48,local_4c);
        FillRect(local_a4,&local_5c,local_60);
        SetTextColor(local_a4,0x2000000);
        SetBkMode(local_a4,1);
        GetWindowTextA(hwnd,local_108,100);
        SelectObject(local_a4,local_18);
        DrawTextA(local_a4,local_108,-1,&local_5c,0x25);
        EndPaint(hwnd,&local_a0);
        DeleteObject(local_60);
        DeleteObject(local_4c);
      }
      return 0;
    }
    if (y == 1) {
      local_18 = CreateFontA(0xc,0,0,0,400,0,0,0,0,4,0,0,0,s_Arial_10046624);
      if (local_18 == (HFONT)0x0) {
        return -1;
      }
      SetWindowLongA(hwnd,0,(LONG)local_18);
      return 0;
    }
    if (y == 2) {
      WVar1 = GetWindowWord(hwnd,0);
      local_18 = (HFONT)(uint32_t)WVar1;
      if (local_18 != (HGDIOBJ)0x0) {
        DeleteObject(local_18);
      }
      return 0;
    }
  }
  else {
    if (y == 0x100) {
      SetFocus(DAT_10176868);
      pHVar2 = GetFocus();
      PostMessageA(pHVar2,y,width,(LPARAM)str_4);
      return 0;
    }
    if (y == 0x400) {
      local_18 = (HFONT)GetWindowLongA(hwnd,0);
      local_28 = width & 0xffff;
      local_2c = width >> 0x10;
      local_24 = str_4;
      local_34 = GetDC(hwnd);
      if (local_34 != (HDC)0x0) {
        thunk_FUN_10031425(local_34);
        SelectObject(local_34,local_18);
        lpsz = &local_20;
        c = lstrlenA(local_24);
        GetTextExtentPointA(local_34,local_24,c,lpsz);
        local_30 = local_20.cx + 10;
        local_38 = local_20.cy + 6;
        ReleaseDC(hwnd,local_34);
        lpRect = &local_14;
        pHVar2 = GetParent(hwnd);
        GetClientRect(pHVar2,lpRect);
        if (local_14.right < (int)(local_30 + local_28)) {
          local_28 = local_14.right - local_30;
        }
        MoveWindow(hwnd,local_28,local_2c,local_30,local_38,1);
        SetWindowTextA(hwnd,local_24);
        ShowWindow(hwnd,5);
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
  }
  LVar3 = DefWindowProcA(hwnd,y,width,(LPARAM)str_4);
  return LVar3;
}


