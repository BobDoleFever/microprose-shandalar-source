/*
 * Decompiled function: FUN_10007a85
 * Entry Point: 10007a85
 * Size: 123 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_10007a85(int *ptr_1)

{
  if (ptr_1[0x17] != 0) {
    free((void *)ptr_1[0x17]);
    ptr_1[0x17] = 0;
  }
  if (*ptr_1 != 0) {
    if ((void *)*ptr_1 != (void *)0x0) {
      thunk_FUN_10008520((void *)*ptr_1,1);
    }
    *ptr_1 = 0;
  }
  return 0;
}


