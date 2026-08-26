/*
 * Decompiled function: FUN_0046c859
 * Entry Point: 0046c859
 * Size: 78 bytes
 */
#include "magic.h"


void FUN_0046c859(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_006fe404; local_8 = local_8 + 1) {
    DeleteObject(*(HGDIOBJ *)(&DAT_006a3f80 + local_8 * 0x18));
  }
  DAT_006fe404 = 0;
  return;
}


