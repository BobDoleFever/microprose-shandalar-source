/*
 * Decompiled function: FUN_0040a566
 * Entry Point: 0040a566
 * Size: 120 bytes
 */
#include "magic.h"


undefined4 FUN_0040a566(void)

{
  int local_8;
  
  DAT_0067bde8 = 0;
  DAT_0067f3b8 = 0;
  for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
    if ((*(int *)(&deck + local_8 * 4) != -1) &&
       (DAT_0067bde8 = DAT_0067bde8 + 1, ((&DAT_00702151)[local_8 * 4] & 0x40) == 0)) {
      DAT_0067f3b8 = DAT_0067f3b8 + 1;
    }
  }
  return 0;
}


