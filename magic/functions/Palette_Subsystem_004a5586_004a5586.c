/*
 * Decompiled function: Palette_Subsystem_004a5586
 * Entry Point: 004a5586
 * Size: 125 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a5586(int x,int y,int *width,int *height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (x * 0x280) / DAT_00522458;
  iVar2 = ((y * 3 + -0x30) * 0xa0) / DAT_0052245c;
  iVar3 = (iVar1 + 0x60) / 2 - (iVar2 + -0x110);
  *width = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
  iVar1 = iVar2 + -0x110 + (iVar1 + 0x60) / 2;
  *height = ((int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5) + 1;
  return;
}


