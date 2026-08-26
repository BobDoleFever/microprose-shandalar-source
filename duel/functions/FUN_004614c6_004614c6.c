/*
 * Decompiled function: FUN_004614c6
 * Entry Point: 004614c6
 * Size: 347 bytes
 */
#include "duel.h"


bool FUN_004614c6(int param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (param_3 == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(1);
    bVar1 = false;
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c34,s_PIRATE_SHIP_004f8c28);
      FUN_00461047(param_1,param_2,1);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      FUN_004612b0(param_1,param_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    FUN_00461715(param_1,param_2,param_3);
    bVar1 = false;
  }
  return bVar1;
}


