/*
 * Decompiled function: thunk_FUN_1000a795
 * Entry Point: 100010b4
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_1000a795(int *ptr_1)

{
  if (ptr_1[5] != 0) {
    operator_delete((void *)ptr_1[5]);
  }
  if (ptr_1[6] != 0) {
    operator_delete((void *)ptr_1[6]);
  }
  ptr_1[6] = 0;
  ptr_1[5] = ptr_1[6];
  if (ptr_1[0x67] != 0) {
    free((void *)ptr_1[0x67]);
    ptr_1[0x67] = 0;
  }
  if (ptr_1[2] != 0) {
    DrawDibClose(ptr_1[2]);
    ptr_1[2] = 0;
  }
  if (*ptr_1 != 0) {
    ICClose(*ptr_1);
    *ptr_1 = 0;
  }
  if (ptr_1[0x5f] != 0) {
    ptr_1[0x5f] = 0;
  }
  if (ptr_1[0x60] != 0) {
    ptr_1[0x60] = 0;
  }
  *ptr_1 = 0;
  ptr_1[3] = 0;
  return 0;
}


