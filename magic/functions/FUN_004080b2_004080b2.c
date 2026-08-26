/*
 * Decompiled function: FUN_004080b2
 * Entry Point: 004080b2
 * Size: 93 bytes
 */
#include "magic.h"


undefined4 FUN_004080b2(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00538210;
  if (DAT_00516bdc == 0) {
    uVar1 = 0;
  }
  else {
    DAT_00516bdc = DAT_00516bdc + -1;
    if (DAT_00516bdc != 0) {
      memcpy(&DAT_00538210,&DAT_00538214,DAT_00516bdc * 4);
    }
  }
  return uVar1;
}


