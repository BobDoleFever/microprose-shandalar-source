/*
 * Decompiled function: FUN_0048e1bf
 * Entry Point: 0048e1bf
 * Size: 239 bytes
 */
#include "magic.h"


uint FUN_0048e1bf(char *str_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_c;
  int local_8;
  
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    local_c = 0;
  }
  else {
    DAT_0054aab0 = 1;
    uVar1 = FUN_0048e01d(&local_8,4);
    if (local_8 == DAT_00695e98) {
      uVar2 = FUN_0048d259();
      uVar3 = FUN_0048e01d(&_PlayerFace,4);
      uVar4 = FUN_0048e01d(&_OpponFace,4);
      uVar5 = FUN_0048e01d(&DAT_006ff310,0x32);
      DAT_006ff342 = 0;
      local_c = FUN_0048e01d(&DAT_0068a6a0,0x32);
      local_c = uVar1 & 1 & uVar2 & uVar3 & uVar4 & uVar5 & local_c;
      DAT_0068a6d2 = 0;
    }
    else {
      local_c = 0;
    }
    _close(DAT_0054aab8);
  }
  return local_c;
}


