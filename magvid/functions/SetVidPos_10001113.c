/*
 * Decompiled function: SetVidPos
 * Entry Point: 10001113
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidPos(int arg1,short *arg2)

{
  int arg_1;
  int32_t uval_1;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t *puStack_8;
  
                    /* 0x1113  15  SetVidPos */
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 2;
  }
  else {
    arg_1 = *(int *)(&DAT_10010868 + arg1 * 4);
    if (arg_1 == 0) {
      uval_1 = 0;
    }
    else {
      puStack_8 = *(int32_t **)(arg_1 + 8);
      if (puStack_8 == (int32_t *)0x0) {
        uval_1 = 2;
      }
      else if (*(int *)(arg_1 + 0x50) == 0) {
        uval_1 = 2;
      }
      else {
        thunk_FUN_100063e6(arg_1,(int)*arg2,(int)arg2[1]);
        iStack_18 = 0;
        iStack_14 = 0;
        iStack_10 = 0;
        iStack_c = 0;
        thunk_FUN_1000b4fb((void *)*puStack_8,&iStack_18);
        *arg2 = *arg2 + (short)*(int32_t *)(arg_1 + 0x58);
        arg2[1] = arg2[1] + (short)*(int32_t *)(arg_1 + 0x5c);
        iStack_18 = iStack_18 + *arg2;
        iStack_14 = iStack_14 + arg2[1];
        iStack_10 = iStack_10 + *arg2;
        iStack_c = iStack_c + arg2[1];
        thunk_FUN_1000b54e((void *)*puStack_8,&iStack_18);
        uval_1 = 0;
      }
    }
  }
  return uval_1;
}


