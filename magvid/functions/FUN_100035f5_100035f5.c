/*
 * Decompiled function: FUN_100035f5
 * Entry Point: 100035f5
 * Size: 104 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100035f5(int *ptr_1,int arg_2)

{
  int32_t uval_1;
  
  if ((arg_2 < 0) || (2 < arg_2)) {
    uval_1 = 2;
  }
  else if (*(int *)(&DAT_10010868 + arg_2 * 4) == 0) {
    uval_1 = 0;
  }
  else {
    thunk_FUN_1000bc86((void *)**(int32_t **)(*(int *)(&DAT_10010868 + arg_2 * 4) + 8),ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}


