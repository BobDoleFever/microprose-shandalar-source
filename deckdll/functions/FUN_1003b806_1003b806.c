/*
 * Decompiled function: FUN_1003b806
 * Entry Point: 1003b806
 * Size: 58 bytes
 */
#include "deckdll.h"


int32_t FUN_1003b806(void)

{
  int32_t uval_1;
  
  if ((DAT_1004bb90 == 0) || (DAT_1004bb90 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1013eed0)();
  }
  return uval_1;
}


