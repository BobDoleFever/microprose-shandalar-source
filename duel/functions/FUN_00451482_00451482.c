/*
 * Decompiled function: FUN_00451482
 * Entry Point: 00451482
 * Size: 734 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00451482(undefined4 arg1,undefined4 arg2)

{
  undefined4 uVar1;
  int local_10;
  int local_8;
  
  FUN_00451760();
  if ((DAT_0068edd4 == 0) && (DAT_0068f230 == -1)) {
    _DAT_0068f0b4 = 0;
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
      if ((*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2
          ) != 0)) {
        FUN_0048b81a(local_8,local_10,0x3c,0xffffffff);
      }
    }
  }
  FUN_00451995();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
      if ((*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 2
          ) != 0)) {
        FUN_0048b81a(local_8,local_10,0x34,0xffffffff);
        FUN_0048b81a(local_8,local_10,0x32,0xffffffff);
        FUN_0048b81a(local_8,local_10,0x33,0xffffffff);
      }
    }
  }
  if (DAT_0066aaf4 != 1) {
    DAT_00676500 = 0;
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
        if (*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) {
          uVar1 = FUN_0046da4a(local_8,local_10);
          *(undefined4 *)(&DAT_00682714 + local_10 * 0x120 + local_8 * 0x5b20) = uVar1;
        }
      }
    }
    if (DAT_0068eed8 == 0) {
      Mem_AllocOrFree_0049f704(arg1,arg2);
    }
    else {
      SendMessageA(DAT_00618990,0x464,0xffff,0);
    }
  }
  return;
}


