/*
 * Decompiled function: FUN_0040d5a8
 * Entry Point: 0040d5a8
 * Size: 478 bytes
 */
#include "duel.h"


bool FUN_0040d5a8(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    FUN_00468097(param_1,param_2,3);
  }
  if (((param_3 == 0x32) || (param_3 == 0x33)) &&
     ((DAT_00690c48 == param_2 && (DAT_0068ecb0 == param_1)))) {
    iVar2 = FUN_004680fc(param_1,param_2);
    DAT_0066642c = DAT_0066642c + iVar2;
  }
  if (param_3 == 0x73) {
    iVar2 = FUN_004680fc(param_1,param_2);
    bVar1 = 0 < iVar2;
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(1);
    bVar1 = false;
  }
  else {
    if ((param_3 == 0x6d) && (iVar2 = FUN_004680fc(param_1,param_2), 0 < iVar2)) {
      FUN_00434660(s_prompts_txt_004f2878,s_TRISKELION_004f286c);
      iVar2 = FUN_00461047(param_1,param_2,1);
      if (iVar2 != 0) {
        *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) | 0x6000000;
        FUN_00467eef(param_1,param_2);
      }
    }
    if (param_3 == 0x72) {
      FUN_004612b0(param_1,param_2,0x72,1);
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    bVar1 = false;
  }
  return bVar1;
}


