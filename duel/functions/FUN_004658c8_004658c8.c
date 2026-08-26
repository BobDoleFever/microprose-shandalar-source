/*
 * Decompiled function: FUN_004658c8
 * Entry Point: 004658c8
 * Size: 355 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004658c8(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((*(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0x20010) == 0) {
      if (arg_1 == DAT_00676510) {
        uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 0x40;
      }
      else {
        uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 0x40;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if (arg_3 == 0x6d) {
      if (local_8 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                 *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_00682718 + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x5b20 +
                      *(int *)(&DAT_0068271c + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x120) | 0x10;
        (&DAT_006826d2)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_1 * 0x5b20 + arg_2 * 0x120) = local_8;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


