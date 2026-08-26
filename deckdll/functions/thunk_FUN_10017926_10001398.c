/*
 * Decompiled function: thunk_FUN_10017926
 * Entry Point: 10001398
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017926(int arg_1)

{
  int32_t uStack_8;
  
  uStack_8 = 0;
  if ((DAT_101cf7fc & 1) == 0) {
    uStack_8 = 1;
  }
  else {
    if (((DAT_101cf7fc & 2) != 0) && (DAT_101cf7fe <= arg_1)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7fc & 4) != 0) && (arg_1 <= DAT_101cf7fe)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7fc & 8) != 0) && (DAT_101cf7fe == arg_1)) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


