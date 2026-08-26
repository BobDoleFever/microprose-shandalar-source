/*
 * Decompiled function: FUN_004994f8
 * Entry Point: 004994f8
 * Size: 688 bytes
 */
#include "duel.h"


int FUN_004994f8(HWND hwnd,int *arg_2,undefined4 *arg_3,undefined4 *arg_4,undefined4 *arg_5)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((hwnd == (HWND)0x0) || (arg_2 == (int *)0x0)) {
    local_8 = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    local_8 = 0;
    for (local_14 = 0; local_14 < LVar2; local_14 = local_14 + 1) {
      local_18 = 0;
      while ((local_18 < *(int *)(LVar1 + 0xcc + local_14 * 0x19c) && (local_8 == 0))) {
        iVar3 = FUN_00486348(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1),arg_2);
        if (iVar3 != 0) {
          local_8 = 1;
          local_20 = FUN_0048644e(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1));
          local_10 = *(undefined4 *)(local_18 * 4 + local_14 * 0x19c + 4 + LVar1);
          local_c = 1;
        }
        local_18 = local_18 + 1;
      }
      local_18 = 0;
      while ((local_18 < *(int *)(LVar1 + 0x198 + local_14 * 0x19c) && (local_8 == 0))) {
        iVar3 = FUN_00486348(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1),arg_2);
        if (iVar3 != 0) {
          local_8 = 1;
          local_20 = FUN_0048644e(*(HWND *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1));
          local_10 = *(undefined4 *)(local_18 * 4 + local_14 * 0x19c + 0xd0 + LVar1);
          local_c = 0;
        }
        local_18 = local_18 + 1;
      }
    }
  }
  if (arg_3 != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *arg_3 = 0xffffffff;
    }
    else {
      *arg_3 = local_20;
    }
  }
  if (arg_4 != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *arg_4 = 0;
    }
    else {
      *arg_4 = local_10;
    }
  }
  if (arg_5 != (undefined4 *)0x0) {
    if (local_8 == 0) {
      *arg_5 = 0;
    }
    else {
      *arg_5 = local_c;
    }
  }
  return local_8;
}


