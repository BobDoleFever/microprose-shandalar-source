/*
 * Decompiled function: FUN_00510fc0
 * Entry Point: 00510fc0
 * Size: 350 bytes
 */
#include "magic.h"


void FUN_00510fc0(int *arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  
  iVar1 = *arg2;
  iVar2 = arg2[1];
  iVar3 = arg2[2];
  iVar5 = iVar2;
  if (iVar2 <= iVar3) {
    iVar5 = iVar3;
  }
  if (iVar5 <= iVar1) {
    iVar5 = iVar1;
  }
  local_1c = iVar2;
  if (iVar3 <= iVar2) {
    local_1c = iVar3;
  }
  if (iVar1 <= local_1c) {
    local_1c = iVar1;
  }
  if (iVar5 != 0) {
    local_1c = iVar5 - local_1c;
    iVar4 = (local_1c * 0x1000) / iVar5;
    if (local_1c == 0) {
      *arg1 = 0;
      arg1[1] = iVar4;
      arg1[2] = iVar5 << 6;
      return;
    }
    if (iVar5 == iVar1) {
      local_1c = ((iVar2 - iVar3) * 0xf00) / local_1c;
    }
    else if (iVar5 == iVar2) {
      local_1c = ((iVar3 - iVar1) * 0xf00) / local_1c + 0x1e00;
    }
    else {
      local_1c = ((iVar1 - iVar2) * 0xf00) / local_1c + 0x3c00;
    }
    if (local_1c < 0) {
      local_1c = local_1c + 0x5a00;
    }
    *arg1 = local_1c;
    arg1[1] = iVar4;
    arg1[2] = iVar5 << 6;
    return;
  }
  *arg1 = -1;
  arg1[1] = 0;
  arg1[2] = 0;
  return;
}


