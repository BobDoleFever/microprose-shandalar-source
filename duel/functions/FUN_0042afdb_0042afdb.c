/*
 * Decompiled function: FUN_0042afdb
 * Entry Point: 0042afdb
 * Size: 220 bytes
 */
#include "duel.h"


undefined4 FUN_0042afdb(void)

{
  bool bVar1;
  undefined4 local_8;
  
  if ((DAT_00681ea8 < 1) || (DAT_00681eac < 1)) {
    bVar1 = true;
  }
  else if ((DAT_006668f0 < 10) && (DAT_006668f4 < 10)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (DAT_0066aaf4 == 1) {
      if (9 < DAT_006668f0) {
        DAT_00681ea8 = 0;
      }
      if (9 < DAT_006668f4) {
        DAT_00681eac = 0;
      }
      local_8 = 0;
    }
    else {
      FUN_00451482(0,0xff);
      local_8 = 1;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


