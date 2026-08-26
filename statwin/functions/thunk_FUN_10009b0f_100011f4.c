/*
 * Decompiled function: thunk_FUN_10009b0f
 * Entry Point: 100011f4
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __cdecl thunk_FUN_10009b0f(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_10012fe4 == 0) || (DAT_10012fe4 == 2)) {
    uval_1 = 7;
  }
  else {
    uval_1 = (*DAT_1001e84c)(arg_1);
  }
  return uval_1;
}


