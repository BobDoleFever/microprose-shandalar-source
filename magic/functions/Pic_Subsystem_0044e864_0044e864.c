/*
 * Decompiled function: Pic_Subsystem_0044e864
 * Entry Point: 0044e864
 * Size: 328 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044e864(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = abs(arg2 + -0x20);
  iVar2 = abs(arg1 + -0x20);
  iVar1 = (iVar1 + iVar2) * (iVar1 + iVar2);
  iVar2 = abs(arg1 - arg2);
  iVar3 = Pic_Subsystem_0044eb9d(arg1 << 5,arg2 << 5);
  iVar4 = Pic_Subsystem_0044eb9d(arg1 << 8,arg2 << 8);
  iVar5 = Pic_Subsystem_0044eb9d(arg1 << 9,arg2 << 9);
  iVar1 = FUN_0040a305(((int)(iVar1 + (iVar1 >> 0x1f & 0x1ffU)) >> 9) +
                       ((int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4),0,0xc);
  iVar1 = (iVar3 * 4 + iVar4 * 2 + iVar5 + iVar1 * -0x200) * 7;
  iVar1 = iVar1 + (iVar1 >> 0x1f & 0x3fU);
  FUN_0040a305((int)((iVar1 >> 6) + (iVar1 >> 0x1f & 3U)) >> 2,0,100);
  return;
}


