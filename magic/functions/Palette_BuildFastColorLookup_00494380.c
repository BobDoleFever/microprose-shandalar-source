/*
 * Decompiled function: Palette_BuildFastColorLookup
 * Entry Point: 00494380
 * Size: 98 bytes
 */
#include "magic.h"


undefined4 Palette_BuildFastColorLookup(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = 0;
  do {
    iVar3 = 0;
    uVar4 = 0x80;
    do {
      iVar1 = iVar3 + uVar2 * 8;
      uVar5 = uVar4 & uVar2;
      PTR_DAT_0052a1ac[iVar1] = (uVar5 == 0) - 1U & 4;
      PTR_DAT_0052a1b0[iVar1] = (uVar5 == 0) - 1U & 2;
      uVar4 = (int)uVar4 >> 1;
      iVar3 = iVar3 + 1;
      PTR_DAT_0052a1b4[iVar1] = uVar5 != 0;
    } while (iVar3 < 8);
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x100);
  return 0;
}


