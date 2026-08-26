/*
 * Decompiled function: FUN_00479e3f
 * Entry Point: 00479e3f
 * Size: 362 bytes
 */
#include "magic.h"


void FUN_00479e3f(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  LONG local_1c;
  HANDLE local_18;
  tagRECT local_14;
  
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    local_1c = GetWindowLongA(hwnd,0x20);
    local_18 = (HANDLE)GetWindowLongA(hwnd,0x18);
    LVar1 = GetWindowLongA(hwnd,0x1c);
    GetClientRect(hwnd,&local_14);
    if ((local_18 == (HANDLE)0x0) || (LVar1 == 0)) {
      SetRect(arg2,local_1c - local_14.right / 0x14,0,local_1c + local_14.right / 0x14,
              local_14.bottom);
    }
    else {
      GetObjectA(local_18,0x18,local_3c);
      local_24 = local_14.bottom;
      local_20 = ((local_38 / 2) * local_14.bottom) / (local_34 / LVar1);
      SetRect(arg2,local_1c - local_20 / 2,0,(local_1c - local_20 / 2) + local_20,local_14.bottom);
    }
    if (arg2->left < local_14.left) {
      OffsetRect(arg2,local_14.left - arg2->left,0);
    }
    else if (local_14.right < arg2->right) {
      OffsetRect(arg2,local_14.right - arg2->right,0);
    }
  }
  return;
}


