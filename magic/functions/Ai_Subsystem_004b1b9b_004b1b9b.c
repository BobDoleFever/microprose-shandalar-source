/*
 * Decompiled function: Ai_Subsystem_004b1b9b
 * Entry Point: 004b1b9b
 * Size: 1344 bytes
 */
#include "magic.h"


HGDIOBJ Ai_Subsystem_004b1b9b(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  HWND pHVar2;
  int iVar3;
  HBRUSH hbr;
  code *dwNewLong;
  tagRECT local_44;
  COLORREF local_34;
  HWND local_30;
  HWND local_2c;
  int local_28;
  HDC local_24;
  HWND local_20;
  HWND local_1c;
  UINT local_18;
  UINT local_14;
  int local_10;
  uint local_c;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_30 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_30[5].unused) {
        local_34 = DAT_00556a88;
      }
      else {
        local_34 = DAT_00556958;
      }
      FUN_004f5107((int)local_30,DAT_00556950,DAT_00556a48,DAT_005569d0,local_34,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_44);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      iVar3 = SaveDC(g_HdcBackBuffer);
      hDC = g_HdcBackBuffer;
      if (DAT_00556adc == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hDC,&local_44,hbr);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_44,DAT_00556adc);
      }
      RestoreDC(g_HdcBackBuffer,iVar3);
      GetClientRect(hwnd,&local_44);
      BitBlt(wParam,0,0,local_44.right,local_44.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_24 = wParam;
      FUN_004f3955(wParam);
      local_2c = lParam;
      local_28 = GetDlgCtrlID(lParam);
      SetBkMode(local_24,1);
      SetTextColor(local_24,DAT_00556a70);
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Ai_Subsystem_004b2183
                (&DAT_00556adc,&DAT_00556a70,(int *)&DAT_00556950,(int *)&DAT_00556a48,
                 (int *)&DAT_005569d0,&DAT_00556958,&DAT_00556a88);
      SetDlgItemTextA(hwnd,0x41a,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        iVar3 = 0;
        pHVar2 = GetDlgItem(hwnd,0x41b);
        ShowWindow(pHVar2,iVar3);
      }
      SendMessageA(hwnd,0x401,1,0);
      SetDlgItemInt(hwnd,0x419,local_8[1].unused,0);
      dwNewLong = Ai_Subsystem_004b20e5;
      iVar3 = -4;
      pHVar2 = GetDlgItem(hwnd,0x419);
      DAT_006498ec = SetWindowLongA(pHVar2,iVar3,(LONG)dwNewLong);
      pHVar2 = GetDlgItem(hwnd,0x419);
      SetFocus(pHVar2);
      SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      local_c = (uint)wParam & 0xffff;
      if (local_c == 1) {
        local_14 = GetDlgItemInt(hwnd,0x419,&local_10,0);
        if (local_10 == 0) {
          pHVar2 = GetDlgItem(hwnd,0x419);
          SetFocus(pHVar2);
          SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
        }
        else {
          Ai_Subsystem_004b2260((int)DAT_00556adc,DAT_00556950,DAT_00556a48,DAT_005569d0);
          EndDialog(hwnd,local_14);
        }
      }
      else if (local_c == 2) {
        Ai_Subsystem_004b2260((int)DAT_00556adc,DAT_00556950,DAT_00556a48,DAT_005569d0);
        EndDialog(hwnd,-1);
      }
      else if (local_c == 0x41b) {
        local_18 = GetWindowLongA(hwnd,8);
        SetDlgItemInt(hwnd,0x419,local_18,0);
        pHVar2 = GetDlgItem(hwnd,0x419);
        SetFocus(pHVar2);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      pvVar1 = (HGDIOBJ)FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return pvVar1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    local_1c = (HWND)wParam;
    local_20 = lParam;
    pHVar2 = GetDlgItem(hwnd,2);
    if (pHVar2 == local_1c) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (local_1c != (HWND)0x0) {
      InvalidateRect(local_1c,(RECT *)0x0,1);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


