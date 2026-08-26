/*
 * Decompiled function: FUN_004b27eb
 * Entry Point: 004b27eb
 * Size: 171 bytes
 */
#include "duel.h"


undefined4 FUN_004b27eb(HWND hwnd,int *arg2)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_10;
  undefined4 local_8;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  local_8 = 0;
  for (local_10 = 0; local_10 < LVar2; local_10 = local_10 + 1) {
    iVar3 = FUN_00486348(*(HWND *)(LVar1 + local_10 * 4),arg2);
    if (iVar3 != 0) {
      local_8 = *(int *)(LVar1 + local_10 * 4);
    }
  }
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004b289b(hwnd,local_8);
  }
  return uVar4;
}


