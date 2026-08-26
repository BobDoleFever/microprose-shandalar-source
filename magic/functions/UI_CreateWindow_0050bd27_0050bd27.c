/*
 * Decompiled function: UI_CreateWindow_0050bd27
 * Entry Point: 0050bd27
 * Size: 2798 bytes
 */
#include "magic.h"


LRESULT UI_CreateWindow_0050bd27(HWND hwnd,uint y,HWND param_3,uint height)

{
  HWND pHVar1;
  HBRUSH pHVar2;
  HGDIOBJ pvVar3;
  size_t c;
  LRESULT LVar4;
  int iVar5;
  int local_464;
  char local_460 [12];
  tagPOINT local_454;
  tagRECT local_44c;
  char local_43c [12];
  tagRECT local_430;
  int local_420;
  int local_41c;
  int local_418;
  int local_414;
  tagRECT local_410;
  int local_400;
  int local_3fc;
  int local_3f8;
  HDC local_3f4;
  tagPAINTSTRUCT local_3f0;
  tagRECT local_3b0;
  char local_3a0 [264];
  ULONG_PTR local_298;
  int local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  tagRECT local_274;
  int aiStack_264 [100];
  int local_d4;
  char local_d0 [100];
  char local_6c [100];
  int local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8 = GetWindowLongA(hwnd,0);
      local_3f8 = Mem_AllocOrFree_0050c82b((uint)(hwnd != DAT_006fe48c));
      if (local_8 != local_3f8) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      local_3f4 = BeginPaint(hwnd,&local_3f0);
      if (local_3f4 != (HDC)0x0) {
        FUN_004f3955(local_3f4);
        GetClientRect(hwnd,&local_3b0);
        if (DAT_0068a674 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_3f4,&local_3b0,pHVar2);
          Sleep(200);
        }
        if (local_3f8 == 0) {
          pHVar2 = GetStockObject(4);
          FillRect(local_3f4,&local_3b0,pHVar2);
        }
        else if (local_3f8 == 1) {
          Palette_Subsystem_0049c6cb(local_3f4,&local_3b0);
        }
        else {
          pHVar2 = GetStockObject(4);
          FillRect(g_HdcBackBuffer,&local_3b0,pHVar2);
          iVar5 = local_3f8;
          if (0x4a < local_3f8) {
            iVar5 = 0x4b;
          }
          local_418 = (((local_3b0.right * 0x28) / 100) * iVar5) / 0x4b;
          local_3fc = (local_3b0.bottom * local_418) / local_3b0.right;
          SetRect(&local_410,local_3b0.left,local_3b0.top,local_3b0.right - local_418,
                  local_3b0.bottom - local_3fc);
          pvVar3 = GetStockObject(2);
          SelectObject(local_3f4,pvVar3);
          pvVar3 = GetStockObject(7);
          SelectObject(local_3f4,pvVar3);
          local_41c = local_3f8 / 5;
          if (local_41c < 2) {
            local_41c = 1;
          }
          local_41c = local_418 / local_41c;
          if (local_41c < 3) {
            local_41c = 2;
          }
          local_420 = local_3f8 / 5;
          if (local_420 < 2) {
            local_420 = 1;
          }
          local_420 = local_3fc / local_420;
          if (local_420 < 4) {
            local_420 = 3;
          }
          local_414 = local_3b0.bottom;
          for (local_400 = local_3b0.right; local_410.right < local_400;
              local_400 = local_400 - local_41c) {
            SetRect(&local_430,local_400 - (local_410.right - local_410.left),
                    local_414 - (local_410.bottom - local_410.top),local_400,local_414);
            Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_430);
            local_414 = local_414 - local_420;
          }
          Palette_Subsystem_0049c6cb(g_HdcBackBuffer,&local_410);
          BitBlt(local_3f4,0,0,local_3b0.right,local_3b0.bottom,g_HdcBackBuffer,0,0,0xcc0020);
          if (DAT_006808c4 != 0) {
            sprintf(local_43c,&DAT_0053252c,local_3f8);
            SetBkMode(local_3f4,1);
            SetTextColor(local_3f4,0xffffff);
            c = strlen(local_43c);
            TextOutA(local_3f4,0,0,local_43c,c);
          }
        }
        EndPaint(hwnd,&local_3f0);
        local_8 = local_3f8;
        SetWindowLongA(hwnd,0,local_3f8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      return 0;
    }
    if (y == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,0,0);
      return 0;
    }
  }
  else if (y < 0x21) {
    if (y == 0x20) {
      LVar4 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,height);
      return LVar4;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x117) {
    if (y == 0x116) {
      local_8 = GetWindowLongA(hwnd,0);
      sprintf(local_460,&DAT_00532530,local_8);
      AppendMenuA(DAT_0061e118,0x10,(UINT_PTR)DAT_0061e11c,s_Count_library_cards_00532534);
      ModifyMenuA(DAT_0061e11c,0x65,0,0x65,local_460);
      AppendMenuA(DAT_0061e118,0,100,s_Help____00532548);
      return 0;
    }
    if (y == 0x111) {
      if (((uint)param_3 & 0xffff) == 100) {
        local_298 = 0x7e9;
        strcpy(local_3a0,&DAT_006807a0);
        strcat(local_3a0,s__duel_hlp_00532520);
        WinHelpA(g_MainAppHwnd,local_3a0,1,local_298);
      }
      return 0;
    }
  }
  else if (y < 0x202) {
    if (y == 0x201) {
      return 0;
    }
    if (y == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (height == 0)) {
        local_464 = GetMenuItemCount(DAT_0061e118);
        while (local_464 != 0) {
          RemoveMenu(DAT_0061e118,0,0x400);
          local_464 = local_464 + -1;
        }
      }
      return 0;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      LVar4 = FUN_004f5d1a(hwnd,y,param_3,height);
      return LVar4;
    }
    if (y == 0x204) {
      local_454.x = height & 0xffff;
      local_454.y = height >> 0x10;
      ClientToScreen(hwnd,&local_454);
      SetRect(&local_44c,local_454.x,local_454.y,local_454.x + 1,local_454.y + 1);
      TrackPopupMenu(DAT_0061e118,2,local_454.x,local_454.y,0,hwnd,&local_44c);
      return 0;
    }
  }
  else {
    if (y == 0x400) {
      local_28c = Mem_AllocOrFree_0050c82b((uint)(hwnd != DAT_006fe48c));
      GetClientRect(hwnd,&local_274);
      iVar5 = local_28c;
      if (0x4a < local_28c) {
        iVar5 = 0x4b;
      }
      local_294 = (((local_274.right * 0x28) / 100) * iVar5) / 0x4b;
      local_290 = (local_274.bottom * local_294) / local_274.right;
      local_284 = local_274.right - local_294;
      local_288 = local_274.bottom - local_290;
      GetWindowRect(hwnd,&local_274);
      local_278 = local_274.left;
      local_27c = local_274.top;
      if (100 < local_28c) {
        local_28c = 100;
      }
      iVar5 = GetSystemMetrics(0x49);
      if (iVar5 == 0) {
        if ((5 < local_28c) && (local_28c = local_28c / 3, local_28c < 6)) {
          local_28c = 5;
        }
      }
      else if ((4 < local_28c) && (local_28c = local_28c / 5, local_28c < 5)) {
        local_28c = 4;
      }
      for (local_280 = 0; iVar5 = local_28c, local_280 < local_28c; local_280 = local_280 + 1) {
        pHVar1 = CreateWindowExA(0,s_ShuffleCard_00532514,&DAT_00532510,0x90000000,local_278,
                                 local_27c,local_284,local_288,g_MainAppHwnd,(HMENU)0x0,
                                 g_AppHInstance,(LPVOID)0x0);
        aiStack_264[local_280] = (int)pHVar1;
        if (aiStack_264[local_280] != 0) {
          UpdateWindow((HWND)aiStack_264[local_280]);
          local_278 = local_278 + (local_284 * 0xf) / 100;
        }
      }
      while (local_280 = iVar5 + -1, -1 < local_280) {
        if (aiStack_264[local_280] != 0) {
          DestroyWindow((HWND)aiStack_264[local_280]);
        }
        UpdateWindow(g_MainAppHwnd);
        iVar5 = local_280;
      }
      return 0;
    }
    if (y == 0x432) {
      local_8 = GetWindowLongA(hwnd,0);
      local_d4 = Mem_AllocOrFree_0050c82b((uint)(hwnd != DAT_006fe48c));
      if (local_8 != local_d4) {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
      return 0;
    }
    if (y == 0x437) {
      if (hwnd == DAT_006fe48c) {
        strcpy(local_6c,s_Your_005324fc);
      }
      else {
        Ai_Subsystem_004b6f49(local_6c);
      }
      sprintf(local_d0,s__s_library_00532504,local_6c);
      strcpy((char *)param_3,local_d0);
      return 1;
    }
  }
  LVar4 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
  return LVar4;
}


