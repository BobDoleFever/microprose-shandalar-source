/*
 * Decompiled function: FUN_0044233e
 * Entry Point: 0044233e
 * Size: 1024 bytes
 */
#include "duel.h"


LRESULT FUN_0044233e(HWND param_1,uint param_2,WPARAM param_3,LONG *param_4)

{
  HWND pHVar1;
  uint uVar2;
  HWND hWnd;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar3;
  UINT Msg;
  tagPAINTSTRUCT local_60;
  tagRECT local_20;
  WPARAM local_10;
  LONG *local_c;
  WPARAM local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = GetWindowLongA(param_1,0);
      local_10 = GetWindowLongA(param_1,8);
      local_c = (LONG *)GetWindowLongA(param_1,4);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(param_1,&local_20);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&local_20,hbr);
      if (DAT_0068f108 == local_8) {
        FUN_0042043e(DAT_0060157c,&local_20);
      }
      else {
        FUN_00423651(DAT_0060157c,&local_20,&DAT_00618ac0 + local_8 * 0x98,0,0);
      }
      if (local_10 != 0) {
        FUN_00423e55(DAT_0060157c,&local_20,local_c);
      }
      hdc = BeginPaint(param_1,&local_60);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,local_20.right,local_20.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(param_1,&local_60);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_8 = *param_4;
      SetWindowLongA(param_1,0,local_8);
      local_10 = 0;
      local_c = (LONG *)0x0;
      SetWindowLongA(param_1,8,0);
      SetWindowLongA(param_1,4,(LONG)local_c);
      return 0;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      pHVar1 = GetParent(param_1);
      SendMessageA(pHVar1,param_2,param_3,(LPARAM)param_4);
      return 0;
    }
    if (param_2 == 0x87) {
      return 4;
    }
  }
  else {
    if (param_2 < 0x312) {
      if (0x30e < param_2) {
        LVar3 = FUN_00472b60(param_1,param_2,param_3,param_4);
        return LVar3;
      }
      if (param_2 != 0x200) {
        if (param_2 == 0x201) {
          pHVar1 = param_1;
          uVar2 = GetDlgCtrlID(param_1);
          uVar2 = uVar2 & 0xffff | 0x10000;
          Msg = 0x111;
          hWnd = GetParent(param_1);
          SendMessageA(hWnd,Msg,uVar2,(LPARAM)pHVar1);
          return 0;
        }
        if (param_2 != 0x204) goto LAB_00442673;
      }
      if ((((param_2 == 0x200) && (DAT_00663e24 != 2)) ||
          ((param_2 == 0x204 && (DAT_00663e24 == 2)))) &&
         (local_8 = GetWindowLongA(param_1,0), DAT_00516a98 != param_1)) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
        DAT_00516a98 = param_1;
      }
      return 0;
    }
    if (param_2 == 0x414) {
      local_10 = param_3;
      local_c = param_4;
      SetWindowLongA(param_1,8,param_3);
      SetWindowLongA(param_1,4,(LONG)local_c);
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 == 0x437) {
      local_8 = GetWindowLongA(param_1,0);
      if (DAT_00663e24 != 2) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
LAB_00442673:
  LVar3 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
  return LVar3;
}


