/*
 * Decompiled function: thunk_FUN_10017128
 * Entry Point: 1000138e
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017128(int arg_1)

{
  int iStack_8;
  
  iStack_8 = 0;
  while( true ) {
    if (DAT_101cf920 <= iStack_8) {
      return 0;
    }
    if (((&DAT_1016a620)[iStack_8 * 4] == arg_1) && (*(int *)(&DAT_1016a628 + iStack_8 * 0x10) == 1)
       ) break;
    iStack_8 = iStack_8 + 1;
  }
  return 1;
}


