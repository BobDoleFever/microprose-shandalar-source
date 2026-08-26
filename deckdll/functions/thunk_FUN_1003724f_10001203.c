/*
 * Decompiled function: thunk_FUN_1003724f
 * Entry Point: 10001203
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1003724f(int arg_1)

{
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  for (iStack_c = 0; iStack_c < DAT_101cf920; iStack_c = iStack_c + 1) {
    if (((&DAT_1016a620)[iStack_c * 4] == arg_1) &&
       ((*(uint32_t *)(&DAT_1016a62c + iStack_c * 0x10) & 1 << (DAT_10162904 & 0x1f)) == 0)) {
      iStack_8 = iStack_8 + 1;
    }
  }
  return iStack_8;
}


