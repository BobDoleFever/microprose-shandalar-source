/*
 * Decompiled function: Pic_Subsystem_00451cb2
 * Entry Point: 00451cb2
 * Size: 222 bytes
 */
#include "magic.h"


uint Pic_Subsystem_00451cb2(void)

{
  uint uVar1;
  int iVar2;
  int local_7dc;
  int aiStack_7d8 [500];
  int local_8;
  
  local_8 = 0;
  for (local_7dc = 0; local_7dc < 500; local_7dc = local_7dc + 1) {
    if ((*(int *)(&deck + local_7dc * 4) != -1) && (((&DAT_00702151)[local_7dc * 4] & 0xc0) == 0)) {
      aiStack_7d8[local_8] = local_7dc;
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = FUN_0040a1d2(local_8);
    *(uint *)(&deck + aiStack_7d8[iVar2] * 4) = *(uint *)(&deck + aiStack_7d8[iVar2] * 4) | 0x8000;
    uVar1 = *(uint *)(&deck + aiStack_7d8[iVar2] * 4) & 0xfff;
  }
  return uVar1;
}


