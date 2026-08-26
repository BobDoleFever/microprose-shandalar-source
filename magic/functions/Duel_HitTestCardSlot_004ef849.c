/*
 * Decompiled function: Duel_HitTestCardSlot
 * Entry Point: 004ef849
 * Size: 295 bytes
 */
#include "magic.h"


int Duel_HitTestCardSlot(HWND hwnd,int *y,undefined4 *arg_3,undefined4 *arg_4)

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
      iVar3 = FUN_0046bb29(*(HWND *)(LVar1 + local_14 * 4),y);
      if (iVar3 != 0) {
        local_8 = 1;
        local_1c = FUN_0046bc2f(*(HWND *)(LVar1 + local_14 * 4));
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


