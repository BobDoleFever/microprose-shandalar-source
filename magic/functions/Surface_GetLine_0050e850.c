/*
 * Decompiled function: Surface_GetLine
 * Entry Point: 0050e850
 * Size: 96 bytes
 */
#include "magic.h"


void Surface_GetLine(undefined4 *arg_1,int arg_2,int arg_3,int arg_4,uint arg_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  AssertOrLog((uint)(arg_2 != 0),0x5325e0,0x4b8,s_GetLine_not_implemented_for_page_00532688);
  iVar1 = (&DAT_0070a850)[arg_2];
  puVar3 = (undefined4 *)
           ((*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x20)) * arg_4 + *(int *)(iVar1 + 0x18) +
           arg_3);
  for (uVar2 = arg_5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *arg_1 = *puVar3;
    puVar3 = puVar3 + 1;
    arg_1 = arg_1 + 1;
  }
  for (uVar2 = arg_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)arg_1 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    arg_1 = (undefined4 *)((int)arg_1 + 1);
  }
  return;
}


