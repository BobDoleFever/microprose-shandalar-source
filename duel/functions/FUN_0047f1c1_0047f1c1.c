/*
 * Decompiled function: FUN_0047f1c1
 * Entry Point: 0047f1c1
 * Size: 38 bytes
 */
#include "duel.h"


undefined2 FUN_0047f1c1(uint param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)(param_1 & 0xffffffe0);
  param_2 = param_2 >> 6;
  do {
    uVar2 = *puVar3;
    puVar1 = puVar3 + 0x20;
    puVar3 = puVar3 + 0x40;
    param_2 = param_2 - 1;
  } while (param_2 != 0);
  return CONCAT11(*puVar1,uVar2);
}


