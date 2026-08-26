/*
 * Decompiled function: FUN_004398be
 * Entry Point: 004398be
 * Size: 64 bytes
 */
#include "duel.h"


void FUN_004398be(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    iVar1 = _rand();
    *(int *)(&DAT_00516748 + local_8 * 4) = iVar1;
  }
  Mem_AllocOrFree_004398fe();
  return;
}


