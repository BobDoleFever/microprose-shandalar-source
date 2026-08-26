/*
 * Decompiled function: FUN_10023ee1
 * Entry Point: 10023ee1
 * Size: 74 bytes
 */
#include "deckdll.h"


int32_t FUN_10023ee1(void *arg_1)

{
  uint8_t local_8 [4];
  
  local_8[0] = 0xc;
  fwrite(local_8,1,1,DAT_1013f728);
  fwrite(arg_1,3,0x100,DAT_1013f728);
  return 0;
}


