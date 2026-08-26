/*
 * Decompiled function: thunk_FUN_1003b840
 * Entry Point: 1000125d
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1003b840(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_1004bb90 == 0) || (DAT_1004bb90 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1013eed4)(arg1,arg2);
  }
  return uval_1;
}


