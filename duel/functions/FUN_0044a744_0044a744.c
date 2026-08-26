/*
 * Decompiled function: FUN_0044a744
 * Entry Point: 0044a744
 * Size: 5167 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0044a744(HWND param_1,uint param_2,uint param_3,uint param_4)

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
  RECT local_494;
  int local_484;
  int local_480;
  undefined1 local_47c [12];
  tagPOINT local_470;
  tagRECT local_468;
  int local_458 [4];
  int local_448;
  int local_444;
  int local_440;
  undefined1 local_43c [264];
  CHAR local_334 [8];
  int local_32c;
  COLORREF local_328 [7];
  HDC local_30c;
  tagPAINTSTRUCT local_308;
  int local_2c8;
  int local_2c4;
  RECT local_2c0;
  tagRECT local_2b0;
  COLORREF local_2a0;
  int local_29c [7];
  uint local_280;
  uint local_27c;
  tagMSG local_278;
  RECT local_25c;
  BOOL local_24c;
  int local_248;
  int local_244;
  int local_240;
  tagRECT local_23c;
  uint local_22c;
  CHAR local_228 [264];
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
  undefined1 local_8c [12];
  uint local_80;
  RECT local_7c;
  undefined1 local_6c [100];
  int *local_8;
  
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      local_8 = (int *)GetWindowLongA(param_1,0);
      FUN_0044853b(local_458,param_1 != DAT_00618950);
      if (((((*local_8 != local_458[0]) || (local_8[1] != local_458[1])) ||
           (local_8[2] != local_458[2])) ||
          ((local_8[4] != local_448 || (local_8[3] != local_458[3])))) ||
         ((local_8[5] != local_444 || (local_8[6] != local_440)))) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(param_1,&local_2b0);
      local_30c = DAT_0060157c;
      local_2c8 = SaveDC(DAT_0060157c);
      if (DAT_00516b50 == 0) {
        FUN_004d9630(local_43c,&DAT_006189a0);
        FUN_004d9640(local_43c,s__WINBK_ManaPool_pic_004f8080);
        DAT_00516b50 = FUN_0043d713(local_43c);
      }
      if (DAT_00516b50 == 0) {
        pHVar4 = GetStockObject(1);
        FillRect(local_30c,&local_2b0,pHVar4);
      }
      else {
        FUN_004709ae(local_30c,&local_2b0,DAT_00516b50);
      }
      SelectObject(local_30c,DAT_00516b4c);
      SetBkMode(local_30c,1);
      SetTextAlign(local_30c,6);
      local_32c = (local_2b0.right * 0x28) / 100;
      SetMapMode(local_30c,8);
      FUN_0044bb84(&local_2c0,param_1,1);
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
          RestoreDC(DAT_0060157c,local_2c8);
          local_30c = BeginPaint(param_1,&local_308);
          if (local_30c != (HDC)0x0) {
            FUN_004707a4(local_30c);
            GetClientRect(param_1,&local_2b0);
            if (DAT_00601580 != 0) {
              pHVar4 = GetStockObject(0);
              FillRect(local_30c,&local_2b0,pHVar4);
              Sleep(200);
            }
            BitBlt(local_30c,0,0,local_2b0.right,local_2b0.bottom,DAT_0060157c,0,0,0xcc0020);
            EndPaint(param_1,&local_308);
            *local_8 = local_458[0];
            local_8[1] = local_458[1];
            local_8[2] = local_458[2];
            local_8[4] = local_448;
            local_8[3] = local_458[3];
            local_8[5] = local_444;
            local_8[6] = local_440;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
          return 0;
        }
        wsprintfA(local_334,&DAT_004f8094,local_458[local_2c4]);
        FUN_0044bb84(&local_2c0,param_1,local_2c4);
        DPtoLP(local_30c,(LPPOINT)&local_2c0,2);
        if (local_2c4 == 6) {
          BVar2 = IsRectEmpty(&local_2c0);
          if (BVar2 == 0) goto LAB_0044b32b;
        }
        else {
          local_2c0.left = local_2c0.left + local_32c;
LAB_0044b32b:
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
    if (param_2 == 1) {
      local_8 = _malloc(0x1c);
      local_8[6] = 0;
      local_8[5] = local_8[6];
      local_8[3] = local_8[5];
      local_8[4] = local_8[3];
      local_8[2] = local_8[4];
      local_8[1] = local_8[2];
      *local_8 = local_8[1];
      SetWindowLongA(param_1,0,(LONG)local_8);
      if (local_8 == (undefined4 *)0x0) {
        return -1;
      }
      return 0;
    }
    if (param_2 == 2) {
      local_8 = (int *)GetWindowLongA(param_1,0);
      FUN_004db150(local_8);
      return 0;
    }
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      LVar5 = FUN_00471df6(param_1,0x20,param_3,param_4);
      return LVar5;
    }
    if (param_2 == 0x14) {
      return 1;
    }
  }
  else if (param_2 < 0x118) {
    if (param_2 == 0x117) {
      bVar1 = false;
      for (local_480 = 0; local_480 < 7; local_480 = local_480 + 1) {
        if ((&DAT_0068ece0)[local_480] != 0) {
          bVar1 = true;
        }
      }
      if ((((DAT_00618158 != 0) && (bVar1)) &&
          ((DAT_00664780 == 0xffffffff || (DAT_00664780 == DAT_006663fc)))) &&
         ((((DAT_00664784 == -1 || (DAT_00664784 == 0)) || (DAT_00664784 == 1)) &&
          ((((DAT_00664788 == -1 || (DAT_00664788 == 0)) || (DAT_00664788 == DAT_006764bc)) &&
           (((DAT_0066478c == 0xffffffff || (DAT_0066478c == DAT_006663fc)) &&
            ((DAT_00664790 == 0xffffffff || ((DAT_00664790 & 1) != 0)))))))))) {
        GetCursorPos(&local_500);
        MapWindowPoints((HWND)0x0,param_1,&local_500,1);
        local_484 = -1;
        FUN_0044bb84(&local_494,param_1,1);
        pt_07.y = local_500.y;
        pt_07.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_07);
        if (BVar2 != 0) {
          local_484 = 1;
          FUN_004d9630(local_47c,s_black_004f8098);
        }
        FUN_0044bb84(&local_494,param_1,5);
        pt_08.y = local_500.y;
        pt_08.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_08);
        if (BVar2 != 0) {
          local_484 = 5;
          FUN_004d9630(local_47c,s_white_004f80a0);
        }
        FUN_0044bb84(&local_494,param_1,2);
        pt_09.y = local_500.y;
        pt_09.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_09);
        if (BVar2 != 0) {
          local_484 = 2;
          FUN_004d9630(local_47c,&DAT_004f80a8);
        }
        FUN_0044bb84(&local_494,param_1,3);
        pt_10.y = local_500.y;
        pt_10.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_10);
        if (BVar2 != 0) {
          local_484 = 3;
          FUN_004d9630(local_47c,s_green_004f80b0);
        }
        FUN_0044bb84(&local_494,param_1,4);
        pt_11.y = local_500.y;
        pt_11.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_11);
        if (BVar2 != 0) {
          local_484 = 4;
          FUN_004d9630(local_47c,&DAT_004f80b8);
        }
        FUN_0044bb84(&local_494,param_1,0);
        pt_12.y = local_500.y;
        pt_12.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_12);
        if (BVar2 != 0) {
          local_484 = 0;
          FUN_004d9630(local_47c,&DAT_004f80bc);
        }
        FUN_0044bb84(&local_494,param_1,6);
        pt_13.y = local_500.y;
        pt_13.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_13);
        if (BVar2 != 0) {
          local_484 = 0;
          FUN_004d9630(local_47c,s_artifact_004f80c4);
        }
        if (local_484 != -1) {
          _sprintf(local_4f8,s_Spend_1_mana___s_004f80d0,local_47c);
          AppendMenuA(DAT_00516b48,0,local_484 + 0x65,local_4f8);
        }
      }
      iVar3 = GetMenuItemCount(DAT_00516b48);
      if (0 < iVar3) {
        AppendMenuA(DAT_00516b48,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00516b48,0,100,s_Help____004f80e4);
      return 0;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 100) {
        local_120 = 0x7ea;
        FUN_004d9630(local_228,&DAT_005f76e0);
        FUN_004d9640(local_228,s__duel_hlp_004f8074);
        WinHelpA(DAT_00618990,local_228,1,local_120);
      }
      else {
        local_22c = param_3 & 0xffff;
        if (100 < local_22c) {
          DAT_006663fc = (uint)(param_1 != DAT_00618950);
          DAT_006764bc = local_22c - 0x65;
          DAT_0066643c = 0;
          _DAT_00516b38 = 0xfffffffd;
          _DAT_00516b3c = 0xffffffff;
          _DAT_00516b40 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516b38);
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x202) {
    if (param_2 == 0x201) {
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        local_24c = PeekMessageA(&local_278,param_1,0x203,0x203,0);
        FUN_0044853b(local_29c,param_1 != DAT_00618950);
        GetClientRect(param_1,&local_23c);
        local_280 = param_4 & 0xffff;
        local_27c = param_4 >> 0x10;
        local_248 = local_23c.bottom / 6;
        DAT_006663fc = (uint)(param_1 != DAT_00618950);
        DAT_006764bc = -1;
        local_240 = local_248;
        for (local_244 = 0; local_244 < 7; local_244 = local_244 + 1) {
          FUN_0044bb84(&local_25c,param_1,local_244);
          pt_06.y = local_27c;
          pt_06.x = local_280;
          BVar2 = PtInRect(&local_25c,pt_06);
          if ((BVar2 != 0) && (0 < local_29c[local_244])) {
            DAT_006764bc = local_244;
          }
        }
        if ((((DAT_006764bc != -1) && (DAT_00618158 != 0)) &&
            ((DAT_00664780 == 0xffffffff || (DAT_00664780 == DAT_006663fc)))) &&
           ((DAT_00664790 == 0xffffffff || ((DAT_00664790 & 1) != 0)))) {
          DAT_0066643c = local_24c;
          _DAT_00516b28 = 0xfffffffd;
          _DAT_00516b2c = 0xffffffff;
          _DAT_00516b30 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516b28);
        }
      }
      return 0;
    }
    if (param_2 == 0x11f) {
      if ((param_3 >> 0x10 == 0xffff) && (param_4 == 0)) {
        local_508 = GetMenuItemCount(DAT_00516b48);
        while (local_508 != 0) {
          DeleteMenu(DAT_00516b48,0,0x400);
          local_508 = local_508 + -1;
        }
      }
      return 0;
    }
  }
  else if (param_2 < 0x312) {
    if (0x30e < param_2) {
      LVar5 = FUN_00472b60(param_1,param_2,param_3,param_4);
      return LVar5;
    }
    if (param_2 == 0x204) {
      local_470.x = param_4 & 0xffff;
      local_470.y = param_4 >> 0x10;
      ClientToScreen(param_1,&local_470);
      SetRect(&local_468,local_470.x,local_470.y,local_470.x + 1,local_470.y + 1);
      TrackPopupMenu(DAT_00516b48,2,local_470.x,local_470.y,0,param_1,&local_468);
      return 0;
    }
  }
  else {
    if (param_2 == 0x432) {
      local_8 = (int *)GetWindowLongA(param_1,0);
      FUN_0044853b(&local_11c,param_1 != DAT_00618950);
      if ((((*local_8 != local_11c) || (local_8[1] != local_118)) || (local_8[2] != local_114)) ||
         (((local_8[4] != local_10c || (local_8[3] != local_110)) ||
          ((local_8[5] != local_108 || (local_8[6] != local_104)))))) {
        InvalidateRect(param_1,(RECT *)0x0,0);
      }
      return 0;
    }
    if (param_2 == 0x437) {
      local_98 = param_4 & 0xffff;
      local_94 = param_4 >> 0x10;
      local_9c = -2;
      FUN_0044bb84(&local_7c,param_1,1);
      pt.y = local_94;
      pt.x = local_98;
      BVar2 = PtInRect(&local_7c,pt);
      if (BVar2 != 0) {
        local_9c = 1;
      }
      FUN_0044bb84(&local_7c,param_1,5);
      pt_00.y = local_94;
      pt_00.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_00);
      if (BVar2 != 0) {
        local_9c = 5;
      }
      FUN_0044bb84(&local_7c,param_1,2);
      pt_01.y = local_94;
      pt_01.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_01);
      if (BVar2 != 0) {
        local_9c = 2;
      }
      FUN_0044bb84(&local_7c,param_1,3);
      pt_02.y = local_94;
      pt_02.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_02);
      if (BVar2 != 0) {
        local_9c = 3;
      }
      FUN_0044bb84(&local_7c,param_1,4);
      pt_03.y = local_94;
      pt_03.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_03);
      if (BVar2 != 0) {
        local_9c = 4;
      }
      FUN_0044bb84(&local_7c,param_1,0);
      pt_04.y = local_94;
      pt_04.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_04);
      if (BVar2 != 0) {
        local_9c = 0;
      }
      FUN_0044bb84(&local_7c,param_1,6);
      pt_05.y = local_94;
      pt_05.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_05);
      if (BVar2 != 0) {
        local_9c = 6;
      }
      local_80 = (uint)(param_1 != DAT_00618950);
      if (local_80 == 0) {
        FUN_004d9630(local_6c,&DAT_004f8014);
      }
      else {
        FUN_00448412(local_6c);
      }
      FUN_004d9640(local_6c,s_mana_pool_004f801c);
      if (local_9c == 1) {
        FUN_004d9630(local_8c,s_Black_004f8028);
      }
      else if (local_9c == 5) {
        FUN_004d9630(local_8c,s_White_004f8030);
      }
      else if (local_9c == 2) {
        FUN_004d9630(local_8c,&DAT_004f8038);
      }
      else if (local_9c == 3) {
        FUN_004d9630(local_8c,s_Green_004f8040);
      }
      else if (local_9c == 4) {
        FUN_004d9630(local_8c,&DAT_004f8048);
      }
      else if (local_9c == 0) {
        FUN_004d9630(local_8c,&DAT_004f804c);
      }
      else if (local_9c == 6) {
        FUN_004d9630(local_8c,s_Artifact_004f8054);
      }
      if (((local_9c == 0) || (local_9c == 1)) ||
         ((local_9c == 5 ||
          ((((local_9c == 3 || (local_9c == 4)) || (local_9c == 2)) || (local_9c == 6)))))) {
        _sprintf(local_100,s__s__amount_of__s_004f8060,local_6c,local_8c);
        local_90 = 1;
      }
      else {
        local_90 = 0;
      }
      if (local_90 == 0) {
        return 0;
      }
      FUN_004d9630(param_3,local_100);
      return local_90;
    }
  }
  LVar5 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar5;
}


