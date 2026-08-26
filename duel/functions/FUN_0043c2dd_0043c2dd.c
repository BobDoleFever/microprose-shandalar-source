/*
 * Decompiled function: FUN_0043c2dd
 * Entry Point: 0043c2dd
 * Size: 496 bytes
 */
#include "duel.h"


void FUN_0043c2dd(LPRECT arg_1,HWND hwnd,int width,int height)

{
  HWND pHVar1;
  tagRECT *ptVar2;
  undefined1 local_c4 [64];
  undefined1 local_84 [64];
  int local_44;
  int local_40;
  tagRECT local_3c;
  tagRECT local_2c;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  FUN_00448897((int)local_c4,&local_18,(int)local_84,&local_1c);
  ptVar2 = &local_3c;
  pHVar1 = GetDlgItem(hwnd,0x43c);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_3c,2);
  ptVar2 = &local_2c;
  pHVar1 = GetDlgItem(hwnd,0x439);
  GetWindowRect(pHVar1,ptVar2);
  MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_2c,2);
  local_44 = local_3c.right - local_3c.left;
  GetClientRect(hwnd,&local_14);
  local_14.left = local_3c.left;
  if (width == 0) {
    if ((local_1c < 1) || (local_1c <= height)) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      for (local_40 = (local_44 * 0x3c) / 100;
          (local_14.right - local_3c.left < (local_1c + -1) * local_40 + local_44 &&
          ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
      }
      CopyRect(arg_1,&local_2c);
      OffsetRect(arg_1,local_40 * height,0);
    }
  }
  else if ((local_18 < 1) || (local_18 <= height)) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    for (local_40 = (local_44 * 0x3c) / 100;
        (local_14.right - local_3c.left < (local_18 + -1) * local_40 + local_44 &&
        ((local_44 * 10) / 100 < local_40)); local_40 = local_40 + -1) {
    }
    CopyRect(arg_1,&local_3c);
    OffsetRect(arg_1,local_40 * height,0);
  }
  return;
}


