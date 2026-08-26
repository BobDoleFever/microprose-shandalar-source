/*
 * Decompiled function: thunk_FUN_10008774
 * Entry Point: 100011b8
 * Size: 5 bytes
 */
#include "magvid.h"


void __fastcall thunk_FUN_10008774(int32_t *ptr_1)

{
  *ptr_1 = &PTR_LAB_1000f060;
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


