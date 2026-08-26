/*
 * Decompiled function: FUN_00471df6
 * Entry Point: 00471df6
 * Size: 134 bytes
 */
#include "duel.h"


LRESULT FUN_00471df6(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  HCURSOR hCursor;
  LRESULT LVar1;
  
  if (param_2 == 0x20) {
    if (DAT_00618158 == 0) {
      hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f8a);
      SetCursor(hCursor);
      LVar1 = 0;
    }
    else {
      LVar1 = DefWindowProcA(param_1,0x20,param_3,param_4);
    }
  }
  else {
    LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  return LVar1;
}


