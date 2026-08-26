/*
 * Decompiled function: thunk_FUN_10004481
 * Entry Point: 10001235
 * Size: 5 bytes
 */
#include "statwin.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall thunk_FUN_10004481(int arg_1)

{
  _DAT_10012acc = 0;
  if (*(int *)(arg_1 + 8) != 0) {
    operator_delete(*(void **)(arg_1 + 8));
  }
  if (*(int *)(arg_1 + 0xc) != 0) {
    if (*(void **)(arg_1 + 0xc) != (void *)0x0) {
      thunk_FUN_10004250(*(void **)(arg_1 + 0xc),1);
    }
  }
  *(int32_t *)(arg_1 + 0xc) = 0;
  *(int32_t *)(arg_1 + 8) = 0;
  return;
}


