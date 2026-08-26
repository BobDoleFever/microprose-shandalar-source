/*
 * Decompiled function: FUN_00434446
 * Entry Point: 00434446
 * Size: 123 bytes
 */
#include "duel.h"


void * FUN_00434446(int arg1,byte *arg2)

{
  void *pvVar1;
  int local_8;
  
  local_8 = FUN_0043456a(arg2);
  if ((*(int *)(arg1 + 0xc) == 0) || (**(int **)(arg1 + 0xc) != local_8)) {
    pvVar1 = _bsearch(&local_8,*(void **)(arg1 + 8),*(size_t *)(arg1 + 4),0xc,FUN_004343f6);
    *(void **)(arg1 + 0xc) = pvVar1;
  }
  else {
    pvVar1 = *(void **)(arg1 + 0xc);
  }
  return pvVar1;
}


