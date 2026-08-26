/*
 * Decompiled function: thunk_FUN_10027b96
 * Entry Point: 10001019
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10027b96(int32_t arg1,int32_t arg2)

{
  int32_t uStack_24;
  int32_t uStack_20;
  int32_t uStack_1c;
  uint32_t uStack_8;
  
  if ((DAT_1017646c & 1) == 0) {
    memset(&uStack_24,0,0x20);
    uStack_8 = uStack_8 | 4;
    uStack_24 = 400;
    uStack_20 = 0;
    uStack_1c = 0;
    thunk_FUN_1003b487(arg1,arg2,&uStack_24);
    thunk_FUN_1003b840(arg2,1);
  }
  return;
}


