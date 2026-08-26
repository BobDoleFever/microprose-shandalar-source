/*
 * Decompiled function: FUN_00462244
 * Entry Point: 00462244
 * Size: 357 bytes
 */
#include "duel.h"


bool FUN_00462244(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  if (param_3 == 0x73) {
    bVar2 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(1);
    bVar2 = false;
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c78,s_ORCISH_ARTILLERY_004f8c64);
      FUN_00461047(param_1,param_2,2);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      iVar1 = FUN_004612b0(param_1,param_2,0x72,2);
      if (iVar1 != 0) {
        FUN_004afd1c(param_1,3,param_1,param_2);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}


