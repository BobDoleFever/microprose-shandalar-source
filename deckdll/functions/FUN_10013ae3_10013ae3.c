/*
 * Decompiled function: FUN_10013ae3
 * Entry Point: 10013ae3
 * Size: 112 bytes
 */
#include "deckdll.h"


int FUN_10013ae3(int x,int arg_2,int width,int height)

{
  int local_8;
  
  if (x == -1) {
    local_8 = 0;
  }
  else {
    local_8 = thunk_FUN_10013a4c(x,arg_2);
    if ((local_8 != 0) && ((*(int *)(local_8 + 8) != width || (*(int *)(local_8 + 0xc) != height))))
    {
      local_8 = 0;
    }
  }
  return local_8;
}


