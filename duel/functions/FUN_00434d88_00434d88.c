/*
 * Decompiled function: FUN_00434d88
 * Entry Point: 00434d88
 * Size: 319 bytes
 */
#include "duel.h"


int FUN_00434d88(int *arg_1)

{
  int iVar1;
  void *pvVar2;
  size_t local_410;
  int local_40c;
  int local_408;
  undefined1 local_404 [1024];
  
  iVar1 = DAT_005166e4;
  local_408 = 0;
  local_410 = 0;
  DAT_005166e4 = DAT_005166e4 + 1;
  if (DAT_004f4610 < DAT_005166e4) {
    DAT_004f4610 = DAT_005166e4;
  }
  if (*arg_1 == 0) {
    for (local_40c = 0; local_40c < 8; local_40c = local_40c + 1) {
      if (arg_1[local_40c + 2] != 0) {
        iVar1 = FUN_00434d88((int *)arg_1[local_40c + 2]);
        local_408 = local_408 + iVar1;
        local_410 = local_410 + 1;
      }
    }
    if (local_410 != 0) {
      local_410 = 0;
      FUN_00434d09(arg_1,(int)local_404,(int *)&local_410);
      pvVar2 = _malloc(local_410);
      arg_1[10] = (int)pvVar2;
      arg_1[0xb] = local_410;
      FID_conflict__memcpy((void *)arg_1[10],local_404,local_410);
    }
    DAT_005166e4 = DAT_005166e4 + -1;
  }
  else {
    local_408 = 1;
    DAT_005166e4 = iVar1;
  }
  return local_408;
}


