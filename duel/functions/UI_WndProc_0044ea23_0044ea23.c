/*
 * Decompiled function: UI_WndProc_0044ea23
 * Entry Point: 0044ea23
 * Size: 4223 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT UI_WndProc_0044ea23(HWND hwnd,uint uMsg,uint wParam,uint lParam)

{
  uint uVar1;
  UINT dwMilliseconds;
  HBRUSH pHVar2;
  int iVar3;
  LRESULT LVar4;
  int local_5a4;
  int local_5a0;
  int local_59c;
  int local_598;
  int local_594 [38];
  tagPOINT local_4fc;
  UINT_PTR local_4f4;
  int local_4f0;
  UINT_PTR local_4ec;
  UINT_PTR local_4e8;
  tagRECT local_4e4;
  int local_4d4;
  tagPOINT local_4d0;
  tagRECT local_4c8;
  uint local_4b8 [66];
  HRGN local_3b0;
  HDC local_3ac;
  int local_3a8;
  undefined1 local_3a4 [4];
  int local_3a0;
  int local_39c;
  tagPAINTSTRUCT local_38c;
  int local_34c;
  tagRECT local_348;
  int local_338;
  tagRECT local_334;
  undefined4 local_324;
  tagMSG local_320;
  BOOL local_304;
  POINT local_300;
  tagRECT local_2f8;
  int local_2e8;
  uint local_2e4 [66];
  ULONG_PTR local_1dc;
  int local_1d8;
  int local_1d4;
  tagRECT local_1d0;
  tagRECT local_1c0;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  undefined4 local_1a0;
  uint local_19c [66];
  ULONG_PTR local_94;
  int local_90;
  uint local_8c [25];
  int local_28;
  POINT local_24;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      FUN_0044897a(&local_338,&local_3a8);
      if (DAT_00516b70 == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_4b8,(uint *)&DAT_006189a0);
        FUN_004d9640(local_4b8,(uint *)s__WINBK_PhaseCombat_pic_004f8474);
        DAT_00516b70 = (HANDLE)FUN_0043d713((char *)local_4b8);
      }
      if (local_8 != local_3a8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_3ac = DAT_0060157c;
      local_34c = SaveDC(DAT_0060157c);
      GetClientRect(hwnd,&local_334);
      FUN_0044897a(&local_338,(undefined4 *)0x0);
      if (DAT_00516b70 == (HANDLE)0x0) {
        pHVar2 = GetStockObject(4);
        FillRect(local_3ac,&local_334,pHVar2);
      }
      else {
        GetObjectA(DAT_00516b70,0x18,local_3a4);
        if (local_338 == 1) {
          local_5a0 = 0;
        }
        else {
          local_5a0 = local_3a0 / 2;
        }
        FUN_00470a16(local_3ac,&local_334.left,DAT_00516b70,local_5a0,0,
                     (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
      }
      if (local_3a8 != -1) {
        GetClientRect(hwnd,&local_334);
        FUN_0044fc75(&local_348,local_3a8,local_334.right,local_334.bottom);
        local_3b0 = CreateRectRgnIndirect(&local_348);
        SelectClipRgn(local_3ac,local_3b0);
        if (DAT_00516b70 == (HANDLE)0x0) {
          pHVar2 = GetStockObject(2);
          FillRect(local_3ac,&local_334,pHVar2);
        }
        else {
          GetObjectA(DAT_00516b70,0x18,local_3a4);
          if (local_338 == 1) {
            local_5a4 = local_3a0 + (local_3a0 >> 0x1f & 3U);
          }
          else {
            local_5a4 = local_3a0 * 3 + (local_3a0 * 3 >> 0x1f & 3U);
          }
          local_5a4 = local_5a4 >> 2;
          FUN_00470a16(local_3ac,&local_334.left,DAT_00516b70,local_5a4,0,
                       (int)(local_3a0 + (local_3a0 >> 0x1f & 3U)) >> 2,local_39c);
        }
        SelectClipRgn(local_3ac,(HRGN)0x0);
        DeleteObject(local_3b0);
      }
      RestoreDC(DAT_0060157c,local_34c);
      FUN_0044fe36(local_3ac,(int)&local_334);
      local_3ac = BeginPaint(hwnd,&local_38c);
      if (local_3ac != (HDC)0x0) {
        FUN_004707a4(local_3ac);
        GetClientRect(hwnd,&local_334);
        BitBlt(local_3ac,0,0,local_334.right,local_334.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_38c);
        local_8 = local_3a8;
        SetWindowLongA(hwnd,0,local_3a8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar4 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      GetCursorPos(&local_4fc);
      ScreenToClient(hwnd,&local_4fc);
      GetClientRect(hwnd,&local_4e4);
      FUN_0044fab8(&local_4fc,&local_4e4,&local_598);
      FUN_0044897a(&local_4d4,(undefined4 *)0x0);
      if (local_598 == 0x15) {
        local_4f0 = 0;
      }
      else if (local_598 == 0x16) {
        local_4f0 = 1;
      }
      else if (local_598 == 0x17) {
        local_4f0 = 2;
      }
      else if (local_598 == 0x18) {
        local_4f0 = 3;
      }
      else if (local_598 == 0x19) {
        local_4f0 = 4;
      }
      else if (local_598 == 0x1b) {
        local_4f0 = 5;
      }
      else if (local_598 == 0x1e) {
        local_4f0 = 6;
      }
      else {
        local_4f0 = -1;
      }
      if (local_598 != -1) {
        if (DAT_00618158 != 0) {
          local_4ec = local_4f0 + 0x96;
          AppendMenuA(DAT_00516b78,0,local_4ec,s_Run_to_this_phase_004f848c);
        }
        iVar3 = GetMenuItemCount(DAT_00516b78);
        if (iVar3 != 0) {
          AppendMenuA(DAT_00516b78,0x800,0,(LPCSTR)0x0);
        }
        local_4e8 = local_4f0 + 200;
        AppendMenuA(DAT_00516b78,0,local_4e8,s_Mark_this_phase_to_always_stop_004f84a0);
        FUN_004489c3(local_594,local_4d4);
        if (local_594[local_598] != 0) {
          CheckMenuItem(DAT_00516b78,local_4e8,8);
        }
        local_4f4 = local_4f0 + 0xfa;
        AppendMenuA(DAT_00516b78,0,local_4f4,s_Help_for_this_phase____004f84c0);
      }
      AppendMenuA(DAT_00516b78,0,100,s_Help____004f84d8);
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 100) {
        local_94 = 0x7e5;
        Mem_AllocOrFree_004d9630(local_19c,(uint *)&DAT_005f76e0);
        FUN_004d9640(local_19c,(uint *)s__duel_hlp_004f845c);
        WinHelpA(DAT_00618990,(LPCSTR)local_19c,1,local_94);
      }
      else {
        uVar1 = wParam & 0xffff;
        if (uVar1 < 0xfa) {
          if (uVar1 < 200) {
            local_1a8 = 0x96;
          }
          else {
            local_1a8 = 200;
          }
        }
        else {
          local_1a8 = 0xfa;
        }
        local_1ac = uVar1 - local_1a8;
        local_1a4 = local_1ac;
        if (local_1a8 == 0x96) {
          if (local_1ac == 0) {
            local_1b0 = 0x15;
          }
          else if (local_1ac == 1) {
            local_1b0 = 0x16;
          }
          else if (local_1ac == 2) {
            local_1b0 = 0x17;
          }
          else if (local_1ac == 3) {
            local_1b0 = 0x18;
          }
          else if (local_1ac == 4) {
            local_1b0 = 0x19;
          }
          else if (local_1ac == 5) {
            local_1b0 = 0x1b;
          }
          else if (local_1ac == 6) {
            local_1b0 = 0x1e;
          }
          FUN_0044897a(&local_1a0,(undefined4 *)0x0);
          DAT_0066aac4 = local_1a0;
          DAT_0066ab04 = local_1b0;
          DAT_0066643c = 0;
          _DAT_00516b90 = 0xfffffffe;
          _DAT_00516b94 = 0xffffffff;
          _DAT_00516b98 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516b90);
        }
        else if (local_1a8 == 200) {
          if (local_1ac == 0) {
            local_1d8 = 0x15;
          }
          else if (local_1ac == 1) {
            local_1d8 = 0x16;
          }
          else if (local_1ac == 2) {
            local_1d8 = 0x17;
          }
          else if (local_1ac == 3) {
            local_1d8 = 0x18;
          }
          else if (local_1ac == 4) {
            local_1d8 = 0x19;
          }
          else if (local_1ac == 5) {
            local_1d8 = 0x1b;
          }
          else if (local_1ac == 6) {
            local_1d8 = 0x1e;
          }
          FUN_0044897a(&local_1d4,(undefined4 *)0x0);
          if (((&DAT_006667c0)[local_1d8 * 4 + local_1d4 * 0x98] & 1) == 0) {
            *(uint *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) | 1;
          }
          else {
            *(uint *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) =
                 *(uint *)(&DAT_006667c0 + local_1d8 * 4 + local_1d4 * 0x98) & 0xfffffffe;
          }
          FUN_004457a2();
          GetClientRect(hwnd,&local_1d0);
          FUN_0044fc75(&local_1c0,local_1d8,local_1d0.right,local_1d0.bottom);
          InvalidateRect(hwnd,&local_1c0,0);
        }
        else if (local_1a8 == 0xfa) {
          if (local_1ac == 0) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 1) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 2) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 3) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 4) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 5) {
            local_1dc = 0x7dd;
          }
          else if (local_1ac == 6) {
            local_1dc = 0x7dd;
          }
          Mem_AllocOrFree_004d9630(local_2e4,(uint *)&DAT_005f76e0);
          FUN_004d9640(local_2e4,(uint *)s__duel_hlp_004f8468);
          WinHelpA(DAT_00618990,(LPCSTR)local_2e4,1,local_1dc);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      dwMilliseconds = GetDoubleClickTime();
      Sleep(dwMilliseconds);
      local_304 = PeekMessageA(&local_320,hwnd,0x203,0x203,0);
      local_300.x = lParam & 0xffff;
      local_300.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_2f8);
      FUN_0044fab8(&local_300,&local_2f8,&local_2e8);
      if ((local_2e8 != -1) && (DAT_00618158 != 0)) {
        FUN_0044897a(&local_324,(undefined4 *)0x0);
        DAT_0066aac4 = local_324;
        DAT_0066ab04 = local_2e8;
        DAT_0066643c = local_304;
        _DAT_00516b80 = 0xfffffffe;
        _DAT_00516b84 = 0xffffffff;
        _DAT_00516b88 = 0xffffffff;
        PostMessageA(DAT_00618990,0x464,0,0x516b80);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_59c = GetMenuItemCount(DAT_00516b78);
        while (local_59c != 0) {
          DeleteMenu(DAT_00516b78,0,0x400);
          local_59c = local_59c + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar4 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar4;
    }
    if (uMsg == 0x204) {
      local_4d0.x = lParam & 0xffff;
      local_4d0.y = lParam >> 0x10;
      if (DAT_00618158 != 0) {
        ClientToScreen(hwnd,&local_4d0);
        SetRect(&local_4c8,local_4d0.x,local_4d0.y,local_4d0.x + 1,local_4d0.y + 1);
        TrackPopupMenu(DAT_00516b78,2,local_4d0.x,local_4d0.y,0,hwnd,&local_4c8);
      }
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Mem_AllocOrFree_0045033a(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      local_8 = GetWindowLongA(hwnd,0);
      FUN_0044897a((undefined4 *)0x0,&local_90);
      if (local_8 != local_90) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_24.x = lParam & 0xffff;
      local_24.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_18);
      FUN_0044fab8(&local_24,&local_18,&local_28);
      local_1c = 1;
      if (local_28 == 0x15) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Choose_attackers_phase_004f83a4);
      }
      else if (local_28 == 0x16) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Attacker_fast_effects_phase_004f83bc);
      }
      else if (local_28 == 0x17) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Assign_defenders_phase_004f83d8);
      }
      else if (local_28 == 0x18) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Blocker_fast_effects_phase_004f83f0);
      }
      else if (local_28 == 0x19) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Resolve_1st_strike_damage_004f840c);
      }
      else if ((local_28 == 0x1a) || (local_28 == 0x1b)) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Resolve_normal_damage_004f8428);
      }
      else if (local_28 == 0x1e) {
        Mem_AllocOrFree_004d9630(local_8c,(uint *)s_Main_phase__post_combat__004f8440);
      }
      else {
        local_1c = 0;
      }
      if (local_1c == 0) {
        return 0;
      }
      Mem_AllocOrFree_004d9630((uint *)wParam,local_8c);
      return local_1c;
    }
  }
  LVar4 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar4;
}


