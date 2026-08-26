/*
 * Decompiled function: UI_CreateWindow_004410df
 * Entry Point: 004410df
 * Size: 4321 bytes
 */
#include "duel.h"


LRESULT UI_CreateWindow_004410df(HWND hwnd,uint y,HDC hdc,undefined4 *arg_4)

{
  uint uVar1;
  int iVar2;
  DWORD dwStyle;
  int cx;
  int iVar3;
  int iVar4;
  LRESULT LVar5;
  HGDIOBJ pvVar6;
  HDC hdc_00;
  size_t c;
  BOOL bMenu;
  UINT uFlags;
  tagSIZE *psizl;
  LONG local_15c;
  LONG local_154;
  tagRECT local_150;
  tagSIZE local_140;
  int local_138;
  tagRECT local_134;
  CHAR local_124 [100];
  HDC local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  LONG local_ac;
  uint local_a8;
  tagRECT local_a4;
  tagRECT local_94;
  HDC local_84;
  tagRECT local_80;
  uint local_70;
  int local_6c;
  uint local_68;
  int local_64;
  tagRECT local_60;
  uint local_50;
  uint local_4c;
  uint local_48;
  LONG local_44;
  undefined4 *local_40;
  LONG local_3c;
  HWND local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_84 = hdc;
      FUN_004707a4(hdc);
      GetClientRect(hwnd,&local_80);
      FillRect(local_84,&local_80,DAT_00516ac8);
      return 1;
    }
    if (y == 0x10) {
LAB_00441443:
      local_3c = GetWindowLongA(hwnd,8);
      if (local_3c == 0) {
        FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
        EndDialog(hwnd,-1);
      }
      return 1;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      if (hdc == (HDC)0xc8) {
        SendMessageA(hwnd,0x10,0,0);
        local_15c = 0;
      }
      else {
        local_15c = DefWindowProcA(hwnd,0xa1,(WPARAM)hdc,(LPARAM)arg_4);
      }
      SetWindowLongA(hwnd,0,local_15c);
      return 1;
    }
    if (y == 0x84) {
      local_154 = DefWindowProcA(hwnd,0x84,(WPARAM)hdc,(LPARAM)arg_4);
      if ((local_154 == 8) || (local_154 == 2)) {
        hdc_00 = GetDC((HWND)0x0);
        psizl = &local_140;
        c = _strlen((char *)((int)DAT_005169cc + 0x650));
        GetTextExtentPoint32A(hdc_00,(LPCSTR)((int)DAT_005169cc + 0x650),c,psizl);
        ReleaseDC((HWND)0x0,hdc_00);
        GetClientRect(hwnd,&local_150);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_150,2);
        if (local_150.right - local_140.cx <= (int)((uint)arg_4 & 0xffff)) {
          local_154 = 200;
        }
      }
      SetWindowLongA(hwnd,0,local_154);
      return 1;
    }
    if ((0x84 < y) && (y < 0x87)) {
      local_ac = GetWindowLongA(hwnd,8);
      GetWindowRect(hwnd,&local_94);
      OffsetRect(&local_94,-local_94.left,-local_94.top);
      if ((local_94.right != local_94.left) && (local_94.bottom != local_94.top)) {
        if (y == 0x85) {
          DefWindowProcA(hwnd,0x85,(WPARAM)hdc,(LPARAM)arg_4);
        }
        local_a8 = (uint)(y != 0x85);
        local_c0 = GetWindowDC(hwnd);
        if (local_c0 != (HDC)0x0) {
          FUN_004707a4(local_c0);
          GetWindowRect(hwnd,&local_94);
          GetClientRect(hwnd,&local_134);
          MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_134,2);
          OffsetRect(&local_134,-local_94.left,-local_94.top);
          OffsetRect(&local_94,-local_94.left,-local_94.top);
          GetWindowTextA(hwnd,local_124,100);
          local_138 = local_134.left - local_94.left;
          local_b4 = local_94.bottom - local_134.bottom;
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -1,local_b8);
          SelectObject(local_c0,DAT_00516998);
          local_b8 = 1;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,(local_94.right - local_138) + 1,local_b8);
            local_b8 = local_b8 + 1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_b4 + -1;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom + -1);
          SelectObject(local_c0,DAT_00516998);
          local_b0 = 1;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + 1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = local_134.left + -1;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b0 = local_94.right + -1;
          MoveToEx(local_c0,local_b0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom);
          SelectObject(local_c0,DAT_0051699c);
          local_b0 = local_94.right + -2;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + -1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = local_94.right - local_138;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b8 = local_94.bottom + -1;
          MoveToEx(local_c0,0,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right,local_b8);
          SelectObject(local_c0,DAT_0051699c);
          local_b8 = local_94.bottom + -2;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,local_94.right + -1,local_b8);
            local_b8 = local_b8 + -1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_94.bottom - local_b4;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -2,local_b8);
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_134.top + -1;
          MoveToEx(local_c0,local_134.left,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SetRect(&local_a4,local_134.left,local_b4,local_94.right - local_138,local_134.top + -1);
          FillRect(local_c0,&local_a4,DAT_00516a8c);
          SetTextColor(local_c0,DAT_00516af0);
          SetBkMode(local_c0,1);
          local_a4.left = local_a4.left + 5;
          DrawTextA(local_c0,local_124,-1,&local_a4,0x24);
          if (local_ac == 0) {
            DrawTextA(local_c0,(LPCSTR)((int)DAT_005169cc + 0x650),-1,&local_a4,0x26);
          }
          ReleaseDC(hwnd,local_c0);
        }
        SetWindowLongA(hwnd,0,local_a8);
        return 1;
      }
      LVar5 = DefWindowProcA(hwnd,y,(WPARAM)hdc,(LPARAM)arg_4);
      return LVar5;
    }
  }
  else if (y < 0x111) {
    if (y == 0x110) {
      local_34 = 1;
      DAT_005169cc = arg_4;
      SetWindowLongA(hwnd,8,arg_4[0x193]);
      DAT_00516a98 = 0;
      FUN_004421e2((int *)&DAT_00516ac8,(int *)&DAT_00516998,(int *)&DAT_00516acc,
                   (int *)&DAT_0051699c,(int *)&DAT_00516a8c,&DAT_00516af0);
      SetWindowTextA(hwnd,(LPCSTR)*DAT_005169cc);
      local_30 = DAT_005169cc[0x191];
      DAT_005169a4 = (DAT_0061534c * 2) / 3;
      DAT_00516b04 = (DAT_0061898c * 2) / 3;
      DAT_00516978 = 8;
      DAT_00516968 = 8;
      local_2c = 6;
      if (local_30 % 6 == 1) {
        local_2c = 5;
      }
      local_18 = local_30 / local_2c;
      if (0 < local_30 % local_2c) {
        local_18 = local_18 + 1;
      }
      local_1c = 4;
      SetRect(&local_14,0,0,(DAT_005169a4 + 8) * local_2c + 8,(DAT_00516b04 + 8) * local_18 + 8);
      uVar1 = GetWindowLongA(hwnd,-0x10);
      SetWindowLongA(hwnd,-0x10,uVar1 & 0xffdfffff);
      if (local_1c < local_18) {
        uVar1 = GetWindowLongA(hwnd,-0x10);
        SetWindowLongA(hwnd,-0x10,uVar1 | 0x200000);
        SetScrollRange(hwnd,1,0,local_14.bottom -
                                ((DAT_00516b04 + DAT_00516968) * local_1c + DAT_00516968),1);
        SetScrollPos(hwnd,1,0,1);
        local_14.bottom = (DAT_00516b04 + DAT_00516968) * local_1c + local_14.top + DAT_00516968;
        iVar2 = GetSystemMetrics(2);
        local_14.right = local_14.right + iVar2;
      }
      bMenu = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&local_14,dwStyle,bMenu);
      uFlags = 4;
      iVar2 = local_14.bottom - local_14.top;
      cx = local_14.right - local_14.left;
      iVar3 = GetSystemMetrics(1);
      iVar3 = (iVar3 - (local_14.bottom - local_14.top)) / 2;
      iVar4 = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(iVar4 - (local_14.right - local_14.left)) / 2,iVar3,cx,iVar2,
                   uFlags);
      local_20 = DAT_00516978;
      local_24 = DAT_00516968;
      GetClientRect(hwnd,&local_14);
      for (local_28 = 0; local_28 < (int)DAT_005169cc[0x191]; local_28 = local_28 + 1) {
        local_38 = CreateWindowExA(0,s_ShowListCard_004f7d20,s_List_Card_004f7d14,0x50000000,
                                   local_20,local_24,DAT_005169a4,DAT_00516b04,hwnd,
                                   (HMENU)(local_28 + 10),DAT_00664680,
                                   (LPVOID)DAT_005169cc[local_28 + 1]);
        if (DAT_005169cc[0x192] != 0) {
          SendMessageA(local_38,0x414,1,DAT_005169cc[local_28 + 0xc9]);
        }
        local_20 = local_20 + DAT_00516978 + DAT_005169a4;
        if (local_14.right < local_20 + DAT_005169a4) {
          local_24 = local_24 + DAT_00516b04 + DAT_00516968;
          local_20 = DAT_00516978;
        }
      }
      SetFocus(hwnd);
      return 0;
    }
    if (y == 0x100) {
      if (hdc == (HDC)0x22) {
        SendMessageA(hwnd,0x115,3,0);
      }
      else if (hdc == (HDC)0x21) {
        SendMessageA(hwnd,0x115,2,0);
      }
      else if (hdc == (HDC)0x28) {
        SendMessageA(hwnd,0x115,1,0);
      }
      else if (hdc == (HDC)0x26) {
        SendMessageA(hwnd,0x115,0,0);
      }
      else if (hdc == (HDC)0x1b) {
        SendMessageA(hwnd,0x10,0,0);
      }
      return 1;
    }
  }
  else if (y < 0x116) {
    if (y == 0x115) {
      local_70 = GetScrollPos(hwnd,1);
      GetScrollRange(hwnd,1,(LPINT)&local_68,(LPINT)&local_50);
      GetClientRect(hwnd,&local_60);
      local_6c = DAT_00516b04 + DAT_00516968;
      local_64 = local_60.bottom - DAT_00516968;
      switch((uint)hdc & 0xffff) {
      case 0:
        local_4c = local_70 - local_6c;
        break;
      case 1:
        local_4c = local_6c + local_70;
        break;
      case 2:
      case 4:
      case 5:
        local_4c = (uint)hdc >> 0x10;
        break;
      case 3:
        local_4c = local_70 + local_64;
        break;
      default:
        local_4c = local_70;
      }
      if ((int)local_4c < (int)local_68) {
        local_4c = local_68;
      }
      if ((int)local_50 < (int)local_4c) {
        local_4c = local_50;
      }
      ScrollWindow(hwnd,0,-(local_4c - local_70),(RECT *)0x0,(RECT *)0x0);
      SetScrollPos(hwnd,1,local_4c,1);
      return 1;
    }
    if (y == 0x111) {
      local_48 = (uint)hdc & 0xffff;
      local_40 = arg_4;
      local_44 = GetWindowLongA(hwnd,8);
      if ((local_48 == 2) || (local_48 == 1)) {
        if (local_44 == 0) {
          FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
          EndDialog(hwnd,-1);
        }
      }
      else if (local_40 != (undefined4 *)0x0) {
        FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
        EndDialog(hwnd,local_48 - 10);
      }
      return 1;
    }
  }
  else {
    if (y == 0x201) goto LAB_00441443;
    if ((0x30e < y) && (y < 0x312)) {
      LVar5 = FUN_00472b60(hwnd,y,(HWND)hdc,arg_4);
      return LVar5;
    }
  }
  return 0;
}


