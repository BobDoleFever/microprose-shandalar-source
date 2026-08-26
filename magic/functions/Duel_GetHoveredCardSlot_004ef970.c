/*
 * Decompiled function: Duel_GetHoveredCardSlot
 * Entry Point: 004ef970
 * Size: 171 bytes
 */
#include "magic.h"


undefined4 Duel_GetHoveredCardSlot(HWND hwnd,int *arg2)

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
    iVar3 = FUN_0046bb29(*(HWND *)(LVar1 + local_10 * 4),arg2);
    if (iVar3 != 0) {
      local_8 = *(int *)(LVar1 + local_10 * 4);
    }
  }
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = Duel_GetCardSlotWindowHandle(hwnd,local_8);
  }
  return uVar4;
}


