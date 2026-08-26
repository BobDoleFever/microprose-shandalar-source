/*
 * Decompiled function: FUN_1000219c
 * Entry Point: 1000219c
 * Size: 285 bytes
 */
#include "magsnd.h"


int __cdecl FUN_1000219c(int arg1,int arg2)

{
  int32_t *ptr_1;
  int val_1;
  
  if (((*(uint32_t *)(arg1 + 4) >> 6 & 1) == 0) || (*(int *)(arg1 + 0x18) != arg2 + -1)) {
    ptr_1 = *(int32_t **)(arg1 + 0x34 + arg2 * 4);
    val_1 = thunk_FUN_10005f0c(ptr_1,*(int *)(*(int *)(arg1 + 0x34) + (arg2 * 3 + -3) * 8 + 0x14));
    if (val_1 == 0) {
      ptr_1[1] = ptr_1[1] | 0x20;
      ptr_1[1] = ptr_1[1] & 0xfffffffb;
      ptr_1[1] = ptr_1[1] & 0xffffffef;
      ptr_1[0x76] = 0;
      ptr_1[2] = *(uint32_t *)(arg1 + 8) & 1 | ptr_1[2] & 0xfffffffe;
      ptr_1[0x7c] = *(int32_t *)(arg1 + 0x1f0);
      ptr_1[0x7b] = *(int32_t *)(arg1 + 0x1ec);
      ptr_1[0x7a] = *(int32_t *)(arg1 + 0x1e8);
      val_1 = 0;
    }
  }
  else {
    val_1 = 0xd;
  }
  return val_1;
}


