/*
 * Decompiled function: UI_Register_WINBK_TellUser_004771fa
 * Entry Point: 004771fa
 * Size: 2920 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_Register_WINBK_TellUser_004771fa(HWND hwnd,uint y,LPSTR str_3,int height)

{
  BOOL BVar1;
  int cHeight;
  HBRUSH hbr;
  HGDIOBJ pvVar2;
  uint uVar3;
  char local_254 [264];
  HDC local_14c;
  tagPAINTSTRUCT local_148;
  CHAR local_108 [200];
  tagRECT local_40;
  LPCSTR local_30;
  int local_2c;
  HGDIOBJ local_28;
  HFONT local_24;
  tagRECT local_20;
  uint local_10;
  undefined4 local_c;
  LPSTR local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8 = (LPSTR)GetWindowLongA(hwnd,0);
      local_14c = BeginPaint(hwnd,&local_148);
      if (local_14c != (HDC)0x0) {
        FUN_004f3955(local_14c);
        GetClientRect(hwnd,&local_40);
        if (DAT_00538e40 == (HANDLE)0x0) {
          strcpy(local_254,&DAT_006b2e90);
          strcat(local_254,s__WINBK_TellUser_pic_00525da0);
          DAT_00538e40 = (HANDLE)Pic_Load_00423833(local_254);
        }
        if (DAT_00538e40 == (HANDLE)0x0) {
          hbr = GetStockObject(1);
          FillRect(local_14c,&local_40,hbr);
        }
        else {
          FUN_004f3d11(local_14c,&local_40.left,DAT_00538e40);
        }
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,0);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,0,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,1);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,1,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,2);
        MoveToEx(local_14c,2,2,(LPPOINT)0x0);
        LineTo(local_14c,2,local_40.bottom + -4);
        pvVar2 = GetStockObject(7);
        SelectObject(local_14c,pvVar2);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,3);
        MoveToEx(local_14c,3,3,(LPPOINT)0x0);
        LineTo(local_14c,3,local_40.bottom + -4);
        pvVar2 = GetStockObject(7);
        SelectObject(local_14c,pvVar2);
        MoveToEx(local_14c,0,local_40.bottom + -1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right,local_40.bottom + -1);
        MoveToEx(local_14c,local_40.right + -1,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom);
        SelectObject(local_14c,DAT_00538e20);
        MoveToEx(local_14c,1,local_40.bottom + -2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom + -2);
        MoveToEx(local_14c,local_40.right + -2,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -1);
        SelectObject(local_14c,DAT_00538e44);
        MoveToEx(local_14c,2,local_40.bottom + -3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -3);
        MoveToEx(local_14c,local_40.right + -3,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -2);
        SelectObject(local_14c,DAT_00538e18);
        MoveToEx(local_14c,2,local_40.bottom + -4,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -4);
        MoveToEx(local_14c,local_40.right + -4,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,local_40.bottom + -3);
        GetWindowTextA(hwnd,local_108,200);
        SetBkMode(local_14c,1);
        FUN_0047820f(hwnd,local_14c,&local_40.left);
        DPtoLP(local_14c,(LPPOINT)&local_40,2);
        OffsetRect(&local_40,2,2);
        SetTextColor(local_14c,DAT_00538e10);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,0);
        OffsetRect(&local_40,-2,-2);
        SetTextColor(local_14c,DAT_00538e0c);
        Palette_Subsystem_0049e5bc(local_14c,&local_40.left,local_108,1);
        EndPaint(hwnd,&local_148);
      }
      return 0;
    }
    if (y == 1) {
      local_8 = DAT_00538e14;
      SetWindowLongA(hwnd,0,(LONG)DAT_00538e14);
      DAT_00676e38 = CreateWindowExA(0,s_BUTTON_00525d78,&DAT_00525d74,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x1,g_AppHInstance,(LPVOID)0x0);
      DAT_00676e34 = CreateWindowExA(0,s_BUTTON_00525d84,&DAT_00525d80,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x2,g_AppHInstance,(LPVOID)0x0);
      if ((DAT_00676e38 != (HWND)0x0) && (DAT_00676e34 != (HWND)0x0)) {
        GetClientRect(hwnd,&local_20);
        cHeight = (local_20.bottom * 2) / 100;
        if (cHeight < 0xd) {
          cHeight = 0xc;
        }
        local_24 = CreateFontA(cHeight,0,0,0,400,0,0,0,1,0,0,0,0,s_MS_Sans_Serif_00525d8c);
        SendMessageA(DAT_00676e38,0x30,(WPARAM)local_24,0);
        SendMessageA(DAT_00676e34,0x30,(WPARAM)local_24,0);
        return 0;
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_28 = (HGDIOBJ)SendMessageA(DAT_00676e38,0x31,0,0);
      SendMessageA(DAT_00676e38,0x30,0,0);
      SendMessageA(DAT_00676e34,0x30,0,0);
      DeleteObject(local_28);
      return 0;
    }
  }
  else if (y < 0x2c) {
    if (y == 0x2b) {
      local_2c = height;
      *(uint *)(height + 0x10) = *(uint *)(height + 0x10) & 0xffffffef;
      FUN_004f5107(height,DAT_00538e2c,DAT_00538e18,DAT_00538e20,DAT_00538e28,0);
      if (*(int *)(local_2c + 4) == 1) {
        local_30 = &DAT_006b2d70;
      }
      else if (*(int *)(local_2c + 4) == 2) {
        local_30 = &DAT_0068a680;
      }
      else {
        local_30 = &DAT_00525d9c;
      }
      SetMapMode(*(HDC *)(local_2c + 0x18),8);
      SetWindowExtEx(*(HDC *)(local_2c + 0x18),*(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c)
                     ,0x18,(LPSIZE)0x0);
      SetViewportExtEx(*(HDC *)(local_2c + 0x18),
                       *(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c),
                       *(int *)(local_2c + 0x28) - *(int *)(local_2c + 0x20),(LPSIZE)0x0);
      SelectObject(*(HDC *)(local_2c + 0x18),DAT_00538e08);
      SetTextColor(*(HDC *)(local_2c + 0x18),DAT_00538e28);
      if ((*(byte *)(local_2c + 0x10) & 1) != 0) {
        OffsetRect((LPRECT)(local_2c + 0x1c),2,2);
      }
      DPtoLP(*(HDC *)(local_2c + 0x18),(LPPOINT)(local_2c + 0x1c),2);
      DrawTextA(*(HDC *)(local_2c + 0x18),local_30,-1,(LPRECT)(local_2c + 0x1c),0x25);
      return 1;
    }
    if (y == 0x14) {
      return 1;
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      if (((uint)str_3 & 0xffff) == 1) {
        SendMessageA(hwnd,0x401,1,0);
      }
      else if (((uint)str_3 & 0xffff) == 2) {
        SendMessageA(hwnd,0x401,2,0);
      }
      return 0;
    }
    if (y == 0x30) {
      local_8 = str_3;
      if (str_3 == (LPSTR)0x0) {
        local_8 = DAT_00538e14;
      }
      SetWindowLongA(hwnd,0,(LONG)local_8);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x31) {
      uVar3 = GetWindowLongA(hwnd,0);
      return uVar3;
    }
  }
  else if (y < 0x312) {
    if (0x30e < y) {
      uVar3 = FUN_004f5d1a(hwnd,y,(HWND)str_3,height);
      return uVar3;
    }
    if (y == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      if ((DAT_006b1578 != 0) &&
         ((BVar1 = IsWindowVisible(DAT_00676e38), BVar1 != 0 ||
          (BVar1 = IsWindowVisible(DAT_00676e34), BVar1 != 0)))) {
        if (str_3 == (LPSTR)0x0) {
          BVar1 = IsWindowVisible(DAT_00676e34);
          if (BVar1 == 0) {
            local_c = 0xffffffff;
          }
          else {
            local_c = 0xfffffffe;
          }
        }
        else if (str_3 == (LPSTR)0x2) {
          local_c = 0xfffffffe;
        }
        else {
          local_c = 0xffffffff;
        }
        DAT_00627a84 = 0xffffffff;
        DAT_00627a88 = 0xffffffff;
        DAT_00627864 = 0;
        _DAT_00538e30 = 0xfffffffe;
        _DAT_00538e34 = 0xffffffff;
        _DAT_00538e38 = local_c;
        PostMessageA(g_MainAppHwnd,0x464,0,0x538e30);
      }
      return 0;
    }
    if (y == 0x402) {
      if (str_3 != (LPSTR)0x0) {
        GetWindowTextA(hwnd,str_3,200);
      }
      local_10 = 0;
      BVar1 = IsWindowVisible(DAT_00676e38);
      if (BVar1 != 0) {
        local_10 = local_10 | 1;
      }
      BVar1 = IsWindowVisible(DAT_00676e34);
      if (BVar1 == 0) {
        return local_10;
      }
      return local_10 | 2;
    }
    if (y == 0x403) {
      FUN_00478163(hwnd);
      return 0;
    }
  }
  uVar3 = DefWindowProcA(hwnd,y,(WPARAM)str_3,height);
  return uVar3;
}


