/*
 * Decompiled function: FUN_00421a81
 * Entry Point: 00421a81
 * Size: 177 bytes
 */
#include "magic.h"


undefined4 FUN_00421a81(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  
  if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
     (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
    bVar1 = false;
  }
  else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
          (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if (arg2 == 2) {
      DAT_00538a28 = *(undefined4 *)(arg1 + 0x2c);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


