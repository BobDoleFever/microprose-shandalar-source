/*
 * Decompiled function: FUN_0041a6c6
 * Entry Point: 0041a6c6
 * Size: 4921 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0041a6c6(HWND param_1,uint param_2,int *param_3,int *param_4)

{
  POINT Point;
  int *piVar1;
  LONG LVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  HBRUSH pHVar7;
  DWORD DVar8;
  HWND pHVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  LRESULT LVar13;
  tagPOINT local_30c;
  int local_304;
  tagPOINT local_300;
  tagRECT local_2f8;
  int local_2e8;
  int local_2e4;
  uint local_2e0;
  HDC local_2dc;
  tagPAINTSTRUCT local_2d8;
  int local_298;
  tagRECT local_294;
  uint local_284;
  DWORD local_280;
  int local_264;
  int local_260;
  int local_25c;
  int local_258;
  int *local_254;
  CHAR local_250 [264];
  ULONG_PTR local_148;
  CHAR local_144 [264];
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  LONG local_c;
  int *local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = (int *)GetWindowLongA(param_1,0);
      local_10 = GetWindowLongA(param_1,4);
      local_18 = GetWindowLongA(param_1,8);
      local_14 = GetWindowLongA(param_1,0xc);
      local_c = GetWindowLongA(param_1,0x10);
      if ((((local_8 == (int *)0xffffffff) || (DAT_0068f108 == local_8)) ||
          (DAT_0061743c + -1 < (int)local_8)) && ((DAT_00663e24 == 2 && (DAT_006152e0 == param_1))))
      {
        SendMessageA(param_1,0x113,1,0);
        LVar13 = DefWindowProcA(param_1,0xf,(WPARAM)param_3,(LPARAM)param_4);
        return LVar13;
      }
      if (DAT_00666720 == local_8) {
        local_284 = FUN_00446ea2(local_10,local_18);
      }
      else if (DAT_00666444 == local_8) {
        FUN_004479d5(local_10,local_18,&local_2e0,&local_2e4);
        local_284 = local_2e4 << 0x10 | local_2e0 & 0xffff;
      }
      else {
        local_284 = 0;
      }
      if ((local_10 == -1) || (local_18 == -1)) {
        local_298 = 0;
      }
      else {
        uVar6 = FUN_0044781f(local_10,local_18);
        local_298 = FUN_0048c367(uVar6);
      }
      if (local_284 != local_14) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      if (local_298 != local_c) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_280 = GetTickCount();
      GetClientRect(param_1,&local_294);
      local_2dc = BeginPaint(param_1,&local_2d8);
      if (local_2dc != (HDC)0x0) {
        FUN_004707a4(local_2dc);
        if (DAT_00601580 != 0) {
          pHVar7 = GetStockObject(0);
          FillRect(local_2dc,&local_294,pHVar7);
          Sleep(200);
        }
        if (DAT_0061743c + -1 < (int)local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_294,pHVar7);
          FUN_0042043e(DAT_0060157c,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
        }
        else if (((int)local_8 < 0) || (DAT_0068f108 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_294,pHVar7);
          FUN_0042043e(DAT_0060157c,&local_294);
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
        }
        else if ((((DAT_00666720 == local_8) || (DAT_00666450 == local_8)) ||
                 (DAT_00666444 == local_8)) || (DAT_0066aae8 == local_8)) {
          pHVar7 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_294,pHVar7);
          iVar4 = FUN_00447184(local_10,local_18);
          if (iVar4 == -1) {
            FUN_0042043e(DAT_0060157c,&local_294);
          }
          else {
            FUN_00422b2d(DAT_0060157c,&local_294,local_8,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
        }
        else if (DAT_0068f0fc == local_8) {
          pHVar7 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_294,pHVar7);
          iVar4 = FUN_00447184(local_10,local_18);
          if (iVar4 == -1) {
            FUN_0042043e(DAT_0060157c,&local_294);
          }
          else {
            FUN_0042297a(DAT_0060157c,&local_294,local_10,local_18);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
        }
        else {
          pHVar7 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_294,pHVar7);
          if (((local_10 == -1) || (local_18 == -1)) ||
             (iVar4 = FUN_00447184(local_10,local_18), iVar4 == -1)) {
            if (local_8 == (int *)0xffffffff) {
              FUN_0042043e(DAT_0060157c,&local_294);
              local_2e8 = 1;
            }
            else {
              local_2e8 = FUN_0042053a(DAT_0060157c,&local_294,&DAT_00618ac0 + (int)local_8 * 0x98,0
                                       ,0,DAT_00663e10);
            }
          }
          else {
            local_2e8 = FUN_004215c2(DAT_0060157c,&local_294,&DAT_00618ac0 + (int)local_8 * 0x98,
                                     local_10,local_18,0,DAT_00663e10);
          }
          BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
          if (local_2e8 == 0) {
            if (((local_10 == -1) || (local_18 == -1)) ||
               (iVar4 = FUN_00447184(local_10,local_18), iVar4 == -1)) {
              if (local_8 != (int *)0xffffffff) {
                FUN_0042053a(DAT_0060157c,&local_294,&DAT_00618ac0 + (int)local_8 * 0x98,0,2,
                             DAT_00663e10);
              }
            }
            else {
              FUN_004215c2(DAT_0060157c,&local_294,&DAT_00618ac0 + (int)local_8 * 0x98,local_10,
                           local_18,2,DAT_00663e10);
            }
            BitBlt(local_2dc,0,0,local_294.right,local_294.bottom,DAT_0060157c,0,0,0xcc0020);
          }
        }
        EndPaint(param_1,&local_2d8);
        local_14 = local_284;
        SetWindowLongA(param_1,0xc,local_284);
        local_c = local_298;
        SetWindowLongA(param_1,0x10,local_298);
      }
      DVar8 = GetTickCount();
      _DAT_0060d494 = _DAT_0060d494 + (DVar8 - local_280);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_8 = (int *)0xffffffff;
      SetWindowLongA(param_1,0,-1);
      local_10 = 0xffffffff;
      local_18 = -1;
      SetWindowLongA(param_1,4,-1);
      SetWindowLongA(param_1,8,local_18);
      local_14 = 0;
      SetWindowLongA(param_1,0xc,0);
      local_c = 0;
      SetWindowLongA(param_1,0x10,0);
      local_254 = param_4;
      local_25c = param_4[5];
      local_264 = param_4[4];
      local_260 = (local_264 * 200) / 300;
      local_258 = (local_25c * 300) / 200;
      iVar4 = FUN_004d9810(local_258 - local_264);
      iVar5 = FUN_004d9810(local_260 - local_25c);
      if (4 < iVar4 + iVar5) {
        if (local_260 < local_25c) {
          SetWindowPos(param_1,(HWND)0x0,0,0,local_260,local_264,6);
        }
        else {
          SetWindowPos(param_1,(HWND)0x0,0,0,local_25c,local_258,6);
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      LVar13 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar13;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      uVar3 = (uint)param_3 & 0xffff;
      if (uVar3 == 1) {
        DAT_00663e10 = (uint)(DAT_00663e10 == 0);
        FUN_00481890();
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      else if (uVar3 == 100) {
        local_3c = (int *)GetWindowLongA(param_1,0);
        if (DAT_0068f108 == local_3c) {
          local_3c = (int *)0xc1b;
        }
        if (local_3c != (int *)0xffffffff) {
          FUN_004d9630(local_144,&DAT_005f76e0);
          FUN_004d9640(local_144,s__duel_hlp_004f2c9c);
          WinHelpA(DAT_00618990,local_144,1,(ULONG_PTR)local_3c);
        }
      }
      else if (uVar3 == 0x65) {
        local_148 = 0x7e7;
        FUN_004d9630(local_250,&DAT_005f76e0);
        FUN_004d9640(local_250,s__duel_hlp_004f2ca8);
        WinHelpA(DAT_00618990,local_250,1,local_148);
      }
      return 0;
    }
    if (param_2 == 0x46) {
      DefWindowProcA(param_1,0x46,(WPARAM)param_3,(LPARAM)param_4);
      iVar4 = param_4[4];
      iVar5 = param_4[5];
      iVar10 = (iVar5 * 200) / 300;
      iVar11 = (iVar4 * 300) / 200;
      iVar12 = FUN_004d9810(iVar10 - iVar4);
      iVar5 = FUN_004d9810(iVar11 - iVar5);
      if (iVar12 + iVar5 < 5) {
        return 0;
      }
      if (iVar10 < iVar4) {
        param_4[4] = iVar10;
      }
      else {
        param_4[5] = iVar11;
      }
      return 0;
    }
  }
  else if (param_2 < 0x118) {
    if (param_2 == 0x117) {
      AppendMenuA(DAT_0050abb8,0,1,s_Expand_text_box_004f2cb4);
      if (DAT_00663e10 != 0) {
        CheckMenuItem(DAT_0050abb8,1,8);
      }
      AppendMenuA(DAT_0050abb8,0,100,s_Help_for_this_card____004f2cc4);
      AppendMenuA(DAT_0050abb8,0,0x65,s_Help____004f2cdc);
      return 0;
    }
    if (param_2 == 0x113) {
      if ((param_3 == (int *)0x1) && (DAT_00663e24 == 2)) {
        GetCursorPos(&local_30c);
        Point.y = local_30c.y;
        Point.x = local_30c.x;
        pHVar9 = WindowFromPoint(Point);
        if (pHVar9 != param_1) {
          SendMessageA(param_1,0x201,1,0);
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
      pHVar9 = GetParent(param_1);
      if (pHVar9 != DAT_00618990) {
        return 0;
      }
      return 0;
    }
    if (param_2 == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (param_4 == (int *)0x0)) {
        local_304 = GetMenuItemCount(DAT_0050abb8);
        while (local_304 != 0) {
          local_304 = local_304 + -1;
          DeleteMenu(DAT_0050abb8,0,0x400);
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x205) {
    if (param_2 == 0x204) {
      local_300.x = (uint)param_4 & 0xffff;
      local_300.y = (uint)param_4 >> 0x10;
      ClientToScreen(param_1,&local_300);
      SetRect(&local_2f8,local_300.x,local_300.y,local_300.x + 1,local_300.y + 1);
      TrackPopupMenu(DAT_0050abb8,2,local_300.x,local_300.y,0,param_1,&local_2f8);
      return 0;
    }
    if (param_2 == 0x201) {
      if (DAT_00663e24 == 2) {
        ShowWindow(param_1,0);
        KillTimer(param_1,1);
      }
      return 0;
    }
  }
  else if (param_2 < 0x402) {
    if (param_2 == 0x401) {
      local_8 = param_3;
      local_30 = param_4;
      if (((((DAT_00666720 == param_3) || (DAT_00666450 == param_3)) || (DAT_00666444 == param_3))
          || (DAT_0066aae8 == param_3)) &&
         (((param_4 == (int *)0x0 || (*param_4 == -1)) || (param_4[1] == -1)))) {
        return 0;
      }
      if (((param_4 != (int *)0x0) && (*param_4 != -1)) && (param_4[1] == -1)) {
        return 0;
      }
      if (param_4 == (int *)0x0) {
        local_10 = -1;
        local_18 = -1;
      }
      else {
        local_10 = *param_4;
        local_18 = param_4[1];
      }
      local_34 = 0;
      piVar1 = (int *)GetWindowLongA(param_1,0);
      if (piVar1 != local_8) {
        local_34 = 1;
      }
      LVar2 = GetWindowLongA(param_1,4);
      if ((LVar2 != local_10) || (LVar2 = GetWindowLongA(param_1,8), LVar2 != local_18)) {
        local_34 = 1;
      }
      if (local_34 == 0) {
        SendMessageA(param_1,0x432,0,0);
      }
      else {
        SetWindowLongA(param_1,0,(LONG)local_8);
        SetWindowLongA(param_1,4,local_10);
        SetWindowLongA(param_1,8,local_18);
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      if (DAT_00663e24 == 2) {
        ShowWindow(param_1,5);
        if (DAT_006152e0 == param_1) {
          SetTimer(param_1,1,12000,(TIMERPROC)0x0);
        }
        BringWindowToTop(param_1);
      }
      return 0;
    }
    if ((0x30e < param_2) && (param_2 < 0x312)) {
      LVar13 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar13;
    }
  }
  else {
    switch(param_2) {
    case 0x40b:
      local_38 = param_3;
      local_10 = GetWindowLongA(param_1,4);
      local_18 = GetWindowLongA(param_1,8);
      if ((*local_38 == local_10) && (local_38[1] == local_18)) {
        SendMessageA(param_1,0x401,0xffffffff,0);
        return 1;
      }
      return 0;
    case 0x432:
      local_8 = (int *)GetWindowLongA(param_1,0);
      local_10 = GetWindowLongA(param_1,4);
      local_18 = GetWindowLongA(param_1,8);
      local_14 = GetWindowLongA(param_1,0xc);
      if (DAT_00666720 == local_8) {
        local_20 = FUN_00446ea2(local_10,local_18);
      }
      else if (DAT_00666444 == local_8) {
        FUN_004479d5(local_10,local_18,&local_28,&local_2c);
        local_20 = local_2c << 0x10 | local_28 & 0xffff;
      }
      else {
        local_20 = 0;
      }
      local_c = GetWindowLongA(param_1,0x10);
      if ((local_10 == -1) || (local_18 == -1)) {
        local_24 = 0;
      }
      else {
        uVar6 = FUN_0044781f(local_10,local_18);
        local_24 = FUN_0048c367(uVar6);
      }
      if (local_20 != local_14) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      if (local_24 != local_c) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      if ((local_10 != -1) && (local_18 != -1)) {
        iVar4 = FUN_00447b5f(local_10,local_18);
        if (iVar4 != 0) {
          InvalidateRect(param_1,(RECT *)0x0,0);
        }
        piVar1 = (int *)FUN_00447184(local_10,local_18);
        if (piVar1 != local_8) {
          InvalidateRect(param_1,(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      local_1c = param_3;
      local_1c = (int *)GetWindowLongA(param_1,0);
      InvalidateRect(param_1,(RECT *)0x0,0);
      return 0;
    case 0x437:
      return 0;
    }
  }
  LVar13 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,(LPARAM)param_4);
  return LVar13;
}


