/*
 * Decompiled function: FUN_004d8477
 * Entry Point: 004d8477
 * Size: 372 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004d8477(undefined4 *arg_1,undefined4 arg_2,undefined4 arg_3)

{
  uint arg_1_00;
  undefined4 *puVar1;
  int iVar2;
  byte local_24;
  int local_14;
  uint local_c;
  int local_8;
  
  puVar1 = arg_1;
  DAT_005ddaa8 = arg_2;
  _DAT_005ddaac = arg_2;
  DAT_005ddab0 = arg_3;
  DAT_005093c8 = 0;
  local_c = FUN_004d8f90(8);
  do {
    while( true ) {
      if (local_c == 0xffffffff) {
        return (int)arg_1 - (int)puVar1 >> 2;
      }
      if (0x7ffffffe < *(int *)(&DAT_005dcea8 + local_c * 0xc)) break;
      arg_1_00 = *(uint *)(&DAT_005dceac + local_c * 0xc);
      *arg_1 = *(undefined4 *)(&DAT_005dcea8 + local_c * 0xc);
      arg_1 = arg_1 + 1;
      local_24 = (byte)arg_1_00;
      iVar2 = FUN_004d8f90(arg_1_00);
      if (iVar2 == -1) {
        local_c = 0xffffffff;
      }
      else {
        local_c = (int)local_c >> (local_24 & 0x1f) | iVar2 << (8 - local_24 & 0x1f);
      }
    }
    local_8 = *(int *)(&DAT_005dceb0 + local_c * 0xc);
    do {
      iVar2 = FUN_004d9080();
      if (iVar2 == -1) goto LAB_004d85c6;
      if (iVar2 == 0) {
        local_14 = *(int *)(&DAT_005ddac4 + local_8 * 8);
      }
      else {
        local_14 = *(int *)(&DAT_005ddac0 + local_8 * 8);
      }
      local_8 = local_14 - _DAT_005ddab8;
    } while (-1 < local_8);
    *arg_1 = *(undefined4 *)(DAT_005ddabc + local_14 * 4);
    arg_1 = arg_1 + 1;
LAB_004d85c6:
    local_c = FUN_004d8f90(8);
  } while( true );
}


