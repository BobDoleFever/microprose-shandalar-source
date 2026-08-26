/*
 * Decompiled function: Pic_Subsystem_00451b1c
 * Entry Point: 00451b1c
 * Size: 406 bytes
 */
#include "magic.h"


int Pic_Subsystem_00451b1c(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  int local_18;
  int local_c;
  
  iVar1 = *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20);
  uVar2 = *(uint *)(&DAT_0051aecc + iVar1 * 0x34);
  local_18 = ((int)*(short *)(&DAT_0051aec2 + iVar1 * 0x34) & 0xffffbfffU) * 2;
  if ((&DAT_0051aebd)[iVar1 * 0x34] == '\0') {
    local_18 = 0;
  }
  local_c = (int)((local_18 + 2) *
                 (((int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34) & 0xffffbfffU) + 1)) / 2;
  if ((((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
     (arg1 == g_DefendingPlayer)) {
    local_c = local_c + -1;
  }
  if ((uVar2 & 0x80) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x100) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if (((&DAT_0051aed0)[iVar1 * 0x34] & 3) != 0) {
    local_c = (local_c * 3) / 2;
  }
  if ((uVar2 & 0x40) != 0) {
    local_c = (int)((((int)*(short *)(&DAT_0051aec4 + iVar1 * 0x34) & 0xffffbfffU) + 1) * local_c) /
              2;
  }
  if ((uVar2 & 0x200) != 0) {
    local_c = (local_c * 3) / 2;
  }
  return (int)(*(int *)(&DAT_00695e88 + arg1 * 4) * local_c +
              (*(int *)(&DAT_00695e88 + arg1 * 4) * local_c >> 0x1f & 7U)) >> 3;
}


