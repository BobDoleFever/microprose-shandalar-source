/*
 * Decompiled function: Ai_Subsystem_004b3847
 * Entry Point: 004b3847
 * Size: 2379 bytes
 */
#include "magic.h"


HBRUSH Ai_Subsystem_004b3847(HWND hwnd,uint uMsg,HWND wParam,HWND lParam)

{
  HBRUSH pHVar1;
  HWND pHVar2;
  int nCmdShow;
  BOOL BVar3;
  tagRECT *ptVar4;
  tagRECT local_58;
  HWND local_48;
  int local_44;
  tagRECT local_40;
  COLORREF local_30;
  HWND local_2c;
  HWND local_28;
  int local_24;
  HWND local_20;
  HWND local_18;
  HWND local_14;
  uint local_10;
  undefined4 local_c;
  HWND local_8;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_2c = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_2c[5].unused) {
        local_30 = DAT_00556aec;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005569cc;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_004f5107((int)local_2c,DAT_00556a78,DAT_005569bc,DAT_00556a60,local_30,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      local_48 = wParam;
      FUN_004f3955((HDC)wParam);
      GetClientRect(hwnd,&local_40);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_44 = SaveDC(g_HdcBackBuffer);
      local_48 = (HWND)g_HdcBackBuffer;
      if (DAT_005569b8 == (HANDLE)0x0) {
        pHVar1 = GetStockObject(2);
        FillRect((HDC)local_48,&local_40,pHVar1);
      }
      else {
        FUN_004f3b5f((int)g_HdcBackBuffer,(int)&local_40,DAT_005569b8);
      }
      if (DAT_005569c0 != 0xffffffff) {
        ptVar4 = &local_40;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_40,2);
        Palette_Subsystem_0049d843
                  ((HDC)local_48,&local_40.left,(int)(&DAT_006b3070 + DAT_005569c0 * 0x98),
                   DAT_005569b0,DAT_005569b4,0x11,DAT_006fe430);
      }
      RestoreDC(g_HdcBackBuffer,local_44);
      local_48 = wParam;
      GetClientRect(hwnd,&local_40);
      BitBlt((HDC)local_48,0,0,local_40.right,local_40.bottom,g_HdcBackBuffer,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_004b3d43:
      local_20 = wParam;
      FUN_004f3955((HDC)wParam);
      local_28 = lParam;
      local_24 = GetDlgCtrlID(lParam);
      if ((local_24 != 0x498) && (local_24 != 0x499)) {
        pHVar2 = GetFocus();
        if (pHVar2 == local_28) {
          SetTextColor((HDC)local_20,DAT_00556aec);
        }
        else {
          SetTextColor((HDC)local_20,DAT_00556ac4);
        }
        SetBkMode((HDC)local_20,1);
        pHVar1 = GetStockObject(5);
        return pHVar1;
      }
      SetTextColor((HDC)local_20,DAT_00556ac4);
      SetBkMode((HDC)local_20,1);
      return DAT_00556a78;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      Ai_Subsystem_004b4197
                (&DAT_005569b8,&DAT_00556ac4,(int *)&DAT_00556a78,(int *)&DAT_005569bc,
                 (int *)&DAT_00556a60,&DAT_005569cc,&DAT_00556aec);
      SetWindowTextA(hwnd,(LPCSTR)local_8->unused);
      DAT_005569b0 = local_8[3].unused;
      DAT_005569b4 = local_8[4].unused;
      DAT_005569c0 = Ai_Subsystem_004b5cbb(DAT_005569b0,DAT_005569b4);
      nCmdShow = 0;
      pHVar2 = GetDlgItem(hwnd,0x474);
      ShowWindow(pHVar2,nCmdShow);
      if (local_8[2].unused == 0) {
        SetDlgItemTextA(hwnd,0x431,s__Black_0052d328);
        SetDlgItemTextA(hwnd,0x430,s_Bl_ue_0052d330);
        SetDlgItemTextA(hwnd,0x433,s__Green_0052d338);
        SetDlgItemTextA(hwnd,0x432,&DAT_0052d340);
        SetDlgItemTextA(hwnd,0x42f,s__White_0052d348);
        SetDlgItemTextA(hwnd,0x436,s__Black_0052d350);
        SetDlgItemTextA(hwnd,0x435,s_Bl_ue_0052d358);
        SetDlgItemTextA(hwnd,0x438,s__Green_0052d360);
        SetDlgItemTextA(hwnd,0x437,&DAT_0052d368);
        SetDlgItemTextA(hwnd,0x434,s__White_0052d370);
      }
      CheckDlgButton(hwnd,0x42f,1);
      CheckRadioButton(hwnd,0x42f,0x433,0x42f);
      CheckDlgButton(hwnd,0x438,1);
      CheckRadioButton(hwnd,0x434,0x438,0x438);
      SetWindowLongA(hwnd,8,(uint)(ushort)local_8[2].unused << 0x10 | 0x820);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_004f570c(hwnd);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x111) {
      local_10 = (uint)wParam & 0xffff;
      local_c = GetWindowLongA(hwnd,8);
      if (local_10 == 1) {
        Ai_Subsystem_004b4274((int)DAT_005569b8,DAT_00556a78,DAT_005569bc,DAT_00556a60);
        EndDialog(hwnd,local_c);
      }
      else if (local_10 == 2) {
        Ai_Subsystem_004b4274((int)DAT_005569b8,DAT_00556a78,DAT_005569bc,DAT_00556a60);
        EndDialog(hwnd,-2);
      }
      else {
        if (local_10 == 0x431) {
          local_c = local_c & 0xffffff02 | 2;
        }
        else if (local_10 == 0x42f) {
          local_c = local_c & 0xffffff20 | 0x20;
        }
        else if (local_10 == 0x433) {
          local_c = local_c & 0xffffff08 | 8;
        }
        else if (local_10 == 0x430) {
          local_c = local_c & 0xffffff04 | 4;
        }
        else if (local_10 == 0x432) {
          local_c = local_c & 0xffffff10 | 0x10;
        }
        else if (local_10 == 0x436) {
          local_c = local_c & 0xffff02ff | 0x200;
        }
        else if (local_10 == 0x434) {
          local_c = local_c & 0xffff20ff | 0x2000;
        }
        else if (local_10 == 0x438) {
          local_c = local_c & 0xffff08ff | 0x800;
        }
        else if (local_10 == 0x435) {
          local_c = local_c & 0xffff04ff | 0x400;
        }
        else if (local_10 == 0x437) {
          local_c = local_c & 0xffff10ff | 0x1000;
        }
        SetWindowLongA(hwnd,8,local_c);
        if ((((char)local_c == '\0') || (local_c._1_1_ == '\0')) ||
           ((local_c & 0xffff) >> 8 == (local_c & 0xff))) {
          BVar3 = 0;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
        else {
          BVar3 = 1;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004b3ffd:
      if (((uMsg == 0x200) && (DAT_006fe444 != 2)) || ((uMsg == 0x204 && (DAT_006fe444 == 2)))) {
        ptVar4 = &local_58;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_58,2);
        if ((DAT_005569c0 != 0xffffffff) &&
           (BVar3 = PtInRect(&local_58,
                             (POINT)(CONCAT44((uint)lParam >> 0x10,lParam) & 0xffffffff0000ffff)),
           BVar3 != 0)) {
          SendMessageA(DAT_0069f744,0x401,DAT_005569c0,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_004b3d43;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004b3ffd;
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar1 = (HBRUSH)FUN_004f5d1a(hwnd,uMsg,wParam,lParam);
      return pHVar1;
    }
    if (uMsg == 0x4c8) {
      local_14 = wParam;
      local_18 = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == local_14) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_14 != (HWND)0x0) {
        InvalidateRect(local_14,(RECT *)0x0,1);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}


