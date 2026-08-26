/*
 * Decompiled function: thunk_FUN_10006622
 * Entry Point: 10001091
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_10006622(void *ptr_1)

{
  int32_t uval_1;
  
  if (ptr_1 == (void *)0x0) {
    uval_1 = 5;
  }
  else {
    (**(code **)(**(int **)((int)ptr_1 + 0xbc) + 8))(*(int32_t *)((int)ptr_1 + 0xbc));
    operator_delete(ptr_1);
    uval_1 = 0;
  }
  return uval_1;
}


