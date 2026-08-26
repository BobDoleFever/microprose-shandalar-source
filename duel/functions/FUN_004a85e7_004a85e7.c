/*
 * Decompiled function: FUN_004a85e7
 * Entry Point: 004a85e7
 * Size: 702 bytes
 */
#include "duel.h"


undefined4 FUN_004a85e7(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x10,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_0050623c,s_RIGTHEOUSNESS_0050622c);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x10,0,
                           &DAT_006679f0,1,&local_10);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar1);
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
      local_10 = *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_c = *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0x10,0)
      ;
      iVar2 = FUN_0041c0ab(local_10,local_c,0,param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_8 = FUN_004a2b00(param_1,param_2,DAT_0066aaec,local_10,local_c);
        if (local_8 != -1) {
          *(undefined2 *)(&DAT_006826d8 + local_8 * 0x120 + param_1 * 0x5b20) = 7;
          *(undefined2 *)(&DAT_006826da + local_8 * 0x120 + param_1 * 0x5b20) = 7;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


