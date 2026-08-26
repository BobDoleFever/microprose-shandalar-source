/*
 * Decompiled function: thunk_FUN_100052e9
 * Entry Point: 100010f5
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl thunk_FUN_100052e9(int32_t arg_1,int32_t arg_2)

{
  int32_t uval_1;
  
  if ((DAT_10010584 == 0) || (DAT_10010584 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_10032cbc)(arg_1,arg_2);
  }
  return uval_1;
}


