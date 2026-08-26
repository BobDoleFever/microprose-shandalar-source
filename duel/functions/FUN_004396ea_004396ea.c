/*
 * Decompiled function: FUN_004396ea
 * Entry Point: 004396ea
 * Size: 324 bytes
 */
#include "duel.h"


int FUN_004396ea(int arg_1)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_1 == -1) {
    iVar1 = -1;
  }
  else {
    local_10 = 0;
    for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
      local_10 = local_10 + (&DAT_004f71c4)[arg_1 * 0xa0 + local_8 * 2];
    }
    if (local_10 == 0) {
      iVar1 = -1;
    }
    else {
      local_c = FUN_00439892(local_10);
      for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
        local_c = local_c - (&DAT_004f71c4)[arg_1 * 0xa0 + local_8 * 2];
        if (local_c < 0) {
          local_14 = *(int *)(&DAT_004f71c0 + local_8 * 8 + arg_1 * 0x280);
          if (DAT_0066aaf4 != 1) {
            (&DAT_004f71c4)[arg_1 * 0xa0 + local_8 * 2] =
                 (&DAT_004f71c4)[arg_1 * 0xa0 + local_8 * 2] + -1;
          }
          break;
        }
      }
      for (local_8 = 0;
          (iVar1 = DAT_00665ed0, local_8 < DAT_00665ed0 &&
          (iVar1 = local_8, *(int *)(&DAT_004ff590 + local_8 * 0x34) != local_14));
          local_8 = local_8 + 1) {
      }
    }
  }
  return iVar1;
}


