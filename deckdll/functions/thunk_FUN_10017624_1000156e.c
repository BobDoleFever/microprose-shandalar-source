/*
 * Decompiled function: thunk_FUN_10017624
 * Entry Point: 1000156e
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10017624(int arg1,int arg2)

{
  int32_t uStack_8;
  
  uStack_8 = 0;
  if (((DAT_101cf7d4._1_1_ & 0x10) == 0) || (arg1 != 2)) {
    uStack_8 = 0;
  }
  else {
    if (((DAT_101cf7d4._1_1_ & 0x20) != 0) && (arg2 == 0xda)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 0x40) != 0) && (arg2 == 0xd4)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._1_1_ & 0x80) != 0) && (arg2 == 0x6d)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 1) != 0) && (arg2 == 0x2d)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 2) != 0) && (arg2 == 0xc)) {
      uStack_8 = 1;
    }
    if (((DAT_101cf7d4._2_1_ & 4) != 0) && (arg2 == 0x45)) {
      uStack_8 = 1;
    }
    if (arg2 == 0xcc) {
      uStack_8 = 1;
    }
  }
  return uStack_8;
}


