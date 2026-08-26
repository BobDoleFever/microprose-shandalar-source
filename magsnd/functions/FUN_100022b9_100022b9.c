/*
 * Decompiled function: FUN_100022b9
 * Entry Point: 100022b9
 * Size: 208 bytes
 */
#include "magsnd.h"


void __cdecl FUN_100022b9(int *ptr_1,int *ptr_2)

{
  int arg_1;
  int32_t local_c;
  
  arg_1 = *ptr_1;
  *ptr_1 = *ptr_2;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(arg_1 + 0x38 + local_c * 4) == *ptr_1) {
      *(int *)(*ptr_1 + 0x38 + local_c * 4) = arg_1;
    }
    else {
      *(int32_t *)(*ptr_1 + 0x38 + local_c * 4) = *(int32_t *)(arg_1 + 0x38 + local_c * 4);
    }
    *(int32_t *)(arg_1 + 0x38 + local_c * 4) = 0;
  }
  *(int32_t *)(*ptr_1 + 0x10) = *(int32_t *)(arg_1 + 0x10);
  *(uint32_t *)(arg_1 + 8) = *(uint32_t *)(arg_1 + 8) | 0x10;
  *(uint32_t *)(*ptr_1 + 8) = *(uint32_t *)(*ptr_1 + 8) & 0xffffffef;
  thunk_FUN_10004665(arg_1);
  thunk_FUN_1000460c(*ptr_1);
  return;
}


