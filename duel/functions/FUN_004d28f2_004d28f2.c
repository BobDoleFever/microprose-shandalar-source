/*
 * Decompiled function: FUN_004d28f2
 * Entry Point: 004d28f2
 * Size: 639 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004d28f2(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    if (DAT_00676510 == param_1) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 2;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 2;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508fac,s_EARTH_BIND_00508fa0);
    }
    iVar2 = FUN_00468130(param_1,1 - param_1,param_2);
    DAT_00681ea4 = (uint)(iVar2 == 0);
    if ((param_3 == 0x71) && (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1)) {
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
      uVar1 = FUN_0048b81a((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                           *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),0x34,
                           0xffffffff);
      if ((uVar1 & 0x20) != 0) {
        FUN_004af950((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                     *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),2,param_1,
                     param_2);
      }
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
    if (((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (param_3 == 0x34)))))) {
      DAT_0066642c = DAT_0066642c & 0xffffffdf;
    }
    uVar1 = 0;
  }
  return uVar1;
}


