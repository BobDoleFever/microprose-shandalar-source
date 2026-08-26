/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 004b9284
 * Size: 5153 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint uMsg,char *wParam,uint lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  bool bVar1;
  UINT dwMilliseconds;
  BOOL BVar2;
  int iVar3;
  HBRUSH pHVar4;
  LRESULT LVar5;
  int local_508;
  tagPOINT local_500;
  char local_4f8 [100];
  tagRECT local_494;
  int local_484;
  int local_480;
  char local_47c [12];
  tagPOINT local_470;
  tagRECT local_468;
  int local_458 [4];
  int local_448;
  int local_444;
  int local_440;
  char local_43c [264];
  CHAR local_334 [8];
  int local_32c;
  COLORREF local_328 [7];
  HDC local_30c;
  tagPAINTSTRUCT local_308;
  int local_2c8;
  int local_2c4;
  tagRECT local_2c0;
  tagRECT local_2b0;
  COLORREF local_2a0;
  int local_29c [7];
  uint local_280;
  uint local_27c;
  tagMSG local_278;
  tagRECT local_25c;
  BOOL local_24c;
  int local_248;
  int local_244;
  int local_240;
  tagRECT local_23c;
  uint local_22c;
  char local_228 [264];
  ULONG_PTR local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  char local_100 [100];
  int local_9c;
  uint local_98;
  uint local_94;
  int local_90;
  char local_8c [12];
  uint local_80;
  tagRECT local_7c;
  char local_6c [100];
  int *local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b7072(local_458,(uint)(hwnd != DAT_006b2d60));
      if (((((*local_8 != local_458[0]) || (local_8[1] != local_458[1])) ||
           (local_8[2] != local_458[2])) ||
          ((local_8[4] != local_448 || (local_8[3] != local_458[3])))) ||
         ((local_8[5] != local_444 || (local_8[6] != local_440)))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
      GetClientRect(hwnd,&local_2b0);
      local_30c = g_HdcBackBuffer;
      local_2c8 = SaveDC(g_HdcBackBuffer);
      if (DAT_00556b20 == (HANDLE)0x0) {
        strcpy(local_43c,&DAT_006b2e90);
        strcat(local_43c,s__WINBK_ManaPool_pic_0052d560);
        DAT_00556b20 = (HANDLE)Pic_Load_00423833(local_43c);
      }
      if (DAT_00556b20 == (HANDLE)0x0) {
        pHVar4 = GetStockObject(1);
        FillRect(local_30c,&local_2b0,pHVar4);
      }
      else {
        FUN_004f3b5f((int)local_30c,(int)&local_2b0,DAT_00556b20);
      }
      SelectObject(local_30c,DAT_00556b1c);
      SetBkMode(local_30c,1);
      SetTextAlign(local_30c,6);
      local_32c = (local_2b0.right * 0x28) / 100;
      SetMapMode(local_30c,8);
      Ai_Subsystem_004ba6b6(&local_2c0,hwnd,1);
      SetWindowExtEx(local_30c,local_2c0.right - local_2c0.left,0x28,(LPSIZE)0x0);
      SetViewportExtEx(local_30c,local_2c0.right - local_2c0.left,local_2c0.bottom - local_2c0.top,
                       (LPSIZE)0x0);
      local_2a0 = 0x10000c9;
      local_328[1] = 0x10000c8;
      local_328[2] = 0x100005d;
      local_328[3] = 0x1000026;
      local_328[4] = 0x100001e;
      local_328[5] = 0x10000bf;
      local_328[0] = 0x10000c5;
      local_328[6] = 0x10000d0;
      local_2c4 = 0;
      do {
        if (6 < local_2c4) {
          RestoreDC(g_HdcBackBuffer,local_2c8);
          local_30c = BeginPaint(hwnd,&local_308);
          if (local_30c != (HDC)0x0) {
            FUN_004f3955(local_30c);
            GetClientRect(hwnd,&local_2b0);
            if (DAT_0068a674 != 0) {
              pHVar4 = GetStockObject(0);
              FillRect(local_30c,&local_2b0,pHVar4);
              Sleep(200);
            }
            BitBlt(local_30c,0,0,local_2b0.right,local_2b0.bottom,g_HdcBackBuffer,0,0,0xcc0020);
            EndPaint(hwnd,&local_308);
            *local_8 = local_458[0];
            local_8[1] = local_458[1];
            local_8[2] = local_458[2];
            local_8[4] = local_448;
            local_8[3] = local_458[3];
            local_8[5] = local_444;
            local_8[6] = local_440;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff2f0);
          return 0;
        }
        wsprintfA(local_334,&DAT_0052d574,local_458[local_2c4]);
        Ai_Subsystem_004ba6b6(&local_2c0,hwnd,local_2c4);
        DPtoLP(local_30c,(LPPOINT)&local_2c0,2);
        if (local_2c4 == 6) {
          BVar2 = IsRectEmpty(&local_2c0);
          if (BVar2 == 0) goto LAB_004b9e62;
        }
        else {
          local_2c0.left = local_2c0.left + local_32c;
LAB_004b9e62:
          SetTextColor(local_30c,local_2a0);
          iVar3 = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left + 1,local_2c0.top + 1,local_334,iVar3);
          SetTextColor(local_30c,local_328[local_2c4]);
          iVar3 = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left,local_2c0.top,local_334,iVar3);
        }
        local_2c4 = local_2c4 + 1;
      } while( true );
    }
    if (uMsg == 1) {
      local_8 = malloc(0x1c);
      local_8[6] = 0;
      local_8[5] = local_8[6];
      local_8[3] = local_8[5];
      local_8[4] = local_8[3];
      local_8[2] = local_8[4];
      local_8[1] = local_8[2];
      *local_8 = local_8[1];
      SetWindowLongA(hwnd,0,(LONG)local_8);
      if (local_8 == (undefined4 *)0x0) {
        return -1;
      }
      return 0;
    }
    if (uMsg == 2) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      free(local_8);
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
      bVar1 = false;
      for (local_480 = 0; local_480 < 7; local_480 = local_480 + 1) {
        if ((&DAT_006b2d40)[local_480] != 0) {
          bVar1 = true;
        }
      }
      if ((((DAT_006b1578 != 0) && (bVar1)) &&
          ((DAT_006feec0 == 0xffffffff || (DAT_006feec0 == DAT_00627858)))) &&
         ((((DAT_006feec4 == -1 || (DAT_006feec4 == 0)) || (DAT_006feec4 == 1)) &&
          ((((DAT_006feec8 == -1 || (DAT_006feec8 == 0)) || (DAT_006feec8 == DAT_00633430)) &&
           (((DAT_006feecc == 0xffffffff || (DAT_006feecc == DAT_00627858)) &&
            ((DAT_006feed0 == 0xffffffff || ((DAT_006feed0 & 1) != 0)))))))))) {
        GetCursorPos(&local_500);
        MapWindowPoints((HWND)0x0,hwnd,&local_500,1);
        local_484 = -1;
        Ai_Subsystem_004ba6b6(&local_494,hwnd,1);
        pt_07.y = local_500.y;
        pt_07.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_07);
        if (BVar2 != 0) {
          local_484 = 1;
          strcpy(local_47c,s_black_0052d578);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,5);
        pt_08.y = local_500.y;
        pt_08.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_08);
        if (BVar2 != 0) {
          local_484 = 5;
          strcpy(local_47c,s_white_0052d580);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,2);
        pt_09.y = local_500.y;
        pt_09.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_09);
        if (BVar2 != 0) {
          local_484 = 2;
          strcpy(local_47c,&DAT_0052d588);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,3);
        pt_10.y = local_500.y;
        pt_10.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_10);
        if (BVar2 != 0) {
          local_484 = 3;
          strcpy(local_47c,s_green_0052d590);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,4);
        pt_11.y = local_500.y;
        pt_11.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_11);
        if (BVar2 != 0) {
          local_484 = 4;
          strcpy(local_47c,&DAT_0052d598);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,0);
        pt_12.y = local_500.y;
        pt_12.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_12);
        if (BVar2 != 0) {
          local_484 = 0;
          strcpy(local_47c,&DAT_0052d59c);
        }
        Ai_Subsystem_004ba6b6(&local_494,hwnd,6);
        pt_13.y = local_500.y;
        pt_13.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_13);
        if (BVar2 != 0) {
          local_484 = 0;
          strcpy(local_47c,s_artifact_0052d5a4);
        }
        if (local_484 != -1) {
          sprintf(local_4f8,s_Spend_1_mana___s_0052d5b0,local_47c);
          AppendMenuA(DAT_00556b18,0,local_484 + 0x65,local_4f8);
        }
      }
      iVar3 = GetMenuItemCount(DAT_00556b18);
      if (0 < iVar3) {
        AppendMenuA(DAT_00556b18,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00556b18,0,100,s_Help____0052d5c4);
      return 0;
    }
    if (uMsg == 0x111) {
      if (((uint)wParam & 0xffff) == 100) {
        local_120 = 0x7ea;
        strcpy(local_228,&DAT_006807a0);
        strcat(local_228,s__duel_hlp_0052d554);
        WinHelpA(g_MainAppHwnd,local_228,1,local_120);
      }
      else {
        local_22c = (uint)wParam & 0xffff;
        if (100 < local_22c) {
          DAT_00627858 = (uint)(hwnd != DAT_006b2d60);
          DAT_00633430 = local_22c - 0x65;
          DAT_00627864 = 0;
          _DAT_00556b08 = 0xfffffffd;
          _DAT_00556b0c = 0xffffffff;
          _DAT_00556b10 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x556b08);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      if (DAT_006b1578 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        local_24c = PeekMessageA(&local_278,hwnd,0x203,0x203,0);
        Ai_Subsystem_004b7072(local_29c,(uint)(hwnd != DAT_006b2d60));
        GetClientRect(hwnd,&local_23c);
        local_280 = lParam & 0xffff;
        local_27c = lParam >> 0x10;
        local_248 = local_23c.bottom / 6;
        DAT_00627858 = (uint)(hwnd != DAT_006b2d60);
        DAT_00633430 = -1;
        local_240 = local_248;
        for (local_244 = 0; local_244 < 7; local_244 = local_244 + 1) {
          Ai_Subsystem_004ba6b6(&local_25c,hwnd,local_244);
          pt_06.y = local_27c;
          pt_06.x = local_280;
          BVar2 = PtInRect(&local_25c,pt_06);
          if ((BVar2 != 0) && (0 < local_29c[local_244])) {
            DAT_00633430 = local_244;
          }
        }
        if ((((DAT_00633430 != -1) && (DAT_006b1578 != 0)) &&
            ((DAT_006feec0 == 0xffffffff || (DAT_006feec0 == DAT_00627858)))) &&
           ((DAT_006feed0 == 0xffffffff || ((DAT_006feed0 & 1) != 0)))) {
          DAT_00627864 = local_24c;
          _DAT_00556af8 = 0xfffffffd;
          _DAT_00556afc = 0xffffffff;
          _DAT_00556b00 = 0xffffffff;
          PostMessageA(g_MainAppHwnd,0x464,0,0x556af8);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_508 = GetMenuItemCount(DAT_00556b18);
        while (local_508 != 0) {
          DeleteMenu(DAT_00556b18,0,0x400);
          local_508 = local_508 + -1;
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
      local_470.x = lParam & 0xffff;
      local_470.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_470);
      SetRect(&local_468,local_470.x,local_470.y,local_470.x + 1,local_470.y + 1);
      TrackPopupMenu(DAT_00556b18,2,local_470.x,local_470.y,0,hwnd,&local_468);
      return 0;
    }
  }
  else {
    if (uMsg == 0x432) {
      local_8 = (int *)GetWindowLongA(hwnd,0);
      Ai_Subsystem_004b7072(&local_11c,(uint)(hwnd != DAT_006b2d60));
      if ((((*local_8 != local_11c) || (local_8[1] != local_118)) || (local_8[2] != local_114)) ||
         (((local_8[4] != local_10c || (local_8[3] != local_110)) ||
          ((local_8[5] != local_108 || (local_8[6] != local_104)))))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_98 = lParam & 0xffff;
      local_94 = lParam >> 0x10;
      local_9c = -2;
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,1);
      pt.y = local_94;
      pt.x = local_98;
      BVar2 = PtInRect(&local_7c,pt);
      if (BVar2 != 0) {
        local_9c = 1;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,5);
      pt_00.y = local_94;
      pt_00.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_00);
      if (BVar2 != 0) {
        local_9c = 5;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,2);
      pt_01.y = local_94;
      pt_01.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_01);
      if (BVar2 != 0) {
        local_9c = 2;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,3);
      pt_02.y = local_94;
      pt_02.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_02);
      if (BVar2 != 0) {
        local_9c = 3;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,4);
      pt_03.y = local_94;
      pt_03.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_03);
      if (BVar2 != 0) {
        local_9c = 4;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,0);
      pt_04.y = local_94;
      pt_04.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_04);
      if (BVar2 != 0) {
        local_9c = 0;
      }
      Ai_Subsystem_004ba6b6(&local_7c,hwnd,6);
      pt_05.y = local_94;
      pt_05.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_05);
      if (BVar2 != 0) {
        local_9c = 6;
      }
      local_80 = (uint)(hwnd != DAT_006b2d60);
      if (local_80 == 0) {
        strcpy(local_6c,&DAT_0052d4f4);
      }
      else {
        Ai_Subsystem_004b6f49(local_6c);
      }
      strcat(local_6c,s_mana_pool_0052d4fc);
      if (local_9c == 1) {
        strcpy(local_8c,s_Black_0052d508);
      }
      else if (local_9c == 5) {
        strcpy(local_8c,s_White_0052d510);
      }
      else if (local_9c == 2) {
        strcpy(local_8c,&DAT_0052d518);
      }
      else if (local_9c == 3) {
        strcpy(local_8c,s_Green_0052d520);
      }
      else if (local_9c == 4) {
        strcpy(local_8c,&DAT_0052d528);
      }
      else if (local_9c == 0) {
        strcpy(local_8c,&DAT_0052d52c);
      }
      else if (local_9c == 6) {
        strcpy(local_8c,s_Artifact_0052d534);
      }
      if (((local_9c == 0) || (local_9c == 1)) ||
         ((local_9c == 5 ||
          ((((local_9c == 3 || (local_9c == 4)) || (local_9c == 2)) || (local_9c == 6)))))) {
        sprintf(local_100,s__s__amount_of__s_0052d540,local_6c,local_8c);
        local_90 = 1;
      }
      else {
        local_90 = 0;
      }
      if (local_90 == 0) {
        return 0;
      }
      strcpy(wParam,local_100);
      return local_90;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar5;
}


