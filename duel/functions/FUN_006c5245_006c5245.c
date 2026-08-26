/*
 * Decompiled function: FUN_006c5245
 * Entry Point: 006c5245
 * Size: 112 bytes
 */
#include "duel.h"


void __fastcall FUN_006c5245(undefined4 arg1,undefined4 arg2)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_004ff154 == 0 && DAT_004ff158 == 0) {
    return;
  }
  DAT_004ff168 = 0;
  DAT_004ff169 = 0;
  DAT_004ff160 = &DAT_004ff57f;
  if (PTR_DAT_004f7918 <= DAT_0069453c) {
    (*DAT_00694740)(arg2,arg1);
  }
  uVar1 = *DAT_0069453c;
  DAT_004ff174 = (uint)uVar1;
  if (0xb < (byte)uVar1) {
    DAT_004ff174 = CONCAT31((uint3)(byte)(uVar1 >> 8),0xb);
  }
  DAT_004ff16b = (undefined1)DAT_004ff174;
  DAT_004ff178 = 8;
  DAT_004ff16a = 9;
  DAT_004ff16c = 0x1ff;
  DAT_004ff170 = 0x100;
  iVar4 = 0;
  iVar3 = 0x800;
  DAT_0069453c = DAT_0069453c + 1;
  do {
    *(undefined2 *)((int)&DAT_004fb154 + iVar4) = 0xffff;
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar2 = '\0';
  iVar4 = 0;
  iVar3 = 0x100;
  do {
    (&DAT_004fb156)[iVar4] = cVar2;
    cVar2 = cVar2 + '\x01';
    iVar4 = iVar4 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


