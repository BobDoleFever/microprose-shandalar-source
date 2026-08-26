/*
 * Decompiled function: thunk_FUN_10023e33
 * Entry Point: 10001073
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10023e33(uint8_t arg_1)

{
  uint8_t auStack_8 [4];
  
  auStack_8[0] = 0xc1;
  if ((arg_1 & 0xc0) == 0xc0) {
    fwrite(auStack_8,1,1,DAT_1013f728);
  }
  fwrite(&arg_1,1,1,DAT_1013f728);
  return;
}


