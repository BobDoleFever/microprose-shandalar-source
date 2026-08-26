/*
 * Decompiled function: Ai_Subsystem_004b0e80
 * Entry Point: 004b0e80
 * Size: 1026 bytes
 */
#include "magic.h"


LRESULT Ai_Subsystem_004b0e80(HWND hwnd,uint uMsg,WPARAM wParam,LONG *lParam)

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
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      GetClientRect(hwnd,&local_20);
      hbr = GetStockObject(4);
      FillRect(g_HdcBackBuffer,&local_20,hbr);
      if (DAT_006ff2e8 == local_8) {
        Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_20);
      }
      else {
        Palette_Subsystem_0049f8cd
                  (g_HdcBackBuffer,&local_20.left,(WPARAM *)(&DAT_006b3070 + local_8 * 0x98),0,0);
      }
      if (local_10 != 0) {
        Palette_Subsystem_004a00d1(g_HdcBackBuffer,&local_20.left,local_c);
      }
      hdc = BeginPaint(hwnd,&local_60);
      if (hdc != (HDC)0x0) {
        FUN_004f3955(hdc);
        BitBlt(hdc,0,0,local_20.right,local_20.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        EndPaint(hwnd,&local_60);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
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
        LVar3 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
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
        if (uMsg != 0x204) goto LAB_004b11b7;
      }
      if ((((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) &&
         (local_8 = GetWindowLongA(hwnd,0), DAT_00556a68 != hwnd)) {
        SendMessageA(DAT_0069f744,0x401,local_8,0);
        DAT_00556a68 = hwnd;
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
      if (DAT_006fe444 != 2) {
        SendMessageA(DAT_0069f744,0x401,local_8,0);
      }
      return 0;
    }
  }
LAB_004b11b7:
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar3;
}


