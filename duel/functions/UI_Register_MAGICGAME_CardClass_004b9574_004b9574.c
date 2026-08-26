/*
 * Decompiled function: UI_Register_MAGICGAME_CardClass_004b9574
 * Entry Point: 004b9574
 * Size: 5262 bytes
 */
#include "duel.h"


LRESULT UI_Register_MAGICGAME_CardClass_004b9574(HWND hwnd,uint y,HWND param_3,LONG *arg_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  HBRUSH hbr;
  LRESULT LVar4;
  int local_394;
  tagPOINT local_390;
  tagRECT local_388;
  int local_378;
  int local_374;
  CHAR local_370 [100];
  tagRECT local_30c;
  HDC local_2fc;
  tagPAINTSTRUCT local_2f8;
  int local_2b8;
  tagRECT local_2b4;
  int local_2a4;
  tagRECT local_2a0;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  uint local_274;
  uint local_270;
  int local_26c;
  int local_268;
  int local_264;
  tagRECT local_260;
  tagRECT local_250;
  uint local_240 [66];
  ULONG_PTR local_138;
  int local_134;
  HWND local_130;
  LRESULT local_12c;
  int local_128;
  HWND local_124;
  int local_120;
  int local_11c;
  HWND local_118;
  int local_114;
  char local_110 [52];
  int local_dc;
  char local_d8 [52];
  HWND local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  char local_94 [52];
  int local_60;
  HWND local_5c;
  HWND local_58;
  int local_54;
  HWND local_50;
  HWND local_4c;
  LONG *local_48;
  LONG *local_44;
  HWND local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  LONG local_24;
  int local_20;
  LONG local_1c;
  LONG local_18;
  LONG local_14;
  void *local_10;
  int local_c;
  HWND local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_1c = GetWindowLongA(hwnd,8);
      local_18 = GetWindowLongA(hwnd,0xc);
      local_14 = GetWindowLongA(hwnd,0x10);
      local_24 = GetWindowLongA(hwnd,0x14);
      local_8 = (HWND)GetWindowLongA(hwnd,0x18);
      FUN_004bb037(DAT_0061534c,DAT_0061898c,local_1c,local_18,local_14,local_24,&local_2a4,
                   &local_290,&local_378,&local_374);
      GetClientRect(hwnd,&local_30c);
      local_288 = local_30c.top + local_2a4;
      local_280 = local_30c.bottom - local_290;
      local_28c = local_30c.left + local_378;
      local_284 = local_30c.right - local_378;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_2b8 = SaveDC(DAT_0060157c);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&local_30c,hbr);
      FUN_004badc2(DAT_0060157c,&local_30c.left,&local_28c,local_374,local_1c,local_18,local_14,
                   local_24,local_8);
      SetMapMode(DAT_0060157c,8);
      SetWindowExtEx(DAT_0060157c,local_30c.right - local_30c.left,0x14,(LPSIZE)0x0);
      SetViewportExtEx(DAT_0060157c,local_30c.right - local_30c.left,(local_2a4 * 0x30) / 100,
                       (LPSIZE)0x0);
      SelectObject(DAT_0060157c,DAT_005dce08);
      GetWindowTextA(hwnd,local_370,100);
      SetBkMode(DAT_0060157c,1);
      SetRect(&local_2b4,local_30c.left,local_30c.top,local_30c.right,local_288);
      DPtoLP(DAT_0060157c,(LPPOINT)&local_2b4,2);
      OffsetRect(&local_2b4,2,2);
      SetTextColor(DAT_0060157c,DAT_005dce00);
      DrawTextA(DAT_0060157c,local_370,-1,&local_2b4,0x25);
      OffsetRect(&local_2b4,-2,-2);
      SetTextColor(DAT_0060157c,DAT_005dcdfc);
      DrawTextA(DAT_0060157c,local_370,-1,&local_2b4,0x25);
      RestoreDC(DAT_0060157c,local_2b8);
      local_2fc = BeginPaint(hwnd,&local_2f8);
      if (local_2fc != (HDC)0x0) {
        FUN_004707a4(local_2fc);
        GetClientRect(hwnd,&local_2a0);
        BitBlt(local_2fc,0,0,local_2a0.right,local_2a0.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_2f8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (y == 1) {
      local_20 = 0;
      SetWindowLongA(hwnd,4,0);
      local_10 = _malloc(200);
      SetWindowLongA(hwnd,0,(LONG)local_10);
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_24 = 0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,0xc,local_18);
      SetWindowLongA(hwnd,0x10,local_14);
      SetWindowLongA(hwnd,0x14,local_24);
      local_8 = (HWND)0x0;
      SetWindowLongA(hwnd,0x18,0);
      local_c = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      if (local_10 == (void *)0x0) {
        return -1;
      }
      FUN_004baa8b(hwnd);
      return 0;
    }
    if (y == 2) {
      local_10 = (void *)GetWindowLongA(hwnd,0);
      FUN_004db150(local_10);
      local_8 = (HWND)GetWindowLongA(hwnd,0x18);
      if (local_8 != (HANDLE)0x0) {
        FUN_00471395(local_8);
      }
      return 0;
    }
  }
  else if (y < 0x15) {
    if (y == 0x14) {
      return 1;
    }
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
  }
  else if (y < 0x118) {
    if (y == 0x117) {
      AppendMenuA(DAT_005dce04,0,100,s_Help____00508794);
      return 0;
    }
    if (y == 0x111) {
      if (((uint)param_3 & 0xffff) == 100) {
        local_138 = 0x7e3;
        Mem_AllocOrFree_004d9630(local_240,(uint *)&DAT_005f76e0);
        FUN_004d9640(local_240,(uint *)s__duel_hlp_00508788);
        WinHelpA(DAT_00618990,(LPCSTR)local_240,1,local_138);
      }
      return 0;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
      GetWindowRect(hwnd,&local_260);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_250);
      iVar2 = Mem_AllocOrFree_004d9810(local_250.top - local_260.top);
      iVar3 = Mem_AllocOrFree_004d9810(local_250.left - local_260.left);
      if (iVar2 + iVar3 < 5) {
        local_274 = (uint)arg_4 & 0xffff;
        local_270 = (uint)arg_4 >> 0x10;
        local_10 = (void *)GetWindowLongA(hwnd,0);
        local_20 = GetWindowLongA(hwnd,4);
        local_c = GetWindowLongA(hwnd,0x1c);
        local_1c = GetWindowLongA(hwnd,8);
        local_18 = GetWindowLongA(hwnd,0xc);
        local_14 = GetWindowLongA(hwnd,0x10);
        local_24 = GetWindowLongA(hwnd,0x14);
        if ((1 < local_20) &&
           (FUN_004bb037(DAT_0061534c,DAT_0061898c,local_1c,local_18,local_14,local_24,&local_26c,
                         &local_268,&local_27c,&local_278), (int)local_270 < local_26c)) {
          GetClientRect(hwnd,&local_250);
          if ((int)local_274 < (local_250.right * 0x14) / 100) {
            local_264 = local_20;
            if (0 < local_c) {
              local_264 = local_c;
            }
            local_264 = local_264 + -1;
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)local_10 + local_264 * 4),0);
          }
          else if ((local_250.right * 0x50) / 100 < (int)local_274) {
            if (local_c < local_20 + -1) {
              local_264 = local_c + 1;
            }
            else {
              local_264 = 0;
            }
            SendMessageA(hwnd,0x400,*(WPARAM *)((int)local_10 + local_264 * 4),0);
          }
        }
      }
      return 0;
    }
    if (y == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (arg_4 == (LONG *)0x0)) {
        local_394 = GetMenuItemCount(DAT_005dce04);
        while (local_394 != 0) {
          DeleteMenu(DAT_005dce04,0,0x400);
          local_394 = local_394 + -1;
        }
      }
      return 0;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      LVar4 = FUN_00472b60(hwnd,y,param_3,arg_4);
      return LVar4;
    }
    if (y == 0x204) {
      local_390.x = (uint)arg_4 & 0xffff;
      local_390.y = (uint)arg_4 >> 0x10;
      ClientToScreen(hwnd,&local_390);
      SetRect(&local_388,local_390.x,local_390.y,local_390.x + 1,local_390.y + 1);
      TrackPopupMenu(DAT_005dce04,2,local_390.x,local_390.y,0,hwnd,&local_388);
      return 0;
    }
  }
  else {
    switch(y) {
    case 0x400:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_50 = param_3;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      for (local_54 = 0; local_54 < local_20; local_54 = local_54 + 1) {
        if (*(HWND *)((int)local_10 + local_54 * 4) == local_50) {
          local_c = local_54;
          SetWindowLongA(hwnd,0x1c,local_54);
          FUN_004baa8b(hwnd);
        }
      }
      return 0;
    case 0x40a:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_c = GetWindowLongA(hwnd,0x1c);
      if (0x31 < local_20) {
        return 0;
      }
      local_58 = param_3;
      local_5c = (HWND)SendMessageA(hwnd,0x40f,(WPARAM)param_3,0);
      if (local_5c == (HWND)0x0) {
        local_5c = CreateWindowExA(0,s_MAGICGAME_CardClass_00508774,s_Hand_Card_00508768,0x54000000,
                                   0,0,0,0,hwnd,(HMENU)0x1,DAT_00664680,local_58);
        if (local_5c != (HWND)0x0) {
          *(HWND *)((int)local_10 + local_20 * 4) = local_5c;
          local_20 = local_20 + 1;
          SetWindowLongA(hwnd,4,local_20);
          iVar2 = local_20;
          if (local_c + 1 == local_20 + -1) {
            local_c = local_20 + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          else {
            while (local_60 = iVar2 + -1, local_c + 1 < local_60) {
              *(undefined4 *)((int)local_10 + local_60 * 4) =
                   *(undefined4 *)((int)local_10 + -4 + local_60 * 4);
              iVar2 = local_60;
            }
            *(HWND *)((int)local_10 + 4 + local_c * 4) = local_5c;
            local_c = local_c + 1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          FUN_004baa8b(hwnd);
          FUN_004bb0c2(local_94,hwnd,local_20);
          return local_20;
        }
        return 0;
      }
      iVar2 = FUN_00447184(local_58->unused,local_58[1].unused);
      iVar2 = FUN_004863ca(local_5c,iVar2);
      if (iVar2 != 0) {
        return local_20;
      }
      SendMessageA(hwnd,0x40b,(WPARAM)local_58,0);
      SendMessageA(hwnd,0x40a,(WPARAM)local_58,0);
      return local_20;
    case 0x40b:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_c = GetWindowLongA(hwnd,0x1c);
      local_a4 = param_3;
      local_98 = 0;
      local_9c = 0;
      while ((local_9c < local_20 && (local_98 == 0))) {
        iVar2 = FUN_00486348(*(HWND *)((int)local_10 + local_9c * 4),&local_a4->unused);
        if (iVar2 != 0) {
          local_98 = 1;
          DestroyWindow(*(HWND *)((int)local_10 + local_9c * 4));
          local_20 = local_20 + -1;
          SetWindowLongA(hwnd,4,local_20);
          for (local_a0 = local_9c; local_a0 < local_20; local_a0 = local_a0 + 1) {
            *(undefined4 *)((int)local_10 + local_a0 * 4) =
                 *(undefined4 *)((int)local_10 + 4 + local_a0 * 4);
          }
          if (local_9c == local_c) {
            if (local_c == 0) {
              local_c = local_20;
            }
            local_c = local_c + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          else {
            if (local_c == 0) {
              local_c = local_20;
            }
            local_c = local_c + -1;
            SetWindowLongA(hwnd,0x1c,local_c);
          }
          FUN_004bb0c2(local_d8,hwnd,local_20);
          UpdateWindow(hwnd);
        }
        local_9c = local_9c + 1;
      }
      if (local_98 == 0) {
        return 0;
      }
      FUN_004baa8b(hwnd);
      return local_98;
    case 0x40c:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_dc = 0; local_dc < local_20; local_dc = local_dc + 1) {
        DestroyWindow(*(HWND *)((int)local_10 + local_dc * 4));
      }
      local_20 = 0;
      SetWindowLongA(hwnd,4,0);
      local_c = 0xffffffff;
      SetWindowLongA(hwnd,0x1c,-1);
      FUN_004baa8b(hwnd);
      FUN_004bb0c2(local_110,hwnd,local_20);
      return 0;
    case 0x40d:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_124 = param_3;
      local_114 = 0;
      local_11c = 0;
      while( true ) {
        if (local_20 <= local_11c) {
          return local_114;
        }
        if (local_114 != 0) break;
        iVar2 = FUN_00486348(*(HWND *)((int)local_10 + local_11c * 4),&local_124->unused);
        if (iVar2 != 0) {
          local_114 = 1;
          local_118 = *(HWND *)((int)local_10 + local_11c * 4);
          BringWindowToTop(local_118);
          for (local_120 = local_11c; local_120 < local_20 + -1; local_120 = local_120 + 1) {
            *(undefined4 *)((int)local_10 + local_120 * 4) =
                 *(undefined4 *)((int)local_10 + 4 + local_120 * 4);
          }
          *(HWND *)((int)local_10 + -4 + local_20 * 4) = local_118;
        }
        local_11c = local_11c + 1;
      }
      return local_114;
    case 0x40e:
    case 0x40f:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_130 = param_3;
      local_128 = 0;
      local_134 = 0;
      while ((local_134 < local_20 && (local_128 == 0))) {
        iVar2 = FUN_00486348(*(HWND *)((int)local_10 + local_134 * 4),&local_130->unused);
        if (iVar2 != 0) {
          local_128 = 1;
          if (y == 0x40e) {
            local_12c = FUN_0048644e(*(HWND *)((int)local_10 + local_134 * 4));
          }
          else {
            local_12c = *(LRESULT *)((int)local_10 + local_134 * 4);
          }
        }
        local_134 = local_134 + 1;
      }
      if (local_128 != 0) {
        return local_12c;
      }
      if (y == 0x40e) {
        return -1;
      }
      return 0;
    case 0x432:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_30 = 0; local_30 < local_20; local_30 = local_30 + 1) {
        SendMessageA(*(HWND *)((int)local_10 + local_30 * 4),0x432,0,0);
      }
      return 0;
    case 0x433:
    case 0x434:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_2c = param_3;
      for (local_28 = 0; local_28 < local_20; local_28 = local_28 + 1) {
        iVar2 = FUN_004863ca(*(HWND *)((int)local_10 + local_28 * 4),(int)local_2c);
        if (iVar2 != 0) {
          InvalidateRect(*(HWND *)((int)local_10 + local_28 * 4),(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x435:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      for (local_34 = 0; local_34 < local_20; local_34 = local_34 + 1) {
        InvalidateRect(*(HWND *)((int)local_10 + local_34 * 4),(RECT *)0x0,0);
      }
      return 0;
    case 0x436:
      local_10 = (void *)GetWindowLongA(hwnd,0);
      local_20 = GetWindowLongA(hwnd,4);
      local_40 = param_3;
      local_44 = arg_4;
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      local_38 = 0;
      local_3c = 0;
      while ((local_3c < local_20 && (local_38 == 0))) {
        iVar2 = FUN_00486348(*(HWND *)((int)local_10 + local_3c * 4),&local_40->unused);
        if (iVar2 != 0) {
          local_38 = 1;
          if (local_44 == (LONG *)0x0) {
            InvalidateRect(*(HWND *)((int)local_10 + local_3c * 4),(RECT *)0x0,0);
          }
          else {
            SendMessageA(*(HWND *)((int)local_10 + local_3c * 4),0x432,0,0);
          }
        }
        local_3c = local_3c + 1;
      }
      return 0;
    case 0x438:
      LVar1 = GetWindowLongA(hwnd,0x18);
      return LVar1;
    case 0x439:
      local_4c = param_3;
      local_48 = arg_4;
      local_8 = (HWND)GetWindowLongA(hwnd,0x18);
      if (local_8 != (HGDIOBJ)0x0) {
        DeleteObject(local_8);
      }
      local_8 = local_4c;
      local_1c = *local_48;
      local_18 = local_48[1];
      local_14 = local_48[2];
      local_24 = local_48[3];
      SetWindowLongA(hwnd,8,local_1c);
      SetWindowLongA(hwnd,0xc,local_18);
      SetWindowLongA(hwnd,0x10,local_14);
      SetWindowLongA(hwnd,0x14,local_24);
      SetWindowLongA(hwnd,0x18,(LONG)local_8);
      FUN_004baa8b(hwnd);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
  }
  LVar4 = DefWindowProcA(hwnd,y,(WPARAM)param_3,(LPARAM)arg_4);
  return LVar4;
}


