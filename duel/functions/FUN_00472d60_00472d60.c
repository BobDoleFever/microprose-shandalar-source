/*
 * Decompiled function: FUN_00472d60
 * Entry Point: 00472d60
 * Size: 305 bytes
 */
#include "duel.h"


uint FUN_00472d60(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_10;
  
  if (arg_1 == 0) {
    local_10 = 0;
  }
  else if ((((arg_2 == 0x20) || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)) {
    iVar1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uVar3 = iVar1 * arg_3 >> 0x1f;
    uVar3 = 4 - (((iVar1 * arg_3 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3);
    uVar4 = (int)uVar3 >> 0x1f;
    puVar2 = (uint *)((iVar1 * arg_3 + (((uVar3 ^ uVar4) - uVar4 & 3 ^ uVar4) - uVar4)) * arg_5 +
                      iVar1 * arg_4 + arg_1);
    if (arg_2 == 0x20) {
      local_10 = *puVar2;
    }
    else if (arg_2 == 0x18) {
      local_10 = (uint)(byte)*puVar2 << 0x10 | (uint)*(byte *)((int)puVar2 + 1) << 8 |
                 (uint)*(byte *)((int)puVar2 + 2);
    }
    else if (arg_2 == 0x10) {
      local_10 = (uint)CONCAT11((byte)*puVar2,*(byte *)((int)puVar2 + 1));
    }
    else if (arg_2 == 8) {
      local_10 = (uint)(byte)*puVar2;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}


