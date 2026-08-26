/*
 * Decompiled function: Pic_Subsystem_0044eb9d
 * Entry Point: 0044eb9d
 * Size: 259 bytes
 */
#include "magic.h"


int Pic_Subsystem_0044eb9d(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = arg1 - 0x80U >> 8 & 0xf;
  uVar3 = (arg1 - 0x80U & 0xff) >> 3;
  uVar4 = arg2 - 0x80U >> 8 & 0xf;
  uVar5 = (arg2 - 0x80U & 0xff) >> 3;
  iVar1 = (int)(char)(&DAT_0067a830)[uVar2 * 0x13 + uVar4] * (0x20 - uVar5) * (0x20 - uVar3) +
          (int)(char)(&DAT_0067a830)[uVar4 + (uVar2 + 1) * 0x13] * (0x20 - uVar5) * uVar3 +
          (int)(char)(&DAT_0067a831)[uVar4 + uVar2 * 0x13] * (0x20 - uVar3) * uVar5 +
          (int)(char)(&DAT_0067a831)[uVar4 + (uVar2 + 1) * 0x13] * uVar5 * uVar3;
  return (int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5;
}


