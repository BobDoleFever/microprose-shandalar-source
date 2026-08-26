/*
 * Decompiled function: FUN_0047ee28
 * Entry Point: 0047ee28
 * Size: 59 bytes
 */
#include "duel.h"


void FUN_0047ee28(undefined8 *arg_1,undefined8 *arg_2,uint arg_3)

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


