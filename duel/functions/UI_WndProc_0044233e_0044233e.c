/*
 * Decompiled function: UI_WndProc_0044233e
 * Entry Point: 0044233e
 * Size: 1024 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_0044233e(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam)

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
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      local_10 = GetWindowLongA(hwnd,8);
      local_c = (LONG *)GetWindowLongA(hwnd,4);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(hwnd,&local_20);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&local_20,hbr);
      if (DAT_0068f108 == local_8) {
        FUN_0042043e(DAT_0060157c,&local_20);
      }
      else {
        FUN_00423651(DAT_0060157c,&local_20.left,(undefined4 *)(&DAT_00618ac0 + local_8 * 0x98),0,0)
        ;
      }
      if (local_10 != 0) {
        FUN_00423e55(DAT_0060157c,&local_20.left,local_c);
      }
      hdc = BeginPaint(hwnd,&local_60);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,local_20.right,local_20.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_60);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = *lParam;
      SetWindowLongA(hwnd,0,local_8);
      local_10 = 0;
      local_c = (LONG *)0x0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)local_c);
      return 0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      pHVar1 = GetParent(hwnd);
      SendMessageA(pHVar1,uMsg,wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x87) {
      return 4;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        LVar3 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
        return LVar3;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          pHVar1 = hwnd;
          uVar2 = GetDlgCtrlID(hwnd);
          uVar2 = uVar2 & 0xffff | 0x10000;
          Msg = 0x111;
          hWnd = GetParent(hwnd);
          SendMessageA(hWnd,Msg,uVar2,(LPARAM)pHVar1);
          return 0;
        }
        if (uMsg != 0x204) goto LAB_00442673;
      }
      if ((((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) &&
         (local_8 = GetWindowLongA(hwnd,0), DAT_00516a98 != hwnd)) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
        DAT_00516a98 = hwnd;
      }
      return 0;
    }
    if (uMsg == 0x414) {
      local_10 = wParam;
      local_c = lParam;
      SetWindowLongA(hwnd,8,wParam);
      SetWindowLongA(hwnd,4,(LONG)local_c);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x437) {
      local_8 = GetWindowLongA(hwnd,0);
      if (DAT_00663e24 != 2) {
        SendMessageA(DAT_006152e0,0x401,local_8,0);
      }
      return 0;
    }
  }
LAB_00442673:
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar3;
}


