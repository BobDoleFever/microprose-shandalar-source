/*
 * Decompiled function: FUN_004cda70
 * Entry Point: 004cda70
 * Size: 811 bytes
 */
#include "duel.h"


undefined4 FUN_004cda70(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
    }
    if (param_3 == 0x73) {
      iVar2 = FUN_0049b68d(param_1,param_2,2,2);
      if (iVar2 != 0) {
        uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar3 | 0x20);
        if (iVar2 != 0) {
          return 1;
        }
      }
      uVar1 = 0;
    }
    else {
      if ((param_3 == 0x6d) && (FUN_0042ecaf(param_1,param_2,2,2), DAT_00681ea4 != 1)) {
        FUN_00434660(s_prompts_txt_00508d4c,s_FLOOD_00508d44);
        uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_c);
        iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0,0,uVar3 | 0x20);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
          *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      if (param_3 == 0x72) {
        uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0x200,2,0,0,uVar3 | 0x20);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_004a7b83(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                       *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20));
        }
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


