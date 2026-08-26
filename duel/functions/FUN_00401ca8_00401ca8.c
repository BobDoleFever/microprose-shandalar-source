/*
 * Decompiled function: FUN_00401ca8
 * Entry Point: 00401ca8
 * Size: 529 bytes
 */
#include "duel.h"


undefined4 FUN_00401ca8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    if ((param_1 == DAT_00676504) && (iVar1 = FUN_0049b309(param_1,7,3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_004f2058,s_BRAINGEYSER_004f204c);
      iVar1 = FUN_0041e2a2(param_1,2,param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,
                           0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_8 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      for (local_c = 0; local_c < *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
          local_c = local_c + 1) {
        FUN_00487ce1(local_8);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


