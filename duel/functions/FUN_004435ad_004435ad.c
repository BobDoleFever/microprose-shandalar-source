/*
 * Decompiled function: FUN_004435ad
 * Entry Point: 004435ad
 * Size: 148 bytes
 */
#include "duel.h"


LRESULT FUN_004435ad(HWND hwnd,UINT y,uint width,LPARAM arg_4)

{
  LRESULT LVar1;
  
  if (y == 0x102) {
    if (((width < 0x30) || (0x39 < width)) && (width != 8)) {
      LVar1 = 0;
    }
    else {
      LVar1 = CallWindowProcA(DAT_006944c4,hwnd,0x102,width,arg_4);
    }
  }
  else {
    LVar1 = CallWindowProcA(DAT_006944c4,hwnd,y,width,arg_4);
  }
  return LVar1;
}


