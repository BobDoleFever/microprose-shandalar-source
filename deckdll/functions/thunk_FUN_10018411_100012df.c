/*
 * Decompiled function: thunk_FUN_10018411
 * Entry Point: 100012df
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10018411(int arg_1)

{
  int iStack_c;
  int iStack_8;
  
  iStack_c = 0;
  do {
    if (6 < iStack_c) {
      return 0;
    }
    for (iStack_8 = 0; iStack_8 < 0x20; iStack_8 = iStack_8 + 1) {
      if (((*(uint32_t *)(&DAT_101cf7d8 + iStack_c * 4) & 1 << ((uint8_t)iStack_8 & 0x1f)) != 0) &&
         (iStack_c * 0x20 + iStack_8 + 1 == arg_1)) {
        return 1;
      }
    }
    iStack_c = iStack_c + 1;
  } while( true );
}


