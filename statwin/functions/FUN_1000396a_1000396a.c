/*
 * Decompiled function: FUN_1000396a
 * Entry Point: 1000396a
 * Size: 332 bytes
 */
#include "statwin.h"


void FUN_1000396a(HWND x,uint32_t y,WPARAM width,LPARAM height)

{
  if (y < 0x15) {
    if (y == 0x14) {
      if (DAT_1001179c != 0) {
        DefWindowProcA(x,0x14,width,height);
        DAT_1001179c = 0;
      }
    }
    else {
      switch(y) {
      case 1:
        DAT_1001179c = 1;
        DefWindowProcA(x,y,width,height);
        return;
      case 2:
        DAT_1001179c = 1;
        break;
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
  else if ((y == 0x100) || (y == 0x202)) {
    DAT_10013180 = 1;
  }
  else if (y == 0x311) {
    InvalidateRect(x,(RECT *)0x0,0);
  }
  DefWindowProcA(x,y,width,height);
  return;
}


