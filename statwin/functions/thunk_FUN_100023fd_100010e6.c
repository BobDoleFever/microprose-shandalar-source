/*
 * Decompiled function: thunk_FUN_100023fd
 * Entry Point: 100010e6
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t thunk_FUN_100023fd(void)

{
  BOOL BVar1;
  tagMSG tStack_20;
  
  BVar1 = PeekMessageA(&tStack_20,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&tStack_20);
    DispatchMessageA(&tStack_20);
  }
  return 0;
}


