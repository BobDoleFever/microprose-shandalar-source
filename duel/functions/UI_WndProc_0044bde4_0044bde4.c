/*
 * Decompiled function: UI_WndProc_0044bde4
 * Entry Point: 0044bde4
 * Size: 1003 bytes
 */
#include "duel.h"


LRESULT UI_WndProc_0044bde4(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam)

{
  POINT pt;
  BOOL BVar1;
  UINT UVar2;
  size_t c;
  LRESULT LVar3;
  char local_f8 [100];
  int local_94;
  HDC local_90;
  int local_8c;
  tagPAINTSTRUCT local_88;
  tagPALETTEENTRY local_48;
  HBRUSH local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  tagRECT local_1c;
  int local_c;
  UINT local_8;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      local_8 = GetWindowLongA(hwnd,DAT_004f80ec);
      local_90 = BeginPaint(hwnd,&local_88);
      if (local_90 != (HDC)0x0) {
        FUN_004707a4(local_90);
        GetClientRect(hwnd,&local_40);
        DAT_004f80f0 = ((local_40.right - local_40.left) + -0x100) / 2;
        DAT_004f80f4 = ((local_40.bottom - local_40.top) + -0x100) / 2;
        for (local_8c = 0; local_8c < 0x10; local_8c = local_8c + 1) {
          for (local_94 = 0; local_94 < 0x10; local_94 = local_94 + 1) {
            local_44 = CreateSolidBrush(local_8c * 0x10 + local_94 & 0xffffU | 0x1000000);
            SetRect(&local_40,local_94 << 4,local_8c << 4,(local_94 + 1) * 0x10,
                    (local_8c + 1) * 0x10);
            OffsetRect(&local_40,DAT_004f80f0,DAT_004f80f4);
            FillRect(local_90,&local_40,local_44);
            DeleteObject(local_44);
          }
        }
        UVar2 = GetPaletteEntries(DAT_005f76d0,local_8,1,&local_48);
        if (UVar2 == 0) {
          _sprintf(local_f8,s___3d__not_in_palette_004f8114,local_8);
        }
        else {
          _sprintf(local_f8,s___3d___3d__3d__3d_004f80f8,local_8,(uint)local_48.peRed,
                   (uint)local_48.peGreen,(uint)local_48.peBlue);
        }
        c = _strlen(local_f8);
        TextOutA(local_90,0,0,local_f8,c);
        EndPaint(hwnd,&local_88);
      }
      return 0;
    }
    if (uMsg == 1) {
      local_8 = 0;
      SetWindowLongA(hwnd,DAT_004f80ec,0);
      return 0;
    }
  }
  else {
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
    if (uMsg == 0x200) {
      local_8 = GetWindowLongA(hwnd,DAT_004f80ec);
      local_28 = lParam & 0xffff;
      local_24 = lParam >> 0x10;
      local_c = 0;
      local_20 = 0;
      while ((local_20 < 0x10 && (local_c == 0))) {
        local_2c = 0;
        while ((local_2c < 0x10 && (local_c == 0))) {
          SetRect(&local_1c,local_2c << 4,local_20 << 4,(local_2c + 1) * 0x10,(local_20 + 1) * 0x10)
          ;
          OffsetRect(&local_1c,DAT_004f80f0,DAT_004f80f4);
          pt.y = local_24;
          pt.x = local_28;
          BVar1 = PtInRect(&local_1c,pt);
          if (BVar1 != 0) {
            local_c = 1;
            local_30 = local_20 * 0x10 + local_2c;
          }
          local_2c = local_2c + 1;
        }
        local_20 = local_20 + 1;
      }
      if ((local_c != 0) && (local_8 != local_30)) {
        local_8 = local_30;
        SetWindowLongA(hwnd,DAT_004f80ec,local_30);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
  }
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar3;
}


