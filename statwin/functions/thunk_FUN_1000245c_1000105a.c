/*
 * Decompiled function: thunk_FUN_1000245c
 * Entry Point: 1000105a
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t thunk_FUN_1000245c(void)

{
  BOOL BVar1;
  HWND hWndParent;
  DLGPROC lpDialogFunc;
  LPARAM dwInitParam;
  tagMSG tStack_24;
  int32_t uStack_8;
  
  uStack_8 = 0;
  BVar1 = PeekMessageA(&tStack_24,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&tStack_24);
    if ((tStack_24.message == 0x205) && (DAT_10013184 != 0)) {
      dwInitParam = 0;
      lpDialogFunc = (DLGPROC)&LAB_10001019;
      hWndParent = (HWND)thunk_FUN_10001c1a();
      DialogBoxParamA(DAT_1001316c,(LPCSTR)0x65,hWndParent,lpDialogFunc,dwInitParam);
    }
    if ((tStack_24.message == 0x202) || (tStack_24.message == 0x100)) {
      uStack_8 = 1;
    }
    DispatchMessageA(&tStack_24);
  }
  return uStack_8;
}


