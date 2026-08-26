/*
 * Decompiled function: Ai_Subsystem_004b257c
 * Entry Point: 004b257c
 * Size: 3363 bytes
 */
#include "magic.h"


HGDIOBJ Ai_Subsystem_004b257c(HWND hwnd,uint uMsg,HDC wParam,HWND lParam)

{
  HDC hDC;
  HGDIOBJ pvVar1;
  int iVar2;
  HBRUSH pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  tagRECT *ptVar6;
  tagRECT local_48;
  COLORREF local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  HWND local_24;
  HWND local_20;
  uint local_1c;
  tagRECT local_18;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_34 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_34[5].unused) {
        local_38 = DAT_0055695c;
      }
      else {
        local_38 = DAT_00556af0;
      }
      FUN_004f5107((int)local_34,DAT_00556aa8,DAT_00556a7c,DAT_00556a44,local_38,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004f3955(wParam);
      GetClientRect(hwnd,&local_48);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      iVar2 = SaveDC(g_HdcBackBuffer);
      hDC = g_HdcBackBuffer;
      if (DAT_00556aa4 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(hDC,&local_48,pHVar3);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_48,DAT_00556aa4);
      }
      Ai_Subsystem_004b35b4(&local_48,hwnd,DAT_00556ae8);
      if (DAT_00556a40 == (HANDLE)0x0) {
        pHVar3 = CreateSolidBrush(0x2908c52);
        FrameRect(hDC,&local_48,pHVar3);
        DeleteObject(pHVar3);
      }
      else {
        FUN_004f3b5f((int)hDC,(int)&local_48,DAT_00556a40);
      }
      pHVar4 = GetDlgItem(hwnd,0x422);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556994);
      }
      pHVar4 = GetDlgItem(hwnd,0x423);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556988);
      }
      pHVar4 = GetDlgItem(hwnd,0x424);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x420);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556984);
      }
      pHVar4 = GetDlgItem(hwnd,0x425);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556990);
      }
      pHVar4 = GetDlgItem(hwnd,0x426);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_0055698c);
      }
      pHVar4 = GetDlgItem(hwnd,0x427);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x421);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_004f3e29(hDC,&local_48,DAT_00556980);
      }
      RestoreDC(g_HdcBackBuffer,iVar2);
      GetClientRect(hwnd,&local_48);
      BitBlt(wParam,0,0,local_48.right,local_48.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_28 = wParam;
      FUN_004f3955(wParam);
      local_30 = lParam;
      local_2c = GetDlgCtrlID(lParam);
      SetBkMode(local_28,1);
      if (local_2c == 0x489) {
        SetTextColor(local_28,DAT_005569c4);
      }
      else {
        SetTextColor(local_28,DAT_00556ae0);
      }
      pvVar1 = GetStockObject(5);
      return pvVar1;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Ai_CalcManaRequirement_004b32d1
                (&DAT_00556aa4,&DAT_005569c4,&DAT_00556a40,&DAT_00556980,&DAT_00556ae0,
                 (int *)&DAT_00556aa8,(int *)&DAT_00556a7c,(int *)&DAT_00556a44,&DAT_00556af0,
                 &DAT_0055695c);
      SetDlgItemTextA(hwnd,0x489,(LPCSTR)local_8->unused);
      if (local_8[2].unused == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x428);
        ShowWindow(pHVar4,iVar2);
      }
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      DAT_00556ae8 = local_8[1].unused;
      if (local_8[3].unused == 0) {
        SetDlgItemTextA(hwnd,0x424,s__Swamp_0052d224);
        SetDlgItemTextA(hwnd,0x423,s__Island_0052d22c);
        SetDlgItemTextA(hwnd,0x426,s__Forest_0052d234);
        SetDlgItemTextA(hwnd,0x425,s__Mountain_0052d23c);
        SetDlgItemTextA(hwnd,0x422,s__Plains_0052d248);
        SetDlgItemTextA(hwnd,0x427,s_Generic___X__0052d250);
      }
      if ((local_8[4].unused & 2) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x420);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x424);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 4) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x423);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 8) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x426);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x10) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x425);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 0x20) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x422);
        ShowWindow(pHVar4,iVar2);
      }
      if ((local_8[4].unused & 1) == 0) {
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x421);
        ShowWindow(pHVar4,iVar2);
        iVar2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x427);
        ShowWindow(pHVar4,iVar2);
      }
      FUN_004f570c(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      local_1c = (uint)wParam & 0xffff;
      if (local_1c < 0x41d) {
        if (local_1c == 0x41c) {
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 5;
          Ai_Subsystem_004b35b4(&local_18,hwnd,5);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
        }
        else if ((local_1c != 0) && (local_1c < 3)) {
          Ai_Subsystem_004b34fe
                    ((int)DAT_00556aa4,(int)DAT_00556a40,0x556980,DAT_00556aa8,DAT_00556a7c,
                     DAT_00556a44);
          if (local_1c == 1) {
            EndDialog(hwnd,DAT_00556ae8);
          }
          else {
            EndDialog(hwnd,-2);
          }
        }
      }
      else {
        switch(local_1c) {
        case 0x41d:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 3;
          Ai_Subsystem_004b35b4(&local_18,hwnd,3);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41e:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 2;
          Ai_Subsystem_004b35b4(&local_18,hwnd,2);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41f:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 4;
          Ai_Subsystem_004b35b4(&local_18,hwnd,4);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x420:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 1;
          Ai_Subsystem_004b35b4(&local_18,hwnd,1);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x421:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = 0;
          Ai_Subsystem_004b35b4(&local_18,hwnd,0);
          InvalidateRect(hwnd,&local_18,0);
          if ((uint)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x428:
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,1);
          DAT_00556ae8 = GetWindowLongA(hwnd,8);
          Ai_Subsystem_004b35b4(&local_18,hwnd,DAT_00556ae8);
          InvalidateRect(hwnd,&local_18,0);
          pHVar4 = GetDlgItem(hwnd,1);
          SetFocus(pHVar4);
        }
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
    local_20 = (HWND)wParam;
    local_24 = lParam;
    pHVar4 = GetDlgItem(hwnd,2);
    if (pHVar4 == local_20) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (local_20 != (HWND)0x0) {
      InvalidateRect(local_20,(RECT *)0x0,1);
    }
    if (local_24 != (HWND)0x0) {
      InvalidateRect(local_24,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}


