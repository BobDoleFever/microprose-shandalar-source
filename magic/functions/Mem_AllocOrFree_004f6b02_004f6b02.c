/*
 * Decompiled function: Mem_AllocOrFree_004f6b02
 * Entry Point: 004f6b02
 * Size: 49 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_004f6b02(void)

{
  if (DAT_00695e9c != 0) {
    free((void *)DAT_00695e9c);
  }
  DAT_00695e9c = 0;
  return;
}


