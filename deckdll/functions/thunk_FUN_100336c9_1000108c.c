/*
 * Decompiled function: thunk_FUN_100336c9
 * Entry Point: 1000108c
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100336c9(HWND hwnd,int arg_2,int arg_3)

{
  int32_t uval_1;
  int val_2;
  int32_t uStack_c;
  
  if ((arg_2 == 0) || (arg_3 < 1)) {
    uval_1 = 0;
  }
  else {
    val_2 = thunk_FUN_10033646(arg_2,arg_3);
    if (val_2 == -1) {
      uval_1 = 0;
    }
    else {
      SetWindowPos(*(HWND *)(arg_2 + val_2 * 4),hwnd,0,0,0,0,3);
      if (val_2 + 1 < arg_3) {
        uStack_c = val_2 * 4 + 4 + arg_2;
      }
      else {
        uStack_c = 0;
      }
      thunk_FUN_100336c9(*(HWND *)(arg_2 + val_2 * 4),uStack_c,arg_3 - (val_2 + 1));
      uval_1 = 1;
    }
  }
  return uval_1;
}


