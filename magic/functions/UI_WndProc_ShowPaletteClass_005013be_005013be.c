/*
 * Decompiled function: UI_WndProc_ShowPaletteClass_005013be
 * Entry Point: 005013be
 * Size: 652 bytes
 */
#include "magic.h"


LRESULT UI_WndProc_ShowPaletteClass_005013be(HWND hwnd,uint uMsg,WPARAM wParam,uint lParam)

{
  LRESULT LVar1;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) goto LAB_0050164f;
    if (uMsg == 2) {
      Pic_Subsystem_00423ae1();
      PostQuitMessage(0);
      LVar1 = DefWindowProcA(hwnd,2,wParam,lParam);
      return LVar1;
    }
  }
  else if (uMsg < 0x105) {
    if ((uMsg == 0x104) || (uMsg == 0x100)) {
      FUN_00407e40(wParam,lParam);
      if (wParam != 0x7a) {
        LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
        return LVar1;
      }
      if (DAT_0061d87c == 0) {
        UI_Register_ShowPaletteClass_00513820(g_AppHInstance);
        DAT_0061d87c = 1;
      }
      DAT_0061d884 = FindWindowExA((HWND)0x0,(HWND)0x0,s_ShowPaletteClass_00530f88,
                                   s_Current_Palette_00530f78);
      if (DAT_0061d884 == (HWND)0x0) {
        DAT_0061d884 = (HWND)UI_Register_ShowPaletteClass_005138b0(g_AppHInstance,(HWND)0x0);
        if (DAT_0061d884 == (HWND)0x0) {
          return 0;
        }
        ShowWindow(DAT_0061d884,5);
      }
      else {
        BringWindowToTop(DAT_0061d884);
      }
      UpdateWindow(DAT_0061d884);
      LVar1 = DefWindowProcA(hwnd,uMsg,0x7a,lParam);
      return LVar1;
    }
  }
  else if (uMsg < 0x10101011) {
    if (uMsg == 0x10101010) {
      Pic_Subsystem_00423ed6();
      return 0;
    }
    switch(uMsg) {
    case 0x200:
      DAT_007039cc = lParam & 0xffff;
      DAT_007039c8 = lParam >> 0x10;
      break;
    case 0x201:
      DAT_007039c4 = 1;
      DAT_007039cc = lParam & 0xffff;
      DAT_007039c8 = lParam >> 0x10;
      break;
    case 0x202:
      DAT_007039d0 = DAT_007039d0 | 2;
      DAT_007039c4 = 0;
      break;
    default:
      goto switchD_0050162b_caseD_203;
    case 0x204:
      DAT_007039c4 = 2;
      DAT_007039cc = lParam & 0xffff;
      DAT_007039c8 = lParam >> 0x10;
      break;
    case 0x205:
      DAT_007039d0 = DAT_007039d0 | 1;
      DAT_007039c4 = 0;
    }
LAB_0050164f:
    LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
    return LVar1;
  }
switchD_0050162b_caseD_203:
  LVar1 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar1;
}


