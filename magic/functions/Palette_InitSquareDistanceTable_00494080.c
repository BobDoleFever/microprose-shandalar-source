/*
 * Decompiled function: Palette_InitSquareDistanceTable
 * Entry Point: 00494080
 * Size: 58 bytes
 */
#include "magic.h"


undefined4 Palette_InitSquareDistanceTable(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (DAT_0052a1a8 != 0) {
    return 0;
  }
  iVar1 = -0xff;
  piVar2 = &DAT_0064b0c0;
  do {
    piVar3 = piVar2 + 1;
    iVar4 = iVar1 * iVar1;
    iVar1 = iVar1 + 1;
    *piVar2 = iVar4;
    piVar2 = piVar3;
  } while (piVar3 < &DAT_0064b8c0);
  DAT_0052a1a8 = 1;
  return 1;
}


