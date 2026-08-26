/*
 * Decompiled function: FUN_0050e6f0
 * Entry Point: 0050e6f0
 * Size: 109 bytes
 */
#include "magic.h"


void FUN_0050e6f0(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(arg_2 + 4);
  iVar2 = *(int *)(arg_2 + 0xc);
  iVar3 = *(int *)(arg_2 + 8);
  iVar4 = *(int *)(arg_2 + 0x10);
  *(int *)(arg_2 + 8) = arg_4;
  *(int *)(arg_2 + 4) = arg_3;
  *(int *)(arg_2 + 0xc) = arg_3 + arg_5;
  *(int *)(arg_2 + 0x10) = arg_6 + arg_4;
  *arg_1 = iVar1;
  arg_1[1] = iVar3;
  arg_1[2] = iVar2 - iVar1;
  arg_1[3] = iVar4 - iVar3;
  return;
}


