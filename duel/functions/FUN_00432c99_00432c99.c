/*
 * Decompiled function: FUN_00432c99
 * Entry Point: 00432c99
 * Size: 226 bytes
 */
#include "duel.h"


undefined4 FUN_00432c99(char *str_1)

{
  undefined4 uVar1;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_004d9630((uint *)(str_1 + 9),(uint *)&DAT_004f4514);
  DAT_00515e88 = __open(str_1,0x8000);
  if (DAT_00515e88 == -1) {
    uVar1 = 0;
  }
  else {
    DAT_00515e80 = 1;
    FUN_00432e04();
    __close(DAT_00515e88);
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
        if (*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_c * 0x120) != -1) {
          (&DAT_00666408)[local_8] = local_c;
        }
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


