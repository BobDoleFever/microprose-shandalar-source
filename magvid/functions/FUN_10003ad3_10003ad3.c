/*
 * Decompiled function: FUN_10003ad3
 * Entry Point: 10003ad3
 * Size: 531 bytes
 */
#include "magvid.h"


void FUN_10003ad3(HWND x,uint32_t y,WPARAM width,int height)

{
  int val_1;
  int local_14;
  LRESULT local_10;
  HDC local_c;
  HANDLE local_8;
  
  if (y < 0x15) {
    if (y == 0x14) {
      if (DAT_10010550 != 0) {
        local_10 = DefWindowProcA(x,0x14,width,height);
        local_c = GetDC(x);
        DAT_10010554 = SetSystemPaletteUse(local_c,1);
        ReleaseDC(x,local_c);
        DAT_10010550 = 0;
      }
      local_14 = -1;
      val_1 = thunk_FUN_10004249((int)x,&local_14);
      if (val_1 == 0) {
        DrawVidBackground(local_14);
      }
    }
    else {
      switch(y) {
      case 1:
        break;
      case 2:
        DAT_10010550 = 1;
        local_c = GetDC(x);
        SetSystemPaletteUse(local_c,DAT_10010554);
        ReleaseDC(x,local_c);
        DAT_10010550 = 1;
        break;
      case 5:
        InvalidateRect(x,(RECT *)0x0,0);
        break;
      case 7:
        local_8 = GetCurrentProcess();
        SetPriorityClass(local_8,0x80);
        break;
      case 8:
        local_8 = GetCurrentProcess();
        SetPriorityClass(local_8,0x20);
        break;
      case 0xf:
        InvalidateRect(x,(RECT *)0x0,0);
      }
    }
  }
  else if (y != 0x202) {
    if (y == 0x311) {
      InvalidateRect(x,(RECT *)0x0,0);
    }
    else if (((y == 0x401) && (*(int *)(&DAT_10010868 + height * 4) != 0)) &&
            (*(int *)(*(int *)(&DAT_10010868 + height * 4) + 0x50) == 0)) {
      thunk_FUN_10006020(*(int *)(&DAT_10010868 + height * 4));
    }
  }
  DefWindowProcA(x,y,width,height);
  return;
}


