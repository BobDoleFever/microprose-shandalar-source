/*
 * Decompiled function: thunk_FUN_1000e6cc
 * Entry Point: 100011c7
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000e6cc(void)

{
  int32_t uval_1;
  int iStack_c;
  int iStack_8;
  
  if (DAT_10041570 == 0) {
    iStack_c = -0xff;
    for (iStack_8 = 0; iStack_8 < 0x200; iStack_8 = iStack_8 + 1) {
      *(int *)(&DAT_10204010 + iStack_8 * 4) = iStack_c * iStack_c;
      iStack_c = iStack_c + 1;
    }
    DAT_10041570 = 1;
    uval_1 = 1;
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


