/*
 * Decompiled function: FUN_0048aee0
 * Entry Point: 0048aee0
 * Size: 59 bytes
 */
#include "magic.h"


void FUN_0048aee0(undefined8 *arg1,uint arg2)

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


