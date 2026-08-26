/*
 * Decompiled function: FUN_10002fc8
 * Entry Point: 10002fc8
 * Size: 118 bytes
 */
#include "magvid.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t __cdecl FUN_10002fc8(int arg_1)

{
  LPVOID arg_1_00;
  int32_t uval_1;
  
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    arg_1_00 = *(LPVOID *)(&DAT_10010868 + arg_1 * 4);
    if (arg_1_00 == (LPVOID)0x0) {
      uval_1 = 0;
    }
    else {
      if (*(int *)((int)arg_1_00 + 8) != 0) {
        thunk_FUN_10005d8d(arg_1_00);
      }
      _DAT_10010544 = _DAT_10010544 + 1;
      uval_1 = 0;
    }
  }
  return uval_1;
}


