/*
 * Decompiled function: UI_DialogProc_00444d18
 * Entry Point: 00444d18
 * Size: 2369 bytes
 */
#include "duel.h"


HBRUSH UI_DialogProc_00444d18(HWND hwnd,uint uMsg,HWND wParam,HWND lParam)

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
        local_30 = DAT_00516b1c;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005169fc;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_00471f45((int)local_2c,DAT_00516aa8,DAT_005169ec,DAT_00516a90,local_30,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      local_48 = wParam;
      FUN_004707a4((HDC)wParam);
      GetClientRect(hwnd,&local_40);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_44 = SaveDC(DAT_0060157c);
      local_48 = (HWND)DAT_0060157c;
      if (DAT_005169e8 == (HANDLE)0x0) {
        pHVar1 = GetStockObject(2);
        FillRect((HDC)local_48,&local_40,pHVar1);
      }
      else {
        FUN_004709ae((int)DAT_0060157c,(int)&local_40,DAT_005169e8);
      }
      if (DAT_005169f0 != 0xffffffff) {
        ptVar4 = &local_40;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_40,2);
        FUN_004215c2((HDC)local_48,&local_40.left,(int)(&DAT_00618ac0 + DAT_005169f0 * 0x98),
                     DAT_005169e0,DAT_005169e4,0x11,DAT_00663e10);
      }
      RestoreDC(DAT_0060157c,local_44);
      local_48 = wParam;
      GetClientRect(hwnd,&local_40);
      BitBlt((HDC)local_48,0,0,local_40.right,local_40.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_00445207:
      local_20 = wParam;
      FUN_004707a4((HDC)wParam);
      local_28 = lParam;
      local_24 = GetDlgCtrlID(lParam);
      if ((local_24 != 0x498) && (local_24 != 0x499)) {
        pHVar2 = GetFocus();
        if (pHVar2 == local_28) {
          SetTextColor((HDC)local_20,DAT_00516b1c);
        }
        else {
          SetTextColor((HDC)local_20,DAT_00516af4);
        }
        SetBkMode((HDC)local_20,1);
        pHVar1 = GetStockObject(5);
        return pHVar1;
      }
      SetTextColor((HDC)local_20,DAT_00516af4);
      SetBkMode((HDC)local_20,1);
      return DAT_00516aa8;
    }
    if (uMsg == 0x110) {
      local_8 = lParam;
      Pic_Load_s_WINBK_ChangeText_0044565e
                (&DAT_005169e8,&DAT_00516af4,(int *)&DAT_00516aa8,(int *)&DAT_005169ec,
                 (int *)&DAT_00516a90,&DAT_005169fc,&DAT_00516b1c);
      SetWindowTextA(hwnd,(LPCSTR)local_8->unused);
      DAT_005169e0 = local_8[3].unused;
      DAT_005169e4 = local_8[4].unused;
      DAT_005169f0 = FUN_00447184(DAT_005169e0,DAT_005169e4);
      nCmdShow = 0;
      pHVar2 = GetDlgItem(hwnd,0x474);
      ShowWindow(pHVar2,nCmdShow);
      if (local_8[2].unused == 0) {
        SetDlgItemTextA(hwnd,0x431,s__Black_004f7e48);
        SetDlgItemTextA(hwnd,0x430,s_Bl_ue_004f7e50);
        SetDlgItemTextA(hwnd,0x433,s__Green_004f7e58);
        SetDlgItemTextA(hwnd,0x432,&DAT_004f7e60);
        SetDlgItemTextA(hwnd,0x42f,s__White_004f7e68);
        SetDlgItemTextA(hwnd,0x436,s__Black_004f7e70);
        SetDlgItemTextA(hwnd,0x435,s_Bl_ue_004f7e78);
        SetDlgItemTextA(hwnd,0x438,s__Green_004f7e80);
        SetDlgItemTextA(hwnd,0x437,&DAT_004f7e88);
        SetDlgItemTextA(hwnd,0x434,s__White_004f7e90);
      }
      CheckDlgButton(hwnd,0x42f,1);
      CheckRadioButton(hwnd,0x42f,0x433,0x42f);
      CheckDlgButton(hwnd,0x438,1);
      CheckRadioButton(hwnd,0x434,0x438,0x438);
      SetWindowLongA(hwnd,8,(uint)(ushort)local_8[2].unused << 0x10 | 0x820);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_00472552(hwnd);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x111) {
      local_10 = (uint)wParam & 0xffff;
      local_c = GetWindowLongA(hwnd,8);
      if (local_10 == 1) {
        FUN_0044573a((int)DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
        EndDialog(hwnd,local_c);
      }
      else if (local_10 == 2) {
        FUN_0044573a((int)DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
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
        if ((((char)local_c == '\0') || (local_c._1_1_ == 0)) ||
           ((uint)local_c._1_1_ == (local_c & 0xff))) {
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
LAB_004454c1:
      if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
        ptVar4 = &local_58;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_58,2);
        if ((DAT_005169f0 != 0xffffffff) &&
           (BVar3 = PtInRect(&local_58,
                             (POINT)(CONCAT44((uint)lParam >> 0x10,lParam) & 0xffffffff0000ffff)),
           BVar3 != 0)) {
          SendMessageA(DAT_006152e0,0x401,DAT_005169f0,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_00445207;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004454c1;
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar1 = (HBRUSH)FUN_00472b60(hwnd,uMsg,wParam,lParam);
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


