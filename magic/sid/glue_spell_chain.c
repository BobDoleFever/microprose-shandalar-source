/*
 * sid/glue_spell_chain.c - Spell Resolution Stack & Spell Chain Window UI
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"

/*
 * SpellChain_RegisterClass
 * Purpose: Register window classes and load background PIC assets for spell stack.
 * Procedure:
 * 1. Register main spell chain and minimized window classes.
 * 2. Load spell chain PIC background illustrations.
 * 3. Create pens and solid brushes for UI chrome.
 * 4. Return initialization success status.
 */
/*
 * Decompiled function: SpellChain_RegisterClass
 * Entry Point: 004cd760
 * Size: 673 bytes
 */

int SpellChain_RegisterClass(LPCSTR name_or_path)

{
  ATOM atom_res;
  char local_138 [264];
  int local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0x800;
  local_2c.lpfnWndProc = SpellChain_WndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 8;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = name_or_path;
  atom_res = RegisterClassA(&local_2c);
  if (atom_res == 0) {
    local_30 = 0;
  }
  local_2c.style = 3;
  local_2c.lpfnWndProc = SpellChain_MinimizedWndProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = g_AppHInstance;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = s_SpellMinimized_0052e6e8;
  atom_res = RegisterClassA(&local_2c);
  if (atom_res == 0) {
    local_30 = 0;
  }
  DAT_0056594c = CreatePopupMenu();
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellChain_pic_0052e6f8);
  DAT_00565984 = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellMushrooms_pic_0052e710);
  DAT_0056597c = Pic_Load_00423833(local_138);
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellSnails_pic_0052e72c);
  DAT_00565978 = Pic_Load_00423833(local_138);
  DAT_0052e6e4 = 3;
  strcpy(local_138,&DAT_006b2e90);
  strcat(local_138,s__WINBK_SpellMin_pic_0052e744);
  DAT_00565980 = Pic_Load_00423833(local_138);
  SetRect((LPRECT)&DAT_00565968,0,0,0,0);
  DAT_00565948 = CreatePen(0,0,0x1000040);
  DAT_0056598c = CreatePen(0,0,0x1000037);
  DAT_00565950 = CreatePen(0,0,0x1000016);
  DAT_00565988 = CreateSolidBrush(0x1000037);
  DAT_00565944 = 0x1000048;
  if ((((DAT_00565948 == (HPEN)0x0) || (DAT_0056598c == (HPEN)0x0)) || (DAT_00565950 == (HPEN)0x0))
     || (DAT_00565988 == (HBRUSH)0x0)) {
    local_30 = 0;
  }
  return local_30;
}

/*
 * SpellChain_CleanupUI
 * Purpose: Destroy menus, bitmaps, pens, and brushes used by spell chain window.
 * Procedure:
 * 1. Destroy popup context menu.
 * 2. Free loaded PIC background objects.
 * 3. Delete GDI pens and brushes.
 */
/*
 * Decompiled function: SpellChain_CleanupUI
 * Entry Point: 004cda01
 * Size: 334 bytes
 */

void SpellChain_CleanupUI(void)

{
  if (DAT_0056594c != (HMENU)0x0) {
    DestroyMenu(DAT_0056594c);
  }
  DAT_0056594c = (HMENU)0x0;
  if (DAT_00565984 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00565984);
  }
  if (DAT_0056597c != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_0056597c);
  }
  if (DAT_00565978 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00565978);
  }
  if (DAT_00565980 != (HANDLE)0x0) {
    GDI_DestroyDIBSection_Magic(DAT_00565980);
  }
  if (DAT_00565948 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565948);
  }
  if (DAT_0056598c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0056598c);
  }
  if (DAT_00565950 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565950);
  }
  if (DAT_00565988 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565988);
  }
  DAT_00565984 = (HANDLE)0x0;
  DAT_0056597c = (HANDLE)0x0;
  DAT_00565978 = (HANDLE)0x0;
  DAT_00565980 = (HANDLE)0x0;
  DAT_00565948 = (HGDIOBJ)0x0;
  DAT_0056598c = (HGDIOBJ)0x0;
  DAT_00565950 = (HGDIOBJ)0x0;
  DAT_00565988 = (HGDIOBJ)0x0;
  return;
}

/*
 * SpellChain_WndProc
 * Purpose: Main window procedure for spell chain resolution stack.
 * Procedure:
 * 1. Handle WM_CREATE to configure scrollbars and child card controls.
 * 2. Handle WM_PAINT to draw spell stack background and chain links.
 * 3. Handle WM_COMMAND for minimize, help, and popup menu actions.
 * 4. Forward unhandled messages to DefWindowProcA.
 */
/*
 * Decompiled function: SpellChain_WndProc
 * Entry Point: 004cdb4f
 * Size: 7402 bytes
 */

uint SpellChain_WndProc(HWND hwnd,uint y,HWND wParam,uint height)

{
  int status;
  LONG LVar2;
  LONG LVar3;
  void *pvVar4;
  HBRUSH hbr;
  HGDIOBJ pvVar5;
  int iVar6;
  HWND pHVar7;
  uint uVar8;
  int *puVar9;
  int *puVar10;
  int local_1a04;
  tagPOINT local_1a00;
  tagRECT local_19f8;
  uint local_19e8;
  uint8_t local_19e0 [8];
  int local_19d8;
  int local_19c4;
  int local_19c0;
  tagRECT local_19bc;
  int local_19ac;
  int local_19a8;
  tagRECT local_19a4;
  HBITMAP local_1994;
  CHAR local_1990 [100];
  HDC local_192c;
  uint8_t local_1928 [4];
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
  uint8_t local_175c [4];
  int local_1758;
  tagRECT local_1744;
  tagRECT local_1734;
  LRESULT local_1724;
  HWND local_1720;
  char local_171c [264];
  ULONG_PTR local_1614;
  int local_1610;
  uint8_t local_160c [4];
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
  int local_15c0 [1322];
  int uStackY_118;
  int auStackY_114 [19];
  int uStackY_c8;
  int in_stack_ffffff40;
  int in_stack_ffffff44;
  int iVar11;
  int iVar12;
  UINT Msg;
  WPARAM wParam;
  uint8_t *puVar13;
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
      uVar8 = DefWindowProcA(hwnd,0x18,(WPARAM)wParam,height);
      return uVar8;
    }
    if (y == 0x14) {
      local_1760 = wParam;
      GDI_RealizeAndFlushPalette_Magic((HDC)wParam);
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
      local_18b8 = DefWindowProcA(hwnd,0x84,(WPARAM)wParam,height);
      if (local_18b8 != 2) {
        return local_18b8;
      }
      local_18bc = GetSystemMetrics(0x1e);
      GetClientRect(hwnd,&local_18b4);
      MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_18b4,2);
      return 8;
    }
    if (y == 0x20) {
      uVar8 = UI_WndProc_004f4fb8(hwnd,0x20,(WPARAM)wParam,height);
      return uVar8;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      local_18c4 = wParam;
      if (wParam == (HWND)0x8) {
        SendMessageA(hwnd,0x111,0x65,0);
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0xa1,(WPARAM)wParam,height);
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
        GDI_RealizeAndFlushPalette_Magic(local_192c);
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
      uVar8 = DefWindowProcA(hwnd,y,(WPARAM)wParam,height);
      return uVar8;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      uVar8 = (uint)wParam & 0xffff;
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
      if (((uint)wParam >> 0x10 == 0xffff) && (height == 0)) {
        local_1a04 = GetMenuItemCount(DAT_0056594c);
        while (local_1a04 != 0) {
          DeleteMenu(DAT_0056594c,0,0x400);
          local_1a04 = local_1a04 + -1;
        }
      }
      return 0;
    }
    if (y == 0x112) {
      local_19e8 = (uint)wParam & 0xfff0;
      if (local_19e8 == 0xf010) {
        return 0;
      }
      uVar8 = DefWindowProcA(hwnd,0x112,(WPARAM)wParam,height);
      return uVar8;
    }
    if (y == 0x114) {
      local_1874 = GetDlgItem(hwnd,0);
      SendMessageA(local_1874,0xe3,(WPARAM)&local_189c,(LPARAM)&local_1870);
      local_18a0 = SendMessageA(local_1874,0xe1,0,0);
      local_1898 = DAT_006a28b0;
      GetClientRect(hwnd,&local_1884);
      local_18a4 = local_1884.right;
      switch((uint)wParam & 0xffff) {
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
        local_186c = (uint)wParam >> 0x10;
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
        *(int *)(LVar2 + 0x54 + local_15d4 * 0x58) = 0;
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
      uVar8 = GDI_RealizePaletteTree_Magic(hwnd,y,wParam,height);
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
        puVar10 = (int *)&stack0xffffff40;
        for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        uStackY_c8 = 0x4ce06d;
        local_15d0 = SpellChain_FindEntryIndex(hwnd);
        if (local_15d0 == local_15c8) {
          puVar9 = local_15c0 + local_15d0 * 0x2b;
          puVar10 = (int *)&stack0xffffff44;
          for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          puVar9 = (int *)(local_15d0 * 0x58 + LVar2);
          puVar10 = auStackY_114;
          for (iVar11 = 0x16; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          uStackY_118 = 0x4ce0db;
          iVar11 = SpellChain_EntryTargetsMatch();
          if (iVar11 == 0) {
            SpellChain_ClearEntryTargets(hwnd,local_15d0);
            puVar9 = local_15c0 + local_15d0 * 0x2b;
            puVar10 = (int *)&stack0xffffff40;
            for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar10 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar10 = puVar10 + 1;
            }
            uStackY_c8 = 0x4ce135;
            SpellChain_RebuildEntryTargets(hwnd);
            local_15c4 = 1;
          }
        }
        else if (local_15d0 == -1) {
          puVar9 = local_15c0 + local_15c8 * 0x2b;
          puVar10 = (int *)&stack0xffffff40;
          for (iVar11 = 0x2b; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          uStackY_c8 = 0x4ce190;
          SpellChain_InsertEntry(hwnd,in_stack_ffffff40,in_stack_ffffff44);
          local_15c4 = 1;
        }
        else if (local_15c8 < local_15d0) {
          for (local_15cc = local_15c8; local_15cc < local_15d0; local_15cc = local_15cc + 1) {
            SpellChain_RemoveEntry(hwnd,local_15cc);
          }
          local_15c4 = 1;
        }
      }
      LVar2 = GetWindowLongA(hwnd,4);
      for (local_15cc = local_15c8; local_15cc < LVar2; local_15cc = local_15cc + 1) {
        SpellChain_RemoveEntry(hwnd,local_15cc);
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
        puVar13 = (uint8_t *)0x0;
        while ((int)puVar13 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58)) {
          iVar6 = 0x432;
          pHVar7 = *(HWND *)((int)puVar13 * 4 + 0x17134 + LVar2);
          SendMessageA(pHVar7,0x432,0,0);
          puVar13 = (uint8_t *)((int)&pHVar7->unused + 1);
        }
      }
      return 0;
    case 0x433:
    case 0x434:
      LVar2 = GetWindowLongA(hwnd,0);
      LVar3 = GetWindowLongA(hwnd,4);
      for (iVar6 = 0; iVar6 < LVar3; iVar6 = iVar6 + 1) {
        pHVar7 = *(HWND *)(LVar2 + iVar6 * 0x58);
        iVar11 = FUN_0046bbab(pHVar7,(int)wParam);
        if (iVar11 != 0) {
          pHVar7 = (HWND)0x0;
          InvalidateRect(*(HWND *)(LVar2 + iVar6 * 0x58),(RECT *)0x0,0);
        }
        puVar13 = (uint8_t *)0x0;
        wParam = pHVar7;
        while ((int)puVar13 < *(int *)(LVar2 + 0x54 + iVar6 * 0x58)) {
          pHVar7 = *(HWND *)((int)wParam * 4 + iVar6 * 0x58 + 4 + LVar2);
          iVar11 = FUN_0046bbab(pHVar7,(int)wParam);
          if (iVar11 != 0) {
            wParam = (HWND)0x0;
            pHVar7 = (HWND)0x0;
            InvalidateRect(*(HWND *)(iVar6 * 0x58 + 4 + LVar2),(RECT *)0x0,0);
          }
          puVar13 = (uint8_t *)((int)&wParam->unused + 1);
          wParam = pHVar7;
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
      if (wParam == (HWND)0x0) {
        return 0;
      }
      iVar11 = 0;
      iVar6 = 0;
      while ((iVar6 < LVar3 && (iVar11 == 0))) {
        iVar12 = FUN_0046bb29(*(HWND *)(LVar2 + iVar6 * 0x58),&wParam->unused);
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
          status = FUN_0046bb29(*(HWND *)(iVar12 * 4 + iVar6 * 0x58 + 4 + LVar2),&wParam->unused);
          if (status != 0) {
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
  uVar8 = DefWindowProcA(hwnd,y,(WPARAM)wParam,height);
  return uVar8;
}

/*
 * SpellChain_FindEntryIndex
 * Purpose: Get number of active spell cards currently on resolution stack.
 * Procedure:
 * 1. Query window extra bytes for spell stack count.
 * 2. Return active spell count.
 */
/*
 * Decompiled function: SpellChain_FindEntryIndex
 * Entry Point: 004cf8b6
 * Size: 175 bytes
 */

int SpellChain_FindEntryIndex(HWND hwnd)

{
  LONG LVar1;
  LONG LVar2;
  int temp_idx;
  int in_stack_000000b4;
  int local_10;
  int local_c;
  
  if (hwnd == (HWND)0x0) {
    local_10 = -1;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    local_10 = -1;
    local_c = in_stack_000000b4;
    while ((local_c < LVar2 && (local_10 == -1))) {
      temp_idx = FUN_0046bb29(*(HWND *)(LVar1 + local_c * 0x58),(int *)&stack0x00000008);
      if (temp_idx != 0) {
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
  }
  return local_10;
}

/*
 * SpellChain_RemoveEntry
 * Purpose: Update target coordinates and scroll offsets for cards in spell stack.
 * Procedure:
 * 1. Iterate through all cards on resolution stack.
 * 2. Calculate child window positions and update window handles.
 * 3. Refresh scroll range if stack exceeds visible bounds.
 */
/*
 * Decompiled function: SpellChain_RemoveEntry
 * Entry Point: 004cf965
 * Size: 333 bytes
 */

void SpellChain_RemoveEntry(HWND hwnd,int card_slot)

{
  LONG LVar1;
  LONG LVar2;
  int local_10;
  int local_c;
  
  if (((hwnd != (HWND)0x0) && (-1 < card_slot)) && (card_slot < 0x65)) {
    LVar1 = GetWindowLongA(hwnd,0);
    LVar2 = GetWindowLongA(hwnd,4);
    DestroyWindow(*(HWND *)(LVar1 + card_slot * 0x58));
    for (local_10 = 0; local_10 < *(int *)(LVar1 + 0x54 + card_slot * 0x58); local_10 = local_10 + 1) {
      if (*(int *)(card_slot * 0x58 + local_10 * 4 + 4 + LVar1) != 0) {
        DestroyWindow(*(HWND *)(card_slot * 0x58 + local_10 * 4 + 4 + LVar1));
      }
    }
    for (local_c = card_slot; local_c < LVar2 + -1; local_c = local_c + 1) {
      memcpy((void *)(local_c * 0x58 + LVar1),(void *)((local_c + 1) * 0x58 + LVar1),0x58);
    }
    SetWindowLongA(hwnd,4,LVar2 + -1);
  }
  return;
}

/*
 * SpellChain_EntryTargetsMatch
 * Purpose: Check if spell resolution stack has pending spells.
 * Procedure:
 * 1. Read active spell counter.
 * 2. Return true if count is greater than zero.
 */
/*
 * Decompiled function: SpellChain_EntryTargetsMatch
 * Entry Point: 004cfab2
 * Size: 125 bytes
 */

bool SpellChain_EntryTargetsMatch(void)

{
  int status;
  bool is_match;
  int in_stack_00000058;
  int in_stack_00000104;
  int local_8;
  
  is_match = in_stack_00000104 == in_stack_00000058;
  for (local_8 = 0; local_8 < in_stack_00000058; local_8 = local_8 + 1) {
    status = FUN_0046bb29(*(HWND *)(&stack0x00000008 + local_8 * 4),
                         (int *)(&stack0x00000064 + local_8 * 8));
    if (status == 0) {
      is_match = false;
    }
  }
  return is_match;
}

/*
 * SpellChain_InsertEntry
 * Purpose: Allocate and attach card window slot to spell stack chain.
 * Procedure:
 * 1. Create child card window control.
 * 2. Store spell card index and target index in slot array.
 * 3. Trigger layout recalculation.
 */
/*
 * Decompiled function: SpellChain_InsertEntry
 * Entry Point: 004cfb2f
 * Size: 569 bytes
 */

int SpellChain_InsertEntry(HWND hwnd,int card_slot,int arg3)

{
  LONG LVar1;
  HWND pHVar2;
  int in_stack_000000b0;
  int in_stack_000000b4;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  LONG local_60;
  HWND local_5c;
  int aiStack_58 [20];
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    local_6c = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    local_60 = GetWindowLongA(hwnd,4);
    if (local_60 == 100) {
      local_6c = 0;
    }
    else {
      local_6c = 1;
      local_74 = card_slot;
      local_70 = arg3;
      local_5c = CreateWindowExA(0,s_MAGICGAME_CardClass_0052e7d0,s_Spell_Card_0052e7c4,0x50000000,0
                                 ,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,&local_74);
      if (local_5c == (HWND)0x0) {
        local_6c = 0;
      }
      local_8 = 0;
      local_68 = 0;
      while ((local_68 < in_stack_000000b0 && (local_6c != 0))) {
        local_74 = *(int *)(&stack0x00000010 + local_68 * 8);
        local_70 = *(int *)(&stack0x00000014 + local_68 * 8);
        pHVar2 = CreateWindowExA(0,s_MAGICGAME_CardClass_0052e7f8,s_Spell_Target_Card_0052e7e4,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,&local_74);
        aiStack_58[local_68] = (int)pHVar2;
        if (aiStack_58[local_68] == 0) {
          local_6c = 0;
        }
        else {
          local_8 = local_8 + 1;
        }
        local_68 = local_68 + 1;
      }
      if (local_6c == 0) {
        if (local_5c != (HWND)0x0) {
          DestroyWindow(local_5c);
        }
        for (local_68 = 0; local_68 < local_8; local_68 = local_68 + 1) {
          if (aiStack_58[local_68] != 0) {
            DestroyWindow((HWND)aiStack_58[local_68]);
          }
        }
      }
      else {
        for (local_64 = in_stack_000000b4; local_64 < local_60; local_64 = local_64 + 1) {
          memcpy((void *)((local_64 + 1) * 0x58 + LVar1),(void *)(local_64 * 0x58 + LVar1),0x58);
        }
        memcpy((void *)(in_stack_000000b4 * 0x58 + LVar1),&local_5c,0x58);
        local_60 = local_60 + 1;
        SetWindowLongA(hwnd,4,local_60);
      }
    }
  }
  return local_6c;
}

/*
 * SpellChain_ClearEntryTargets
 * Purpose: Remove card window slot from spell stack chain and destroy handle.
 * Procedure:
 * 1. Destroy child window control.
 * 2. Shift remaining slots left in slot table.
 * 3. Invalidate window client area.
 */
/*
 * Decompiled function: SpellChain_ClearEntryTargets
 * Entry Point: 004cfd68
 * Size: 229 bytes
 */

void SpellChain_ClearEntryTargets(HWND hwnd,int card_slot)

{
  LONG LVar1;
  int local_c;
  
  if (((hwnd != (HWND)0x0) && (-1 < card_slot)) && (card_slot < 0x65)) {
    LVar1 = GetWindowLongA(hwnd,0);
    GetWindowLongA(hwnd,4);
    for (local_c = 0; local_c < *(int *)(LVar1 + 0x54 + card_slot * 0x58); local_c = local_c + 1) {
      if (*(int *)(card_slot * 0x58 + local_c * 4 + 4 + LVar1) != 0) {
        DestroyWindow(*(HWND *)(card_slot * 0x58 + local_c * 4 + 4 + LVar1));
      }
    }
    *(int *)(LVar1 + 0x54 + card_slot * 0x58) = 0;
  }
  return;
}

/*
 * SpellChain_RebuildEntryTargets
 * Purpose: Create target line link between spell card and targeted permanent.
 * Procedure:
 * 1. Create child target window control.
 * 2. Store targeting relationship coordinates in slot buffer.
 */
/*
 * Decompiled function: SpellChain_RebuildEntryTargets
 * Entry Point: 004cfe4d
 * Size: 397 bytes
 */

int SpellChain_RebuildEntryTargets(HWND hwnd)

{
  LONG LVar1;
  HWND pHVar2;
  int in_stack_000000b0;
  int in_stack_000000b4;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  LONG local_60;
  int local_5c;
  int aiStack_58 [20];
  int local_8;
  
  if (hwnd == (HWND)0x0) {
    local_68 = 0;
  }
  else {
    LVar1 = GetWindowLongA(hwnd,0);
    local_60 = GetWindowLongA(hwnd,4);
    local_68 = 1;
    local_5c = *(int *)(LVar1 + in_stack_000000b4 * 0x58);
    local_8 = 0;
    local_64 = 0;
    while ((local_64 < in_stack_000000b0 && (local_68 != 0))) {
      local_70 = *(int *)(&stack0x00000010 + local_64 * 8);
      local_6c = *(int *)(&stack0x00000014 + local_64 * 8);
      pHVar2 = CreateWindowExA(0,s_MAGICGAME_CardClass_0052e820,s_Spell_Target_Card_0052e80c,
                               0x50000000,0,0,0,0,hwnd,(HMENU)0x1,g_AppHInstance,&local_70);
      aiStack_58[local_64] = (int)pHVar2;
      if (aiStack_58[local_64] == 0) {
        local_68 = 0;
      }
      else {
        local_8 = local_8 + 1;
      }
      local_64 = local_64 + 1;
    }
    if (local_68 == 0) {
      for (local_64 = 0; local_64 < local_8; local_64 = local_64 + 1) {
        if (aiStack_58[local_64] != 0) {
          DestroyWindow((HWND)aiStack_58[local_64]);
        }
      }
      *(int *)(LVar1 + 0x54 + in_stack_000000b4 * 0x58) = 0;
    }
    else {
      memcpy((void *)(in_stack_000000b4 * 0x58 + LVar1),&local_5c,0x58);
    }
  }
  return local_68;
}

/*
 * SpellChain_UpdateLayout
 * Purpose: Recalculate layout and resize spell chain window dimensions.
 * Procedure:
 * 1. Compute required dimensions based on active spell count.
 * 2. Resize and reposition window via MoveWindow.
 * 3. Force synchronous window update.
 */
/*
 * Decompiled function: SpellChain_UpdateLayout
 * Entry Point: 004cffda
 * Size: 1550 bytes
 */

void SpellChain_UpdateLayout(HWND hwnd,LPRECT card_slot)

{
  LONG LVar1;
  BOOL BVar2;
  int temp_idx;
  DWORD dwStyle;
  int local_8c;
  int local_88 [2];
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  LONG local_4c;
  tagRECT local_48;
  int local_38;
  int local_34;
  int local_30;
  tagRECT local_2c;
  tagRECT local_1c;
  HWND local_c;
  LRESULT local_8;
  
  LVar1 = GetWindowLongA(hwnd,0);
  local_4c = GetWindowLongA(hwnd,4);
  local_c = GetDlgItem(hwnd,0);
  local_8 = SendMessageA(local_c,0xe1,0,0);
  if (local_4c == 0) {
    BVar2 = IsWindowVisible(hwnd);
    if ((BVar2 != 0) || (BVar2 = IsWindowVisible(DAT_00565940), BVar2 != 0)) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_00565940,0);
      UpdateWindow(DAT_006b2e2c);
    }
    if (card_slot != (LPRECT)0x0) {
      SetRect(card_slot,0,0,0,0);
    }
  }
  else {
    GetWindowRect(local_c,&local_2c);
    temp_idx = local_2c.bottom - local_2c.top;
    local_54 = 5;
    local_50 = 5;
    local_70 = 5;
    local_7c = (int)(DAT_006a28b0 + (DAT_006a28b0 >> 0x1f & 3U)) >> 2;
    local_30 = 0;
    for (local_5c = 0; local_5c < local_4c; local_5c = local_5c + 1) {
      if (*(int *)(LVar1 + 0x54 + local_5c * 0x58) != 0) {
        local_30 = 1;
      }
    }
    SetRect(&local_48,500,500,0,0);
    local_58 = local_54;
    local_80 = local_50;
    local_74 = local_50 + DAT_006b2e30 / 2 + DAT_006b2e30;
    for (local_5c = 0; local_5c < local_4c; local_5c = local_5c + 1) {
      SendMessageA(*(HWND *)(LVar1 + local_5c * 0x58),0x401,(WPARAM)local_88,0);
      if (local_88[0] == 0) {
        local_60 = local_74;
        local_34 = (local_74 - DAT_006b2e30) - local_70;
      }
      else {
        local_60 = local_80;
        local_34 = local_80 + DAT_006b2e30 + local_70;
      }
      MoveWindow(*(HWND *)(LVar1 + local_5c * 0x58),local_58,local_60,DAT_006a28b0,DAT_006b2e30,1);
      if (local_58 < local_48.left) {
        local_48.left = local_58;
      }
      if (local_48.right < local_58 + DAT_006a28b0) {
        local_48.right = local_58 + DAT_006a28b0;
      }
      if (local_60 < local_48.top) {
        local_48.top = local_60;
      }
      if (local_48.bottom < local_60 + DAT_006b2e30) {
        local_48.bottom = local_60 + DAT_006b2e30;
      }
      local_78 = local_58;
      for (local_68 = 0; local_68 < *(int *)(LVar1 + 0x54 + local_5c * 0x58);
          local_68 = local_68 + 1) {
        MoveWindow(*(HWND *)(local_68 * 4 + local_5c * 0x58 + 4 + LVar1),local_78,local_34,
                   DAT_006a28b0,DAT_006b2e30,1);
        if (local_78 < local_48.left) {
          local_48.left = local_78;
        }
        if (local_48.right < local_78 + DAT_006a28b0) {
          local_48.right = local_78 + DAT_006a28b0;
        }
        if (local_34 < local_48.top) {
          local_48.top = local_34;
        }
        if (local_48.bottom < local_34 + DAT_006b2e30) {
          local_48.bottom = local_34 + DAT_006b2e30;
        }
        local_78 = local_78 + local_7c;
      }
      local_58 = local_58 + DAT_006a28b0 + 5;
      if (*(int *)(LVar1 + 0x54 + local_5c * 0x58) != 0) {
        local_58 = local_58 + (*(int *)(LVar1 + 0x54 + local_5c * 0x58) + -1) * local_7c;
      }
    }
    local_58 = local_58 + -5 + local_54;
    local_48.right = local_48.right + local_48.left;
    local_48.left = 0;
    local_48.top = 0;
    local_48.bottom = local_48.bottom + local_50;
    local_2c.left = 0;
    local_2c.right = local_58 + -5 + local_54;
    local_2c.top = 0;
    local_2c.bottom = local_50 * 2 + local_74 + DAT_006b2e30 + temp_idx;
    BVar2 = 0;
    dwStyle = GetWindowLongA(hwnd,-0x10);
    AdjustWindowRect(&local_2c,dwStyle,BVar2);
    GetWindowRect(DAT_006a4924,&local_1c);
    local_58 = local_1c.left;
    local_60 = local_1c.top - (local_2c.bottom - local_2c.top);
    if (local_60 < 1) {
      local_60 = 0;
    }
    local_64 = local_1c.right - local_1c.left;
    if (local_2c.right - local_2c.left <= local_1c.right - local_1c.left) {
      local_64 = local_2c.right - local_2c.left;
    }
    local_6c = local_2c.bottom - local_2c.top;
    MoveWindow(hwnd,local_1c.left,local_60,local_64,local_6c,1);
    local_c = GetDlgItem(hwnd,0);
    if (local_64 < local_2c.right - local_2c.left) {
      local_38 = 0;
      local_8c = (local_2c.right - local_2c.left) - local_64;
      SendMessageA(local_c,0xe2,0,local_8c);
      SendMessageA(local_c,0x468,1,0);
    }
    else {
      SendMessageA(local_c,0x468,0,0);
    }
    SendMessageA(local_c,0xe3,(WPARAM)&local_38,(LPARAM)&local_8c);
    if (local_8 < local_38) {
      local_8 = local_38;
    }
    if (local_8c < local_8) {
      local_8 = local_8c;
    }
    SendMessageA(local_c,0xe0,0,0);
    SendMessageA(local_c,0x114,CONCAT31((int3)((uint)(local_8 << 0x10) >> 8),4),(LPARAM)local_c);
    BVar2 = IsWindowVisible(hwnd);
    if ((BVar2 == 0) && (BVar2 = IsWindowVisible(DAT_00565940), BVar2 == 0)) {
      ShowWindow(hwnd,5);
      FUN_004f59f7();
    }
    UpdateWindow(hwnd);
    if (card_slot != (LPRECT)0x0) {
      CopyRect(card_slot,&local_48);
    }
  }
  return;
}

/*
 * SpellChain_GetContentRect
 * Purpose: Copy and apply rectangle bounds to spell chain window.
 * Procedure:
 * 1. Copy rectangle structure to internal bounds cache.
 */
/*
 * Decompiled function: SpellChain_GetContentRect
 * Entry Point: 004d05e8
 * Size: 26 bytes
 */

void SpellChain_GetContentRect(int player,LPRECT card_slot)

{
  CopyRect(card_slot,(RECT *)&DAT_00565968);
  return;
}

/*
 * SpellChain_MinimizedWndProc
 * Purpose: Window procedure for minimized spell chain icon.
 * Procedure:
 * 1. Handle WM_PAINT to render minimized spell icon.
 * 2. Handle WM_RBUTTONUP / WM_LBUTTONDBLCLK to restore full spell chain.
 * 3. Handle popup menu commands.
 */
/*
 * Decompiled function: SpellChain_MinimizedWndProc
 * Entry Point: 004d0602
 * Size: 855 bytes
 */

LRESULT SpellChain_MinimizedWndProc(HWND hwnd,uint uMsg,HDC wParam,uint lParam)

{
  HBRUSH hbr;
  LRESULT LVar1;
  int local_13c;
  tagPOINT local_138;
  tagRECT local_130;
  char local_120 [264];
  HDC local_18;
  tagRECT local_14;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_18 = wParam;
      GDI_RealizeAndFlushPalette_Magic(wParam);
      GetClientRect(hwnd,&local_14);
      IntersectClipRect(local_18,0,0,local_14.right,local_14.bottom);
      if (DAT_00565980 == (HANDLE)0x0) {
        strcpy(local_120,&DAT_006b2e90);
        strcat(local_120,s__WINBK_SpellMin_pic_0052e84c);
        DAT_00565980 = (HANDLE)Pic_Load_00423833(local_120);
      }
      if (DAT_00565980 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_18,&local_14,hbr);
      }
      else {
        FUN_004f3b5f((int)local_18,(int)&local_14,DAT_00565980);
      }
      return 1;
    }
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      ShowWindow(DAT_006fe3fc,0);
      return 0;
    }
  }
  else if (uMsg < 0x120) {
    if (uMsg == 0x11f) {
      if (((uint)wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_13c = GetMenuItemCount(DAT_0056594c);
        while (local_13c != 0) {
          DeleteMenu(DAT_0056594c,0,0x400);
          local_13c = local_13c + -1;
        }
      }
      return 0;
    }
    if (uMsg == 0x117) {
      AppendMenuA(DAT_0056594c,0,0x66,s__Restore_0052e860);
      AppendMenuA(DAT_0056594c,0,100,s_Help____0052e86c);
      return 0;
    }
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) {
      local_138.x = lParam & 0xffff;
      local_138.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_138);
      SetRect(&local_130,local_138.x,local_138.y,local_138.x + 1,local_138.y + 1);
      TrackPopupMenu(DAT_0056594c,2,local_138.x,local_138.y,0,DAT_006fe3fc,&local_130);
      return 0;
    }
    if (uMsg == 0x201) {
      SendMessageA(DAT_006fe3fc,0x111,0x66,0);
      return 0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      LVar1 = GDI_RealizePaletteTree_Magic(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar1;
    }
    if (uMsg == 0x437) {
      strcpy((char *)wParam,s_Minimized_spell_chain_0052e834);
      return 1;
    }
  }
  LVar1 = DefWindowProcA(hwnd,uMsg,(WPARAM)wParam,lParam);
  return LVar1;
}

/*
 * SpellChain_MinimizeIfShown
 * Purpose: Query visibility status of spell chain window.
 * Procedure:
 * 1. Test window visibility flag and return boolean status.
 */
/*
 * Decompiled function: SpellChain_MinimizeIfShown
 * Entry Point: 004d0965
 * Size: 88 bytes
 */

BOOL SpellChain_MinimizeIfShown(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_00565940);
  if (BVar1 == 0) {
    BVar2 = IsWindowVisible(DAT_006fe3fc);
    if (BVar2 != 0) {
      SendMessageA(DAT_006fe3fc,0x111,0x65,0);
    }
  }
  return BVar1;
}

/*
 * SpellChain_RestoreIfMinimized
 * Purpose: Query minimized status of spell chain window.
 * Procedure:
 * 1. Test minimized window visibility and return boolean status.
 */
/*
 * Decompiled function: SpellChain_RestoreIfMinimized
 * Entry Point: 004d09bd
 * Size: 112 bytes
 */

bool SpellChain_RestoreIfMinimized(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_00565940);
  if ((BVar1 != 0) && (BVar2 = IsWindowVisible(DAT_006fe3fc), BVar2 == 0)) {
    SendMessageA(DAT_006fe3fc,0x111,0x66,0);
  }
  return BVar1 == 0;
}

/*
 * Card_DefaultEventHandler
 * Purpose: Get active spell counter.
 * Procedure:
 * 1. Return active spell counter register.
 */
/*
 * Decompiled function: Card_DefaultEventHandler
 * Entry Point: 004d0a30
 * Size: 18 bytes
 */

int Card_DefaultEventHandler(void)

{
  return 0;
}

/*
 * Card_GetColorAndTypeFlags
 * Purpose: Dispatch spell chain resolution trigger event to active permanents.
 * Procedure:
 * 1. Format trigger event parameters.
 * 2. Notify card scripts of pending resolution.
 */
/*
 * Decompiled function: Card_GetColorAndTypeFlags
 * Entry Point: 004d0a42
 * Size: 645 bytes
 */

uint Card_GetColorAndTypeFlags(int player,int card_slot)

{
  char c_res;
  int val_result;
  uint uVar3;
  int local_8;
  
  if (*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) == g_StackObjectCardId) {
    local_8 = *(int *)(&g_ActiveCardsInPlay + card_slot * 0x120 + player * 0x5b20);
  }
  else {
    local_8 = *(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
  }
  if (((&g_MasterCardColorTable)[local_8 * 0x34] & 4) == 0) {
    if (((&g_MasterCardColorTable)[local_8 * 0x34] & 0x10) == 0) {
      if (((&g_MasterCardColorTable)[local_8 * 0x34] & 0x20) == 0) {
        if (((&g_MasterCardColorTable)[local_8 * 0x34] & 8) == 0) {
          val_result = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20]);
          c_res = Card_RemapColorIndexF9(player,card_slot,val_result);
          uVar3 = 0x800 << (c_res - 1U & 0x1f);
        }
        else {
          val_result = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20]);
          c_res = Card_RemapColorIndexF9(player,card_slot,val_result);
          uVar3 = 0x800 << (c_res - 1U & 0x1f) | 0x100000;
        }
      }
      else {
        val_result = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20]);
        c_res = Card_RemapColorIndexF9(player,card_slot,val_result);
        uVar3 = 0x800 << (c_res - 1U & 0x1f) | 0x80000;
      }
    }
    else {
      val_result = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20]);
      c_res = Card_RemapColorIndexF9(player,card_slot,val_result);
      uVar3 = 0x800 << (c_res - 1U & 0x1f) | 0x40000;
    }
  }
  else {
    val_result = Card_ColorMaskToColorIndex((&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20]);
    c_res = Card_RemapColorIndexF9(player,card_slot,val_result);
    uVar3 = 0x800 << (c_res - 1U & 0x1f) | 0x20000;
  }
  return uVar3;
}

