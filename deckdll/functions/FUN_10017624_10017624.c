/*
 * Decompiled function: FUN_10017624
 * Entry Point: 10017624
 * Size: 266 bytes
 */
#include "deckdll.h"


int32_t FUN_10017624(int arg1,int arg2)

{
  int32_t local_8;
  
  local_8 = 0;
  if (((DAT_101cf7d4._1_1_ & 0x10) == 0) || (arg1 != 2)) {
    local_8 = 0;
  }
  else {
    if (((DAT_101cf7d4._1_1_ & 0x20) != 0) && (arg2 == 0xda)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 0x40) != 0) && (arg2 == 0xd4)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 0x80) != 0) && (arg2 == 0x6d)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 1) != 0) && (arg2 == 0x2d)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 2) != 0) && (arg2 == 0xc)) {
      local_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 4) != 0) && (arg2 == 0x45)) {
      local_8 = 1;
    }
    if (arg2 == 0xcc) {
      local_8 = 1;
    }
  }
  return local_8;
}


