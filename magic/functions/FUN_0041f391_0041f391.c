/*
 * Decompiled function: FUN_0041f391
 * Entry Point: 0041f391
 * Size: 89 bytes
 */
#include "magic.h"


int FUN_0041f391(void)

{
  Mem_AllocOrFree_0041f12b(DAT_00519c24);
  if (DAT_00519c24 == 0) {
    DAT_00519c24 = 0;
  }
  else {
    DAT_00519c24 = DAT_00519c24 + -1;
  }
  DAT_00519ff4 = 0xffffffff;
  DAT_00519ff8 = 0xffffffff;
  return DAT_00519c24;
}


