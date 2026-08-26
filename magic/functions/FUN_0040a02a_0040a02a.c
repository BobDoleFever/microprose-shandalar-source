/*
 * Decompiled function: FUN_0040a02a
 * Entry Point: 0040a02a
 * Size: 324 bytes
 */
#include "magic.h"


int FUN_0040a02a(int arg_1)

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
      local_10 = local_10 + *(int *)(&DAT_00516cbc + local_8 * 8 + arg_1 * 0x280);
    }
    if (local_10 == 0) {
      iVar1 = -1;
    }
    else {
      local_c = FUN_0040a1d2(local_10);
      for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
        local_c = local_c - *(int *)(&DAT_00516cbc + local_8 * 8 + arg_1 * 0x280);
        if (local_c < 0) {
          local_14 = *(int *)(&DAT_00516cb8 + local_8 * 8 + arg_1 * 0x280);
          if (g_IsAiThinking != 1) {
            *(int *)(&DAT_00516cbc + local_8 * 8 + arg_1 * 0x280) =
                 *(int *)(&DAT_00516cbc + local_8 * 8 + arg_1 * 0x280) + -1;
          }
          break;
        }
      }
      for (local_8 = 0;
          (iVar1 = g_MasterCardCount, local_8 < g_MasterCardCount &&
          (iVar1 = local_8, *(int *)(&g_MasterCardTypeTable + local_8 * 0x34) != local_14));
          local_8 = local_8 + 1) {
      }
    }
  }
  return iVar1;
}


