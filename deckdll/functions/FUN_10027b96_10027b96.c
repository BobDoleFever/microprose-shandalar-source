/*
 * Decompiled function: FUN_10027b96
 * Entry Point: 10027b96
 * Size: 112 bytes
 */
#include "deckdll.h"


void FUN_10027b96(int32_t arg1,int32_t arg2)

{
  int32_t local_24;
  int32_t local_20;
  int32_t local_1c;
  uint32_t local_8;
  
  if ((DAT_1017646c & 1) == 0) {
    memset(&local_24,0,0x20);
    local_8 = local_8 | 4;
    local_24 = 400;
    local_20 = 0;
    local_1c = 0;
    thunk_FUN_1003b487(arg1,arg2,&local_24);
    thunk_FUN_1003b840(arg2,1);
  }
  return;
}


