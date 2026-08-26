/*
 * Decompiled function: FUN_00407a1e
 * Entry Point: 00407a1e
 * Size: 533 bytes
 */
#include "duel.h"


undefined4 FUN_00407a1e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    if ((DAT_00676504 == param_1) && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_004f2424,s_MINDTWIST_004f2418);
      iVar1 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_10);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      for (local_8 = 0; local_8 < *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
          local_8 = local_8 + 1) {
        FUN_00488150(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),1,0);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


