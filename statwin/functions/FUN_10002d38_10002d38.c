/*
 * Decompiled function: StatWin_WindowProc
 * Entry Point: 10002d38
 * Size: 532 bytes
 */
#include "statwin.h"


LRESULT StatWin_WindowProc(HWND x,uint32_t y,WPARAM width,LPARAM height)

{
  HDC pHVar1;
  LRESULT LVar2;
  
  if (y < 0x15) {
    if (y == 0x14) {
      if (DAT_1001179c != 0) {
        DefWindowProcA(x,0x14,width,height);
        pHVar1 = GetDC(x);
        DAT_10011798 = SetSystemPaletteUse(pHVar1,1);
        ReleaseDC(x,pHVar1);
        DAT_1001179c = 0;
      }
      thunk_FUN_10002f86(x);
    }
    else {
      switch(y) {
      case 1:
        DAT_1001179c = 1;
        LVar2 = DefWindowProcA(x,y,width,height);
        return LVar2;
      case 2:
        pHVar1 = GetDC(x);
        SetSystemPaletteUse(pHVar1,DAT_10011798);
        ReleaseDC(x,pHVar1);
        DAT_1001179c = 1;
        break;
      default:
        goto switchD_10002ed5_caseD_3;
      case 5:
        InvalidateRect(x,(RECT *)0x0,0);
        break;
      case 7:
        break;
      case 8:
        break;
      case 0xf:
        InvalidateRect(x,(RECT *)0x0,0);
      }
    }
  }
  else if (y < 0x203) {
    if ((y != 0x202) && (y != 0x100)) {
switchD_10002ed5_caseD_3:
      LVar2 = DefWindowProcA(x,y,width,height);
      return LVar2;
    }
    DAT_10013180 = 1;
  }
  else if (y == 0x205) {
    DialogBoxParamA(DAT_1001316c,(LPCSTR)0x65,x,(DLGPROC)&LAB_10001019,0);
  }
  else {
    if (y != 0x311) goto switchD_10002ed5_caseD_3;
    InvalidateRect(x,(RECT *)0x0,0);
  }
  if (DAT_100117c8 == 0) {
    LVar2 = 0;
  }
  else {
    LVar2 = DefWindowProcA(x,y,width,height);
  }
  return LVar2;
}


