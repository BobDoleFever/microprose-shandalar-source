/*
 * Decompiled function: Mem_AllocOrFree_004f6d88
 * Entry Point: 004f6d88
 * Size: 49 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_004f6d88(void)

{
  if (DAT_0068a720 != 0) {
    free((void *)DAT_0068a720);
  }
  DAT_0068a720 = 0;
  return;
}


