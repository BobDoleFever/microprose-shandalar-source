/*
 * Decompiled function: thunk_FUN_10004534
 * Entry Point: 1000105a
 * Size: 5 bytes
 */
#include "magsnd.h"


void __cdecl thunk_FUN_10004534(int arg_1)

{
  if (DAT_1000a418 == 0) {
    DAT_1000a418 = arg_1;
  }
  else {
    *(int *)(DAT_1000a41c + 0x1f8) = arg_1;
    *(int *)(arg_1 + 500) = DAT_1000a41c;
  }
  DAT_1000a41c = arg_1;
  return;
}


