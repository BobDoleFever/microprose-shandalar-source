/*
 * Decompiled function: UI_WndProc_004822b7
 * Entry Point: 004822b7
 * Size: 2732 bytes
 */
#include "magic.h"


uint UI_WndProc_004822b7(HWND hwnd,uint uMsg,uint wParam,int lParam)

{
  HGDIOBJ h;
  HWND hWnd;
  uint uVar1;
  tagRECT *lpRect;
  char local_27c [264];
  undefined4 local_174;
  int local_170;
  int local_16c;
  int local_168;
  HDC local_164;
  undefined1 local_160 [4];
  int local_15c;
  int local_158;
  int local_148;
  int local_144;
  tagPAINTSTRUCT local_140;
  int local_100;
  tagRECT local_fc;
  tagRECT local_ec;
  int local_dc;
  int local_d8;
  HGDIOBJ local_d4;
  tagRECT local_d0;
  CHAR local_c0 [100];
  HBRUSH local_5c;
  HDC local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  tagRECT local_40;
  HGDIOBJ local_30;
  tagRECT local_2c;
  int local_1c;
  HGDIOBJ local_18;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      if (DAT_00539534 == (HANDLE)0x0) {
        strcpy(local_27c,&DAT_006b2e90);
        strcat(local_27c,s__WINBK_AttackSword_pic_00526db8);
        DAT_00539534 = (HANDLE)Pic_Load_00423833(local_27c);
      }
      if (DAT_00539564 == (HANDLE)0x0) {
        strcpy(local_27c,&DAT_006b2e90);
        strcat(local_27c,s__WINBK_AttackShield_pic_00526dd0);
        DAT_00539564 = (HANDLE)Pic_Load_00423833(local_27c);
      }
      Ai_Subsystem_004b74b1(&local_dc,(undefined4 *)0x0);
      local_164 = BeginPaint(hwnd,&local_140);
      if (local_164 != (HDC)0x0) {
        FUN_004f3955(local_164);
        GetClientRect(hwnd,&local_ec);
        SendMessageA(DAT_006b3064,0x14,(WPARAM)local_164,0);
        lpRect = &local_fc;
        hWnd = GetDlgItem(DAT_006b3064,0);
        GetWindowRect(hWnd,lpRect);
        MapWindowPoints((HWND)0x0,DAT_006b3064,(LPPOINT)&local_fc,2);
        local_148 = DAT_006b2e30;
        local_144 = (DAT_006b2e30 * 5) / 100;
        if (DAT_00539534 != (HANDLE)0x0) {
          local_100 = SaveDC(local_164);
          GetObjectA(DAT_00539534,0x18,local_160);
          local_15c = local_15c / 2;
          if (local_dc == 1) {
            local_170 = local_ec.top + DAT_00539584;
            local_168 = local_170 + local_148;
          }
          else {
            local_170 = local_fc.bottom + local_144;
            local_168 = local_170 + local_148;
            SetMapMode(local_164,8);
            SetViewportExtEx(local_164,1,-1,(LPSIZE)0x0);
            SetWindowExtEx(local_164,1,1,(LPSIZE)0x0);
            SetViewportOrgEx(local_164,0,local_ec.bottom - DAT_00539584,(LPPOINT)0x0);
            SetWindowOrgEx(local_164,0,local_170,(LPPOINT)0x0);
          }
          local_174 = 5;
          local_16c = ((local_168 - local_170) * local_15c) / local_158 + 5;
          FUN_004f3e29(local_164,&local_174,DAT_00539534);
          RestoreDC(local_164,local_100);
        }
        if (DAT_00539564 != (HANDLE)0x0) {
          GetObjectA(DAT_00539564,0x18,local_160);
          local_15c = local_15c / 2;
          if (local_dc == 0) {
            local_170 = local_ec.top + DAT_00539584;
            local_168 = local_170 + local_148;
          }
          else {
            local_168 = local_ec.bottom - DAT_00539584;
            local_170 = local_168 - local_148;
          }
          local_174 = 5;
          local_16c = ((local_168 - local_170) * local_15c) / local_158 + 5;
          FUN_004f3e29(local_164,&local_174,DAT_00539564);
        }
        EndPaint(hwnd,&local_140);
      }
      return 0;
    }
    if (uMsg == 6) {
      local_8 = DefWindowProcA(hwnd,6,wParam,lParam);
      if (wParam == 0) {
        return local_8;
      }
      SetActiveWindow(DAT_006b3064);
      return local_8;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      uVar1 = UI_WndProc_004f4fb8(hwnd,0x20,wParam,lParam);
      return uVar1;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x113) {
    if (uMsg == 0x112) {
      if ((wParam & 0xfff0) == 0xf010) {
        return 0;
      }
      uVar1 = DefWindowProcA(hwnd,0x112,wParam,lParam);
      return uVar1;
    }
    if (uMsg == 0x83) {
      local_c = lParam;
      local_10 = *(undefined4 *)(lParam + 8);
      uVar1 = DefWindowProcA(hwnd,0x83,wParam,lParam);
      *(undefined4 *)(local_c + 8) = local_10;
      return uVar1;
    }
    if ((0x84 < uMsg) && (uMsg < 0x87)) {
      GetWindowRect(hwnd,&local_2c);
      OffsetRect(&local_2c,-local_2c.left,-local_2c.top);
      if ((local_2c.right != local_2c.left) && (local_2c.bottom != local_2c.top)) {
        local_44 = (uint)(uMsg != 0x85);
        local_58 = GetWindowDC(hwnd);
        if (local_58 == (HDC)0x0) {
          return local_44;
        }
        FUN_004f3955(local_58);
        GetWindowRect(hwnd,&local_2c);
        GetClientRect(hwnd,&local_d0);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_d0,2);
        OffsetRect(&local_d0,-local_2c.left,-local_2c.top);
        OffsetRect(&local_2c,-local_2c.left,-local_2c.top);
        GetWindowTextA(hwnd,local_c0,100);
        local_d8 = local_d0.left - local_2c.left;
        local_4c = local_2c.bottom - local_d0.bottom;
        Ai_Subsystem_004b74b1(&local_1c,(undefined4 *)0x0);
        if (local_1c == 0) {
          local_30 = DAT_00539550;
          local_d4 = DAT_00539580;
          local_18 = DAT_0053953c;
          local_5c = DAT_00539558;
        }
        else {
          local_30 = DAT_00539568;
          local_d4 = DAT_0053956c;
          local_18 = DAT_00539548;
          local_5c = DAT_00539578;
        }
        SelectObject(local_58,local_d4);
        local_50 = 0;
        MoveToEx(local_58,0,0,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,local_30);
        local_50 = 1;
        for (local_54 = 1; local_54 <= local_4c + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,1,local_50,(LPPOINT)0x0);
          LineTo(local_58,local_2c.right,local_50);
          local_50 = local_50 + 1;
        }
        SelectObject(local_58,local_d4);
        local_50 = local_4c + -1;
        MoveToEx(local_58,local_d8 + -1,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_d0.right,local_50);
        SelectObject(local_58,local_d4);
        local_48 = 0;
        MoveToEx(local_58,0,0,(LPPOINT)0x0);
        LineTo(local_58,local_48,local_2c.bottom + -1);
        SelectObject(local_58,local_30);
        local_48 = 1;
        for (local_54 = 1; local_54 <= local_d8 + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,local_48,1,(LPPOINT)0x0);
          LineTo(local_58,local_48,local_2c.bottom + -1);
          local_48 = local_48 + 1;
        }
        SelectObject(local_58,local_d4);
        local_48 = local_d0.left + -1;
        MoveToEx(local_58,local_48,local_4c + -1,(LPPOINT)0x0);
        LineTo(local_58,local_48,local_d0.bottom + 1);
        h = GetStockObject(7);
        SelectObject(local_58,h);
        local_50 = local_2c.bottom + -1;
        MoveToEx(local_58,0,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,local_18);
        local_50 = local_2c.bottom + -2;
        for (local_54 = 1; local_54 <= local_4c + -2; local_54 = local_54 + 1) {
          MoveToEx(local_58,1,local_50,(LPPOINT)0x0);
          LineTo(local_58,local_2c.right,local_50);
          local_50 = local_50 + -1;
        }
        SelectObject(local_58,local_d4);
        local_50 = local_2c.bottom - local_4c;
        MoveToEx(local_58,local_d8 + -1,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SelectObject(local_58,local_d4);
        local_50 = local_d0.top + -1;
        MoveToEx(local_58,local_d0.left,local_50,(LPPOINT)0x0);
        LineTo(local_58,local_2c.right,local_50);
        SetRect(&local_40,local_d0.left,local_4c,local_d0.right,local_d0.top + -1);
        FillRect(local_58,&local_40,local_5c);
        SetTextColor(local_58,DAT_0053954c);
        SetBkMode(local_58,1);
        DrawTextA(local_58,local_c0,-1,&local_40,0x24);
        ReleaseDC(hwnd,local_58);
        return local_44;
      }
      uVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
      return uVar1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    uVar1 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
    return uVar1;
  }
  uVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return uVar1;
}


