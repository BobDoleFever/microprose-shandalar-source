/*
 * Decompiled function: FUN_0048ed04
 * Entry Point: 0048ed04
 * Size: 231 bytes
 */
#include "magic.h"


void FUN_0048ed04(int arg_1,uint *arg_2,int *arg_3)

{
  short sVar1;
  byte *pbVar2;
  uint uVar3;
  int local_20;
  uint local_18;
  byte *local_10;
  
  *arg_2 = 0x7fffffff;
  *arg_3 = 0;
  if (arg_1 != 0) {
    sVar1 = *(short *)(arg_1 + 0xe);
    local_10 = (byte *)(arg_1 + 0x10);
    for (local_20 = 0; local_20 < sVar1; local_20 = local_20 + 1) {
      uVar3 = (uint)*local_10;
      pbVar2 = local_10 + 1;
      if (uVar3 != 0xff) {
        local_18 = (uint)local_10[1];
        pbVar2 = local_10 + 2;
        if (local_18 == 0xfe) {
          local_18 = (uint)local_10[2];
          pbVar2 = local_10 + 3;
        }
        local_10 = pbVar2;
        if ((int)uVar3 < (int)*arg_2) {
          *arg_2 = uVar3;
        }
        if (*arg_3 < (int)(local_18 + uVar3)) {
          *arg_3 = local_18 + uVar3;
        }
        pbVar2 = local_10 + local_18;
      }
      local_10 = pbVar2;
    }
  }
  return;
}


