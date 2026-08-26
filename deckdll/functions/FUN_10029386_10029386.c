/*
 * Decompiled function: FUN_10029386
 * Entry Point: 10029386
 * Size: 165 bytes
 */
#include "deckdll.h"


int32_t FUN_10029386(int x,int arg_2,int width,int height)

{
  int32_t uval_1;
  int val_2;
  
  if (x == -1) {
    uval_1 = 0;
  }
  else {
    val_2 = thunk_FUN_10029205(x,arg_2);
    if (val_2 != 0) {
      if ((*(int *)(val_2 + 8) == width) && (*(int *)(val_2 + 0xc) == height)) {
        return 1;
      }
      thunk_FUN_10029435(x,arg_2);
    }
    val_2 = thunk_FUN_10028f53(x,arg_2,width,height);
    if (val_2 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  return uval_1;
}


