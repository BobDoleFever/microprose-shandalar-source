/*
 * Decompiled function: thunk_FUN_100174ee
 * Entry Point: 10001505
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100174ee(int arg1,int arg2)

{
  int32_t uStack_8;
  
  uStack_8 = 0;
  if ((arg1 == 1) && (((uint8_t)DAT_101cf7d4 & 0x10) != 0)) {
    if ((((uint8_t)DAT_101cf7d4 & 0x20) != 0) && (arg2 == 0x2d)) {
      uStack_8 = 1;
    }
    if ((((uint8_t)DAT_101cf7d4 & 0x40) != 0) && (arg2 != 0x2d)) {
      uStack_8 = 1;
    }
  }
  else {
    uStack_8 = 0;
  }
  return uStack_8;
}


