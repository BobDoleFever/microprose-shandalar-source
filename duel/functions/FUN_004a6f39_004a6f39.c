/*
 * Decompiled function: FUN_004a6f39
 * Entry Point: 004a6f39
 * Size: 412 bytes
 */
#include "duel.h"


undefined4 FUN_004a6f39(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00506170,s_ANCESTRAL_RECALL_0050615c);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,
                           0xffffffff,0,0,0,&DAT_006679f0,1,&local_10);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_8 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      FUN_00487ce1(local_8);
      FUN_00487ce1(local_8);
      FUN_00487ce1(local_8);
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


