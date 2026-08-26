/*
 * Decompiled function: FUN_004d7735
 * Entry Point: 004d7735
 * Size: 77 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d7735(int arg_1)

{
  int local_8;
  
  while (local_8 = arg_1 + 1, local_8 < 500) {
    *(undefined4 *)(&DAT_006c13ac + local_8 * 4) = *(undefined4 *)(&deck + local_8 * 4);
    arg_1 = local_8;
  }
  _DAT_006c1b7c = 0xffffffff;
  return;
}


