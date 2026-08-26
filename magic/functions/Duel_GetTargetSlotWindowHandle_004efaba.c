/*
 * Decompiled function: Duel_GetTargetSlotWindowHandle
 * Entry Point: 004efaba
 * Size: 129 bytes
 */
#include "magic.h"


int Duel_GetTargetSlotWindowHandle(HWND hwnd,int arg2)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  
  LVar1 = GetWindowLongA(hwnd,0);
  LVar2 = GetWindowLongA(hwnd,4);
  local_10 = 0;
  for (local_c = 0; local_c < LVar2; local_c = local_c + 1) {
    iVar3 = FUN_0046bc92(*(HWND *)(LVar1 + local_c * 4));
    if (iVar3 == arg2) {
      local_10 = local_10 + 1;
    }
  }
  return local_10;
}


