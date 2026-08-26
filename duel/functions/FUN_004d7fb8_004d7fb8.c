/*
 * Decompiled function: FUN_004d7fb8
 * Entry Point: 004d7fb8
 * Size: 444 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004d7fb8(undefined1 *arg_1,undefined4 arg_2,undefined4 arg_3)

{
  uint arg_1_00;
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_28;
  int local_1c;
  int local_18;
  uint local_c;
  int local_8;
  
  puVar1 = arg_1;
  DAT_005ddaa8 = arg_2;
  _DAT_005ddaac = arg_2;
  DAT_005ddab0 = arg_3;
  DAT_005093c8 = 0;
  iVar2 = FUN_004d8f90(8);
  for (local_18 = 0; local_18 < iVar2; local_18 = local_18 + 1) {
    uVar3 = FUN_004d8f90(9);
    *(undefined4 *)(&DAT_005ddac0 + local_18 * 8) = uVar3;
    uVar3 = FUN_004d8f90(9);
    *(undefined4 *)(&DAT_005ddac4 + local_18 * 8) = uVar3;
  }
  FUN_004d8174(iVar2);
  local_c = FUN_004d8f90(8);
  do {
    while( true ) {
      if (local_c == 0xffffffff) {
        return (int)arg_1 - (int)puVar1;
      }
      if (*(int *)(&DAT_005dcea8 + local_c * 0xc) < 0) break;
      arg_1_00 = *(uint *)(&DAT_005dceac + local_c * 0xc);
      *arg_1 = (&DAT_005dcea8)[local_c * 0xc];
      arg_1 = arg_1 + 1;
      local_28 = (byte)arg_1_00;
      iVar2 = FUN_004d8f90(arg_1_00);
      if (iVar2 == -1) {
        local_c = 0xffffffff;
      }
      else {
        local_c = (int)local_c >> (local_28 & 0x1f) | iVar2 << (8 - local_28 & 0x1f);
      }
    }
    local_8 = *(int *)(&DAT_005dceb0 + local_c * 0xc);
    do {
      iVar2 = FUN_004d9080();
      if (iVar2 == -1) goto LAB_004d8152;
      if (iVar2 == 0) {
        local_1c = *(int *)(&DAT_005ddac4 + local_8 * 8);
      }
      else {
        local_1c = *(int *)(&DAT_005ddac0 + local_8 * 8);
      }
      local_8 = local_1c + -0x100;
    } while (-1 < local_8);
    *arg_1 = (undefined1)local_1c;
    arg_1 = arg_1 + 1;
LAB_004d8152:
    local_c = FUN_004d8f90(8);
  } while( true );
}


