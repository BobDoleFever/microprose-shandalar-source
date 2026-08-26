/*
 * Decompiled function: FUN_100042c0
 * Entry Point: 100042c0
 * Size: 132 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100042c0(int arg_1)

{
  int arg_1_00;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_1 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    arg_1_00 = *(int *)(*(int *)(&DAT_10010868 + arg_1 * 4) + 8);
    if (arg_1_00 == 0) {
      uval_1 = 2;
    }
    else {
      thunk_FUN_10004c60(arg_1_00);
      uval_1 = 0;
    }
  }
  return uval_1;
}


