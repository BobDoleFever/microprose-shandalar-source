/*
 * Decompiled function: thunk_FUN_10005a46
 * Entry Point: 10001000
 * Size: 5 bytes
 */
#include "magsnd.h"


void __cdecl thunk_FUN_10005a46(int32_t *ptr_1)

{
  mmioClose((HMMIO)ptr_1[0x72],0);
  if (ptr_1[0xd] != 0) {
    operator_delete((void *)ptr_1[0xd]);
  }
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    operator_delete((void *)*ptr_1);
  }
  return;
}


