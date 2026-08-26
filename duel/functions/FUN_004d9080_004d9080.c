/*
 * Decompiled function: FUN_004d9080
 * Entry Point: 004d9080
 * Size: 137 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004d9080(void)

{
  uint local_8;
  
  if (DAT_005093c8 == 0) {
    if (DAT_005ddab0 <= (int)DAT_005ddaa8 - _DAT_005ddaac) {
      return 0xffffffff;
    }
    DAT_005dcea4 = *DAT_005ddaa8;
    DAT_005ddaa8 = DAT_005ddaa8 + 1;
    DAT_005093c8 = 0x20;
  }
  local_8 = (uint)((DAT_005dcea4 & 1) != 0);
  DAT_005dcea4 = DAT_005dcea4 >> 1;
  DAT_005093c8 = DAT_005093c8 + -1;
  return local_8;
}


