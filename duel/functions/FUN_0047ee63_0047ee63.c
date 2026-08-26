/*
 * Decompiled function: FUN_0047ee63
 * Entry Point: 0047ee63
 * Size: 105 bytes
 */
#include "duel.h"


void FUN_0047ee63(undefined8 *arg_1,uint arg_2,uint arg_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = arg_2 << 8 | arg_2;
  uVar3 = (int)uVar1 >> 0x1f | ((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10;
  uVar4 = __allshl(0x20,uVar3);
  uVar4 = CONCAT44(uVar3 | (uint)((ulonglong)uVar4 >> 0x20),uVar1 | uVar1 << 0x10 | (uint)uVar4);
  iVar2 = (arg_3 >> 3) - 1;
  do {
    *arg_1 = uVar4;
    arg_1 = arg_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *arg_1 = uVar4;
  for (uVar3 = arg_3 & 7; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)arg_1 = (char)arg_2;
    arg_1 = (undefined8 *)((int)arg_1 + 1);
  }
  return;
}


