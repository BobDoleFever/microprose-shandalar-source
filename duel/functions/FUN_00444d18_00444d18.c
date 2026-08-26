/*
 * Decompiled function: FUN_00444d18
 * Entry Point: 00444d18
 * Size: 2369 bytes
 */
#include "duel.h"


HGDIOBJ FUN_00444d18(HWND param_1,uint param_2,HWND param_3,HWND param_4)

{
  HGDIOBJ pvVar1;
  HBRUSH hbr;
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
  
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      local_2c = param_4;
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
      FUN_00471f45(local_2c,DAT_00516aa8,DAT_005169ec,DAT_00516a90,local_30,0);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x14) {
      local_48 = param_3;
      FUN_004707a4(param_3);
      GetClientRect(param_1,&local_40);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_44 = SaveDC(DAT_0060157c);
      local_48 = (HWND)DAT_0060157c;
      if (DAT_005169e8 == 0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_48,&local_40,hbr);
      }
      else {
        FUN_004709ae(DAT_0060157c,&local_40,DAT_005169e8);
      }
      if (DAT_005169f0 != 0xffffffff) {
        ptVar4 = &local_40;
        pHVar2 = GetDlgItem(param_1,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_40,2);
        FUN_004215c2(local_48,&local_40,&DAT_00618ac0 + DAT_005169f0 * 0x98,DAT_005169e0,
                     DAT_005169e4,0x11,DAT_00663e10);
      }
      RestoreDC(DAT_0060157c,local_44);
      local_48 = param_3;
      GetClientRect(param_1,&local_40);
      BitBlt((HDC)local_48,0,0,local_40.right,local_40.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x136) {
    if (param_2 == 0x135) {
LAB_00445207:
      local_20 = param_3;
      FUN_004707a4(param_3);
      local_28 = param_4;
      local_24 = GetDlgCtrlID(param_4);
      if ((local_24 != 0x498) && (local_24 != 0x499)) {
        pHVar2 = GetFocus();
        if (pHVar2 == local_28) {
          SetTextColor((HDC)local_20,DAT_00516b1c);
        }
        else {
          SetTextColor((HDC)local_20,DAT_00516af4);
        }
        SetBkMode((HDC)local_20,1);
        pvVar1 = GetStockObject(5);
        return pvVar1;
      }
      SetTextColor((HDC)local_20,DAT_00516af4);
      SetBkMode((HDC)local_20,1);
      return DAT_00516aa8;
    }
    if (param_2 == 0x110) {
      local_8 = param_4;
      FUN_0044565e(&DAT_005169e8,&DAT_00516af4,&DAT_00516aa8,&DAT_005169ec,&DAT_00516a90,
                   &DAT_005169fc,&DAT_00516b1c);
      SetWindowTextA(param_1,(LPCSTR)local_8->unused);
      DAT_005169e0 = local_8[3].unused;
      DAT_005169e4 = local_8[4].unused;
      DAT_005169f0 = FUN_00447184(DAT_005169e0,DAT_005169e4);
      nCmdShow = 0;
      pHVar2 = GetDlgItem(param_1,0x474);
      ShowWindow(pHVar2,nCmdShow);
      if (local_8[2].unused == 0) {
        SetDlgItemTextA(param_1,0x431,s__Black_004f7e48);
        SetDlgItemTextA(param_1,0x430,s_Bl_ue_004f7e50);
        SetDlgItemTextA(param_1,0x433,s__Green_004f7e58);
        SetDlgItemTextA(param_1,0x432,&DAT_004f7e60);
        SetDlgItemTextA(param_1,0x42f,s__White_004f7e68);
        SetDlgItemTextA(param_1,0x436,s__Black_004f7e70);
        SetDlgItemTextA(param_1,0x435,s_Bl_ue_004f7e78);
        SetDlgItemTextA(param_1,0x438,s__Green_004f7e80);
        SetDlgItemTextA(param_1,0x437,&DAT_004f7e88);
        SetDlgItemTextA(param_1,0x434,s__White_004f7e90);
      }
      CheckDlgButton(param_1,0x42f,1);
      CheckRadioButton(param_1,0x42f,0x433,0x42f);
      CheckDlgButton(param_1,0x438,1);
      CheckRadioButton(param_1,0x434,0x438,0x438);
      SetWindowLongA(param_1,8,(uint)(ushort)local_8[2].unused << 0x10 | 0x820);
      pHVar2 = GetDlgItem(param_1,1);
      SetFocus(pHVar2);
      SendMessageA(param_1,0x401,1,0);
      FUN_00472552(param_1);
      return (HGDIOBJ)0x1;
    }
    if (param_2 == 0x111) {
      local_10 = (uint)param_3 & 0xffff;
      local_c = GetWindowLongA(param_1,8);
      if (local_10 == 1) {
        FUN_0044573a(DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
        EndDialog(param_1,local_c);
      }
      else if (local_10 == 2) {
        FUN_0044573a(DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
        EndDialog(param_1,-2);
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
        SetWindowLongA(param_1,8,local_c);
        if ((((char)local_c == '\0') || (local_c._1_1_ == 0)) ||
           ((uint)local_c._1_1_ == (local_c & 0xff))) {
          BVar3 = 0;
          pHVar2 = GetDlgItem(param_1,1);
          EnableWindow(pHVar2,BVar3);
        }
        else {
          BVar3 = 1;
          pHVar2 = GetDlgItem(param_1,1);
          EnableWindow(pHVar2,BVar3);
        }
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
LAB_004454c1:
      if (((param_2 == 0x200) && (DAT_00663e24 != 2)) || ((param_2 == 0x204 && (DAT_00663e24 == 2)))
         ) {
        ptVar4 = &local_58;
        pHVar2 = GetDlgItem(param_1,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_58,2);
        if ((DAT_005169f0 != 0xffffffff) &&
           (BVar3 = PtInRect(&local_58,
                             (POINT)(CONCAT44((uint)param_4 >> 0x10,param_4) & 0xffffffff0000ffff)),
           BVar3 != 0)) {
          SendMessageA(DAT_006152e0,0x401,DAT_005169f0,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (param_2 == 0x138) goto LAB_00445207;
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) goto LAB_004454c1;
    if (param_2 == 0x201) {
      SendMessageA(param_1,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (0x30e < param_2) {
    if (param_2 < 0x312) {
      pvVar1 = (HGDIOBJ)FUN_00472b60(param_1,param_2,param_3,param_4);
      return pvVar1;
    }
    if (param_2 == 0x4c8) {
      local_14 = param_3;
      local_18 = param_4;
      pHVar2 = GetDlgItem(param_1,2);
      if (pHVar2 == local_14) {
        SendMessageA(param_1,0x401,2,0);
      }
      else {
        SendMessageA(param_1,0x401,1,0);
      }
      if (local_14 != (HWND)0x0) {
        InvalidateRect(local_14,(RECT *)0x0,1);
      }
      if (local_18 != (HWND)0x0) {
        InvalidateRect(local_18,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}


