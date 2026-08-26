/*
 * Decompiled function: FUN_0050afbd
 * Entry Point: 0050afbd
 * Size: 79 bytes
 */
#include "magic.h"


void FUN_0050afbd(void)

{
  int iVar1;
  int local_8;
  
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    iVar1 = FUN_0040a1d2(3);
    if (iVar1 == 0) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffdff;
    }
  }
  return;
}


