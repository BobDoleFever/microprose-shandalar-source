/*
 * Decompiled function: FUN_0048d3eb
 * Entry Point: 0048d3eb
 * Size: 51 bytes
 */
#include "duel.h"


undefined4 FUN_0048d3eb(void)

{
  undefined4 uVar1;
  
  if (DAT_006764b8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_0068f23c + DAT_006764b8 * 4);
  }
  return uVar1;
}


