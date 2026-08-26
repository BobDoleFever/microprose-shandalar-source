/*
 * Decompiled function: FUN_00409db6
 * Entry Point: 00409db6
 * Size: 93 bytes
 */
#include "magic.h"


void FUN_00409db6(void)

{
  int local_8;
  
  if (DAT_00516ca8 != (HMODULE)0x0) {
    FreeLibrary(DAT_00516ca8);
    DAT_00516ca8 = (HMODULE)0x0;
  }
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    (&DAT_00701020)[local_8] = 0;
  }
  return;
}


