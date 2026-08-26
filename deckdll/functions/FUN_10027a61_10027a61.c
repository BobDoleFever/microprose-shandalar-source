/*
 * Decompiled function: FUN_10027a61
 * Entry Point: 10027a61
 * Size: 122 bytes
 */
#include "deckdll.h"


void FUN_10027a61(int32_t arg_1,int y,int width,int height)

{
  int local_24;
  int local_20;
  int local_1c;
  uint32_t local_8;
  
  if ((DAT_1017646c & 1) == 0) {
    memset(&local_24,0,0x20);
    local_24 = y << 2;
    local_20 = (width * 0x5622) / 100;
    local_1c = height << 2;
    local_8 = local_8 & 0xffffffee;
    thunk_FUN_1003b524(arg_1,&local_24);
  }
  return;
}


