/*
 * Decompiled function: thunk_FUN_1001787e
 * Entry Point: 10001622
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001787e(int arg_1)

{
  int32_t uStack_8;
  
  uStack_8 = 0;
  if ((DAT_101cf7f8 & 1) == 0) {
    uStack_8 = 1;
  }
  else {
    if (((DAT_101cf7f8 & 2) != 0) && (DAT_101cf7fa <= arg_1)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7f8 & 4) != 0) && (arg_1 <= DAT_101cf7fa)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7f8 & 8) != 0) && (DAT_101cf7fa == arg_1)) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


