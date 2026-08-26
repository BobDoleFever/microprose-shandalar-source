/*
 * Decompiled function: FUN_1003b885
 * Entry Point: 1003b885
 * Size: 69 bytes
 */
#include "deckdll.h"


int32_t FUN_1003b885(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_1004bb90 == 0) || (DAT_1004bb90 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1013eed8)(arg1,arg2);
  }
  return uval_1;
}


