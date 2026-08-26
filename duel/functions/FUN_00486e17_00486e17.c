/*
 * Decompiled function: FUN_00486e17
 * Entry Point: 00486e17
 * Size: 2807 bytes
 */
#include "duel.h"


LRESULT FUN_00486e17(HWND param_1,uint param_2,uint param_3,uint param_4)

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
  CHAR local_3a0 [264];
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
  undefined1 local_6c [100];
  int local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = GetWindowLongA(param_1,0);
      local_3f8 = FUN_00487924(param_1 != DAT_00663e68);
      if (local_8 != local_3f8) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_3f4 = BeginPaint(param_1,&local_3f0);
      if (local_3f4 != (HDC)0x0) {
        FUN_004707a4(local_3f4);
        GetClientRect(param_1,&local_3b0);
        if (DAT_00601580 != 0) {
          pHVar2 = GetStockObject(0);
          FillRect(local_3f4,&local_3b0,pHVar2);
          Sleep(200);
        }
        if (local_3f8 == 0) {
          pHVar2 = GetStockObject(4);
          FillRect(local_3f4,&local_3b0,pHVar2);
        }
        else if (local_3f8 == 1) {
          FUN_0042043e(local_3f4,&local_3b0);
        }
        else {
          pHVar2 = GetStockObject(4);
          FillRect(DAT_0060157c,&local_3b0,pHVar2);
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
            FUN_0042043e(DAT_0060157c,&local_430);
            local_414 = local_414 - local_420;
          }
          FUN_0042043e(DAT_0060157c,&local_410);
          BitBlt(local_3f4,0,0,local_3b0.right,local_3b0.bottom,DAT_0060157c,0,0,0xcc0020);
          if (DAT_005f77f0 != 0) {
            _sprintf(local_43c,&DAT_004fab08,local_3f8);
            SetBkMode(local_3f4,1);
            SetTextColor(local_3f4,0xffffff);
            c = _strlen(local_43c);
            TextOutA(local_3f4,0,0,local_43c,c);
          }
        }
        EndPaint(param_1,&local_3f0);
        local_8 = local_3f8;
        SetWindowLongA(param_1,0,local_3f8);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (param_2 == 1) {
      local_8 = 0;
      SetWindowLongA(param_1,0,0);
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      LVar4 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar4;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x117) {
    if (param_2 == 0x116) {
      local_8 = GetWindowLongA(param_1,0);
      _sprintf(local_460,&DAT_004fab0c,local_8);
      AppendMenuA(DAT_005dadec,0x10,(UINT_PTR)DAT_005dadf0,s_Count_library_cards_004fab10);
      ModifyMenuA(DAT_005dadf0,0x65,0,0x65,local_460);
      AppendMenuA(DAT_005dadec,0,100,s_Help____004fab24);
      return 0;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 100) {
        local_298 = 0x7e9;
        FUN_004d9630(local_3a0,&DAT_005f76e0);
        FUN_004d9640(local_3a0,s__duel_hlp_004faafc);
        WinHelpA(DAT_00618990,local_3a0,1,local_298);
      }
      return 0;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      return 0;
    }
    if (param_2 == 0x11f) {
      if ((param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_464 = GetMenuItemCount(DAT_005dadec);
        while (local_464 != 0) {
          RemoveMenu(DAT_005dadec,0,0x400);
          local_464 = local_464 + -1;
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar4 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar4;
    }
    if (param_2 == 0x204) {
      local_454.x = param_4 & 0xffff;
      local_454.y = param_4 >> 0x10;
      ClientToScreen(param_1,&local_454);
      SetRect(&local_44c,local_454.x,local_454.y,local_454.x + 1,local_454.y + 1);
      TrackPopupMenu(DAT_005dadec,2,local_454.x,local_454.y,0,param_1,&local_44c);
      return 0;
    }
  }
  else {
    if (param_2 == 0x400) {
      local_28c = FUN_00487924(param_1 != DAT_00663e68);
      GetClientRect(param_1,&local_274);
      iVar5 = local_28c;
      if (0x4a < local_28c) {
        iVar5 = 0x4b;
      }
      local_294 = (((local_274.right * 0x28) / 100) * iVar5) / 0x4b;
      local_290 = (local_274.bottom * local_294) / local_274.right;
      local_284 = local_274.right - local_294;
      local_288 = local_274.bottom - local_290;
      GetWindowRect(param_1,&local_274);
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
        pHVar1 = CreateWindowExA(0,s_ShuffleCard_004faaf0,&DAT_004faaec,0x90000000,local_278,
                                 local_27c,local_284,local_288,DAT_00618990,(HMENU)0x0,DAT_00664680,
                                 (LPVOID)0x0);
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
        UpdateWindow(DAT_00618990);
        iVar5 = local_280;
      }
      return 0;
    }
    if (param_2 == 0x432) {
      local_8 = GetWindowLongA(param_1,0);
      local_d4 = FUN_00487924(param_1 != DAT_00663e68);
      if (local_8 != local_d4) {
        InvalidateRect(param_1,(RECT *)0x0,1);
      }
      return 0;
    }
    if (param_2 == 0x437) {
      if (param_1 == DAT_00663e68) {
        FUN_004d9630(local_6c,s_Your_004faad8);
      }
      else {
        FUN_00448412(local_6c);
      }
      _sprintf(local_d0,s__s_library_004faae0,local_6c);
      FUN_004d9630(param_3,local_d0);
      return 1;
    }
  }
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}


