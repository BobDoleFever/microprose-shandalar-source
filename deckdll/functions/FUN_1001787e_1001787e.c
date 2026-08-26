/*
 * Decompiled function: FUN_1001787e
 * Entry Point: 1001787e
 * Size: 168 bytes
 */
#include "deckdll.h"


int32_t FUN_1001787e(int arg_1)

{
  int32_t local_8;
  
  local_8 = 0;
  if ((DAT_101cf7f8 & 1) == 0) {
    local_8 = 1;
  }
  else {
    if (((DAT_101cf7f8 & 2) != 0) && (DAT_101cf7fa <= arg_1)) {
      local_8 = 1;
    }
    if (((DAT_101cf7f8 & 4) != 0) && (arg_1 <= DAT_101cf7fa)) {
      local_8 = 1;
    }
    if (((DAT_101cf7f8 & 8) != 0) && (DAT_101cf7fa == arg_1)) {
      local_8 = 1;
    }
  }
  return local_8;
}


