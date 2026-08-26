/*
 * Decompiled function: thunk_FUN_10017444
 * Entry Point: 100011a4
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017444(int arg1,int arg2)

{
  int32_t uStack_8;
  
  uStack_8 = 0;
  if (((uint8_t)DAT_101cf7d4 & 1) == 0) {
    uStack_8 = 0;
  }
  else {
    if (((((uint8_t)DAT_101cf7d4 & 2) != 0) && (arg1 == 5)) && (arg2 == 10)) {
      uStack_8 = 1;
    }
    if (((((uint8_t)DAT_101cf7d4 & 4) != 0) && (arg1 == 5)) && (arg2 != 10)) {
      uStack_8 = 1;
    }
    if (((((uint8_t)DAT_101cf7d4 & 8) != 0) && (arg1 != 5)) && (arg2 == 10)) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


