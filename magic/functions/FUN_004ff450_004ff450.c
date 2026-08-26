/*
 * Decompiled function: FUN_004ff450
 * Entry Point: 004ff450
 * Size: 374 bytes
 */
#include "magic.h"


void FUN_004ff450(HWND hwnd)

{
  INT_PTR IVar1;
  
  IVar1 = DialogBoxParamA(g_AppHInstance,(LPCSTR)0xe1,hwnd,UI_DialogProc_004ff5c6,0);
  if (IVar1 != 0) {
    if (DAT_006fe448 == -1) {
      Pic_Load_004450c3(0,DAT_006a3f60,DAT_006fe44c);
    }
    else {
      Pic_Load_004450c3(0,DAT_006fe448,DAT_006fe44c);
    }
    LockWindowUpdate(g_MainAppHwnd);
    FUN_00409b2c(0,0);
    FUN_00409b2c(1,0);
    Pic_Subsystem_004441cc(g_MainAppHwnd,DAT_006fe444);
    FUN_00478163(DAT_007006b0);
    Duel_BringCardWindowToTop(DAT_006a4924);
    Duel_BringCardWindowToTop(DAT_006b2e2c);
    Pic_Subsystem_0044cfe4(DAT_0069e720);
    Pic_Subsystem_0044cfe4(DAT_006fe400);
    LockWindowUpdate((HWND)0x0);
    SendMessageA(DAT_0069e720,0x435,0,0);
    SendMessageA(DAT_006fe400,0x435,0,0);
    SendMessageA(DAT_006a4924,0x435,0,0);
    SendMessageA(DAT_006b2e2c,0x435,0,0);
    SendMessageA(DAT_006b3064,0x435,0,0);
    SendMessageA(DAT_006fe3fc,0x435,0,0);
    Rules_ParseFilter_0050065d();
  }
  return;
}


