/*
 * Decompiled function: FUN_10017444
 * Entry Point: 10017444
 * Size: 170 bytes
 */
#include "deckdll.h"


int32_t FUN_10017444(int arg1,int arg2)

{
  int32_t local_8;
  
  local_8 = 0;
  if (((uint8_t)DAT_101cf7d4 & 1) == 0) {
    local_8 = 0;
  }
  else {
    if (((((uint8_t)DAT_101cf7d4 & 2) != 0) && (arg1 == 5)) && (arg2 == 10)) {
      local_8 = 1;
    }
    if (((((uint8_t)DAT_101cf7d4 & 4) != 0) && (arg1 == 5)) && (arg2 != 10)) {
      local_8 = 1;
    }
    if (((((uint8_t)DAT_101cf7d4 & 8) != 0) && (arg1 != 5)) && (arg2 == 10)) {
      local_8 = 1;
    }
  }
  return local_8;
}


