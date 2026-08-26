/*
 * Decompiled function: FUN_00460e05
 * Entry Point: 00460e05
 * Size: 578 bytes
 */
#include "duel.h"


bool FUN_00460e05(int param_1,int param_2,int param_3)

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
      FUN_00434660(s_prompts_txt_004f8c1c,s_PRODIGAL_SORCERER_004f8c08);
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
    if ((param_3 == 0x3b) &&
       ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00666738 + (1 - param_1) * 4) = *(int *)(&DAT_00666738 + (1 - param_1) * 4) + -1
      ;
    }
    if ((((param_3 == 199) && (param_1 == DAT_00666458)) && (param_1 == DAT_00676504)) &&
       ((*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + 0x30;
    }
    if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      DAT_0069340c = DAT_0069340c + -0x30;
    }
    bVar1 = false;
  }
  return bVar1;
}


