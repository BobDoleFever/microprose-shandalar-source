/*
 * Decompiled function: Mem_AllocOrFree_0047f1c1
 * Entry Point: 0047f1c1
 * Size: 38 bytes
 */
#include "duel.h"


undefined2 Mem_AllocOrFree_0047f1c1(uint arg1,uint arg2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)(arg1 & 0xffffffe0);
  uVar3 = arg2 >> 6;
  do {
    uVar2 = *puVar4;
    puVar1 = puVar4 + 0x20;
    puVar4 = puVar4 + 0x40;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return CONCAT11(*puVar1,uVar2);
}


