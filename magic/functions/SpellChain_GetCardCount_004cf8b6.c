/*
 * Decompiled function: SpellChain_GetCardCount
 * Entry Point: 004cf8b6
 * Size: 175 bytes
 */
#include "magic.h"


int SpellChain_GetCardCount(HWND hwnd)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  int in_stack_000000b4;
  int local_10;
  int local_c;
  
  if (hwnd == (HWND)0x0) {
    local_10 = -1;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    local_10 = -1;
    local_c = in_stack_000000b4;
    while ((local_c < LVar2 && (local_10 == -1))) {
      iVar3 = FUN_0046bb29(*(HWND *)(LVar1 + local_c * 0x58),(int *)&stack0x00000008);
      if (iVar3 != 0) {
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_10;
}


