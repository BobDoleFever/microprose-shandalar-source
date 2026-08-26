/*
 * Decompiled function: Haar_Transform2D_Inverse
 * Entry Point: 004f1e50
 * Size: 110 bytes
 */
#include "magic.h"


void Haar_Transform2D_Inverse(undefined8 *arg_1,uint arg_2,uint arg_3)

{
  uint uVar1;
  int iVar2;
  uint arg2;
  undefined8 uVar3;
  
  uVar1 = arg_2 << 8 | arg_2;
  arg2 = (int)uVar1 >> 0x1f | ((int)uVar1 >> 0x1f) << 0x10 | uVar1 >> 0x10;
  uVar3 = __allshl(0x20,arg2);
  uVar3 = CONCAT44(arg2 | (uint)((ulonglong)uVar3 >> 0x20),uVar1 | uVar1 << 0x10 | (uint)uVar3);
  iVar2 = (arg_3 >> 3) - 1;
  do {
    *arg_1 = uVar3;
    arg_1 = arg_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *arg_1 = uVar3;
  for (uVar1 = arg_3 & 7; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(char *)arg_1 = (char)arg_2;
    arg_1 = (undefined8 *)((int)arg_1 + 1);
  }
  return;
}


