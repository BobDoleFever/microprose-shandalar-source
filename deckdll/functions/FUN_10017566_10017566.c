/*
 * Decompiled function: FUN_10017566
 * Entry Point: 10017566
 * Size: 190 bytes
 */
#include "deckdll.h"


int32_t FUN_10017566(int arg1,int arg2)

{
  int val_1;
  int32_t local_8;
  
  local_8 = 0;
  if (((uint8_t)DAT_101cf7d4 & 0x80) == 0) {
    local_8 = 0;
  }
  else {
    if (((DAT_101cf7d4._1_1_ & 1) != 0) && (arg1 == 7)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 2) != 0) && (arg1 == 8)) {
      local_8 = 1;
    }
    if ((((DAT_101cf7d4._1_1_ & 4) != 0) && (arg1 == 1)) && (arg2 == 0x2d)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 8) != 0) && (val_1 = thunk_FUN_10018411(arg2), val_1 != 0)) {
      local_8 = 1;
    }
  }
  return local_8;
}


