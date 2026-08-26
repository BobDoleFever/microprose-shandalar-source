/*
 * Decompiled function: FUN_0040b3c2
 * Entry Point: 0040b3c2
 * Size: 127 bytes
 */
#include "magic.h"


void FUN_0040b3c2(undefined4 arg1,undefined4 arg2)

{
  if (DAT_0067bde0 < 0x100) {
    *(undefined4 *)(&DAT_0067a9a0 + DAT_0067bde0 * 0x10) = arg1;
    *(undefined4 *)(&DAT_0067a9a4 + DAT_0067bde0 * 0x10) = arg2;
    *(int *)(&DAT_0067a9a8 + DAT_0067bde0 * 0x10) =
         (int)(DAT_0052eff0 + (DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5;
    *(int *)(&DAT_0067a9ac + DAT_0067bde0 * 0x10) =
         (int)(DAT_0052eff4 + (DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5;
    DAT_0067bde0 = DAT_0067bde0 + 1;
  }
  return;
}


