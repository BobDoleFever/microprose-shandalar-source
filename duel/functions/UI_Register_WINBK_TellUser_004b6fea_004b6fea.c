/*
 * Decompiled function: UI_Register_WINBK_TellUser_004b6fea
 * Entry Point: 004b6fea
 * Size: 2920 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UI_Register_WINBK_TellUser_004b6fea(HWND hwnd,uint y,HWND param_3,int height)

{
  BOOL BVar1;
  int cHeight;
  HBRUSH hbr;
  HGDIOBJ pvVar2;
  uint uVar3;
  uint local_254 [66];
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
  HWND local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      local_8 = (HWND)GetWindowLongA(hwnd,0);
      local_14c = BeginPaint(hwnd,&local_148);
      if (local_14c != (HDC)0x0) {
        FUN_004707a4(local_14c);
        GetClientRect(hwnd,&local_40);
        if (DAT_005dcdf0 == (HANDLE)0x0) {
          Mem_AllocOrFree_004d9630(local_254,(uint *)&DAT_006189a0);
          FUN_004d9640(local_254,(uint *)s__WINBK_TellUser_pic_005070bc);
          DAT_005dcdf0 = (HANDLE)Pic_Load_00423833((char *)local_254);
        }
        if (DAT_005dcdf0 == (HANDLE)0x0) {
          hbr = GetStockObject(1);
          FillRect(local_14c,&local_40,hbr);
        }
        else {
          FUN_00470b60(local_14c,&local_40.left,DAT_005dcdf0);
        }
        SelectObject(local_14c,DAT_005dcdc8);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,0);
        MoveToEx(local_14c,0,0,(LPPOINT)0x0);
        LineTo(local_14c,0,local_40.bottom + -1);
        SelectObject(local_14c,DAT_005dcdf4);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,1);
        MoveToEx(local_14c,1,1,(LPPOINT)0x0);
        LineTo(local_14c,1,local_40.bottom + -2);
        SelectObject(local_14c,DAT_005dcdd0);
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
        SelectObject(local_14c,DAT_005dcdd0);
        MoveToEx(local_14c,1,local_40.bottom + -2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -1,local_40.bottom + -2);
        MoveToEx(local_14c,local_40.right + -2,1,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -1);
        SelectObject(local_14c,DAT_005dcdf4);
        MoveToEx(local_14c,2,local_40.bottom + -3,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -2,local_40.bottom + -3);
        MoveToEx(local_14c,local_40.right + -3,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -2);
        SelectObject(local_14c,DAT_005dcdc8);
        MoveToEx(local_14c,2,local_40.bottom + -4,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -3,local_40.bottom + -4);
        MoveToEx(local_14c,local_40.right + -4,2,(LPPOINT)0x0);
        LineTo(local_14c,local_40.right + -4,local_40.bottom + -3);
        GetWindowTextA(hwnd,local_108,200);
        SetBkMode(local_14c,1);
        FUN_004b8001(hwnd,local_14c,&local_40.left);
        DPtoLP(local_14c,(LPPOINT)&local_40,2);
        OffsetRect(&local_40,2,2);
        SetTextColor(local_14c,DAT_005dcdc0);
        FUN_0042233a(local_14c,&local_40.left,local_108,0);
        OffsetRect(&local_40,-2,-2);
        SetTextColor(local_14c,DAT_005dcdbc);
        FUN_0042233a(local_14c,&local_40.left,local_108,1);
        EndPaint(hwnd,&local_148);
      }
      return 0;
    }
    if (y == 1) {
      local_8 = DAT_005dcdc4;
      SetWindowLongA(hwnd,0,(LONG)DAT_005dcdc4);
      DAT_005f2f98 = CreateWindowExA(0,s_BUTTON_00507094,&DAT_00507090,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x1,DAT_00664680,(LPVOID)0x0);
      DAT_005f2f94 = CreateWindowExA(0,s_BUTTON_005070a0,&DAT_0050709c,0x4080000b,0,0,0,0,hwnd,
                                     (HMENU)0x2,DAT_00664680,(LPVOID)0x0);
      if ((DAT_005f2f98 != (HWND)0x0) && (DAT_005f2f94 != (HWND)0x0)) {
        GetClientRect(hwnd,&local_20);
        cHeight = (local_20.bottom * 2) / 100;
        if (cHeight < 0xd) {
          cHeight = 0xc;
        }
        local_24 = CreateFontA(cHeight,0,0,0,400,0,0,0,1,0,0,0,0,s_MS_Sans_Serif_005070a8);
        SendMessageA(DAT_005f2f98,0x30,(WPARAM)local_24,0);
        SendMessageA(DAT_005f2f94,0x30,(WPARAM)local_24,0);
        return 0;
      }
      return 0xffffffff;
    }
    if (y == 2) {
      local_28 = (HGDIOBJ)SendMessageA(DAT_005f2f98,0x31,0,0);
      SendMessageA(DAT_005f2f98,0x30,0,0);
      SendMessageA(DAT_005f2f94,0x30,0,0);
      DeleteObject(local_28);
      return 0;
    }
  }
  else if (y < 0x2c) {
    if (y == 0x2b) {
      local_2c = height;
      *(uint *)(height + 0x10) = *(uint *)(height + 0x10) & 0xffffffef;
      FUN_00471f45(height,DAT_005dcddc,DAT_005dcdc8,DAT_005dcdd0,DAT_005dcdd8,0);
      if (*(int *)(local_2c + 4) == 1) {
        local_30 = &DAT_00618960;
      }
      else if (*(int *)(local_2c + 4) == 2) {
        local_30 = &DAT_00601590;
      }
      else {
        local_30 = &DAT_005070b8;
      }
      SetMapMode(*(HDC *)(local_2c + 0x18),8);
      SetWindowExtEx(*(HDC *)(local_2c + 0x18),*(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c)
                     ,0x18,(LPSIZE)0x0);
      SetViewportExtEx(*(HDC *)(local_2c + 0x18),
                       *(int *)(local_2c + 0x24) - *(int *)(local_2c + 0x1c),
                       *(int *)(local_2c + 0x28) - *(int *)(local_2c + 0x20),(LPSIZE)0x0);
      SelectObject(*(HDC *)(local_2c + 0x18),DAT_005dcdb8);
      SetTextColor(*(HDC *)(local_2c + 0x18),DAT_005dcdd8);
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
      if (((uint)param_3 & 0xffff) == 1) {
        SendMessageA(hwnd,0x401,1,0);
      }
      else if (((uint)param_3 & 0xffff) == 2) {
        SendMessageA(hwnd,0x401,2,0);
      }
      return 0;
    }
    if (y == 0x30) {
      local_8 = param_3;
      if (param_3 == (HWND)0x0) {
        local_8 = DAT_005dcdc4;
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
      uVar3 = FUN_00472b60(hwnd,y,param_3,height);
      return uVar3;
    }
    if (y == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
  }
  else {
    if (y == 0x401) {
      if ((DAT_00618158 != 0) &&
         ((BVar1 = IsWindowVisible(DAT_005f2f98), BVar1 != 0 ||
          (BVar1 = IsWindowVisible(DAT_005f2f94), BVar1 != 0)))) {
        if (param_3 == (HWND)0x0) {
          BVar1 = IsWindowVisible(DAT_005f2f94);
          if (BVar1 == 0) {
            local_c = 0xffffffff;
          }
          else {
            local_c = 0xfffffffe;
          }
        }
        else if (param_3 == (HWND)0x2) {
          local_c = 0xfffffffe;
        }
        else {
          local_c = 0xffffffff;
        }
        DAT_0066aac4 = 0xffffffff;
        DAT_0066ab04 = 0xffffffff;
        DAT_0066643c = 0;
        _DAT_005dcde0 = 0xfffffffe;
        _DAT_005dcde4 = 0xffffffff;
        _DAT_005dcde8 = local_c;
        PostMessageA(DAT_00618990,0x464,0,0x5dcde0);
      }
      return 0;
    }
    if (y == 0x402) {
      if (param_3 != (HWND)0x0) {
        GetWindowTextA(hwnd,(LPSTR)param_3,200);
      }
      local_10 = 0;
      BVar1 = IsWindowVisible(DAT_005f2f98);
      if (BVar1 != 0) {
        local_10 = local_10 | 1;
      }
      BVar1 = IsWindowVisible(DAT_005f2f94);
      if (BVar1 == 0) {
        return local_10;
      }
      return local_10 | 2;
    }
    if (y == 0x403) {
      FUN_004b7f54(hwnd);
      return 0;
    }
  }
  uVar3 = DefWindowProcA(hwnd,y,(WPARAM)param_3,height);
  return uVar3;
}


