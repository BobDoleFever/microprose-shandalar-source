/*
 * Decompiled function: FUN_004d7f60
 * Entry Point: 004d7f60
 * Size: 88 bytes
 */
#include "duel.h"


void FUN_004d7f60(undefined8 *arg1,uint arg2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = arg2;
  if (((uint)arg1 & 4) != 0) {
    *(undefined1 *)arg1 = 0;
    arg1 = (undefined8 *)((int)arg1 + 4);
    uVar1 = arg2 - 1;
    if (uVar1 == 0 || (int)arg2 < 1) {
      return;
    }
  }
  uVar2 = uVar1 >> 1;
  if (uVar2 != 0) {
    while (uVar2 = uVar2 - 1, uVar2 != 0) {
      *arg1 = 0;
      arg1 = arg1 + 1;
    }
    *arg1 = 0;
  }
  if ((uVar1 & 1) != 0) {
    *(undefined1 *)arg1 = 0;
  }
  return;
}


