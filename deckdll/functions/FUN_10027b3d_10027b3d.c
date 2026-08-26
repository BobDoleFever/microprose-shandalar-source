/*
 * Decompiled function: FUN_10027b3d
 * Entry Point: 10027b3d
 * Size: 89 bytes
 */
#include "deckdll.h"


void FUN_10027b3d(int32_t arg_1,int arg_2,int arg_3)

{
  int local_24 [8];
  
  if ((DAT_1017646c & 1) == 0) {
    memset(local_24,0,0x20);
    local_24[0] = arg_2 << 2;
    local_24[1] = 0x5622;
    local_24[2] = arg_3 << 2;
    thunk_FUN_1003b524(arg_1,local_24);
  }
  return;
}


