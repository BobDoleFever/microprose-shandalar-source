/*
 * Decompiled function: FUN_00432a0b
 * Entry Point: 00432a0b
 * Size: 178 bytes
 */
#include "duel.h"


uint FUN_00432a0b(char *str_1,int arg2)

{
  uint uVar1;
  
  Mem_AllocOrFree_004d9630((uint *)(str_1 + 9),(uint *)&DAT_004f4470);
  if (arg2 == 0) {
    uVar1 = FUN_00432c99(str_1);
  }
  else {
    DAT_00515e88 = __open(str_1,0x8000);
    if (DAT_00515e88 == -1) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__EMPTY__004f4478);
    }
    else {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f4474);
    }
    __close(DAT_00515e88);
    uVar1 = (uint)(DAT_00515e88 != -1);
  }
  return uVar1;
}


