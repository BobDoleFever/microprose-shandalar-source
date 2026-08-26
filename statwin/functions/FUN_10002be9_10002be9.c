/*
 * Decompiled function: StatWin_CreateStatusWindow
 * Entry Point: 10002be9
 * Size: 335 bytes
 */
#include "statwin.h"


void StatWin_CreateStatusWindow(void)

{
  BOOL BVar1;
  char local_134 [256];
  int local_34;
  tagMSG local_30;
  HWND local_14;
  int32_t local_10;
  int local_c;
  HWND local_8;
  
  DAT_10013184 = 1;
  if (DAT_1001178c == 0) {
    local_8 = (HWND)0x0;
  }
  else {
    local_8 = (HWND)thunk_FUN_10001c1a();
  }
  local_c = GetSystemMetrics(0);
  local_34 = GetSystemMetrics(1);
  local_14 = CreateWindowExA(0,PTR_s_STATWINCLASS_100117a0,(LPCSTR)0x0,0x90000000,0,0,local_c,
                             local_34,local_8,(HMENU)0x0,DAT_1001316c,(LPVOID)0x0);
  SetFocus(local_14);
  SetForegroundWindow(local_14);
  thunk_FUN_1000432f(local_134,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
  thunk_FUN_1000308a(local_134);
  ShowWindow(local_14,1);
  UpdateWindow(local_14);
  DAT_10013180 = 0;
  local_10 = 0;
  while (DAT_10013180 == 0) {
    BVar1 = PeekMessageA(&local_30,(HWND)0x0,0,0,1);
    if (BVar1 != 0) {
      TranslateMessage(&local_30);
      DispatchMessageA(&local_30);
    }
  }
  thunk_FUN_100017b0(0xff);
  DestroyWindow(local_14);
  DAT_10013184 = 0;
  return;
}


