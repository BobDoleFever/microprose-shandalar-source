/*
 * Decompiled function: Mem_AllocOrFree_004f1e20
 * Entry Point: 004f1e20
 * Size: 45 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_004f1e20(undefined8 *arg_1,undefined8 *arg_2,uint arg_3)

{
  uint uVar1;
  
  for (uVar1 = arg_3 >> 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *arg_1 = *arg_2;
    arg_2 = arg_2 + 1;
    arg_1 = arg_1 + 1;
  }
  uVar1 = arg_3 & 7;
  if (uVar1 != 0) {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)arg_1 = *(undefined1 *)arg_2;
      arg_2 = (undefined8 *)((int)arg_2 + 1);
      arg_1 = (undefined8 *)((int)arg_1 + 1);
    }
  }
  return;
}


