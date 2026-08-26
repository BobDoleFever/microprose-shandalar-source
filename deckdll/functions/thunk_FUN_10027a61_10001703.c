/*
 * Decompiled function: thunk_FUN_10027a61
 * Entry Point: 10001703
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10027a61(int32_t arg_1,int y,int width,int height)

{
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  uint32_t uStack_8;
  
  if ((DAT_1017646c & 1) == 0) {
    memset(&iStack_24,0,0x20);
    iStack_24 = y << 2;
    iStack_20 = (width * 0x5622) / 100;
    iStack_1c = height << 2;
    uStack_8 = uStack_8 & 0xffffffee;
    thunk_FUN_1003b524(arg_1,&iStack_24);
  }
  return;
}


