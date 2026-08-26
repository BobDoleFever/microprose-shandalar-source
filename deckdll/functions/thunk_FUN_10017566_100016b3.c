/*
 * Decompiled function: thunk_FUN_10017566
 * Entry Point: 100016b3
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017566(int arg1,int arg2)

{
  int val_1;
  int32_t uStack_8;
  
  uStack_8 = 0;
  if (((uint8_t)DAT_101cf7d4 & 0x80) == 0) {
    uStack_8 = 0;
  }
  else {
    if (((DAT_101cf7d4._1_1_ & 1) != 0) && (arg1 == 7)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 2) != 0) && (arg1 == 8)) {
      uStack_8 = 1;
    }
    if ((((DAT_101cf7d4._1_1_ & 4) != 0) && (arg1 == 1)) && (arg2 == 0x2d)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 8) != 0) && (val_1 = thunk_FUN_10018411(arg2), val_1 != 0)) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


