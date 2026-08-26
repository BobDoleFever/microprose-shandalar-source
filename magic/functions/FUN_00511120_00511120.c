/*
 * Decompiled function: FUN_00511120
 * Entry Point: 00511120
 * Size: 364 bytes
 */
#include "magic.h"


void FUN_00511120(uint *arg1,int *arg2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar1 = arg2[1];
  if ((iVar1 == 0) && (*arg2 == -1)) {
    uVar2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
    *arg1 = uVar2;
    arg1[1] = uVar2;
    arg1[2] = uVar2;
    arg1[3] = local_4;
    return;
  }
  if (*arg2 == 0x5a00) {
    *arg2 = 0;
  }
  uVar2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
  iVar3 = (0x1000 - iVar1) * uVar2;
  uVar4 = (int)(iVar3 + (iVar3 >> 0x1f & 0xfffU)) >> 0xc;
  uVar5 = ((0xf00000 - iVar1 * (*arg2 % 0xf00)) * uVar2) / 0xf00000;
  local_10 = 0xf00;
  uVar6 = (((*arg2 % 0xf00 + -0xf00) * iVar1 + 0xf00000) * uVar2) / 0xf00000;
  switch(*arg2 / 0xf00) {
  case 0:
    local_10 = uVar2;
    local_c = uVar6;
    local_8 = uVar4;
    break;
  case 1:
    local_10 = uVar5;
    local_c = uVar2;
    local_8 = uVar4;
    break;
  case 2:
    local_10 = uVar4;
    local_c = uVar2;
    local_8 = uVar6;
    break;
  case 3:
    local_10 = uVar4;
    local_c = uVar5;
    local_8 = uVar2;
    break;
  case 4:
    local_10 = uVar6;
    local_c = uVar4;
    local_8 = uVar2;
    break;
  case 5:
    local_10 = uVar2;
    local_c = uVar4;
    local_8 = uVar5;
  }
  *arg1 = local_10;
  arg1[1] = local_c;
  arg1[2] = local_8;
  arg1[3] = local_4;
  return;
}


