/*
 * Decompiled function: thunk_FUN_10009de4
 * Entry Point: 10001131
 * Size: 5 bytes
 */
#include "statwin.h"


void __fastcall thunk_FUN_10009de4(int32_t *ptr_1)

{
  *ptr_1 = &PTR_thunk_FUN_1000a2e4_1000f8a8;
  if (ptr_1[1] != 0) {
    free((void *)ptr_1[1]);
  }
  if ((ptr_1[3] != 0) && (ptr_1[2] != 0)) {
    free((void *)ptr_1[2]);
  }
  if (ptr_1[4] != 0) {
    operator_delete((void *)ptr_1[4]);
  }
  return;
}


