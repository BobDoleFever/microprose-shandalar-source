/*
 * Decompiled function: thunk_FUN_100099ff
 * Entry Point: 1000115e
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __cdecl thunk_FUN_100099ff(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10012fe4 == 0) || (DAT_10012fe4 == 2)) {
    uval_1 = 7;
  }
  else {
    uval_1 = (*DAT_1001e834)(arg_1,arg_2);
  }
  return uval_1;
}


