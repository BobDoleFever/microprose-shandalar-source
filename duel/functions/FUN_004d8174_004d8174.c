/*
 * Decompiled function: FUN_004d8174
 * Entry Point: 004d8174
 * Size: 771 bytes
 */
#include "duel.h"


undefined4 FUN_004d8174(int arg_1)

{
  int iVar1;
  uint uVar2;
  int local_ac;
  int local_a4;
  uint local_a0;
  int local_9c;
  int local_98 [25];
  int local_34;
  int local_30 [7];
  int iStack_14;
  int local_c;
  int local_8;
  
  local_34 = 0;
  local_98[0] = 0x100;
  local_98[1] = 0x80;
  local_98[2] = 0x40;
  local_98[3] = 0x20;
  local_98[4] = 0x10;
  local_98[5] = 8;
  local_98[6] = 4;
  local_98[7] = 2;
  local_98[8] = 1;
  for (local_9c = 0; local_9c < 0x10; local_9c = local_9c + 1) {
    local_98[local_9c + 9] = 1;
  }
  local_8 = arg_1 + -1;
  local_30[0] = arg_1 + -1;
  do {
    iVar1 = local_34;
    local_34 = local_34 + 1;
    if (local_98[iVar1 + 9] == 0) {
      local_c = *(int *)(&DAT_005ddac4 + local_8 * 8);
    }
    else {
      local_c = *(int *)(&DAT_005ddac0 + local_8 * 8);
    }
    local_8 = local_c + -0x100;
    local_30[local_34] = local_c + -0x100;
    if (local_8 < 0) {
      local_a0 = 0;
      for (local_a4 = 0; local_a4 < local_34; local_a4 = local_a4 + 1) {
        local_a0 = local_a0 | local_98[local_a4 + 9] << ((byte)local_a4 & 0x1f);
      }
      for (local_9c = 0; local_9c < local_98[local_34]; local_9c = local_9c + 1) {
        uVar2 = local_9c << ((byte)local_34 & 0x1f);
        *(int *)(&DAT_005dceac + (uVar2 | local_a0) * 0xc) = local_34;
        *(undefined4 *)(&DAT_005dcea8 + (uVar2 | local_a0) * 0xc) =
             *(undefined4 *)(DAT_005ddabc + local_c * 4);
        *(undefined4 *)(&DAT_005dceb0 + (uVar2 | local_a0) * 0xc) = 0xffffffff;
      }
      local_98[local_34 + 9] = 1;
      iVar1 = local_34;
      local_34 = local_34 + -1;
      local_98[iVar1 + 8] = local_98[iVar1 + 8] + -1;
      local_8 = local_30[local_34];
LAB_004d8425:
      while ((iVar1 = local_34, -1 < local_98[9] && (local_98[local_34 + 9] < 0))) {
        local_98[local_34 + 9] = 1;
        local_34 = local_34 + -1;
        local_98[iVar1 + 8] = local_98[iVar1 + 8] + -1;
        local_8 = local_30[local_34];
      }
    }
    else if (local_34 == 8) {
      local_a0 = 0;
      for (local_ac = 0; local_ac < 8; local_ac = local_ac + 1) {
        local_a0 = local_a0 | local_98[local_ac + 9] << ((byte)local_ac & 0x1f);
      }
      *(undefined4 *)(&DAT_005dcea8 + local_a0 * 0xc) = 0xffffffff;
      *(undefined4 *)(&DAT_005dceac + local_a0 * 0xc) = 8;
      *(int *)(&DAT_005dceb0 + local_a0 * 0xc) = local_8;
      local_98[0x11] = 1;
      local_34 = 7;
      local_98[0x10] = local_98[0x10] + -1;
      local_8 = iStack_14;
      goto LAB_004d8425;
    }
    if (local_98[9] < 0) {
      return 0;
    }
  } while( true );
}


