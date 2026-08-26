/*
 * Decompiled function: FUN_0070d245
 * Entry Point: 0070d245
 * Size: 112 bytes
 */
#include "magic.h"


void __fastcall FUN_0070d245(undefined4 arg1,undefined4 arg2)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_00536860 == 0 && DAT_00536864 == 0) {
    return;
  }
  DAT_00536874 = 0;
  DAT_00536875 = 0;
  DAT_0053686c = &DAT_00536c8b;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg2,arg1);
  }
  uVar1 = *DAT_00706500;
  DAT_00536880 = (uint)uVar1;
  if (0xb < (byte)uVar1) {
    DAT_00536880 = CONCAT31((uint3)(byte)(uVar1 >> 8),0xb);
  }
  DAT_00536877 = (undefined1)DAT_00536880;
  DAT_00536884 = 8;
  DAT_00536876 = 9;
  DAT_00536878 = 0x1ff;
  DAT_0053687c = 0x100;
  iVar4 = 0;
  iVar3 = 0x800;
  DAT_00706500 = DAT_00706500 + 1;
  do {
    *(undefined2 *)((int)&DAT_00532860 + iVar4) = 0xffff;
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar2 = '\0';
  iVar4 = 0;
  iVar3 = 0x100;
  do {
    (&DAT_00532862)[iVar4] = cVar2;
    cVar2 = cVar2 + '\x01';
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


