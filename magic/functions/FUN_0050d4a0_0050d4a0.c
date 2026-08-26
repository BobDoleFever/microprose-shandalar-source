/*
 * Decompiled function: FUN_0050d4a0
 * Entry Point: 0050d4a0
 * Size: 64 bytes
 */
#include "magic.h"


void FUN_0050d4a0(int *arg1,int arg2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_0070a850)[*arg1];
  iVar2 = (*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * *(int *)(iVar1 + 0x28) * arg2;
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + ((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
  *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) - arg2;
  arg1[4] = arg1[4] - arg2;
  return;
}


