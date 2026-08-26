/*
 * Decompiled function: FUN_0048794d
 * Entry Point: 0048794d
 * Size: 179 bytes
 */
#include "duel.h"


LRESULT FUN_0048794d(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  tagRECT local_14;
  
  if (param_2 == 0x14) {
    FUN_004707a4(param_3);
    GetClientRect(param_1,&local_14);
    FUN_0042043e(param_3,&local_14);
    LVar1 = 0;
  }
  else if ((param_2 < 0x30f) || (0x311 < param_2)) {
    LVar1 = DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  else {
    LVar1 = FUN_00472b60(param_1,param_2,param_3,param_4);
  }
  return LVar1;
}


