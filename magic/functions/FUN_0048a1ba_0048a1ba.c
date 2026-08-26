/*
 * Decompiled function: FUN_0048a1ba
 * Entry Point: 0048a1ba
 * Size: 116 bytes
 */
#include "magic.h"


void FUN_0048a1ba(undefined4 arg_1,int y,undefined4 arg_3,undefined4 arg_4)

{
  if (DAT_00676d54 == 0) {
    (*(code *)PTR_FUN_00527b3c)(arg_1,y,arg_3,arg_4,(int)(y + (y >> 0x1f & 7U)) >> 3 & 3);
  }
  else {
    (*(code *)PTR_FUN_00527b3c)(arg_1,y,arg_3,arg_4,DAT_00676d54);
    DAT_00676d54 = 0;
  }
  return;
}


