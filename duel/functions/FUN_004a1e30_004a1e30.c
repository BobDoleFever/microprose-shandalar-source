/*
 * Decompiled function: FUN_004a1e30
 * Entry Point: 004a1e30
 * Size: 229 bytes
 */
#include "duel.h"


void FUN_004a1e30(HWND hwnd,int arg2)

{
  LONG LVar1;
  int local_c;
  
  if (((hwnd != (HWND)0x0) && (-1 < arg2)) && (arg2 < 0x65)) {
    LVar1 = GetWindowLongA(hwnd,0);
    GetWindowLongA(hwnd,4);
    for (local_c = 0; local_c < *(int *)(LVar1 + 0x54 + arg2 * 0x58); local_c = local_c + 1) {
      if (*(int *)(arg2 * 0x58 + local_c * 4 + 4 + LVar1) != 0) {
        DestroyWindow(*(HWND *)(arg2 * 0x58 + local_c * 4 + 4 + LVar1));
      }
    }
    *(undefined4 *)(LVar1 + 0x54 + arg2 * 0x58) = 0;
  }
  return;
}


