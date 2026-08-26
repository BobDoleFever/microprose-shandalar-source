/*
 * Decompiled function: FUN_0040a1ff
 * Entry Point: 0040a1ff
 * Size: 65 bytes
 */
#include "magic.h"


void FUN_0040a1ff(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    iVar1 = rand();
    *(int *)(&DAT_00538338 + local_8 * 4) = iVar1;
  }
  Mem_AllocOrFree_0040a240();
  return;
}


