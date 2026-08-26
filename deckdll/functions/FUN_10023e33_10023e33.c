/*
 * Decompiled function: FUN_10023e33
 * Entry Point: 10023e33
 * Size: 79 bytes
 */
#include "deckdll.h"


void FUN_10023e33(uint8_t arg_1)

{
  uint8_t local_8 [4];
  
  local_8[0] = 0xc1;
  if ((arg_1 & 0xc0) == 0xc0) {
    fwrite(local_8,1,1,DAT_1013f728);
  }
  fwrite(&arg_1,1,1,DAT_1013f728);
  return;
}


