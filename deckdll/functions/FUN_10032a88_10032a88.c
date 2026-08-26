/*
 * Decompiled function: FUN_10032a88
 * Entry Point: 10032a88
 * Size: 134 bytes
 */
#include "deckdll.h"


LRESULT FUN_10032a88(HWND hwnd,UINT y,WPARAM arg_3,LPARAM arg_4)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (y == 0x20) {
    if (DAT_10176318 == 0) {
      hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f8a);
      SetCursor(hCursor);
      LVar1 = 0;
    }
    else {
      LVar1 = DefWindowProcA(hwnd,0x20,arg_3,arg_4);
    }
  }
  else {
    LVar1 = DefWindowProcA(hwnd,y,arg_3,arg_4);
  }
  return LVar1;
}


