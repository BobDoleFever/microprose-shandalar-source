/*
 * Decompiled function: FUN_004d85eb
 * Entry Point: 004d85eb
 * Size: 280 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004d85eb(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  uint local_c;
  int local_8;
  
  local_c = 0xd;
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    *(uint *)(&DAT_005dce20 + local_8 * 4) = 0xffffffff >> ((byte)local_8 & 0x1f);
  }
  DAT_005ddaa8 = arg_1;
  _DAT_005ddaac = arg_1;
  DAT_005ddab0 = 100000;
  DAT_005093c8 = 0;
  DAT_005dcea4 = 0;
  DAT_005ddab4 = FUN_004d8f90(0xd);
  for (local_8 = 0; local_8 < DAT_005ddab4; local_8 = local_8 + 1) {
    uVar1 = FUN_004d8f90(0xd);
    *(undefined4 *)(&DAT_005ddac0 + local_8 * 8) = uVar1;
    uVar1 = FUN_004d8f90(0xd);
    *(undefined4 *)(&DAT_005ddac4 + local_8 * 8) = uVar1;
    local_c = local_c + 0x1a;
  }
  _DAT_005ddab8 = arg_3;
  DAT_005ddabc = arg_2;
  FUN_004d8703(DAT_005ddab4);
  return (uint)((local_c & 7) != 0) + ((int)(local_c + ((int)local_c >> 0x1f & 7U)) >> 3);
}


