/*
 * Decompiled function: thunk_FUN_10013ae3
 * Entry Point: 100013fc
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10013ae3(int x,int arg_2,int width,int height)

{
  int iStack_8;
  
  if (x == -1) {
    iStack_8 = 0;
  }
  else {
    iStack_8 = thunk_FUN_10013a4c(x,arg_2);
    if ((iStack_8 != 0) &&
       ((*(int *)(iStack_8 + 8) != width || (*(int *)(iStack_8 + 0xc) != height)))) {
      iStack_8 = 0;
    }
  }
  return iStack_8;
}


