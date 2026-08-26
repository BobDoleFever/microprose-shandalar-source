/*
 * Decompiled function: FUN_0046f21e
 * Entry Point: 0046f21e
 * Size: 211 bytes
 */
#include "magic.h"


void FUN_0046f21e(char *arg_1,undefined4 arg_2,undefined4 arg_3)

{
  int local_330;
  int local_32c;
  int local_328;
  undefined4 local_324 [200];
  
  local_330 = 0;
  if (DAT_006781d0 != (void *)0x0) {
    Mem_AllocOrFree_0050fc50(DAT_006781d0);
  }
  Sprite_LoadAll(local_324,arg_1);
  for (local_328 = 0; local_328 < 4; local_328 = local_328 + 1) {
    for (local_32c = 0; local_32c < 9; local_32c = local_32c + 1) {
      (&DAT_006781d0)[local_328 * 9 + local_32c] = (void *)local_324[local_330];
      local_330 = local_330 + 1;
    }
  }
  DAT_00527b34 = arg_2;
  DAT_00527b38 = arg_3;
  return;
}


