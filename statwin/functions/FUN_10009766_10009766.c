/*
 * Decompiled function: FUN_10009766
 * Entry Point: 10009766
 * Size: 74 bytes
 */
#include "statwin.h"


int32_t FUN_10009766(void)

{
  int32_t uval_1;
  
  if (DAT_10012fe4 == 0) {
    uval_1 = 7;
  }
  else {
    DAT_10012fe4 = 0;
    (*DAT_1001e814)();
    FreeLibrary(DAT_1001e874);
    thunk_FUN_10009bda();
    uval_1 = 0;
  }
  return uval_1;
}


