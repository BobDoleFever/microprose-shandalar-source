/*
 * Decompiled function: Ai_Subsystem_004b20e5
 * Entry Point: 004b20e5
 * Size: 148 bytes
 */
#include "magic.h"


LRESULT Ai_Subsystem_004b20e5(HWND hwnd,UINT y,uint width,LPARAM arg_4)

{
  LRESULT LVar1;
  
  if (y == 0x102) {
    if (((width < 0x30) || (0x39 < width)) && (width != 8)) {
      LVar1 = 0;
    }
    else {
      LVar1 = CallWindowProcA(DAT_006498ec,hwnd,0x102,width,arg_4);
    }
  }
  else {
    LVar1 = CallWindowProcA(DAT_006498ec,hwnd,y,width,arg_4);
  }
  return LVar1;
}


