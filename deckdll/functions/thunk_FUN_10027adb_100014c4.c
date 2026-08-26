/*
 * Decompiled function: thunk_FUN_10027adb
 * Entry Point: 100014c4
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10027adb(int32_t arg_1,int arg_2,int arg_3)

{
  int aiStack_24 [7];
  uint32_t uStack_8;
  
  if ((DAT_1017646c & 1) == 0) {
    memset(aiStack_24,0,0x20);
    aiStack_24[0] = arg_2 << 2;
    aiStack_24[1] = 0x5622;
    aiStack_24[2] = arg_3 << 2;
    uStack_8 = uStack_8 | 1;
    thunk_FUN_1003b524(arg_1,aiStack_24);
  }
  return;
}


