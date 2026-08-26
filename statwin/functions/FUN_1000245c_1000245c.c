/*
 * Decompiled function: StatWin_ProcessPendingEvents
 * Entry Point: 1000245c
 * Size: 161 bytes
 */
#include "statwin.h"


int32_t StatWin_ProcessPendingEvents(void)

{
  BOOL BVar1;
  HWND hWndParent;
  DLGPROC lpDialogFunc;
  LPARAM dwInitParam;
  tagMSG local_24;
  int32_t local_8;
  
  local_8 = 0;
  BVar1 = PeekMessageA(&local_24,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&local_24);
    if ((local_24.message == 0x205) && (DAT_10013184 != 0)) {
      dwInitParam = 0;
      lpDialogFunc = (DLGPROC)&LAB_10001019;
      hWndParent = (HWND)thunk_FUN_10001c1a();
      DialogBoxParamA(DAT_1001316c,(LPCSTR)0x65,hWndParent,lpDialogFunc,dwInitParam);
    }
    if ((local_24.message == 0x202) || (local_24.message == 0x100)) {
      local_8 = 1;
    }
    DispatchMessageA(&local_24);
  }
  return local_8;
}


