/*
 * Decompiled function: StopAVI
 * Entry Point: 100012c1
 * Size: 5 bytes
 */
#include "magvid.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl StopAVI(int arg_1)

{
  int arg_1_00;
  int32_t uval_1;
  
                    /* 0x12c1  6  StopAVI */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(int *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == 0) {
      uval_1 = 0;
    }
    else if ((*(uint32_t *)(arg_1_00 + 4) >> 1 & 1) == 0) {
      if (*(int *)(arg_1_00 + 8) != 0) {
        thunk_FUN_10004f90(arg_1 + 0x100);
        thunk_FUN_10005ef9(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + -1;
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}


