/*
 * Decompiled function: FUN_0043b1a4
 * Entry Point: 0043b1a4
 * Size: 705 bytes
 */
#include "duel.h"


LRESULT FUN_0043b1a4(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  BOOL BVar1;
  LONG LVar2;
  WPARAM WVar3;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar4;
  tagPAINTSTRUCT local_58;
  tagRECT local_18;
  WPARAM local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = GetWindowLongA(param_1,0);
      GetClientRect(param_1,&local_18);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&local_18,hbr);
      FUN_0042053a(DAT_0060157c,&local_18,&DAT_00618ac0 + local_8 * 0x98,0,0x11,0);
      hdc = BeginPaint(param_1,&local_58);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,local_18.right,local_18.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(param_1,&local_58);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_8 = 0xffffffff;
      SetWindowLongA(param_1,0,-1);
      return 0;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar4 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar4;
    }
    if (param_2 == 0x206) {
      local_8 = GetWindowLongA(param_1,0);
      if (DAT_00663e24 == 2) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
  else {
    if (param_2 == 0x400) {
      LVar2 = GetWindowLongA(param_1,0);
      return LVar2;
    }
    if (param_2 == 0x401) {
      WVar3 = GetWindowLongA(param_1,0);
      if (param_3 != WVar3) {
        local_8 = param_3;
        SetWindowLongA(param_1,0,param_3);
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      return 0;
    }
    if (param_2 == 0x437) {
      local_8 = GetWindowLongA(param_1,0);
      if ((DAT_00663e24 != 2) || (BVar1 = IsWindowVisible(DAT_006152e0), BVar1 != 0)) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}


