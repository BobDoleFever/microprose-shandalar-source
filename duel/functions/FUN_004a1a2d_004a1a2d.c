/*
 * Decompiled function: FUN_004a1a2d
 * Entry Point: 004a1a2d
 * Size: 333 bytes
 */
#include "duel.h"


void FUN_004a1a2d(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int local_10;
  int local_c;
  
  if (((hwnd != (HWND)0x0) && (-1 < arg2)) && (arg2 < 0x65)) {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    DestroyWindow(*(HWND *)(LVar1 + arg2 * 0x58));
    for (local_10 = 0; local_10 < *(int *)(LVar1 + 0x54 + arg2 * 0x58); local_10 = local_10 + 1) {
      if (*(int *)(arg2 * 0x58 + local_10 * 4 + 4 + LVar1) != 0) {
        DestroyWindow(*(HWND *)(arg2 * 0x58 + local_10 * 4 + 4 + LVar1));
      }
    }
    for (local_c = arg2; local_c < LVar2 + -1; local_c = local_c + 1) {
      FID_conflict__memcpy
                ((void *)(local_c * 0x58 + LVar1),(void *)((local_c + 1) * 0x58 + LVar1),0x58);
    }
    SetWindowLongA(hwnd,4,LVar2 + -1);
  }
  return;
}


