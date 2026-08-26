/*
 * Decompiled function: StatWin_ProcessMessagePump
 * Entry Point: 100023fd
 * Size: 67 bytes
 */
#include "statwin.h"


int32_t StatWin_ProcessMessagePump(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  }
  return 0;
}


