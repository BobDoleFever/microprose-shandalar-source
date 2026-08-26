/*
 * Decompiled function: FUN_1000592b
 * Entry Point: 1000592b
 * Size: 166 bytes
 */
#include "magvid.h"


void __cdecl FUN_1000592b(int arg_1)

{
  int32_t *ptr_1;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_18;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100059d0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  *(int32_t *)(arg_1 + 0x3c) = 0;
  *(int32_t *)(arg_1 + 0x38) = *(int32_t *)(arg_1 + 0x3c);
  *(int32_t *)(arg_1 + 0x40) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
  ptr_1 = operator_new(0x128);
  local_8 = 0;
  if (ptr_1 == (int32_t *)0x0) {
    local_18 = (int32_t *)0x0;
  }
  else {
    local_18 = thunk_FUN_10001740(ptr_1);
  }
  *(int32_t **)(arg_1 + 8) = local_18;
  *unaff_FS_OFFSET = local_10;
  return;
}


