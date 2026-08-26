/*
 * Decompiled function: thunk_FUN_10001722
 * Entry Point: 1000103c
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __cdecl thunk_FUN_10001722(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10011524 == 0) || (DAT_10011524 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_1001e8b4)(arg_1,arg_2);
  }
  return uval_1;
}


