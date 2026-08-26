/*
 * Decompiled function: SpellChain_WndProc
 * Entry Point: 004cdb4f
 * Size: 7402 bytes
 */
#include "magic.h"


uint SpellChain_WndProc(HWND hwnd,uint y,HWND param_3,uint height)

{
  int iVar1;
  LONG LVar2;
  LONG LVar3;
  void *pvVar4;
  HBRUSH hbr;
  HGDIOBJ pvVar5;
  int iVar6;
  HWND pHVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_1a04;
  tagPOINT local_1a00;
  tagRECT local_19f8;
  uint local_19e8;
  undefined1 local_19e0 [8];
  int local_19d8;
  int local_19c4;
  int local_19c0;
  tagRECT local_19bc;
  undefined4 local_19ac;
  int local_19a8;
  tagRECT local_19a4;
  HBITMAP local_1994;
  CHAR local_1990 [100];
  HDC local_192c;
  undefined1 local_1928 [4];
  int local_1924;
  int local_1920;
  int local_1910;
  int local_190c;
  int local_1908;
  int local_1904;
  int local_1900;
  int local_18fc;
  uint local_18f8;
  tagRECT local_18f4;
  tagRECT local_18e4;
  tagRECT local_18d4;
  HWND local_18c4;
  int local_18bc;
  uint local_18b8;
  tagRECT local_18b4;
  int local_18a4;
  uint local_18a0;
  uint local_189c;
  int local_1898;
  tagRECT local_1894;
  tagRECT local_1884;
  HWND local_1874;
  uint local_1870;
  uint local_186c;
  char local_1868 [264];
  HWND local_1760;
  undefined1 local_175c [4];
  int local_1758;
  tagRECT local_1744;
  tagRECT local_1734;
  LRESULT local_1724;
  HWND local_1720;
  char local_171c [264];
  ULONG_PTR local_1614;
  int local_1610;
  undefined1 local_160c [4];
  int local_1608;
  int local_1604;
  int local_15f4;
  int local_15f0;
  int local_15ec;
  tagRECT local_15e8;
  int local_15d8;
  int local_15d4;
  int local_15d0;
  int local_15cc;
  int local_15c8;
  int local_15c4;
  undefined4 local_15c0 [1322];
  undefined4 uStackY_118;
  undefined4 auStackY_114 [19];
  undefined4 uStackY_c8;
  undefined4 in_stack_ffffff40;
  undefined4 in_stack_ffffff44;
  int iVar11;
  int iVar12;
  UINT Msg;
  WPARAM wParam;
  undefined1 *puVar13;
  LPARAM lParam;
  BOOL bRepaint;
  
  Mem_AllocOrFree_00513bd0();
  if (y < 0x11) {
    if (y == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00565940,0);
      return 0;
    }
    if (y == 1) {
      SetWindowLongA(hwnd,4,0);
      pvVar4 = malloc(0x2260);
      SetWindowLongA(hwnd,0,(LONG)pvVar4);
      local_1720 = CreateWindowExA(0,s_MAGICGAME_ScrollbarClass_0052e768,&DAT_0052e764,0x50000000,0,
                                   0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (local_1720 != (HWND)0x0) {
        SendMessageA(local_1720,0x464,(WPARAM)DAT_0056597c,0);
        SendMessageA(local_1720,0x466,DAT_00565978,DAT_0052e6e4);
      }
      DAT_00565940 = CreateWindowExA(0,s_SpellMinimized_0052e788,&DAT_0052e784,0x80000000,0,0,0,0,
                                     hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
      if (((pvVar4 != (void *)0x0) && (local_1720 != (HWND)0x0)) && (DAT_00565940 != (HWND)0x0)) {
        return 0;
      }
      if (pvVar4 != (void *)0x0) {
        free(pvVar4);
      }
      return 0xffffffff;
    }
    if (y == 2) {
      pvVar4 = (void *)GetWindowLongA(hwnd,0);
      free(pvVar4);
      return 0;
    }
    if (y == 5) {
      GetClientRect(hwnd,&local_19bc);
      if (DAT_0056597c == (HANDLE)0x0) {
        local_19c0 = GetSystemMetrics(3);
        local_19c0 = local_19c0 * 2;
      }
      else {
        GetObjectA(DAT_0056597c,0x18,local_19e0);
        iVar6 = GetSystemMetrics(3);
        if (iVar6 * 2 < local_19d8) {
          local_19c0 = local_19d8;
        }
        else {
          local_19c0 = GetSystemMetrics(3);
          local_19c0 = local_19c0 * 2;
        }
      }
      local_19ac = 0;
      local_19c4 = local_19bc.bottom - local_19c0;
      bRepaint = 1;
      iVar12 = 0;
      iVar6 = local_19c4;
      iVar11 = local_19c0;
      pHVar7 = GetDlgItem(hwnd,0);
      MoveWindow(pHVar7,iVar12,iVar6,local_19bc.right,iVar11,bRepaint);
      return 0;
    }
  }
  else if (y < 0x19) {
    if (y == 0x18) {
      PostMessageA(DAT_007006b0,0x403,0,0);
      uVar8 = DefWindowProcA(hwnd,0x18,(WPARAM)param_3,height);
      return uVar8;
    }
    if (y == 0x14) {
      local_1760 = param_3;
      FUN_004f3955((HDC)param_3);
      GetClientRect(hwnd,&local_1734);
      local_1724 = SendDlgItemMessageA(hwnd,0,0xe1,0,0);
      if (DAT_00565984 == (HANDLE)0x0) {
        strcpy(local_1868,&DAT_006b2e90);
        strcat(local_1868,s__WINBK_SpellChain_pic_0052e798);
        DAT_00565984 = (HANDLE)Pic_Load_00423833(local_1868);
      }
      if (DAT_00565984 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_1760,&local_1734,hbr);
      }
      else {
        CopyRect(&local_1744,&local_1734);
        GetObjectA(DAT_00565984,0x18,local_175c);
        local_1744.left = -(local_1724 % local_1758);
        FUN_004f3d11((HDC)local_1760,&local_1744.left,DAT_00565984);
      }
      return 1;
    }
  }
  else if (y < 0x85) {
    if (y == 0x84) {
      local_18b8 = DefWindowProcA(hwnd,0x84,(WPARAM)param_3,height);
      if (local_18b8 != 2) {
        return local_18b8;
      }
      local_18bc = GetSystemMetrics(0x1e);
      GetClientRect(hwnd,&local_18b4);
      MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_18b4,2);
      return 8;
    }
    if (y == 0x20) {
      uVar8 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)param_3,height);
      return uVar8;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      local_18c4 = param_3;
      if (param_3 == (HWND)0x8) {
        SendMessageA(hwnd,0x111,0x65,0);
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0xa1,(WPARAM)param_3,height);
      return uVar8;
    }
    if ((0x84 < y) && (y < 0x87)) {
      GetWindowRect(hwnd,&local_18d4);
      OffsetRect(&local_18d4,-local_18d4.left,-local_18d4.top);
      if ((local_18d4.right != local_18d4.left) && (local_18d4.bottom != local_18d4.top)) {
        local_18f8 = (uint)(y != 0x85);
        local_192c = GetWindowDC(hwnd);
        if (local_192c == (HDC)0x0) {
          return local_18f8;
        }
        FUN_004f3955(local_192c);
        GetWindowRect(hwnd,&local_18d4);
        GetClientRect(hwnd,&local_19a4);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_19a4,2);
        OffsetRect(&local_19a4,-local_18d4.left,-local_18d4.top);
        OffsetRect(&local_18d4,-local_18d4.left,-local_18d4.top);
        GetWindowTextA(hwnd,local_1990,100);
        local_19a8 = local_18d4.right - local_19a4.right;
        local_1900 = local_18d4.bottom - local_19a4.bottom;
        SelectObject(local_192c,DAT_0056598c);
        local_1904 = 0;
        MoveToEx(local_192c,0,0,(LPPOINT)0x0);
        LineTo(local_192c,local_18d4.right + -1,local_1904);
        SelectObject(local_192c,DAT_00565948);
        local_1904 = 1;
        for (local_1908 = 1; local_1908 <= local_1900 + -2; local_1908 = local_1908 + 1) {
          MoveToEx(local_192c,1,local_1904,(LPPOINT)0x0);
          LineTo(local_192c,(local_18d4.right - local_19a8) + 1,local_1904);
          local_1904 = local_1904 + 1;
        }
        SelectObject(local_192c,DAT_0056598c);
        local_1904 = local_1900 + -1;
        MoveToEx(local_192c,local_19a8 + -1,local_1904,(LPPOINT)0x0);
        LineTo(local_192c,local_19a4.right + 1,local_1904);
        SelectObject(local_192c,DAT_0056598c);
        local_18fc = 0;
        MoveToEx(local_192c,0,0,(LPPOINT)0x0);
        LineTo(local_192c,local_18fc,local_18d4.bottom + -1);
        SelectObject(local_192c,DAT_00565948);
        local_18fc = 1;
        for (local_1908 = 1; local_1908 <= local_19a8 + -2; local_1908 = local_1908 + 1) {
          MoveToEx(local_192c,local_18fc,1,(LPPOINT)0x0);
          LineTo(local_192c,local_18fc,local_18d4.bottom + -1);
          local_18fc = local_18fc + 1;
        }
        SelectObject(local_192c,DAT_0056598c);
        local_18fc = local_19a4.left + -1;
        MoveToEx(local_192c,local_18fc,local_1900 + -1,(LPPOINT)0x0);
        LineTo(local_192c,local_18fc,local_19a4.bottom + 1);
        pvVar5 = GetStockObject(7);
        SelectObject(local_192c,pvVar5);
        local_18fc = local_18d4.right + -1;
        MoveToEx(local_192c,local_18fc,0,(LPPOINT)0x0);
        LineTo(local_192c,local_18fc,local_18d4.bottom);
        SelectObject(local_192c,DAT_00565950);
        local_18fc = local_18d4.right + -2;
        for (local_1908 = 1; local_1908 <= local_19a8 + -2; local_1908 = local_1908 + 1) {
          MoveToEx(local_192c,local_18fc,1,(LPPOINT)0x0);
          LineTo(local_192c,local_18fc,local_18d4.bottom + -1);
          local_18fc = local_18fc + -1;
        }
        SelectObject(local_192c,DAT_0056598c);
        local_18fc = local_19a4.right;
        MoveToEx(local_192c,local_19a4.right,local_1900 + -1,(LPPOINT)0x0);
        LineTo(local_192c,local_18fc,local_19a4.bottom + 1);
        pvVar5 = GetStockObject(7);
        SelectObject(local_192c,pvVar5);
        local_1904 = local_18d4.bottom + -1;
        MoveToEx(local_192c,0,local_1904,(LPPOINT)0x0);
        LineTo(local_192c,local_18d4.right,local_1904);
        SelectObject(local_192c,DAT_00565950);
        local_1904 = local_18d4.bottom + -2;
        for (local_1908 = 1; local_1908 <= local_1900 + -2; local_1908 = local_1908 + 1) {
          MoveToEx(local_192c,1,local_1904,(LPPOINT)0x0);
          LineTo(local_192c,local_18d4.right + -1,local_1904);
          local_1904 = local_1904 + -1;
        }
        SelectObject(local_192c,DAT_0056598c);
        local_1904 = local_18d4.bottom - local_1900;
        MoveToEx(local_192c,local_19a8 + -1,local_1904,(LPPOINT)0x0);
        LineTo(local_192c,local_18d4.right + -2,local_1904);
        SelectObject(local_192c,DAT_0056598c);
        local_1904 = local_19a4.top + -1;
        MoveToEx(local_192c,local_19a4.left,local_1904,(LPPOINT)0x0);
        LineTo(local_192c,local_19a4.right + 1,local_1904);
        SetRect(&local_18e4,local_19a4.left,local_1900,local_19a4.right,local_19a4.top + -1);
        FillRect(local_192c,&local_18e4,DAT_00565988);
        SetTextColor(local_192c,DAT_00565944);
        SetBkMode(local_192c,1);
        local_18e4.left = local_18e4.left + 5;
        DrawTextA(local_192c,local_1990,-1,&local_18e4,0x24);
        local_1994 = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fed);
        GetObjectA(local_1994,0x18,local_1928);
        local_190c = local_1924;
        local_1910 = local_1920;
        SetRect(&local_18f4,local_19a4.right - local_1924,local_19a4.top - local_1920,
                local_19a4.right,local_19a4.top);
        FUN_004f3b5f((int)local_192c,(int)&local_18f4,DAT_00565980);
        DeleteObject(local_1994);
        ReleaseDC(hwnd,local_192c);
        return local_18f8;
      }
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
      return uVar8;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uVar8 = (uint)param_3 & 0xffff;
      if (uVar8 == 100) {
        local_1614 = 0xbd2;
        strcpy(local_171c,&DAT_006807a0);
        strcat(local_171c,s__duel_hlp_0052e758);
        WinHelpA(g_MainAppHwnd,local_171c,1,local_1614);
      }
      else if (uVar8 == 0x65) {
        ShowWindow(hwnd,0);
        UpdateWindow(DAT_006b2e2c);
        GetWindowRect(DAT_006a284c,&local_15e8);
        local_15ec = local_15e8.left;
        local_15f4 = local_15e8.right - local_15e8.left;
        if (DAT_00565980 == (HANDLE)0x0) {
          local_1610 = local_15f4 * 2;
        }
        else {
          GetObjectA(DAT_00565980,0x18,local_160c);
          local_1610 = (local_1604 * local_15f4) / local_1608;
        }
        local_15f0 = (local_15e8.bottom - local_15e8.top) / 2 - local_1610 / 2;
        MoveWindow(DAT_00565940,local_15ec,local_15f0,local_15f4,local_1610,1);
        ShowWindow(DAT_00565940,5);
        BringWindowToTop(DAT_00565940);
        SendMessageA(DAT_007006b0,0x403,0,0);
      }
      else if (uVar8 == 0x66) {
        ShowWindow(DAT_00565940,0);
        ShowWindow(hwnd,5);
        SendMessageA(DAT_007006b0,0x403,0,0);
        FUN_004f59f7();
      }
      return 0;
    }
    if (y == 0xa4) {
LAB_004cf521:
      local_1a00.x = height & 0xffff;
      local_1a00.y = height >> 0x10;
      if (y == 0x204) {
        ClientToScreen(hwnd,&local_1a00);
      }
      SetRect(&local_19f8,local_1a00.x,local_1a00.y,local_1a00.x + 1,local_1a00.y + 1);
      TrackPopupMenu(DAT_0056594c,2,local_1a00.x,local_1a00.y,0,hwnd,&local_19f8);
      return 0;
    }
  }
  else if (y < 0x120) {
    if (y == 0x11f) {
      if (((uint)param_3 >> 0x10 == 0xffff) && (height == 0)) {
        local_1a04 = GetMenuItemCount(DAT_0056594c);
        while (local_1a04 != 0) {
          DeleteMenu(DAT_0056594c,0,0x400);
          local_1a04 = local_1a04 + -1;
        }
      }
      return 0;
    }
    if (y == 0x112) {
      local_19e8 = (uint)param_3 & 0xfff0;
      if (local_19e8 == 0xf010) {
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0x112,(WPARAM)param_3,height);
      return uVar8;
    }
    if (y == 0x114) {
      local_1874 = GetDlgItem(hwnd,0);
      SendMessageA(local_1874,0xe3,(WPARAM)&local_189c,(LPARAM)&local_1870);
      local_18a0 = SendMessageA(local_1874,0xe1,0,0);
      local_1898 = DAT_006a28b0;
      GetClientRect(hwnd,&local_1884);
      local_18a4 = local_1884.right;
      switch((uint)param_3 & 0xffff) {
      case 0:
        local_186c = local_18a0 - local_1898;
        break;
      case 1:
        local_186c = local_1898 + local_18a0;
        break;
      case 2:
        local_186c = local_18a0 - local_1884.right;
        break;
      case 3:
        local_186c = local_1884.right + local_18a0;
        break;
      case 4:
      case 5:
        local_186c = (uint)param_3 >> 0x10;
        break;
      case 6:
        local_186c = local_189c;
        break;
      case 7:
        local_186c = local_1870;
        break;
      default:
        local_186c = local_18a0;
      }
      if ((int)local_186c < (int)local_189c) {
        local_186c = local_189c;
      }
      if ((int)local_1870 < (int)local_186c) {
        local_186c = local_1870;
      }
      if (local_186c != local_18a0) {
        SendMessageA(local_1874,0xe0,local_186c,1);
        GetWindowRect(local_1874,&local_1894);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1894,2);
        ScrollWindow(hwnd,local_18a0 - local_186c,0,(RECT *)0x0,(RECT *)0x0);
        MoveWindow(local_1874,local_1894.left,local_1894.top,local_1894.right - local_1894.left,
                   local_1894.bottom - local_1894.top,0);
        UpdateWindow(hwnd);
      }
      return 0;
    }
    if (y == 0x117) {
      AppendMenuA(DAT_0056594c,0,0x65,s__Minimize_0052e7b0);
      AppendMenuA(DAT_0056594c,0,100,s_Help____0052e7bc);
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) goto LAB_004cf521;
    if (y == 0x201) {
      return 0;
    }
  }
  else if (y < 0x40d) {
    if (y == 0x40c) {
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00565940,0);
      for (local_15d4 = 0; local_15d4 < LVar3; local_15d4 = local_15d4 + 1) {
        DestroyWindow(*(HWND *)(LVar2 + local_15d4 * 0x58));
        for (local_15d8 = 0; local_15d8 < *(int *)(LVar2 + 0x54 + local_15d4 * 0x58);
            local_15d8 = local_15d8 + 1) {
          DestroyWindow(*(HWND *)(local_15d8 * 4 + local_15d4 * 0x58 + 4 + LVar2));
        }
        *(undefined4 *)(LVar2 + 0x54 + local_15d4 * 0x58) = 0;
      }
      SetWindowLongA(hwnd,4,0);
      lParam = 1;
      wParam = 0;
      Msg = 0xe0;
      pHVar7 = GetDlgItem(hwnd,0);
      SendMessageA(pHVar7,Msg,wParam,lParam);
      SpellChain_UpdateLayout(hwnd,(LPRECT)&DAT_00565968);
      return 0;
    }
    if ((0x30e < y) && (y < 0x312)) {
      uVar8 = FUN_004f5d1a(hwnd,y,param_3,height);
      return uVar8;
    }
  }
  else {
    switch(y) {
    case 0x412:
      LVar2 = GetWindowLongA(hwnd,0);
      GetWindowLongA(hwnd,4);
      iVar6 = Ai_Subsystem_004b7373(local_15c0);
      local_15c4 = 0;
      for (local_15c8 = 0; local_15c8 < iVar6; local_15c8 = local_15c8 + 1) {
        puVar9 = local_15c0 + local_15c8 * 0x2b;
        puVar10 = (undefined4 *)&stack0xffffff40;
        for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        uStackY_c8 = 0x4ce06d;
        local_15d0 = SpellChain_GetCardCount(hwnd);
        if (local_15d0 == local_15c8) {
          puVar9 = local_15c0 + local_15d0 * 0x2b;
          puVar10 = (undefined4 *)&stack0xffffff44;
          for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          puVar9 = (undefined4 *)(local_15d0 * 0x58 + LVar2);
          puVar10 = auStackY_114;
          for (iVar11 = 0x16; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          uStackY_118 = 0x4ce0db;
          iVar11 = SpellChain_HasActiveSpells();
          if (iVar11 == 0) {
            SpellChain_RemoveCardSlot(hwnd,local_15d0);
            puVar9 = local_15c0 + local_15d0 * 0x2b;
            puVar10 = (undefined4 *)&stack0xffffff40;
            for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            uStackY_c8 = 0x4ce135;
            SpellChain_CreateTargetSlot(hwnd);
            local_15c4 = 1;
          }
        }
        else if (local_15d0 == -1) {
          puVar9 = local_15c0 + local_15c8 * 0x2b;
          puVar10 = (undefined4 *)&stack0xffffff40;
          for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          uStackY_c8 = 0x4ce190;
          SpellChain_CreateCardSlot(hwnd,in_stack_ffffff40,in_stack_ffffff44);
          local_15c4 = 1;
        }
        else if (local_15c8 < local_15d0) {
          for (local_15cc = local_15c8; local_15cc < local_15d0; local_15cc = local_15cc + 1) {
            SpellChain_UpdateTargetPositions(hwnd,local_15cc);
          }
          local_15c4 = 1;
        }
      }
      LVar2 = GetWindowLongA(hwnd,4);
      for (local_15cc = local_15c8; local_15cc < LVar2; local_15cc = local_15cc + 1) {
        SpellChain_UpdateTargetPositions(hwnd,local_15cc);
        local_15c4 = 1;
      }
      if (local_15c4 != 0) {
        SpellChain_UpdateLayout(hwnd,(LPRECT)&DAT_00565968);
      }
      return 0;
    case 0x432:
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      for (iVar6 = 0; iVar6 < LVar3; iVar6 = iVar6 + 1) {
        iVar6 = 0x432;
        SendMessageA(*(HWND *)(LVar2 + 0x17130),0x432,0,0);
        puVar13 = (undefined1 *)0x0;
        while ((int)puVar13 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58)) {
          iVar6 = 0x432;
          pHVar7 = *(HWND *)((int)puVar13 * 4 + 0x17134 + LVar2);
          SendMessageA(pHVar7,0x432,0,0);
          puVar13 = (undefined1 *)((int)&pHVar7->unused + 1);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      for (iVar6 = 0; iVar6 < LVar3; iVar6 = iVar6 + 1) {
        pHVar7 = *(HWND *)(LVar2 + iVar6 * 0x58);
        iVar11 = FUN_0046bbab(pHVar7,(int)param_3);
        if (iVar11 != 0) {
          pHVar7 = (HWND)0x0;
          InvalidateRect(*(HWND *)(LVar2 + iVar6 * 0x58),(RECT *)0x0,0);
        }
        puVar13 = (undefined1 *)0x0;
        param_3 = pHVar7;
        while ((int)puVar13 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58)) {
          pHVar7 = *(HWND *)((int)param_3 * 4 + iVar6 * 0x58 + 4 + LVar2);
          iVar11 = FUN_0046bbab(pHVar7,(int)param_3);
          if (iVar11 != 0) {
            param_3 = (HWND)0x0;
            pHVar7 = (HWND)0x0;
            InvalidateRect(*(HWND *)(iVar6 * 0x58 + 4 + LVar2),(RECT *)0x0,0);
          }
          puVar13 = (undefined1 *)((int)&param_3->unused + 1);
          param_3 = pHVar7;
        }
      }
      return 0;
    case 0x435:
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      for (iVar6 = 0; iVar6 < LVar3; iVar6 = iVar6 + 1) {
        InvalidateRect(*(HWND *)(LVar2 + iVar6 * 0x58),(RECT *)0x0,0);
        for (iVar11 = 0; iVar11 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58); iVar11 = iVar11 + 1) {
          InvalidateRect(*(HWND *)(iVar11 * 4 + iVar6 * 0x58 + 4 + LVar2),(RECT *)0x0,0);
        }
      }
      return 0;
    case 0x436:
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      if (param_3 == (HWND)0x0) {
        return 0;
      }
      iVar11 = 0;
      iVar6 = 0;
      while ((iVar6 < LVar3 && (iVar11 == 0))) {
        iVar12 = FUN_0046bb29(*(HWND *)(LVar2 + iVar6 * 0x58),&param_3->unused);
        if (iVar12 != 0) {
          iVar11 = 1;
          if (height == 0) {
            InvalidateRect(*(HWND *)(LVar2 + iVar6 * 0x58),(RECT *)0x0,0);
          }
          else {
            SendMessageA(*(HWND *)(LVar2 + iVar6 * 0x58),0x432,0,0);
          }
        }
        for (iVar12 = 0; iVar12 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58); iVar12 = iVar12 + 1) {
          iVar1 = FUN_0046bb29(*(HWND *)(iVar12 * 4 + iVar6 * 0x58 + 4 + LVar2),&param_3->unused);
          if (iVar1 != 0) {
            iVar11 = 1;
            if (height == 0) {
              InvalidateRect(*(HWND *)(iVar12 * 4 + iVar6 * 0x58 + 4 + LVar2),(RECT *)0x0,0);
            }
            else {
              SendMessageA(*(HWND *)(iVar12 * 4 + iVar6 * 0x58 + 4 + LVar2),0x432,0,0);
            }
          }
        }
        iVar6 = iVar6 + 1;
      }
      return 0;
    case 0x437:
      return 0;
    }
  }
  uVar8 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
  return uVar8;
}


