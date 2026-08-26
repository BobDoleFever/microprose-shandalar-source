/*
 * Decompiled function: thunk_FUN_10002be9
 * Entry Point: 1000109b
 * Size: 5 bytes
 */
#include "statwin.h"


void thunk_FUN_10002be9(void)

{
  BOOL BVar1;
  char acStack_134 [256];
  int iStack_34;
  tagMSG tStack_30;
  HWND pHStack_14;
  int32_t uStack_10;
  int iStack_c;
  HWND pHStack_8;
  
  DAT_10013184 = 1;
  if (DAT_1001178c == 0) {
    pHStack_8 = (HWND)0x0;
  }
  else {
    pHStack_8 = (HWND)thunk_FUN_10001c1a();
  }
  iStack_c = GetSystemMetrics(0);
  iStack_34 = GetSystemMetrics(1);
  pHStack_14 = CreateWindowExA(0,PTR_s_STATWINCLASS_100117a0,(LPCSTR)0x0,0x90000000,0,0,iStack_c,
                               iStack_34,pHStack_8,(HMENU)0x0,DAT_1001316c,(LPVOID)0x0);
  SetFocus(pHStack_14);
  SetForegroundWindow(pHStack_14);
  thunk_FUN_1000432f(acStack_134,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
  thunk_FUN_1000308a(acStack_134);
  ShowWindow(pHStack_14,1);
  UpdateWindow(pHStack_14);
  DAT_10013180 = 0;
  uStack_10 = 0;
  while (DAT_10013180 == 0) {
    BVar1 = PeekMessageA(&tStack_30,(HWND)0x0,0,0,1);
    if (BVar1 != 0) {
      TranslateMessage(&tStack_30);
      DispatchMessageA(&tStack_30);
    }
  }
  thunk_FUN_100017b0(0xff);
  DestroyWindow(pHStack_14);
  DAT_10013184 = 0;
  return;
}


