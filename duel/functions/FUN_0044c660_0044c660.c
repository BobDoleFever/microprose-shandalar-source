/*
 * Decompiled function: FUN_0044c660
 * Entry Point: 0044c660
 * Size: 220 bytes
 */
#include "duel.h"


undefined4 FUN_0044c660(byte *arg_1)

{
  uint uVar1;
  int iVar2;
  int local_18;
  uint local_10;
  
  local_18 = (int)DAT_00694482;
  while (0 < local_18) {
    uVar1 = _fgetc(DAT_00694430);
    if (((byte)uVar1 & 0xc0) == 0xc0) {
      uVar1 = uVar1 & 0x3f;
      iVar2 = _fgetc(DAT_00694430);
      if (uVar1 < 2) {
        *arg_1 = (byte)iVar2;
        arg_1 = arg_1 + 1;
        local_18 = local_18 + -1;
      }
      else {
        for (local_10 = 0; local_10 < uVar1; local_10 = local_10 + 1) {
          *arg_1 = (byte)iVar2;
          arg_1 = arg_1 + 1;
        }
        local_18 = local_18 - uVar1;
      }
    }
    else {
      *arg_1 = (byte)uVar1;
      arg_1 = arg_1 + 1;
      local_18 = local_18 + -1;
    }
  }
  return 1;
}


