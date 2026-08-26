/*
 * Decompiled function: thunk_FUN_100017b0
 * Entry Point: 100011b8
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __cdecl thunk_FUN_100017b0(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_10011524 == 0) || (DAT_10011524 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1001e8bc)(arg_1);
  }
  return uval_1;
}


