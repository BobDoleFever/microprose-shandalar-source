/*
 * Decompiled function: FUN_004d71e6
 * Entry Point: 004d71e6
 * Size: 412 bytes
 */
#include "duel.h"


int FUN_004d71e6(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  int local_18;
  int local_c;
  
  iVar1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  uVar2 = *(uint *)(&DAT_004ff5a4 + iVar1 * 0x34);
  local_18 = ((int)*(short *)(&DAT_004ff59a + iVar1 * 0x34) & 0xffffbfffU) * 2;
  if ((&DAT_004ff595)[iVar1 * 0x34] == '\0') {
    local_18 = 0;
  }
  local_c = (int)((local_18 + 2) *
                 (((int)*(short *)(&DAT_004ff59c + iVar1 * 0x34) & 0xffffbfffU) + 1)) / 2;
  if ((((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) && (arg1 == DAT_00666458)) {
    local_c = local_c + -1;
  }
  if ((uVar2 & 0x80) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x100) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if (((&DAT_004ff5a8)[iVar1 * 0x34] & 3) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x40) != 0) {
    local_c = (int)((((int)*(short *)(&DAT_004ff59c + iVar1 * 0x34) & 0xffffbfffU) + 1) * local_c) /
              2;
  }
  if ((uVar2 & 0x200) != 0) {
    local_c = (local_c * 3) / 2;
  }
  return (int)(*(int *)(&DAT_00666718 + arg1 * 4) * local_c +
              (*(int *)(&DAT_00666718 + arg1 * 4) * local_c >> 0x1f & 7U)) >> 3;
}


