/*
 * Decompiled function: FUN_100174ee
 * Entry Point: 100174ee
 * Size: 120 bytes
 */
#include "deckdll.h"


int32_t FUN_100174ee(int arg1,int arg2)

{
  int32_t local_8;
  
  local_8 = 0;
  if ((arg1 == 1) && (((uint8_t)DAT_101cf7d4 & 0x10) != 0)) {
    if ((((uint8_t)DAT_101cf7d4 & 0x20) != 0) && (arg2 == 0x2d)) {
      local_8 = 1;
    }
    if ((((uint8_t)DAT_101cf7d4 & 0x40) != 0) && (arg2 != 0x2d)) {
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


