/*
 * Decompiled function: FUN_0047f1e7
 * Entry Point: 0047f1e7
 * Size: 713 bytes
 */
#include "duel.h"


undefined1 *
FUN_0047f1e7(undefined1 *arg_1,int *arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,
            undefined4 arg_8,int arg_9)

{
  undefined1 *puVar1;
  int iVar2;
  int local_2c;
  int local_28;
  int local_20;
  uint local_1c;
  int *local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  if (DAT_005dad84 == 0) {
    for (local_1c = -0x400; (int)local_1c < 0x1c00; local_1c = local_1c + 1) {
      if ((int)local_1c < 1) {
        PTR_DAT_004f9d50[local_1c] = 0;
      }
      else {
        iVar2 = (int)local_1c >> 2;
        if (0xfe < iVar2) {
          iVar2 = 0xff;
        }
        PTR_DAT_004f9d50[local_1c] = (char)iVar2;
      }
    }
    DAT_005dad84 = 1;
  }
  if (arg_1 == (undefined1 *)0x0) {
    arg_1 = _malloc(arg_3 * arg_3 * 3 + 0x10);
  }
  puVar1 = arg_1;
  for (local_20 = 0; local_20 < arg_4; local_20 = local_20 + 1) {
    iVar2 = local_20;
    if (arg_9 != 0) {
      iVar2 = local_20 / 2;
    }
    local_10 = (int *)(iVar2 * arg_7 * 4 + arg_6);
    local_14 = (int *)(iVar2 * arg_7 * 4 + arg_5);
    for (local_1c = 0; (int)local_1c < arg_3; local_1c = local_1c + 1) {
      iVar2 = *arg_2;
      if (arg_9 == 0) {
        local_2c = *local_14;
        local_28 = *local_10;
        local_28 = (local_28 >> 3) + (local_28 >> 1) + local_28;
      }
      else {
        if ((local_1c & 1) == 0) {
          local_2c = *local_14;
          local_28 = *local_10;
        }
        else {
          local_2c = (local_14[arg_3 - 1U != local_1c] + *local_14) / 2;
          local_28 = (local_10[arg_3 - 1U != local_1c] + *local_10) / 2;
        }
        local_28 = (local_28 >> 3) + (local_28 >> 1) + local_28;
      }
      local_8 = local_2c * 2 + -0x400 + iVar2;
      local_c = local_28 + -0x333 + iVar2;
      *arg_1 = PTR_DAT_004f9d50[local_8];
      arg_1[1] = PTR_DAT_004f9d50
                 [((iVar2 * 2 - (iVar2 >> 2)) - (local_c >> 1)) - ((local_8 >> 2) - (local_8 >> 4))]
      ;
      arg_1[2] = PTR_DAT_004f9d50[local_c];
      if (arg_9 == 0) {
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
      }
      else if ((local_1c & 1) != 0) {
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
      }
      arg_2 = arg_2 + 1;
      arg_1 = arg_1 + 3;
    }
  }
  return puVar1;
}


