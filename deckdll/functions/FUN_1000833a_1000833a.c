/*
 * Decompiled function: FUN_1000833a
 * Entry Point: 1000833a
 * Size: 111 bytes
 */
#include "deckdll.h"


HWND FUN_1000833a(HWND hwnd,int arg2)

{
  LRESULT LVar1;
  int32_t local_c;
  int32_t local_8;
  
  local_8 = (HWND)0x0;
  for (local_c = GetTopWindow(hwnd); local_c != (HWND)0x0; local_c = GetWindow(local_c,2)) {
    LVar1 = SendMessageA(local_c,0x400,0,0);
    if (LVar1 == arg2) {
      local_8 = local_c;
    }
  }
  return local_8;
}


