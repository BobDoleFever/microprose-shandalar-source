/*
 * Decompiled function: FUN_1003ba95
 * Entry Point: 1003ba95
 * Size: 73 bytes
 */
#include "deckdll.h"


int32_t FUN_1003ba95(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if ((DAT_1004bb90 == 0) || (DAT_1004bb90 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1013eef8)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}


