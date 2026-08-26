/*
 * Decompiled function: thunk_FUN_1000a1b0
 * Entry Point: 10001195
 * Size: 5 bytes
 */
#include "magvid.h"


void __fastcall thunk_FUN_1000a1b0(int arg_1)

{
  if (*(int *)(arg_1 + 0x10) != 0) {
    operator_delete(*(void **)(arg_1 + 0x10));
  }
  return;
}


