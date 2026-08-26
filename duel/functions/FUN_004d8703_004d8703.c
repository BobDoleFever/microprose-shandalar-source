/*
 * Decompiled function: FUN_004d8703
 * Entry Point: 004d8703
 * Size: 848 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d8703(int arg_1)

{
  int iVar1;
  uint uVar2;
  int local_fc;
  int local_f4;
  uint local_f0;
  int local_ec;
  int local_e8 [5];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8 [35];
  int local_3c;
  int local_38 [7];
  int iStack_1c;
  int local_c;
  int local_8;
  
  local_3c = 0;
  local_d4 = 0x20;
  local_d0 = 0x40;
  local_cc = 0x80;
  local_c8[0] = 0x100;
  local_c8[1] = 0x200;
  local_c8[2] = 0x400;
  for (local_ec = 0; local_ec < 0x20; local_ec = local_ec + 1) {
    local_c8[local_ec + 3] = 1;
  }
  local_8 = arg_1 + -1;
  local_38[0] = arg_1 + -1;
  do {
    iVar1 = local_3c;
    local_3c = local_3c + 1;
    if (local_c8[iVar1 + 3] == 0) {
      local_c = *(int *)(&DAT_005ddac4 + local_8 * 8);
    }
    else {
      local_c = *(int *)(&DAT_005ddac0 + local_8 * 8);
    }
    local_8 = local_c - _DAT_005ddab8;
    local_38[local_3c] = local_c - _DAT_005ddab8;
    if (local_8 < 0) {
      local_f0 = 0;
      for (local_f4 = 0; local_f4 < local_3c; local_f4 = local_f4 + 1) {
        local_f0 = local_f0 | local_c8[local_f4 + 3] << ((byte)local_f4 & 0x1f);
      }
      for (local_ec = 0; local_ec < local_e8[8 - local_3c]; local_ec = local_ec + 1) {
        uVar2 = local_ec << ((byte)local_3c & 0x1f);
        *(int *)(&DAT_005dceac + (local_f0 | uVar2) * 0xc) = local_3c;
        *(undefined4 *)(&DAT_005dcea8 + (local_f0 | uVar2) * 0xc) =
             *(undefined4 *)(DAT_005ddabc + local_c * 4);
        *(undefined4 *)(&DAT_005dceb0 + (local_f0 | uVar2) * 0xc) = 0xffffffff;
      }
      local_c8[local_3c + 3] = 1;
      iVar1 = local_3c;
      local_3c = local_3c + -1;
      local_c8[iVar1 + 2] = local_c8[iVar1 + 2] + -1;
      local_8 = local_38[local_3c];
LAB_004d89f2:
      while ((iVar1 = local_3c, -1 < local_c8[3] && (local_c8[local_3c + 3] < 0))) {
        local_c8[local_3c + 3] = 1;
        local_3c = local_3c + -1;
        local_c8[iVar1 + 2] = local_c8[iVar1 + 2] + -1;
        local_8 = local_38[local_3c];
      }
    }
    else if (local_3c == 8) {
      local_f0 = 0;
      for (local_fc = 0; local_fc < 8; local_fc = local_fc + 1) {
        local_f0 = local_f0 | local_c8[local_fc + 3] << ((byte)local_fc & 0x1f);
      }
      *(undefined4 *)(&DAT_005dcea8 + local_f0 * 0xc) = 0x7fffffff;
      *(undefined4 *)(&DAT_005dceac + local_f0 * 0xc) = 8;
      *(int *)(&DAT_005dceb0 + local_f0 * 0xc) = local_8;
      local_c8[0xb] = 1;
      local_3c = 7;
      local_c8[10] = local_c8[10] + -1;
      local_8 = iStack_1c;
      goto LAB_004d89f2;
    }
    if (local_c8[3] < 0) {
      return 0;
    }
  } while( true );
}


