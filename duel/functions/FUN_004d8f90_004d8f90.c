/*
 * Decompiled function: FUN_004d8f90
 * Entry Point: 004d8f90
 * Size: 221 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004d8f90(uint arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_c;
  
  if (DAT_005093c8 < arg_1) {
    iVar1 = arg_1 - DAT_005093c8;
    if ((int)DAT_005ddaa8 + (4 - _DAT_005ddaac) < DAT_005ddab0) {
      uVar2 = *DAT_005ddaa8;
      DAT_005ddaa8 = DAT_005ddaa8 + 1;
      local_c = (byte)DAT_005093c8;
      uVar3 = DAT_005dcea4 |
              (*(uint *)(&DAT_005dce20 + (0x20 - iVar1) * 4) & uVar2) << (local_c & 0x1f);
      arg_1._0_1_ = (byte)iVar1;
      DAT_005dcea4 = uVar2 >> ((byte)arg_1 & 0x1f);
      DAT_005093c8 = 0x20 - iVar1;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = *(uint *)(&DAT_005dce20 + (0x20 - arg_1) * 4) & DAT_005dcea4;
    DAT_005dcea4 = DAT_005dcea4 >> ((byte)arg_1 & 0x1f);
    DAT_005093c8 = DAT_005093c8 - arg_1;
  }
  return uVar3;
}


