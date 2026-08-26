/*
 * Decompiled function: FUN_004b26c4
 * Entry Point: 004b26c4
 * Size: 295 bytes
 */
#include "duel.h"


int FUN_004b26c4(HWND hwnd,int *y,undefined4 *arg_3,undefined4 *arg_4)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((hwnd == (HWND)0x0) || (y == (int *)0x0)) {
    local_8 = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = 0;
    local_14 = 0;
    while ((local_14 < LVar2 && (local_8 == 0))) {
      iVar3 = FUN_00486348(*(HWND *)(LVar1 + local_14 * 4),y);
      if (iVar3 != 0) {
        local_8 = 1;
        local_1c = FUN_0048644e(*(HWND *)(LVar1 + local_14 * 4));
        local_c = *(undefined4 *)(LVar1 + local_14 * 4);
      }
      local_14 = local_14 + 1;
    }
  }
  if (arg_3 != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *arg_3 = 0xffffffff;
    }
    else {
      *arg_3 = local_1c;
    }
  }
  if (arg_4 != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *arg_4 = 0;
    }
    else {
      *arg_4 = local_c;
    }
  }
  return local_8;
}


