/*
 * Decompiled function: FUN_00433d45
 * Entry Point: 00433d45
 * Size: 237 bytes
 */
#include "duel.h"


uint FUN_00433d45(char *str_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_c;
  int local_8;
  
  DAT_00515e88 = __open(str_1,0x8000);
  if (DAT_00515e88 == -1) {
    local_c = 0;
  }
  else {
    DAT_00515e80 = 1;
    uVar1 = FUN_00433bb6(&local_8,4);
    if (local_8 == DAT_0060cc64) {
      uVar2 = FUN_00432e04();
      uVar3 = FUN_00433bb6(&_PlayerFace,4);
      uVar4 = FUN_00433bb6(&_OpponFace,4);
      uVar5 = FUN_00433bb6(&DAT_00664b90,0x32);
      DAT_00664bc2 = 0;
      local_c = FUN_00433bb6(&DAT_006015b0,0x32);
      local_c = uVar1 & 1 & uVar2 & uVar3 & uVar4 & uVar5 & local_c;
      DAT_006015e2 = 0;
    }
    else {
      local_c = 0;
    }
    __close(DAT_00515e88);
  }
  return local_c;
}


