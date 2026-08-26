/*
 * Decompiled function: thunk_FUN_10023ee1
 * Entry Point: 100015b9
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10023ee1(void *arg_1)

{
  uint8_t auStack_8 [4];
  
  auStack_8[0] = 0xc;
  fwrite(auStack_8,1,1,DAT_1013f728);
  fwrite(arg_1,3,0x100,DAT_1013f728);
  return 0;
}


