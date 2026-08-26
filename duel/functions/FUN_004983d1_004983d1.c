/*
 * Decompiled function: FUN_004983d1
 * Entry Point: 004983d1
 * Size: 578 bytes
 */
#include "duel.h"


void FUN_004983d1(HWND hwnd,LPRECT arg2)

{
  LONG LVar1;
  LONG LVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  if ((hwnd != (HWND)0x0) && (arg2 != (LPRECT)0x0)) {
    local_30 = 5000;
    local_2c = -5000;
    local_28 = 5000;
    local_20 = 0;
    for (local_18 = 0; local_18 < LVar2; local_18 = local_18 + 1) {
      for (local_1c = 0; local_1c < *(int *)(LVar1 + 0xcc + local_18 * 0x19c);
          local_1c = local_1c + 1) {
        GetWindowRect(*(HWND *)(local_1c * 4 + local_18 * 0x19c + 4 + LVar1),&local_14);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14,2);
        if (local_14.left < local_30) {
          local_30 = local_14.left;
        }
        if (local_2c < local_14.right) {
          local_2c = local_14.right;
        }
        if (local_14.top < local_28) {
          local_28 = local_14.top;
        }
        if (local_20 < local_14.bottom) {
          local_20 = local_14.bottom;
        }
      }
      for (local_1c = 0; local_1c < *(int *)(LVar1 + 0x198 + local_18 * 0x19c);
          local_1c = local_1c + 1) {
        GetWindowRect(*(HWND *)(local_1c * 4 + local_18 * 0x19c + 0xd0 + LVar1),&local_14);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14,2);
        if (local_14.left < local_30) {
          local_30 = local_14.left;
        }
        if (local_2c < local_14.right) {
          local_2c = local_14.right;
        }
        if (local_14.top < local_28) {
          local_28 = local_14.top;
        }
        if (local_20 < local_14.bottom) {
          local_20 = local_14.bottom;
        }
      }
    }
    if (local_30 == 5000) {
      SetRect(arg2,0,0,0,0);
    }
    else {
      SetRect(arg2,local_30,local_28,local_2c,local_20);
    }
  }
  return;
}


