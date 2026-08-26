/*
 * Decompiled function: FUN_0049ab7a
 * Entry Point: 0049ab7a
 * Size: 120 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049ab7a(void)

{
  int local_8;
  
  DAT_005ef9b0 = 0;
  _DAT_005f2f88 = 0;
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    if ((*(int *)(&deck + local_8 * 4) != -1) &&
       (DAT_005ef9b0 = DAT_005ef9b0 + 1, ((&DAT_006c13b1)[local_8 * 4] & 0x40) == 0)) {
      _DAT_005f2f88 = _DAT_005f2f88 + 1;
    }
  }
  return 0;
}


