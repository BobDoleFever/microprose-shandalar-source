/*
 * Decompiled function: FUN_100058cd
 * Entry Point: 100058cd
 * Size: 204 bytes
 */
#include "statwin.h"


int32_t __fastcall FUN_100058cd(int *ptr_1)

{
  if (ptr_1[3] != 0) {
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    ptr_1[3] = 0;
  }
  if (*ptr_1 != 0) {
    operator_delete((void *)*ptr_1);
    *ptr_1 = 0;
  }
  if (ptr_1[4] != 0) {
    if ((void *)ptr_1[4] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[4],1);
    }
    ptr_1[4] = 0;
  }
  return 0;
}


