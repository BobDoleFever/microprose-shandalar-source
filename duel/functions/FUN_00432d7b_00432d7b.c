/*
 * Decompiled function: FUN_00432d7b
 * Entry Point: 00432d7b
 * Size: 137 bytes
 */
#include "duel.h"


undefined4 FUN_00432d7b(char *str_1)

{
  undefined4 uVar1;
  
  Mem_AllocOrFree_004d9630((uint *)(str_1 + 9),(uint *)&DAT_004f4518);
  DAT_00515e88 = __open(str_1,0x8301,0x80);
  if (DAT_00515e88 == -1) {
    uVar1 = 0;
  }
  else {
    DAT_00515e80 = 0;
    FUN_00432e04();
    __close(DAT_00515e88);
    if (DAT_00515ea4 == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


