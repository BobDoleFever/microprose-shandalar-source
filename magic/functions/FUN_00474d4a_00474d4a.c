/*
 * Decompiled function: FUN_00474d4a
 * Entry Point: 00474d4a
 * Size: 51 bytes
 */
#include "magic.h"


undefined4 FUN_00474d4a(void)

{
  undefined4 uVar1;
  
  if (DAT_006a3f78 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_006ff4cc + DAT_006a3f78 * 4);
  }
  return uVar1;
}


