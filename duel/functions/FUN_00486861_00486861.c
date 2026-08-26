/*
 * Decompiled function: FUN_00486861
 * Entry Point: 00486861
 * Size: 112 bytes
 */
#include "duel.h"


int FUN_00486861(int x,int y,int width,int height)

{
  int local_8;
  
  if (x == -1) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_004867ca(x,y);
    if ((local_8 != 0) && ((*(int *)(local_8 + 8) != width || (*(int *)(local_8 + 0xc) != height))))
    {
      local_8 = 0;
    }
  }
  return local_8;
}


