/*
 * Decompiled function: FUN_100373af
 * Entry Point: 100373af
 * Size: 632 bytes
 */
#include "deckdll.h"


void FUN_100373af(HDC hdc,RECT *arg_2,WPARAM *arg_3,int height)

{
  int val_1;
  tagRECT local_44;
  tagRECT local_34;
  HFONT local_24;
  int local_20;
  tagRECT local_1c;
  HBRUSH local_c;
  int local_8;
  
  local_20 = SaveDC(hdc);
  CopyRect(&local_1c,arg_2);
  local_c = DAT_10175f00;
  local_8 = 0;
  InflateRect(&local_1c,-2,-2);
  FrameRect(hdc,&local_1c,local_c);
  InflateRect(&local_1c,-1,-1);
  FrameRect(hdc,&local_1c,local_c);
  InflateRect(&local_1c,-2,-2);
  local_1c.bottom = local_1c.bottom + -2;
  SetRect(&local_44,local_1c.left,local_1c.top + (local_1c.bottom - local_1c.top) / 5,local_1c.right
          ,local_1c.bottom);
  if ((local_44.bottom - local_44.top) * 5 < (local_44.right - local_44.left) * 4) {
    val_1 = (local_44.bottom - local_44.top) * 5;
    local_44.right = (int)(val_1 + (val_1 >> 0x1f & 3U)) >> 2;
    local_44.left = local_1c.left + ((local_1c.right - local_1c.left) - local_44.right) / 2;
    local_44.right = local_44.left + local_44.right;
  }
  else {
    local_44.top = local_44.bottom - ((local_44.right - local_44.left) * 4) / 5;
  }
  SetRect(&local_34,local_1c.left,local_1c.top,local_1c.right,local_44.top + -1);
  local_24 = CreateFontA((local_34.bottom - local_34.top) / 2,0,0,0,400,0,0,0,0,4,0,0,0x10,
                         (LPCSTR)0x0);
  SelectObject(hdc,local_24);
  if (height == 0) {
    FillRect(hdc,&local_1c,DAT_10175f00);
    SetBkMode(hdc,1);
    SetTextColor(hdc,0xffffff);
  }
  else {
    FillRect(hdc,&local_1c,local_c);
    SetBkMode(hdc,1);
    SetTextColor(hdc,0xffffff);
  }
  DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_1c,0x19);
  if (*(int *)(&DAT_10162910 + *arg_3 * 0x10) == 0) {
    thunk_FUN_10028a10(*arg_3,0,DAT_10176468,DAT_1016e4b0);
  }
  thunk_FUN_10028d12(hdc,&local_44,*arg_3,0);
  RestoreDC(hdc,local_20);
  DeleteObject(local_24);
  if (local_8 != 0) {
    DeleteObject(local_c);
  }
  return;
}


