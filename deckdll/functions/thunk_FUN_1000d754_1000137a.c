/*
 * Decompiled function: thunk_FUN_1000d754
 * Entry Point: 1000137a
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000d754(int arg_1)

{
  int iStack_8;
  
  iStack_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= iStack_8) {
      return 0xffffffff;
    }
    if ((&DAT_1016a620)[iStack_8 * 4] == arg_1) break;
    iStack_8 = iStack_8 + 1;
  }
  return *(int32_t *)(&DAT_1016a624 + iStack_8 * 0x10);
}


