/*
 * Decompiled function: FUN_1000394a
 * Entry Point: 1000394a
 * Size: 308 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_1000394a(int arg1,short *arg2)

{
  int arg_1;
  int32_t uval_1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t *local_8;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else {
    arg_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (arg_1 == 0) {
      uval_1 = 0;
    }
    else {
      local_8 = *(int32_t **)(arg_1 + 8);
      if (local_8 == (int32_t *)0x0) {
        uval_1 = 2;
      }
      else if (*(int *)(arg_1 + 0x50) == 0) {
        uval_1 = 2;
      }
      else {
        thunk_FUN_100063e6(arg_1,(int)*arg2,(int)arg2[1]);
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        thunk_FUN_1000b4fb((void *)*local_8,&local_18);
        *arg2 = *arg2 + (short)*(int32_t *)(arg_1 + 0x58);
        arg2[1] = arg2[1] + (short)*(int32_t *)(arg_1 + 0x5c);
        local_18 = local_18 + *arg2;
        local_14 = local_14 + arg2[1];
        local_10 = local_10 + *arg2;
        local_c = local_c + arg2[1];
        thunk_FUN_1000b54e((void *)*local_8,&local_18);
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}


