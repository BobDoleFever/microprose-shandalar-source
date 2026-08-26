/*
 * Decompiled function: FUN_0040753d
 * Entry Point: 0040753d
 * Size: 559 bytes
 */
#include "duel.h"


undefined4 FUN_0040753d(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_004f23b4,s_VISIONS_004f23ac);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff
                           ,0xffffffff,0,0,0,&DAT_006679f0,1,&local_c);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
      }
    }
    if (param_3 == 0x71) {
      if (((param_1 == 0) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f23c8,s_VISIONS_004f23c0);
        FUN_004d6639(0,&DAT_006669f0 + *(int *)(&DAT_00682718 + param_2 * 0x120) * 2000,5,
                     &DAT_00667aea,0,&DAT_004f23d4);
      }
      iVar2 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,
                           s_Shuffle_library__Don_t_shuffle__004f23dc,1);
      if (iVar2 == 0) {
        FUN_004d7946(*(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120));
      }
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


