/*
 * Decompiled function: Pic_Load_00424b1f
 * Entry Point: 00424b1f
 * Size: 4956 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Pic_Load_00424b1f(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  bool bVar1;
  uint uVar2;
  UINT dwMilliseconds;
  HBRUSH pHVar3;
  int iVar4;
  LRESULT LVar5;
  int local_5b4;
  int local_5b0;
  int local_5ac [38];
  tagPOINT local_514;
  UINT_PTR local_50c;
  int local_508;
  int local_504;
  UINT_PTR local_500;
  int local_4fc;
  UINT_PTR local_4f8;
  tagRECT local_4f4;
  tagPOINT local_4e4;
  tagRECT local_4dc;
  int local_4cc;
  char local_4c8 [264];
  HRGN local_3c0;
  HDC local_3bc;
  int local_3b8;
  undefined1 local_3b4 [4];
  int local_3b0;
  int local_3ac;
  tagPAINTSTRUCT local_39c;
  int local_35c;
  tagRECT local_358;
  int local_348;
  tagRECT local_344;
  tagMSG local_334;
  uint local_318;
  BOOL local_314;
  POINT local_310;
  tagRECT local_308;
  int local_2f8;
  char local_2f4 [264];
  ULONG_PTR local_1ec;
  int local_1e8;
  uint local_1e4;
  tagRECT local_1e0;
  tagRECT local_1d0;
  int local_1c0;
  uint local_1bc;
  int local_1b8;
  uint local_1b4;
  int local_1b0;
  int local_1ac;
  char local_1a8 [264];
  ULONG_PTR local_a0;
  int local_9c;
  int local_98;
  char local_94 [100];
  int local_30;
  POINT local_2c;
  int local_24;
  int local_20;
  tagRECT local_1c;
  LONG local_c;
  LONG local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_c = GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      Ai_Subsystem_004b74b1(&local_348,&local_3b8);
      if ((local_c != local_3b8) || (local_8 != local_348)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      if (DAT_00538b20 == (HANDLE)0x0) {
        strcpy(local_4c8,&DAT_006b2e90);
        strcat(local_4c8,s__WINBK_Phase_pic_00520e78);
        DAT_00538b20 = (HANDLE)Pic_Load_00423833(local_4c8);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_3bc = g_HdcBackBuffer;
      local_35c = SaveDC(g_HdcBackBuffer);
      GetClientRect(hwnd,&local_344);
      if (DAT_00538b20 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(4);
        FillRect(local_3bc,&local_344,pHVar3);
      }
      else {
        GetObjectA(DAT_00538b20,0x18,local_3b4);
        FUN_004f3bc7(local_3bc,&local_344.left,DAT_00538b20,0,0,local_3b0 / DAT_00538b78,local_3ac);
      }
      if ((local_348 != -1) && (local_3b8 != -1)) {
        Pic_Subsystem_004262cf(&local_358,local_348,local_3b8,local_344.right,local_344.bottom);
        local_3c0 = CreateRectRgnIndirect(&local_358);
        SelectClipRgn(local_3bc,local_3c0);
        if (DAT_00538b20 == (HANDLE)0x0) {
          pHVar3 = GetStockObject(2);
          FillRect(local_3bc,&local_344,pHVar3);
        }
        else {
          GetObjectA(DAT_00538b20,0x18,local_3b4);
          FUN_004f3bc7(local_3bc,&local_344.left,DAT_00538b20,local_3b0 - local_3b0 / DAT_00538b78,0
                       ,local_3b0 / DAT_00538b78,local_3ac);
        }
        SelectClipRgn(local_3bc,(HRGN)0x0);
        DeleteObject(local_3c0);
      }
      RestoreDC(g_HdcBackBuffer,local_35c);
      Pic_Subsystem_00426518(local_3bc,(int)&local_344);
      local_3bc = BeginPaint(hwnd,&local_39c);
      if (local_3bc != (HDC)0x0) {
        FUN_004f3955(local_3bc);
        GetClientRect(hwnd,&local_344);
        if (DAT_0068a674 != 0) {
          pHVar3 = GetStockObject(0);
          FillRect(local_3bc,&local_344,pHVar3);
          Sleep(200);
        }
        BitBlt(local_3bc,0,0,local_344.right,local_344.bottom,g_HdcBackBuffer,0,0,0xcc0020);
        Ai_Subsystem_004b756f(&local_4cc);
        if (local_4cc != -1) {
          if (local_4cc == 0) {
            local_344.bottom = local_344.bottom - (local_344.bottom - local_344.top) / 2;
          }
          else {
            local_344.top = local_344.top + (local_344.bottom - local_344.top) / 2;
          }
          SelectObject(local_3bc,DAT_00538b3c);
          SetBkMode(local_3bc,1);
          Rectangle(local_3bc,local_344.left,local_344.top,local_344.right,local_344.bottom);
        }
        EndPaint(hwnd,&local_39c);
        local_c = local_3b8;
        local_8 = local_348;
        SetWindowLongA(hwnd,0,local_3b8);
        SetWindowLongA(hwnd,4,local_8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (uMsg == 1) {
      local_c = 0;
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      SetWindowLongA(hwnd,4,local_8);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      GetCursorPos(&local_514);
      ScreenToClient(hwnd,&local_514);
      GetClientRect(hwnd,&local_4f4);
      Pic_Subsystem_00425ee3(&local_514,&local_4f4,&local_4fc,&local_5b0);
      if (local_4fc == 1) {
        local_508 = 10;
      }
      else {
        local_508 = 0;
      }
      if (local_5b0 == 1) {
        local_504 = 0;
      }
      else if ((((local_5b0 == 2) || (local_5b0 == 3)) || (local_5b0 == 4)) || (local_5b0 == 5)) {
        local_504 = 1;
      }
      else if (local_5b0 == 10) {
        local_504 = 2;
      }
      else if (local_5b0 == 0x14) {
        local_504 = 3;
      }
      else if ((((local_5b0 == 0x15) || (local_5b0 == 0x16)) ||
               ((local_5b0 == 0x17 || ((local_5b0 == 0x18 || (local_5b0 == 0x19)))))) ||
              ((local_5b0 == 0x1a || (local_5b0 == 0x1b)))) {
        local_504 = 4;
      }
      else if (local_5b0 == 0x1e) {
        local_504 = 5;
      }
      else if (local_5b0 == 0x1f) {
        local_504 = 6;
      }
      else if ((((local_5b0 == 0x20) || (local_5b0 == 0x21)) || (local_5b0 == 0x22)) ||
              (local_5b0 == 0x25)) {
        local_504 = 7;
      }
      else {
        local_504 = -1;
      }
      if (local_5b0 != -1) {
        if (DAT_006b1578 != 0) {
          local_500 = local_504 + local_508 + 0x96;
          AppendMenuA(DAT_00538b40,0,local_500,s_Run_to_this_phase_00520e8c);
        }
        iVar4 = GetMenuItemCount(DAT_00538b40);
        if (iVar4 != 0) {
          AppendMenuA(DAT_00538b40,0x800,0,(LPCSTR)0x0);
        }
        local_4f8 = local_504 + local_508 + 200;
        AppendMenuA(DAT_00538b40,0,local_4f8,s_Mark_this_phase_to_always_stop_00520ea0);
        Ai_Subsystem_004b74fa(local_5ac,local_4fc);
        if (local_5ac[local_5b0] != 0) {
          CheckMenuItem(DAT_00538b40,local_4f8,8);
        }
        local_50c = local_504 + local_508 + 0xfa;
        AppendMenuA(DAT_00538b40,0,local_50c,s_Help_for_this_phase____00520ec0);
      }
      AppendMenuA(DAT_00538b40,0,100,s_Help____00520ed8);
      return 0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 100) {
        local_a0 = 0x7e5;
        strcpy(local_1a8,&DAT_006807a0);
        strcat(local_1a8,s__duel_hlp_00520e60);
        WinHelpA(g_MainAppHwnd,local_1a8,1,local_a0);
      }
      else {
        uVar2 = (uint)wParam & 0xffff;
        if (uVar2 < 0xfa) {
          if (uVar2 < 200) {
            local_1b0 = 0x96;
          }
          else {
            local_1b0 = 200;
          }
        }
        else {
          local_1b0 = 0xfa;
        }
        local_1b8 = uVar2 - local_1b0;
        bVar1 = 9 < local_1b8;
        if (bVar1) {
          local_1b8 = local_1b8 + -10;
        }
        local_1b4 = (uint)bVar1;
        local_1ac = local_1b8;
        if (local_1b0 == 0x96) {
          local_1bc = local_1b4;
          if (local_1b8 == 0) {
            local_1c0 = 1;
          }
          else if (local_1b8 == 1) {
            local_1c0 = 4;
          }
          else if (local_1b8 == 2) {
            local_1c0 = 10;
          }
          else if (local_1b8 == 3) {
            local_1c0 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1c0 = 0x15;
            }
            else {
              local_1c0 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1c0 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1c0 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1c0 = 0x20;
          }
          DAT_00627a84 = local_1b4;
          DAT_00627a88 = local_1c0;
          DAT_00627864 = 0;
          _DAT_00538b68 = 0xfffffffe;
          _DAT_00538b6c = 0xffffffff;
          _DAT_00538b70 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x538b68);
        }
        else if (local_1b0 == 200) {
          local_1e4 = local_1b4;
          if (local_1b8 == 0) {
            local_1e8 = 1;
          }
          else if (local_1b8 == 1) {
            local_1e8 = 4;
          }
          else if (local_1b8 == 2) {
            local_1e8 = 10;
          }
          else if (local_1b8 == 3) {
            local_1e8 = 0x14;
          }
          else if (local_1b8 == 4) {
            if (local_1b4 == 0) {
              local_1e8 = 0x15;
            }
            else {
              local_1e8 = 0x16;
            }
          }
          else if (local_1b8 == 5) {
            local_1e8 = 0x1e;
          }
          else if (local_1b8 == 6) {
            local_1e8 = 0x1f;
          }
          else if (local_1b8 == 7) {
            local_1e8 = 0x20;
          }
          if (((&DAT_00696740)[local_1e8 * 4 + local_1b4 * 0x98] & 1) == 0) {
            *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) | 1;
          }
          else {
            *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) =
                 *(uint *)(&DAT_00696740 + local_1e8 * 4 + local_1b4 * 0x98) & 0xfffffffe;
          }
          Rules_ParseFilter_0050065d();
          Ai_Subsystem_004b42dc();
          GetClientRect(hwnd,&local_1e0);
          Pic_Subsystem_004262cf(&local_1d0,local_1e4,local_1e8,local_1e0.right,local_1e0.bottom);
          InvalidateRect(hwnd,&local_1d0,0);
        }
        else if (local_1b0 == 0xfa) {
          if (local_1b8 == 0) {
            local_1ec = 0x7da;
          }
          else if (local_1b8 == 1) {
            local_1ec = 0x7db;
          }
          else if (local_1b8 == 2) {
            local_1ec = 0x7dc;
          }
          else if (local_1b8 == 3) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 4) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 5) {
            local_1ec = 0x7dd;
          }
          else if (local_1b8 == 6) {
            local_1ec = 0x7de;
          }
          else if (local_1b8 == 7) {
            local_1ec = 0x7df;
          }
          strcpy(local_2f4,&DAT_006807a0);
          strcat(local_2f4,s__duel_hlp_00520e6c);
          WinHelpA(g_MainAppHwnd,local_2f4,1,local_1ec);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      dwMilliseconds = GetDoubleClickTime();
      Sleep(dwMilliseconds);
      local_314 = PeekMessageA(&local_334,hwnd,0x203,0x203,0);
      local_310.x = lParam & 0xffff;
      local_310.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_308);
      Pic_Subsystem_00425ee3(&local_310,&local_308,&local_318,&local_2f8);
      if ((local_2f8 != -1) && (DAT_006b1578 != 0)) {
        DAT_00627a84 = local_318;
        DAT_00627a88 = local_2f8;
        DAT_00627864 = local_314;
        _DAT_00538b28 = 0xfffffffe;
        _DAT_00538b2c = 0xffffffff;
        _DAT_00538b30 = 0xffffffff;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538b28);
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_5b4 = GetMenuItemCount(DAT_00538b40);
        while (local_5b4 != 0) {
          DeleteMenu(DAT_00538b40,0,0x400);
          local_5b4 = local_5b4 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_004f5d1a(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_4e4.x = lParam & 0xffff;
      local_4e4.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_4e4);
      SetRect(&local_4dc,local_4e4.x,local_4e4.y,local_4e4.x + 1,local_4e4.y + 1);
      TrackPopupMenu(DAT_00538b40,2,local_4e4.x,local_4e4.y,0,hwnd,&local_4dc);
      return 0;
    }
  }
  else {
    if (uMsg == 0x400) {
      Pic_Util_004280cf(hwnd,wParam,lParam);
      return 0;
    }
    if (uMsg == 0x432) {
      local_c = GetWindowLongA(hwnd,0);
      local_8 = GetWindowLongA(hwnd,4);
      Ai_Subsystem_004b74b1(&local_98,&local_9c);
      if ((local_c != local_9c) || (local_8 != local_98)) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_2c.x = lParam & 0xffff;
      local_2c.y = lParam >> 0x10;
      GetClientRect(hwnd,&local_1c);
      Pic_Subsystem_00425ee3(&local_2c,&local_1c,&local_20,&local_30);
      local_24 = 1;
      if (local_20 == 0) {
        strcpy(local_94,s_Your_00520da8);
      }
      else {
        Ai_Subsystem_004b6f49(local_94);
        strcat(local_94,&DAT_00520db0);
      }
      switch(local_30) {
      case 1:
        strcat(local_94,s_Untap_phase_00520db4);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        strcat(local_94,s_Upkeep_phase_00520dc0);
        break;
      default:
        local_24 = 0;
        break;
      case 10:
        strcat(local_94,s_Draw_phase_00520dd0);
        break;
      case 0x14:
        strcat(local_94,s_Main_phase__pre_combat__00520ddc);
        break;
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
        if (local_20 == 1) {
          strcat(local_94,s_Main_phase__combat__00520df4);
        }
        else {
          strcat(local_94,s_Main_phase__declare_attack__00520e08);
        }
        break;
      case 0x1e:
        strcat(local_94,s_Main_phase__post_combat__00520e24);
        break;
      case 0x1f:
        strcat(local_94,s_Discard_phase_00520e40);
        break;
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x25:
        strcat(local_94,s_Cleanup_phase_00520e50);
      }
      if (local_24 == 0) {
        return 0;
      }
      strcpy(wParam,local_94);
      return local_24;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}


