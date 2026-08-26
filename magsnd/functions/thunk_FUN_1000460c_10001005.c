/*
 * Decompiled function: thunk_FUN_1000460c
 * Entry Point: 10001005
 * Size: 5 bytes
 */
#include "magsnd.h"


void __cdecl thunk_FUN_1000460c(int arg_1)

{
  if (DAT_1000a410 == 0) {
    DAT_1000a410 = arg_1;
  }
  else {
    *(int *)(DAT_1000a414 + 0x200) = arg_1;
    *(int *)(arg_1 + 0x1fc) = DAT_1000a414;
  }
  DAT_1000a414 = arg_1;
  return;
}


