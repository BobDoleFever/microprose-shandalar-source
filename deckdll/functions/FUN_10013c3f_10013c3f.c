/*
 * Decompiled function: FUN_10013c3f
 * Entry Point: 10013c3f
 * Size: 135 bytes
 */
#include "deckdll.h"


int32_t FUN_10013c3f(WPARAM arg_1,int y,int width,int height)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == 0xffffffff) {
    uval_1 = 0;
  }
  else {
    val_2 = thunk_FUN_10013ae3(arg_1,y,width,height);
    if (val_2 == 0) {
      thunk_FUN_10013cd0(arg_1,y);
      val_2 = thunk_FUN_10013760(arg_1,y,width,height);
      if (val_2 == 0) {
        uval_1 = 0;
      }
      else {
        uval_1 = 1;
      }
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}


